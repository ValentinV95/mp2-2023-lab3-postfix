// ���������� � ���������� ���������� �����
// ���� ������������ ��������: 
// - ������� ��������, 
// - ���������� ��������, 
// - �������� �������� �������� (��� ��������)
// - �������� �� �������, 
// - ��������� ���������� ��������� � �����
// - ������� �����
// ��� ������� � ������ ���� ������ �������������� ������

#pragma once
#include<iostream>

using namespace std;

template <class T>
class TStack
{
private:
	T* pMem;
	int ind = -1;
	size_t size;
public:
	TStack()
	{
		size = 5;
		pMem = new T[size];
	}

	void push(T elem) //�������� ������� � ����
	{
		if (++ind == size)
		{
			T* tmp = new T[size * 2];
			for (size_t i = 0; i < size; i++)
				tmp[i] = pMem[i];
			delete[] pMem;
			pMem = tmp;
			size *= 2;
		}
		pMem[ind] = elem;
	}

	T pop() //������� ������� �� �����
	{
		if (isEmpty())
			throw invalid_argument("Sorry, stack is empty");
		return pMem[ind--];
	}

	T top() //������� �������� �������� � ����� (peek)
	{
		if (isEmpty())
			throw invalid_argument("Sorry, stack is empty");
		return pMem[ind];
	}

	bool isEmpty() //�������� �� ������� �����
	{
		return ind == -1;
	}

	size_t GetSize()
	{
		return ind + 1;
	}

	void clear() //�������� �������
	{
		ind = -1;
	}

	~TStack()
	{
		delete[] pMem;
	}
};