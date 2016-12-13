/*
 * ItemList.h
 *
 *  Created on: Oct 6, 2016
 *      Author: ppGodel
 */

#include "TemplateTools.h"
#include "tools.h"
#include <vector>
#include <functional>
#ifndef ITEMLIST_H_
#define ITEMLIST_H_

namespace Tools {
template<class T>
class ItemList {
public:
	//constructors
	ItemList();
	ItemList(T*);
	virtual ~ItemList();
	//functions
	bool AddItem(T I);
	bool AddItem(T I[]);
	bool AddItem(ItemList<T> I);
	int size() const;
	template<class U>
	double Sum(U T::*member);
	template<class U>
	double Avg(U T::*member);
	template<class U, class BinaryOperation>
	double Aggregate(U T::*member, BinaryOperation bi_op);
	ItemList<int> find(T comp);
	template<class U>
	ItemList<int> find(U T::*member, U comp);
	template<class U>
	ItemList< bitype<U,U> > Summarize(U T::*member);
	template<class U, class BinaryOperation>
	ItemList<T> getElements(U T::*member, U comp, BinaryOperation bi_op);

	T getElement(int index)const
	{
		return items[index];
	};
	
	/*bool operator==(ItemList<T>& a);*/


	// TODO print Items
	T& operator[](int __n) {
		return items[__n];
	}
	//operator string();
private:
	//members
	std::vector<T> items;
};

	template<class T>
	std::ostream& operator<<(std::ostream& os, const ItemList<T>& il)
	{
	    // write obj to stream
		int n = il.size();
		for(int t = 0; t< n;t++)
		{
			os << il.getElement(t) << std::endl;
		}
	    return os;
	}

	template<class T>
	inline bool operator==(const ItemList<T>& lhs, const ItemList<T>& rhs);
	template<class T>
	static Tools::ItemList<T> GetRandomItemList(int size, int xminLenght, int xmaxLenght, int yminLenght, int ymaxLenght);
} /* namespace bpp */
#endif /* ITEMLIST_H_ */
