/*
 * ItemList.cpp
 *
 *  Created on: Oct 6, 2016
 *      Author: ppGodel
 */

#include "ItemList.h"
#include "tools.h"
#include <string>
#include <exception>
#include <iostream>
#include <typeinfo>

#ifndef ITEMLIST_CPP_
#define ITEMLIST_CPP_
namespace Tools {
using namespace std;


template<class T>
ItemList<T>::ItemList() {
	// TODO Auto-generated constructor stub
	//sums.push_back(T)
}
template<class T>
ItemList<T>::ItemList(T * I) {
	// TODO Auto-generated constructor stub
	this->AddItem(I);
}
template<class T>
int ItemList<T>::size() const{
	// TODO Auto-generated constructor stub
	return (int)this->items.size();
}

template<class T>
bool ItemList<T>::AddItem(T I) {
	bool result = false;
	try {
		items.push_back(I); //Tools::ArrayAddItem(items,I);
		result = true;
	} catch (std::exception &e) {
		result = false;
	}
	return result;
}
template<class T>
bool ItemList<T>::AddItem(T I[]) {
	bool result = false;
	try {
		for (int i = 0; i < Tools::GetSize(I); i++) {
			this->AddItem(I[i]); //Tools::ArrayAddItem(items,I);
		}
		result = true;
	} catch (std::exception &e) {
		result = false;
	}
	return result;
}
template<class T>
bool ItemList<T>::AddItem(ItemList<T> I) {
	bool result = false;
	try {
		for (int i = 0; i < (int) I.items.size(); i++) {
			this->AddItem(I[i]); //Tools::ArrayAddItem(items,I);
		}
		result = true;
	} catch (std::exception &e) {
		result = false;
	}
	return result;
}


template<class T>
template<class U>
double ItemList<T>::Sum(U T::*member) //, int T::*_operator)
{
	double sum = 0;
	sum = this->Aggregate(member, std::plus<U>());
	return sum;
}
template<class T>
template<class U, class BinaryOperation>
double ItemList<T>::Aggregate(U T::*member, BinaryOperation bi_op) //, int T::*_operator)
		{
	double sum = 0;
	for (int i = 0; i < size(); i++) {
		sum = bi_op(sum, items[i].*member);
		//T.T::*_operator(cout, items[i].*member);
	}
	return sum;
}
template<class T>
template<class U>
double ItemList<T>::Avg(U T::*member) //, int T::*_operator)
		{
	double n = size();
	double sum = 0;
	sum = this->Sum(*member);
	return (double) (sum / (double) (n < 1 ? 1 : n));
}

template<class T>
inline bool operator==(const ItemList<T>& lhs, const ItemList<T>& rhs)
{
	bool result = false;
//	if (rhs.size() != lhs.size())
//	{
//		result = false;
//	}
//	else
//	{
//		for (int z =0; z <lhs.size(); z++)
//		{
//			bool auxr = false;
//			for (int y = 0; y< rhs.size(); y++)
//			{
//				if (!auxr)
//				{
//					if (lhs.getElement(z) == rhs.getElement(y))
//					{
//						auxr = true;
//						break;
//					}
//					else
//					{
//						continue;
//					}
//				}
//				else
//				{
//					break;
//				}
//
//			}
//			if (auxr)
//			{
//				result = true;
//				continue;
//			}
//			else
//			{
//				result = false;
//				break;
//			}
//		}
//	}
	return result;
}
template<class T>
template<class U>
ItemList<int> ItemList<T>::find(U T::*member, U comp) //, int T::*_operator)
{
	int n = size();
	ItemList<int> r;
	for (int i = 0; i < n; i++)
	{
		if (comp == items[i].*member)
		{
			r.AddItem(i);
		}
		//T.T::*_operator(cout, items[i].*member);
	}
	return r;
}
template<class T>
ItemList<int> ItemList<T>::find(T comp) //, int T::*_operator)
{
	int n = size();
	ItemList<int> r;
	for (int i = 0; i < n; i++) {
		if (comp == getElement(i)) {
			r.AddItem(i);
		}
		//T.T::*_operator(cout, items[i].*member);
	}
	return r;
}
template<class T>
template<class U, class BinaryOperation>
ItemList<T> ItemList<T>::getElements(U T::*member, U comp, BinaryOperation bi_op) //, int T::*_operator)
{
	int n = size();
	ItemList<T> r;
	for (int i = 0; i < n; i++) {
		if ( bi_op(items[i].*member, comp)) {
			T aux = items[i];
			r.AddItem(aux);
		}
		//T.T::*_operator(cout, items[i].*member);
	}
	return r;
}
template<class T>
template<class U>
ItemList< bitype<U,U> > ItemList<T>::Summarize(U T::*member)
{
	ItemList<bitype<U,U> > sum;
	int n = items.size();
	for (int i = 0; i < n; i++)
	{
		ItemList<int> f = sum.find(&Tools::bitype<U,U>::value1, items[i].*member);
		if(f.size()<1)
		{
			bitype<U,U> ac(items[i].*member, f.size());
			sum.AddItem(ac);
		}
	}

	return sum;
}
//template<class T>
//ItemList<T>::operator string()
//{
//	string res;
//	for (int i = 0; i < size(); i++)
//	{
//		res += items[i];
//	}
//	return res;
//}


template<class T>
ItemList<T>::~ItemList() {
	// TODO Auto-generated destructor stub
}

template<class T>
static std::vector<T> GetRandomVectorItem(int size, int minLenght,
		int maxLenght) {
	std::vector<T> result;
	//result = new T[size];
	for (int i = 1; i <= size; i++) {
		int r;
		r = GetRandomIntNumberBetween(minLenght, maxLenght);
		std::string nam;
		nam = to_string(i);
		T iaux(nam, r);
		result.push_back(iaux);
	}
	return result;
}
template<class T>
static Tools::ItemList<T> GetRandomItemList(int size, int xminLenght, int xmaxLenght, int yminLenght, int ymaxLenght)
{
	Tools::ItemList<T> result;
	//result = new T[size];
	for (int i = 1; i <= size; i++) {
		int r, s;
		r = GetRandomIntNumberBetween(xminLenght, xmaxLenght);
		s = GetRandomIntNumberBetween(yminLenght, ymaxLenght);
		std::string nam = to_string(i);
		T iaux(nam, r, s);
		result.AddItem(iaux);
	}
	return result;
}
} /* namespace bpp */
#endif// ITEMLIST_CPP
