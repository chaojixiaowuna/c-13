#pragma once
#include<iostream>
#include<string>
using namespace std;
template<class T>
class Myarray
{
public:
	Myarray(int capacity)//�вι��캯��
	{
		this->m_capacity = capacity;
		this->m_size = 0;
		paddress = new T[this->m_capacity];

	}
	Myarray(Myarray& m)//�������캯��
	{
		this->m_capacity = m.m_capacity;
		this->m_size = m.m_size;
		this->paddress = new T[m.m_capacity];
		for (int i = 0; i < this->m_size; i++)
		{
			this->paddress[i] = m.paddress[i];
		}
	}

	
	Myarray& operator=(Myarray& m1)//����=
	{
		if (this->paddress != NULL)
		{
			delete[] this->paddress;
			this->m_capacity = 0;
			this->m_size = 0;
		}
		this->m_capacity = m1.m_capacity;
		this->m_size = m1.m_size;
		this->paddress = new T[m1.m_capacity];
		for (int i = 0; i < m1.m_capacity; i++)
		{
			this->paddress[i] = m1.paddress[i];
		}
		return *this;
	}
	T& operator[](int index)
	{
		return this->paddress[index];
	}
	void PushBack(const T& t)//β�巨
	{
		if (this->m_size == this->m_capacity)
		{
			return;
		}
		this->paddress[this->m_size] = t;
		this->m_size++;
	}
	void PopBack()//βɾ��
	{
		if (this->m_size == 0)
		{
			return;
		}
		this->m_size--;
	}
	int getsize()
	{
		return this->m_size;
		
	}
	int getcapacity()
	{
		return this->m_capacity;
	}
	~Myarray()//��������
	{
		if (this->paddress != NULL)
		{
			delete[] this->paddress;
			this->paddress = NULL;
			this->m_capacity = 0;
			this->m_size = 0;
		}
		cout << "������������" << endl;
	}
private:
	int m_size;
	int m_capacity;
	T* paddress;
};