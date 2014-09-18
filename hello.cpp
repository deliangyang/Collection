
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMELEN 20

typedef struct PERSON
{
	int age;
	char name[NAMELEN];
}Person, *pPerson;

int main(int argc, char *argv[])
{
	Person person;
	person.age=20;
	strcpy(person.name, "Hello world");

	FILE * fp;
	fp=fopen("hello.txt", "w+");
	if(fp==NULL)
		exit(1);
	fwrite(&person, sizeof(Person), 1, fp);

	fclose(fp);
	
	Person person2;
	fp=fopen("hello.txt", "r");
	fread(&person, sizeof(Person), 1, fp);
	printf("%d\n", person.age);
	printf("%s\n", person.name);

	fclose(fp);

	return 0;
}

