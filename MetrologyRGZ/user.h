#pragma once
#pragma once

#include <set>

template<class T> struct Tset
{
	//��������� ������
	std::set<T> my_set;

	//������ �����������
	Tset()
	{
	}

	//����������
	void clear()
	{
		my_set.clear();
	}
	//��������
	void insert(T d)
	{
		my_set.insert(d);
	}
	//�������
	void erase(T d)
	{
		my_set.erase(d);
	}
	//�����
	bool empty()
	{
		return my_set.empty();
	}
	//�����������
	bool contains(T d)
	{
		return my_set.find(d) != my_set.end();
	}
	//����������
	Tset<T> Union(Tset<T> q)
	{
		Tset<T> res;
		for (T elem : my_set)
			res.insert(elem);

		for (T elem : q.my_set)
			res.insert(elem);
		return res;
	}
	//�������
	Tset<T> substract(Tset<T> q)
	{
		Tset<T> res;
		for (T elem : my_set)
			res.insert(elem);

		for (T elem : q.my_set)
			res.erase(elem);
		return res;
	}
	//��������
	Tset<T> mult(Tset<T> q)
	{
		Tset<T> res;

		for (T elem : my_set)
			if (q.contains(elem))
				res.insert(elem);
		return res;
	}

	//���������
	int size()
	{
		return my_set.size();
	}

	//�������
	T getValue(int j)
	{
		if (j >= my_set.size())
			throw std::out_of_range("Tset::getValue out of range error");
		auto iter = my_set.begin();
		for (int i = 0; i < j; i++)
		{
			iter++;
		}
		return *iter;
	}
};

//������ UnitTests.cpp
