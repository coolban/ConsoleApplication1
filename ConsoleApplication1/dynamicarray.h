#pragma once
#ifndef  DynamicArray
#define DynamicArray

#include<stdio.h>
#include "list.h"

typedef struct ArrayElement_
{
	void* data;
	int position;
} ArrayElement;

typedef struct Row_ {
	List * row;
	int position;
}Row;

typedef struct TwoDimensionArray_ {
	int sizeofrows;
	int sizeofcolumns;
	List * rows;

}TwoDimensionArray;


/*****************************************************************************
*																			 *
* --------------------------- Public Interface ---------------------------   *
*																			 *
*****************************************************************************/

void init_TwoDimensionArray(TwoDimensionArray * tda,int rowsize,int colsize);
void init_ArrayElement(ArrayElement* a,int colposition,void * data);
void init_Row(Row* r,int rowposition);
void set_TwoDimensionArray(TwoDimensionArray * tda,int row, int col, void * array_element);
ArrayElement * get_TwoDimensionArray(TwoDimensionArray * tda, int rowsize, int colsize);
ArrayElement * set_Column(Row * r, int col);
Row * set_Row(TwoDimensionArray * tda, int row);


#endif // DynamicArray




