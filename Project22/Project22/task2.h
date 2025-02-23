#pragma once
int miniChislo;
int maxiChislo;
int i, j, n, m;
int** a;
int* massForMiniChisel;

int min(int a, int b) {
	if (a < b) return a;
}

int max(int a, int b) {
	if (a > b) return a;
}

void poiskMinimalnogoChisla() {
	for (i = 0; i < n; i++) {
		miniChislo = INT_MAX;
		for (j = 0; j < m; j++) {
			miniChislo = min(miniChislo, a[i][j]);
		}
		massForMiniChisel[i] = miniChislo;	
	}
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
	for (i = 0; i < n; i++) {
		a[i] = (int*)malloc(m * sizeof(int*));
		for (j = 0; j < m; j++) {
			printf_s("a[%d][%d] = ", i, j);
			scanf_s("%d", &a[i][j]);
		}
	}
}

void randdomm() {
	srand((unsigned int)time(NULL));
	for (i = 0; i < n; i++) {
		a[i] = (int*)malloc(m * sizeof(int*));
		for (j = 0; j < m; j++) {
			a[i][j] = -100 + rand() % 201;
		}
	}
}