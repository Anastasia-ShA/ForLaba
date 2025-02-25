#include <stdio.h>
#include <malloc.h>
#include <limits.h>
#include "task2.h"

int main() {
	extern int** a;
	extern int i, j, n;
	extern int* massForKolvoStolbtsov;
	int deistvie;
	extern int* massForMiniChisel;
	

	
	printf_s("Enter kolvo stok: ");
	scanf_s("%d", &n);
	//printf_s("Enter kolvo stolbtsov: ");
	//scanf_s("%d", &m);

	if (n <= 0) {
		return 1;
	}

	printf_s("Enter number deistvia:  1- s klaviatyri   2-random: \n");
	scanf_s("%d", &deistvie);

	a = (int**)malloc(n * sizeof(int*));
	massForMiniChisel = (int*)malloc(n * sizeof(int*));
	massForKolvoStolbtsov = (int*)malloc(n * sizeof(int));
	

	switch (deistvie)
	{
	case 1: Klaviatyra(); break;
	case 2: randdomm(); break;
	default: printf_s("Not correct"); break;
	}


	

	printf_s("We get filled massive: \n");
	for (i = 0; i < n; i++)  {
		for (j = 0; j < massForKolvoStolbtsov[i]; j++)  {
			printf_s("%5d ", a[i][j]); 
		}
		printf_s("\n");
	}

	poiskMinimalnogoChisla();
	vivodMinimalnixChisel();
	poiskMaximalnogoIzMinimalnix();
	poiskMaximalnogoChislaIndexa();
	
	massForSoxraneniaChiselMiniStr = (int*)malloc(massForKolvoStolbtsov[indexMinimalnogoForTask2] * sizeof(int*));
	massForSoxraneniaChiselMaxiStr = (int*)malloc(massForKolvoStolbtsov[indexMaximalnogoForTask2] * sizeof(int*));


	soxranenieMinimalStr();
	soxranenieMaximalStr();
	//pereraspredeleniePamiti();
	int tretiyLishniy = massForKolvoStolbtsov[indexMinimalnogoForTask2];
	pereraspredeleniePamityWithRealloc1(&a, massForKolvoStolbtsov, indexMinimalnogoForTask2, massForKolvoStolbtsov[indexMaximalnogoForTask2]);
	pereraspredeleniePamityWithRealloc2(&a, massForKolvoStolbtsov, indexMaximalnogoForTask2, tretiyLishniy);
	//perezapis();



	vivodNovogoMass();

	for (i = 0; i < n; i++) {
		free(*a[i]);}
	free(a);
	free(massForMiniChisel);
	free(massForKolvoStolbtsov);
	free(massForSoxraneniaChiselMiniStr);
	free(massForSoxraneniaChiselMaxiStr);

	getchar();
	return 0;
}