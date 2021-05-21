#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

struct person {
	char name[20];
	char phone[20];
	char address[40];
};

void swap(struct person* p1, struct person* p2);
void print(struct person* p1, struct person* p2);

int main() {

	FILE* f1;
	FILE* f2;

	struct person p1, p2;

	if ((f1 = fopen("input.txt", "r")) == NULL || (f2 = fopen("output.txt", "w")) == NULL) {
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	}

	fscanf(f1, "%s %s", p1.name, p1.phone);
	fgets(p1.address, 40, f1);

	fscanf(f1, "%s %s", p2.name, p2.phone);
	fgets(p2.address, 40, f1);

	print(&p1, &p2);
	swap(&p1, &p2);
	printf("\n");
	print(&p1, &p2);


	fprintf(f2, "%s %s %s\n", p1.name, p1.phone, p1.address);
	fprintf(f2, "%s %s %s\n", p2.name, p2.phone, p2.address);

	fclose(f1);
	fclose(f2);

	return 0;
}



void swap(struct person* p1, struct person* p2) {

	struct person p3;

	strcpy(p3.name, p2->name);
	strcpy(p3.address, p2->address);
	strcpy(p3.phone, p2->phone);

	strcpy(p2->name, p1->name);
	strcpy(p2->address, p1->address);
	strcpy(p2->phone, p1->phone);

	strcpy(p1->name, p3.name);
	strcpy(p1->address, p3.address);
	strcpy(p1->phone, p3.phone);

}

void print(struct person* p1, struct person* p2) {

	printf("	이름	전화번호	주소\n");
	printf("사람1 : %s %s %s\n", p1->name, p1->phone, p1->address);
	printf("사람2 : %s %s %s\n", p2->name, p2->phone, p2->address);

}