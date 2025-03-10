#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRLEN 1024

#define MAX_WORDS 1000
#define MAX_LENGTH 100
#define CODE_LENGTH 10

typedef struct {
    char word[MAX_LENGTH];
    int count;
    char code[CODE_LENGTH];
} WordCount;

int find_word(WordCount words[], int size, const char* target) {
    for (int i = 0; i < size; i++) {
        if (strcmp(words[i].word, target) == 0) {
            return i;
        }
    }
    return -1;
}

void generate_code(char* code, int index) {
    sprintf(code, "CODE_%d", index + 1);
}

void encode_str(char *str, char *encoded_str) {
    WordCount words[MAX_WORDS] = { {0} };
    int word_count = 0;
    char buffer[MAX_LENGTH];
    const char* ptr = str;
    int encoded_index = 0;

    while((str, "%s", buffer) == 1){
        int index = find_word(words, word_count, buffer);
        if(index != -1) {
            words[index].count++;
        }
        else {
            strcpy(words[word_count].word, buffer);
            words[word_count].count = 1;
            word_count++;
        }
        ptr += strlen(buffer) + 1;
        }

    for (int i = 0; i < word_count; i++) {
        if (words[i].count > 3) {
            generate_code(words[i].code, i);
        }
    }


    ptr = str;
    while (sscanf(ptr, "%s", buffer) == 1) {
        int index = find_word(words, word_count, buffer);
        if (index != -1 && words[index].count > 3) {
            strcpy(&encoded_str[encoded_index], words[index].code);
            encoded_index += strlen(words[index].code);
        }
        else {
            strcpy(&encoded_str[encoded_index], buffer);
            encoded_index += strlen(buffer);
        }
        encoded_str[encoded_index++] = ' ';
        ptr += strlen(buffer) + 1;
    }
    encoded_str[encoded_index - 1] = '\0';
}
    





void fromfile(char* str) {
    FILE* myfile;
    fopen_s(&myfile, "C:/Users/777/Desktop/specialforlaba.txt", "r");
    if (myfile == NULL) {
        printf("ERROR!");
        exit(1);
    }

    if (fgets(str, STRLEN, myfile) != NULL) {
        //str[strcspn(str, "n")] = '\0';
        puts(str);
    }
    fclose(myfile);
}

void klaviatyra(char* str) {
    fgets(str, STRLEN, stdin);
    puts(str);
}

int ckolkoLenStroky(char* str) {
    int l = 0;
    while (str[l] != '\0') {
        l++;
    }
    return l;
}

void podschet(char* str, int* ckolkoMinusov, int* ckolkoPlusov, int* ckolkoPoslesNulamy) {
    for (int i = 0; i < ckolkoLenStroky(str); i++) {
        if (str[i] == '+') {
            (*ckolkoPlusov)++;
            if (str[i + 1] == '0') {
                (*ckolkoPoslesNulamy)++;
            }
        }
        if (str[i] == '-') {
            (*ckolkoMinusov)++;
            if (str[i + 1] == '0') {
                (*ckolkoPoslesNulamy)++;
            }
        }
    }
}

void removeComments(char* str) {
    char temp[STRLEN] = { 0 }; 
    int i = 0, j = 0;

    while (str[i] != '\0') {   //означает конец строки
        if (str[i] == '/' && str[i + 1] == '*') {
            while (str[i] != '\0' && !(str[i] == '*' && str[i + 1] == '/')) {
                i++;
            }
            if (str[i] != '\0') {
                i += 2;
            }
        }
        else {
            temp[j++] = str[i++];
        }
    }
    temp[j] = '\0'; 
    strcpy_s(str, STRLEN, temp);
}

int main() {
    char str[STRLEN];
    char encoded_str[2000];
    char decoded_str[2000];

    int deistvie;
    int ckolkoMinusov = 0, ckolkoPlusov = 0, ckolkoPoslesNulamy = 0;

    printf_s("Choose number 1-from file  2-from klaviatura: ");
    scanf_s("%d", &deistvie);
    getchar();

    switch (deistvie) {
    case 1:
        fromfile(str);
        break;
    case 2:
        klaviatyra(str);
        break;
    default:
        printf_s("this is the end\n");
        return 0;
    }

    podschet(str, &ckolkoMinusov, &ckolkoPlusov, &ckolkoPoslesNulamy);
    printf("Plus: %d, Minus: %d, Plus or minus after zero: %d\n", ckolkoPlusov, ckolkoMinusov, ckolkoPoslesNulamy);

    removeComments(str);
    printf("\nString after removing comments: %s\n", str);  

    return 0;
}