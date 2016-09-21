#pragma once
class Set
{
int *data, size;

public:
	Set(int); // конструктор
	Set(const Set &);
	~Set();
	void get();
	void print();
	Set &intersectionOfSets (const Set&);// операция пересечения 
	Set &differenceSets (const Set&); 
	operator int () const; // мощность 
	int deleteNumber(int deleteNum);
	bool checkEvenOrOddElements();// проверка чётных или нечётных элементов
	bool checkNegativsElements ();// проверка отрицательных элементов
};




