#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Field.h"
#include "Fill.h"

 
/* Тип элемента, хранимого в буфере */
typedef CurrentField ElemType;
 
/* Сам буфер */
class CircularBuffer
 { 
    int         size;   // число элементов          
    int         start;  // индекс первого элемента              
    int         end;    // индекс места, где мы пишем следующий  
    ElemType   *elems;  // указатель на массив элементов                 
 public:
	CircularBuffer(int size = 20);
	CircularBuffer(const CircularBuffer &a);
	~CircularBuffer();
	int IsFull();
	int IsEmpty();

	void PushFront(ElemType *elem);
	void PushBack(ElemType *elem);


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

  
 