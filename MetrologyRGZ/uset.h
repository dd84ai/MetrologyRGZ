#pragma once
#pragma once

#include <set>
#include <stdio.h>

template<class T> struct TsetParent
{
public:
	
	std::set<T> Stdset;
	
	/*virtual void clear() = 0;
	virtual void insert(T d) = 0;
	virtual void erase(T d) = 0;
	virtual bool empty() = 0;
	virtual bool contains(T d) = 0;
	virtual int size() = 0;
	virtual T getValue(int j) = 0;*/
};

template<class T> class Tset : public TsetParent<T>
{
public:	

	//������ �����������
	Tset()
	{
	}

	//����������
	void clear()
	{
		Stdset.clear();
	}
	//��������
	void insert(T d)
	{
		Stdset.insert(d);
	}
	//�������
	void erase(T d)
	{
		Stdset.erase(d);
	}
	//�����
	bool empty()
	{
		return Stdset.empty();
	}
	//�����������
	bool contains(T d)
	{
		return Stdset.find(d) != Stdset.end();
	}
	//����������
	Tset<T> Union(Tset<T> q)
	{
		Tset<T> res;
		for (T elem : Stdset)
			res.insert(elem);

		for (T elem : q.Stdset)
			res.insert(elem);
		return res;
	}
	//�������
	Tset<T> substract(Tset<T> q)
	{
		Tset<T> res;
		for (T elem : Stdset)
			res.insert(elem);

		for (T elem : q.Stdset)
			res.erase(elem);
		return res;
	}
	//��������
	Tset<T> mult(Tset<T> q)
	{
		Tset<T> res;

		for (T elem : Stdset)
			if (q.contains(elem))
				res.insert(elem);
		return res;
	}

	//���������
	int size()
	{
		return Stdset.size();
	}

	//�������
	T getValue(int j)
	{
		if (j >= Stdset.size())
			throw std::out_of_range("Tset::getValue out of range error");
		auto iter = Stdset.begin();
		for (int i = 0; i < j; i++)
		{
			iter++;
		}
		return *iter;
	}
};

