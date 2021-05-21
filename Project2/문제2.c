#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>


typedef struct {
	int hour;
	int min;
	int sec;
} TIME;

TIME elapsedTime(TIME start, TIME end, FILE* f);
int main() {

	FILE* f1;
	FILE* f2;
	if ((f1 = fopen("input.txt", "r")) == NULL || (f2 = fopen("output.txt", "w")) == NULL) {
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	}
	TIME start;
	TIME end;
	fscanf_s(f1, "%d:%d:%d", &start.hour, &start.min, &start.sec);
	fscanf_s(f1, "%d:%d:%d", &end.hour, &end.min, &end.sec);

	printf("input.txt 출력\n");
	fprintf(stdout, "%d:%d:%d\n", start.hour, start.min, start.sec);
	fprintf(stdout, "%d:%d:%d\n", end.hour, end.min, end.sec);
	elapsedTime(start, end, f2);
	fclose(f1);
	fclose(f2);

	return 0;

}

TIME elapsedTime(TIME start, TIME end, FILE* f) {
	TIME result;

	if (start.hour > end.hour)
		end.hour += 24;
	else if (start.hour == end.hour) {
		if (start.min > end.min) {
			end.hour += 24;
		}
	}
	result.hour = end.hour - start.hour;
	result.min = end.min - start.min;
	result.sec = end.sec - start.sec;

	if ((result.min) < 0) {
		(result.hour)--;
		result.min += 60;
	}

	if ((result.sec) < 0) {
		(result.min)--;
		result.sec += 60;
	}

	fprintf(f, "경과시간은 %d:%d:%d 입니다.\n", result.hour, result.min, result.sec);
	printf("경과시간은 %d:%d:%d입니다.", result.hour, result.min, result.sec);

	return result;
}