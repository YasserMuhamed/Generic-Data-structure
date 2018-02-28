/*
 ============================================================================
 Name        : generic.c
 Author      : YASSER MOHAMED ABDELGABER
 Version     :
 Copyright   : Your copyright notice
 Description : Generic data structures 
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include"glists.h"
#include <string.h>

typedef struct _student
{
	int studentNumber;
	char name[64];
}STUDENT;

void printData(void*);
int compare(void *list,void *data);


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
	enqueue(&list,&YASSER);
	enqueue(&list,&KHALID);
	enqueue(&list,&YASSER);
	enqueue(&list,&KIDO);

	displayList(&list,printData);

	printData(peek(&list));

	search(&list,&AHMED,compare);


	return EXIT_SUCCESS;
}


void printData(void *data)
{
	printf("%i : %s\n",((STUDENT*)data)->studentNumber,((STUDENT*)data)->name);
}

int compare(void *list,void *data)
{
	return !strcmp(((STUDENT*)list)->name,((STUDENT*)data)->name);
}
