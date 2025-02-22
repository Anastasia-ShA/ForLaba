#include <stdio.h>
#include <malloc.h>
#include <limits.h>
#include "task1.h"

//здесь я ввожу с клавиатуры значения



int main() {
	extern int* a;
	extern int i, j, m, n;
	extern int res;
	extern int mini;
	extern int* massiveForMinimalnix;

	printf_s("enter kol-vo strok: ");
	scanf_s("%d", &n);
	printf_s("enter kol-vo stolcov: ");
	scanf_s("%d", &m);

	if (n < 0 || m < 0) {
		n = abs(n);
		m = abs(m);
	}

	a = (int*)malloc(n * m * sizeof(int));
	massiveForMinimalnix = (int*)malloc(n * sizeof(int));
	

	int deistvie;
	printf_s("Enter number deistvia   1-s klaviatyr....2-random");
	scanf_s("%d", &deistvie);
	switch (deistvie)
	{
	case 1: vvodKlaviatyri(); break;
	case 2: randdoom(); break;
	default: printf_s("not correct"); break;
	}


	

	
	//здесь я просто вывожу массив который получился после заполнения
	printf_s("WER GETTING MASSIVE WITH NUMBERS:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf_s("%5d", *(a + i * m + j));
		}
		printf_s("\n");
	}


	poiskMinimalnogoZnachenia();
	poiskMaximalnogoIzMinimal();
	VivodMinimalnixZnacheniyStroki();
	printf_s("Rresult maximalniy iz minimalnix -----> %d", res);

	free(a);
	free(massiveForMinimalnix);
	getchar();
	return 0;
}