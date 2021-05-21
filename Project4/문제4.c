#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

struct person
{
	char name[20];
	char phone[20];
	char address[40];
};

void add(double* result, double x, double y);
void substract(double* result, double x, double y);


int main(void) {
	double x, y, result;

	void(*pf) (double*, double, double);
	FILE* f1 = fopen("input.txt", "r");
	FILE* f2 = fopen("output.txt", "w");

	if ((f1 = fopen("input.txt", "r")) == NULL || (f2 = fopen("output.txt", "w")) == NULL) {
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	}

	fscanf(f1, "%lf %lf", &x, &y);
	printf("input.txt 출력 >> %.2lf %.2lf\n\n", x, y);

	pf = add;
	pf(&result, x, y);
	fprintf(f2, "더하기 수행: %.2lf + %.2lf = %.2lf\n", x, y, result);
	printf("더하기 수행: %.2lf + %.2lf = %.2lf\n", x, y, result);

	pf = substract;
	pf(&result, x, y);
	fprintf(f2, "빼기 수행: %.2lf - %.2lf = %.2lf\n", x, y, result);
	printf("빼기 수행: %.2lf - %.2lf = %.2lf\n", x, y, result);

	fclose(f1);
	fclose(f2);

	return 0;
}

void add(double* result, double x, double y) {

	*(result) = x + y;

}

void substract(double* result, double x, double y) {

	*(result) = x - y;
}