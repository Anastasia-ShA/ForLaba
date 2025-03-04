#include <stdio.h>
#include <math.h>

double srednee_geometricheskoeA(double a, double b) {
	return (a + b) / 2;

}

double srednee_geometricheskoeB(double a, double b) {
	return sqrt(a * b);
}

double proverkaTochnosty(double a, double b, double zadannayaTochnost) {
	double a_new = srednee_geometricheskoeA(a, b);
	double b_new = srednee_geometricheskoeB(a, b);

	if (fabs(a_new - b_new) <= zadannayaTochnost) { return a_new; }
	else {
		return  proverkaTochnosty(a_new, b_new, zadannayaTochnost);
	}


}


int main() {
	double zadannayaTochnost = 0.00001;
	double a, b;


	printf_s("enter polozhitelniue chisla a and b: ");
	do {
		scanf_s("%lf %lf", &a, &b);
	} while (a <= 0 || b <= 0);

	double res = proverkaTochnosty(a, b, zadannayaTochnost);


	printf_s("srednee which we get pri a=%lf and b=%lf  === res is %lf", a, b, res);


	return 0;
}