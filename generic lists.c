/*
 ============================================================================
 Name        : generic.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include"glists.h"

typedef struct _student
{
	int studentNumber;
	char name[64];
}STUDENT;

void printData(void*);


int main(void) {



STUDENT YASSER;
STUDENT AHMED;
STUDENT KHALID;
STUDENT MARI;
STUDENT MAYA;
STUDENT ALY;
STUDENT KIDO;
YASSER.studentNumber=1;
strcpy(YASSER.name,"YASSER");
AHMED.studentNumber=2;
strcpy(AHMED.name,"AHMED");
KHALID.studentNumber=3;
strcpy(KHALID.name,"KHALID");
MARI.studentNumber=4;
strcpy(MARI.name,"MARI");
MAYA.studentNumber=5;
strcpy(MAYA.name,"MAYA");
ALY.studentNumber=6;
strcpy(ALY.name,"ALY");
KIDO.studentNumber=7;
strcpy(KIDO.name,"KIDO");

GLIST list;
initList(&list);

STUDENT *ARR[]={&YASSER,&AHMED,&KHALID,&MARI,&MAYA,&ALY,&KIDO};


	enqueue(&list,&YASSER);

	enqueue(&list,&ALY);

	displayList(&list,printData);

	printData(peek(&list));

	dequeue(&list);

	printf("\n\n\n\n\n");
	displayList(&list,printData);

	printData(peek(&list));


	return EXIT_SUCCESS;
}


void printData(void *data)
{
	printf("%i : %s\n",((STUDENT*)data)->studentNumber,((STUDENT*)data)->name);
}
