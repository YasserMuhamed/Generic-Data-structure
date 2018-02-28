/*
 * glists.c
 *
 *  Created on: Feb 26, 2018
 *      Author: Yasser Mohamed
 */
#include"glists.h"

void initList(GLIST *list)
{
	list->head=NULL;
	list->tail=NULL;
	list->current=NULL;
}

void addHead(GLIST *list,void *data)
{
	NODE *node=(NODE*)malloc(sizeof(NODE));

	if(node==NULL)
	{
		printf("Head memory allocation failed. \n");
		return;
	}

	else
	{
		node->data=data;

		if(list->head==NULL)
		{
			list->tail=node;
			node->next=NULL;
		}

		else
		{
			node->next=list->head;
		}

		list->head=node;
	}
}

void addTail(GLIST *list,void *data)
{
	NODE *node=(NODE*)malloc(sizeof(NODE));

	if(node==NULL)
	{
		printf("Tail memory allocation failed.\n");
		return;
	}

	else
	{
		node->data=data;

		if(list->head==NULL)
		{
			list->head=node;
		}

		else
		{
			list->tail->next=node;
		}
		list->tail=node;
		node->next=NULL;
	}

}

 void * removeHead(GLIST *list)
{
	if(list->head==NULL)
	{
		printf("List is already empty\n.");

		return NULL;
	}

	else
	{
		NODE *node=list->head;
		void *data=node->data;

		if(node->next==NULL)
		{
			printf("Now list is empty\n.");

			initList(list);
		}

		list->head=node->next;


		free(node);
		node=NULL;
		return data;
	}

}

void*removeTail(GLIST *list)
{
	if(list->head==NULL)
	{
		printf("List is already empty\n.");
		return NULL;
	}

	else if (list->head->next==NULL)
		{
		NODE *node=list->tail;
		void *data=node->data;
			printf("Now list is empty\n.");
			free(node);
			node=NULL;
			initList(list);

			return data;
				}

	else
	{
		NODE *node=list->tail;
		list->current=list->head;
		void *data=node->data;

		while(list->current->next->next)
		{
			list->current=list->current->next;
		}
		list->tail=list->current;
		list->tail->next=NULL;
		list->current=NULL;

		free(node);
		node=NULL;
		return data;

		}
}

void displayList(GLIST *list,void (*PRNT)(void *))
{
	if(list->head==NULL)
	{
		printf("List is empty.\n");
	}

	else
	{
		list->current=list->head;
		while(list->current)
		{
			PRNT(list->current->data);
			list->current=list->current->next;
		}
		list->current=NULL;
	}
}

void push(GLIST *list, void *data)
{
	addHead(list,data);
}

void *pop(GLIST *list)
{
	void *data =removeHead(list);
	return data;
}

int isEmpy(GLIST *list)
{
	return list->head==NULL?1:0;
}

void enqueue(GLIST *list,void *data)
{
	addHead(list,data);
}

void* dequeue(GLIST *list)
{
	void *data=removeTail(list);
	return data;
}

void *peek(GLIST *list)
{
	void *data=list->head->data;

	return data;
}

