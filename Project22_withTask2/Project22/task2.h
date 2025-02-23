#pragma once
int miniChislo;
int maxiChislo;
int i, j, n;
int** a;
int* massForKolvoStolbtsov;
int* massForMiniChisel;
int SamoeMinimalnoeForTask2 = INT_MAX; int SamoeMaximalnoeForTask2 = INT_MIN;
int indexMinimalnogoForTask2; int indexMaximalnogoForTask2;

int min(int a, int b) {
	if (a < b) return a;
}

int max(int a, int b) {
	if (a > b) return a;
}

void poiskMinimalnogoChisla() {
	for (i = 0; i < n; i++) {
		miniChislo = INT_MAX;
		for (j = 0; j < massForKolvoStolbtsov[i]; j++) {
			if (a[i][j] < miniChislo) { miniChislo = a[i][j]; }
			if (a[i][j] < SamoeMinimalnoeForTask2) { 
				SamoeMinimalnoeForTask2 = a[i][j];
				indexMinimalnogoForTask2 = i;
			}
		}
		massForMiniChisel[i] = miniChislo;	
	}
	printf_s("\n\nSamoe minimalnoe chislo in all massive = %d \nindex this stroky = %d ", SamoeMinimalnoeForTask2, indexMinimalnogoForTask2);
}

void poiskMaximalnogoChislaIndexa() {
	for (i = 0; i < n; i++) {
		for (j = 0; j < massForKolvoStolbtsov[i]; j++) {
			if (a[i][j] > SamoeMaximalnoeForTask2) {
				SamoeMaximalnoeForTask2 = a[i][j];
				indexMaximalnogoForTask2 = i;
			}
		}
	}
	printf_s("\n\nSamoe maximalnoe chislo in all massive = %d \nindex this stroky = %d \n", SamoeMaximalnoeForTask2, indexMaximalnogoForTask2);
}

void vivodMinimalnixChisel() {
	for (i = 0; i < n; i++) {
		printf_s("\nThe minimalnoe shiclo in %d stroke == %d", i, massForMiniChisel[i]);
	}
}

void poiskMaximalnogoIzMinimalnix() {
	maxiChislo = INT_MIN;
	for (i = 0; i < n; i++) {
		maxiChislo = max(maxiChislo, massForMiniChisel[i]);
	}
	printf_s("\n Maximalnoe chislo from minimalnix po strokam == %d", maxiChislo);
}

void Klaviatyra() {
	for (i = 0; i<n; i++) {
    printf_s("Enter kolvo stolbtsov v stroke %d: ", i);
    scanf_s("%d", &massForKolvoStolbtsov[i]);
    a[i] = (int*)malloc(massForKolvoStolbtsov[i] * sizeof(int));
    for (j = 0; j< massForKolvoStolbtsov[i]; j++) {
      printf_s("a[%d][%d]= ", i, j);
      scanf_s("%d", &a[i][j]);
    }
  }

}

void randdomm() {
	srand((unsigned int)time(NULL));
	for (i = 0; i < n; i++) {
		printf_s("Enter kolvo stolbtsov v stroke %d: ", i);
		scanf_s("%d", &massForKolvoStolbtsov[i]);
		a[i] = (int*)malloc(massForKolvoStolbtsov[i] * sizeof(int*));
		for (j = 0; j < massForKolvoStolbtsov[i]; j++) {
			a[i][j] = -100 + rand() % 201;
		}
	}
}


void pereraspredeleniePamiti() {
	int* posrednik = a[indexMinimalnogoForTask2];
	a[indexMinimalnogoForTask2] = a[indexMaximalnogoForTask2];
	a[indexMaximalnogoForTask2] = posrednik;

	int tempLenght = massForKolvoStolbtsov[indexMinimalnogoForTask2];
	massForKolvoStolbtsov[indexMinimalnogoForTask2] = massForKolvoStolbtsov[indexMaximalnogoForTask2];
	massForKolvoStolbtsov[indexMaximalnogoForTask2] = tempLenght;
}

void vivodNovogoMass() {
	for (i = 0; i < n; i++) {
		for (j = 0; j < massForKolvoStolbtsov[i]; j++) {
			printf_s("%5d ", a[i][j]);
		}
		printf_s("\n");
	}

}
