#pragma once
int mini, i, j, m, n;
int* massiveForMinimalnix;
int* a;
int res;

int min(int a, int b) {
	if (a < b) return a;
}
int max(int a, int b) {
	if (a > b) return a;
}

void poiskMinimalnogoZnachenia() {
	for (i = 0; i < n; i++) {
		mini = INT_MAX;
		for (j = 0; j < m; j++) {
			mini = min(mini, *(a + i * m + j));
		}
		massiveForMinimalnix[i] = mini;
	}
}

void poiskMaximalnogoIzMinimal() {
	res = INT_MIN;
	for (i = 0; i < n; i++) {
		res = max(res, massiveForMinimalnix[i]);
	}

}

void VivodMinimalnixZnacheniyStroki() {
	for (i = 0; i < n; i++) {
		printf_s("minim values in %d row: %d", i, massiveForMinimalnix[i]);
		printf_s("\n");
	}
}

void vvodKlaviatyri() {
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf_s("a[%d][%d] = ", i, j);
			scanf_s("%d", (a + i * m + j));
		}
	}
}
void randdoom() {
	srand((unsigned int)time(NULL));
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			*(a + i * m + j) = -100 + rand() % 201;

		}
	}
}