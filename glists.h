/*
 * glists.h
 *
 *  Created on: Feb 26, 2018
 *      Author: Yasser Mohamed
 */

#ifndef GLISTS_H_
#define GLISTS_H_

#define NULL ((void *)0)

typedef struct _node
{
	void *data;
	struct _node *next;
}NODE;

typedef struct _list
{
	NODE *head;
	NODE *tail;
	NODE *current;
}GLIST;

void initList(GLIST *list);
void addHead(GLIST *list,void *data);
void addTail(GLIST *list,void *data);
void * removeHead(GLIST *list);
void *removeTail(GLIST *list);
void displayList(GLIST *list,void (*PRNT)(void*));
void push(GLIST *list,void *data);
void *pop(GLIST *list);
void enqueue(GLIST *list,void *data);
void *dequeue(GLIST *list);
int isEmpty(GLIST *list);
void *peekStack(GLIST *list);
int search(GLIST *list,void *data,int (*COMPARE)(void*,void*));


#endif /* GLISTS_H_ */
