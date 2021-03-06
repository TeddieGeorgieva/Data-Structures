// Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

template<typename T>
class Vector
{
private:
	T* arr;
	int size;//elementi
	int capacity;//pamet
	void resize()
	{
		capacity = capacity * 2;
		T* newArr = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;

	}
	void copy(const Vector<T>& other)
	{
		size = other.size;
		capacity = other.capacity;
		//arr = other.arr; wrong обвързва двата елемента и не прави истинско копие;
		//в копи конструктор винаги заделяме на ново памет
		arr = new T[capacity];
		for (size_t i = 0; i < size - 1; i++)
		{
			arr[i] = other.arr[i];
		}
	}
public:
	Vector()
	{
		size = 0;
		capacity = 4;
		arr = new T[capacity];
	}
	Vector(const Vector<T>& other)
	{
		copy(other);
	}
	Vector <T>& operator=(const Vector<T>& other)
	{
		if (this != &other)
		{
			delete[] arr;
			copy(other);
		}
		return *this; //взима обекта
	}
	~Vector()
	{
		delete[] arr; //само динамичната памет трием!!!!!
	}
	 
	void add(T elem)
	{
		if (size == capacity)
		{
			resize();
		}
		arr[size] = elem;
		size++;
	}
 	void print()
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << arr[i] << " ";			
		}
		cout << endl;
	}
	int findIndex(T elem)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] == elem)
			{
				return i;
			}
		
		}
		return -1;
	}
	void remove(T elem)
	{
		int elemIndex = findIndex(elem);
		if (elemIndex >= 0)
		{
			size--;
			for (size_t i = elemIndex; i <= size; i++)
			{
				arr[i] = arr[i + 1];
			}
		}
			
	}
	
};

int main()
{
	Vector<char> arr;
	arr.add('a');
	arr.add('b');
	arr.add('c');
	arr.add('d');
	arr.add('e');
	
	arr.print();
	cout << arr.findIndex('c');
	arr.remove('e');
	cout << endl;
	arr.print();


   return 0; 
}

