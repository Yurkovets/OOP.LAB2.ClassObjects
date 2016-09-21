// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include"Set.h"
#include<iostream>
using namespace std;
#define sizeOfArrayOfSets 4

int main()
{
	setlocale(LC_ALL,"rus");
	Set firstSet(5); cout<<"Введите элементы 1 -го множества\n"; firstSet.get();
	Set secondSet(3);cout<<"Введите элементы 2 -го множества\n";  secondSet.get();
	Set firstAdditionalSet = firstSet;Set secondAdditionalSet = firstSet;
	cout<<"Первое ножество: "; firstSet.print();
	cout<<"Второе множество: "; secondSet.print();
	firstSet.intersectionOfSets(secondSet);
	cout<<"\nПересечение первого и второго множества: "; firstSet.print();
	firstAdditionalSet.differenceSets(secondSet);
	cout<<"\nРазность первого и второго множества - "; firstAdditionalSet.print();

	if ( secondAdditionalSet.deleteNumber(12) == 0) 
		{
			cout<<"\nПосле удаления первого элемента: "; secondAdditionalSet.print();
		}
	else
		cout << "Данный элемент не присутствует в множестве!";
	
	Set arrayOfSets[sizeOfArrayOfSets] ={2,2,2,2};
	cout <<"------------------------------------------------\n";
	cout<<"Введите элементы массива  множеств\n"; 
	for(int i =0; i<sizeOfArrayOfSets; i++)
	{
	 arrayOfSets[i].get();
	}

	for(int i = 0; i < sizeOfArrayOfSets; i++){
		cout<<"\n"; arrayOfSets[i].print();}
	
	cout<<"\nМножества, содержащие или чётные или нечётные элементы: ";
	for(int i = 0; i < sizeOfArrayOfSets; i++)
	{
		if ( arrayOfSets[i].checkEvenOrOddElements()  == true )
		{
			
			cout << "\n";
			 arrayOfSets[i].print();
		}
		
	}	
		cout<<"\nМножества, содержащие отрицательные  элементы: ";
	for(int i = 0; i < sizeOfArrayOfSets; i++)
	{
		if ( arrayOfSets[i].checkNegativsElements()  == true )
		{
			
			cout << "\n";
			 arrayOfSets[i].print();
		}
		
	}	

	system("pause");

}
