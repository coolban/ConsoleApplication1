#include "dynamicarray.h"
#include<stdlib.h>
#include <stdio.h>


/***********************************************************************************************************************
*																													   *
*   ---------------------------------------------init_TwoDimensionArray------------------------------------------------*
*                                                                                                                      *
************************************************************************************************************************/

void init_TwoDimensionArray(TwoDimensionArray * tda, int rowsize, int colsize)
{
	tda->sizeofcolumns = colsize;
	tda->sizeofrows = rowsize;
	//为list rows分配空间
	List* r=(List *)malloc(sizeof(List));
	list_init(r, NULL);
	tda->rows = r;
	for (int i = 0; i < rowsize; i++)
	{
		//初始化行
		Row* r1 = (Row *)malloc(sizeof(Row));
		init_Row(r1, i);
		//将row添加到Rows
		list_ins_next(tda->rows, tda->rows->tail, r1);
	}

}


/***********************************************************************************************************************
*																													   *
*   ---------------------------------------------init_Row--------------------------------------------------------------*
*                                                                                                                      *
************************************************************************************************************************/

void init_Row(Row* r,int rowposition)
{
	r->position = rowposition;
	//为行分配空间
	List* arow = (List *)malloc(sizeof(List));
	//初始化list row
	list_init(arow, NULL);
	r->row = arow;

}

/***********************************************************************************************************************
*																													   *
*   ---------------------------------------------init_ArrayElement-----------------------------------------------------*
*                                                                                                                      *
************************************************************************************************************************/

void init_ArrayElement(ArrayElement* a,int colposition, void * data)
{

	a->data = data;
	a->position = colposition;
}


/***********************************************************************************************************************
*																													   *
*   ---------------------------------------------set_TwoDimensionArray-------------------------------------------------*
*                                                                                                                      *
************************************************************************************************************************/

void set_TwoDimensionArray(TwoDimensionArray * tda,int row, int col, void * data)
{
	//索引不能小于0
	if (row < 0 || col < 0) return;

	if (row >= tda->sizeofrows)
		tda->sizeofrows = row+1;

	if (col >= tda->sizeofcolumns)
		tda->sizeofcolumns = col+1;

	Row * therow;
	therow = set_Row(tda, row);

	ArrayElement * ae;
	ae = set_Column(therow, col);

	ae->data = data;


}


ArrayElement * get_TwoDimensionArray(TwoDimensionArray * tda, int row, int col, void * data)
{
	//索引不能小于0
	if (row < 0 || col < 0 || row >= tda->sizeofrows || col >= tda->sizeofcolumns) return NULL;

	/*
	if (row > tda->sizeofrows)
		tda->sizeofrows = row;

	if (col > tda->sizeofcolumns)
		tda->sizeofcolumns = col;

	*/

	Row * therow;
	therow = set_Row(tda, row);

	ArrayElement * ae;
	ae = set_Column(therow, col);

	return ae;

}

Row * set_Row(TwoDimensionArray * tda, int row)
{
	ListElmt * prerow,* currow;
	
	currow = tda->rows->head;
	prerow = currow;


	while (currow!=NULL && currow->data != NULL) {
		if (((Row *)(currow->data))->position == row) return currow->data;
		
		if (((Row *)(currow->data))->position < row) {
			prerow = currow;
			currow = currow->next;
			continue;
		}

		if (((Row *)(currow->data))->position > row) {
			Row * r = (Row *)malloc(sizeof(Row));
			init_Row(r, row);
			list_ins_next(tda->rows, prerow, r);
			return r;
		}
	}

	if (currow == NULL) {
		Row * r = (Row *)malloc(sizeof(Row));
		init_Row(r, row);
		list_ins_next(tda->rows, tda->rows->tail, r);
		return r;
	}

	return NULL;

}


ArrayElement * set_Column(Row * therow, int col)
{
	ListElmt * precol, *curcol;

	curcol = therow->row->head;
	precol = curcol;


	while (curcol != NULL && curcol->data != NULL) {
		if (((ArrayElement *)(curcol->data))->position == col) return curcol->data;

		if (((ArrayElement *)(curcol->data))->position < col) {
			precol = curcol;
			curcol = curcol->next;
			continue;
		}

		if (((ArrayElement *)(curcol->data))->position > col) {
			ArrayElement * c = (ArrayElement *)malloc(sizeof(ArrayElement));
			init_ArrayElement(c, col,NULL);
			list_ins_next(therow->row, precol, c);
			return c;
		}
	}

	if (curcol == NULL) {
		ArrayElement * c = (ArrayElement *)malloc(sizeof(ArrayElement));
		init_ArrayElement(c, col, NULL);
		list_ins_next(therow->row, therow->row->tail, c);
		return c;
	}

	return NULL;
}


