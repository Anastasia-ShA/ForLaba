#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRLEN 1024

#define MAX_WORDS 1000
#define MAX_LENGTH 100
#define CODE_LENGTH 10


    





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
void podschetSlosnosty(char* str) {
    int znakovprepinania = 0;
    int slova = 0;
    int predlozheniya = 0;

    int currentWordLength = 0;
    int inWord = 0; // 0 - не в слове, 1 - в слове
    int obshieSlova = 0;
    
    for (int i = 0; i<ckolkoLenStroky; i++) {
        if (str[i] == '\0') { break; }
        if (str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '!' || str[i] == '?') {
            if (inWord) {
                slova++;
                inWord = 0;
            }
            if (str[i] == '.' || str[i] == '!' || str[i] == '?') {
                znakovprepinania++;
                predlozheniya++;
                printf("Predloshenie %d: ", predlozheniya);
                for (int j = i - currentWordLength; j <= i; j++) {
                    printf("%c", str[j]);
                }
                printf("\nKolvo slov: %d, kolvo znakov prepinania: %d\n", slova, znakovprepinania);
                obshieSlova += slova;
                slova = 0;
                znakovprepinania = 0;
                currentWordLength = 0;
            }
            else if (str[i] == ',') {
                znakovprepinania++;
            }
        }
        else {
            if (!inWord) {
                inWord = 1;
            }
            currentWordLength++;
        }
    
    }

    printf("\nObshee kolvo slov: %d, obxhee kolvo predlozheniy: %d\n", obshieSlova, predlozheniya);
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
    setlocale(0, "Russian");
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

    podschetSlosnosty(str);

    return 0;
}