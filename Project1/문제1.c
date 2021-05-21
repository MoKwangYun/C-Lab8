#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
int main() {

	FILE* f1;
	FILE* f2;


	int n = 0;
	if ((f1 = fopen("input.txt", "r")) == NULL || (f2 = fopen("output.txt", "w")) == NULL) {
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	}

	fscanf_s(f1, "%d", &n);
	int a, b;
	for (int i = 0; i < n; i++) {
		fscanf_s(f1, "%d %d", &a, &b);


		fprintf(stdout, "%d + %d = %d\n", a, b, a + b);
		fprintf(f2, "%d\n", a + b);
	}
	fclose(f1);
	fclose(f2);

	return 0;


}
