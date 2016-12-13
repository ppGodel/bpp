/*
 * bin.h
 *
 *  Created on: Aug 23, 2016
 *      Author: ppGodel
 */
#include <vector>
#include <string>
#include "Graph.h"
#include "ItemList.h"
#include "tools.h"
#ifndef BIN_H_
#define BIN_H_

namespace bpp {
using namespace Tools;
template <class T>
class bin {
public:
	int lenghtX;
	int lenghtY;
	//std::vector<bpp::Item> itemList;
	ItemList<T>  itemList;
	bpp::Graph<T> graphList;
	bin();
	bin(int);
	bin(int,int);
	bool additem(T I);
	bool additem(T I[]);
	int GetFreeXLenght();
	virtual ~bin();
	bool createGraph();//(std::vector<bpp::item> &itemlist);
//private:
	//int usedLenght = 0;
	//bool SolveBPP();
};

} /* namespace bpp */

#endif /* BIN_H_ */
