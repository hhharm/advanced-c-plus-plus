#pragma once

#include "stdafx.h"
#include "classes.h"
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 20



/* Тип элемента, хранимого в буфере */
typedef coord ElemType;
 
/* Сам буфер */
class CircularBuffer
 { 
    int         size;   // число элементов          
    int         start;  // индекс первого элемента              
    int         end;    // индекс места, где мы пишем следующий  
    ElemType   *elems;  // указатель на массив элементов                 
 public:
	CircularBuffer(int size = BUF_SIZE);
	CircularBuffer(const CircularBuffer &a);
	~CircularBuffer();

	int IsFull();
	int IsEmpty();

	void PushFront(ElemType *elem);	//в конец
	void PushBack(ElemType *elem); //в начало


	void operator =(CircularBuffer b);

	/* Вытаскивает последний. Нужно всегда проверять !cbIsEmpty(). */
	ElemType PopFront();
	/* Вытаскивает первый. Нужно всегда проверять !cbIsEmpty(). */
	ElemType PopBack();

	ElemType& Read(int i);
	//читает нужный нам элемент стека (чтобы всё это можно было отобразить)
	

	int Size();
	int Start();
	int End();
};

  
 