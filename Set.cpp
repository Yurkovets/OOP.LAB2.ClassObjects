#include "stdafx.h"
#include "Set.h"
#include<iostream>
using namespace std;


Set::Set(int size)// конструктор
{
	this->size=size;
	this->data=new int[size];
}

Set::Set(const Set &x)// Конструктор копирования
{
	this->size=x.size;
	this->data=new int[x.size];
	for(int i=0; i<this->size;i++)
		this->data[i]=x.data[i];
}

Set::~Set()//деконструктор
{
	delete[] data;
}

void Set::get()// ввод элементов множества
{
	int ElementOfSet;
	for(int i=0; i<size; i++)
	{
		cin>>ElementOfSet;
		this->data[i]=ElementOfSet;
	}
}

void Set::print()
{
	for(int i=0; i<size; i++)
		cout<<this->data[i]<<" ";
	cout<<endl;
}

Set& Set::intersectionOfSets (const Set& SomeSet)// пересечение
{
	int count=(this->size+SomeSet.size);// определение размера
	int *storage=new int[count]; int t=0; // выделение памяти
	for(int i=0; i<this->size;i++)
	{
		for(int j=0; j<SomeSet.size;j++)
		{
			if(this->data[i]==SomeSet.data[j])// если совпадают
			{storage[t]=SomeSet.data[j]; t++;}// записать в storage
		}
	}
	for(int i=0; i<t; i++)
	{
		this->data[i]=storage[i];// переписать из storage
	}
	this->size=t; delete[] storage;//удалить storage
	return *this;
}

Set& Set::differenceSets (const Set& SomeSet)// разность
{
	int count=(this->size+SomeSet.size);// 
	for(int i=0; i<=this->size;i++)
	{
		for(int j=0; j<=SomeSet.size;j++)
		{
			if(this->data[i]==SomeSet.data[j])
			{
				  this->deleteNumber(this->data[i]);
			}
							
		}
	}
	return *this;
}
int Set::deleteNumber(int deleteNum)
{
	size_t i = 0;
	for (i = 0; i < this->size && this->data[i] != deleteNum; i++);
	if (i == this->size)
	{
		return -1;
	}
	else
	{
		data[i] = data[this->size-1];
		this->size--;	
		return 0;
	}	
}
bool Set::checkEvenOrOddElements ()
{
	int i;
	for(i = 0; i < this->size; i++){
		if ( (this->data[i] % 2) == 0);
		else break;
	}
	if (i == this->size) return true;

	for(i = 0; i < this->size; i++){
		if ( (this->data[i] % 2) == 1);
		else break;
	}
	if (i == this->size) return true;
	return false;
}

bool Set::checkNegativsElements (){
	int i;
	for(i = 0; i < this->size; i++)
	{
		if (this->data[i] < 0);
		else break;
	}
	if (i == this->size) return true;
	return false;
}
