#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "function.h"
typedef struct {
	int grade; 
	char* name;
} Student;

//create a student list size n
Student* Create_(int);
//set value of the student's grade and name
void SetVal_(Student*, int, int, char[]);
//compare the grades of the student, return 1 if id2 has higher priority than id1
int Compare_(Student*, int id1, int id2);
//swap student 
void Swap_(Student*, int, int);
//free the student list 
void Free_(Student*, int);

int main() {
	int n; scanf("%d\n", &n);
	Student* arr = Create_(n);
	for(int i = 0; i < n; i++) {
		int num;
		char c[51];
		scanf("%d %s", &num, c);
		SetVal_(arr, i, num, c);
	}
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(Compare_(arr, i, j) > 0) {
				Swap_(arr, i, j);
			} 
		}
	}
	for(int i = 0; i < n; i++) {
		printf("%d %s\n", arr[i].grade, arr[i].name);
	}
	Free_(arr, n);
}

//create
Student *Create_(int n)
{
	Student *data = (Student*) malloc(n*sizeof(Student));
	for (int i = 0; i < n; i++)
	{
		data[i].name = (char*) malloc(sizeof(char) * 51);
	}
	return data;
}

//set value of the student's grade and name
void SetVal_(Student* arr, int i, int num, char c[])
{
	arr[i].grade = num;
	strcpy(arr[i].name, c);
	
}

//compare the grades of the student, return 1 if id2 has higher priority than id1
int Compare_(Student* arr, int id1, int id2)
{//kalau sama dia lihat nama karena yang utama adalah nilai
	if(arr[id1].grade > arr[id2].grade) return 0;
	else if(arr[id1].grade < arr[id2].grade) return 1;
	if (strcmp(arr[id1].name,arr[id2].name) < 0) return 1;
	return 0;
	
}
//swap student 
void Swap_(Student* arr, int id1, int id2)
{
	Student temp; //Mau switch semuakan
	temp = arr[id1];
	arr[id1] = arr[id2];
	arr[id2] = temp;
}
//free the student list 
void Free_(Student* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		free(arr[i].name);
	}
	free(arr);
}



