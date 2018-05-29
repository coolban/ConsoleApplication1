#pragma once
/*****************************************************************************
*																		     *
* ------------------------------- cdlist.h --------------------------------   *
*																			 *
*****************************************************************************/
#ifndef CDLIST_H
#define CDLIST_H

#include<stdlib.h>
/*****************************************************************************
*																			 *
* Define a structure for circular doubly list elements.							 *
*																			 *
*****************************************************************************/
typedef struct CDListElmt_ {
	void *data;
	struct CDListElmt_ *prev;
	struct CDListElmt_ *next;
}CDListElmt;

/*****************************************************************************
*																			 *
* Define a structure for circular doubly lists.									 *
*																			 *
*****************************************************************************/
typedef struct CDList_ {
	int size;

	int (*match)(const void *key1, const void *key2);
	void (*destroy)(void *data);

	CDListElmt *head;

} CDList;

/*****************************************************************************
*																			 *
* --------------------------- Public Interface ---------------------------   *
*																			 *
*****************************************************************************/
extern void cdlist_init(CDList *list, void(*destroy)(void *data));
void cdlist_destroy(CDList *list);
int cdlist_ins_prev(CDList *list, CDListElmt *element, const void *data);
int cdlist_ins_next(CDList *list, CDListElmt *element, const void *data);
int cdlist_rem(CDList *list, CDListElmt *element, void **data);
#define cdlist_size(list) ((list)->size)
#define cdlist_head(list) ((list)->head)
//#define cdlist_ishead(element) ((element==(list)->head)?true:false)
#define cdlist_data(element) ((element)->data)
#define cdlist_prev(element) ((element)->prev)
#define cdlist_next(element) ((element)->next)
#endif


