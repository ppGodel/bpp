/*
 * BidimentionalItem.h
 *
 *  Created on: Oct 15, 2016
 *      Author: ppGodel
 */

#include <string>
#include "tools.h"
#ifndef BIDIMENTIONALITEM_H_
#define BIDIMENTIONALITEM_H_

namespace bpp {
using namespace std;
using namespace Tools;

class BidimentionalItem {
public:
	int sizeX;
	int sizeY;
	string Id;
	BidimentionalItem(string , int , int );
	BidimentionalItem();
	virtual ~BidimentionalItem();
	bool operator<(const BidimentionalItem& r)
	{
		return (this->sizeX*this->sizeY) < (r.sizeX* r.sizeY); // keep the same order
	};
	/*std::basic_ostream<char>& operator<<(std::basic_ostream<char>& os)
	{
	    // write obj to stream
			os << Id << std::endl;
	    return os;
	}*/
};

std::ostream& operator<<(std::ostream& os, const BidimentionalItem& bi);

//int GetRandomItemList(int size, int minLenght, int maxLenght);

} /* namespace bpp */

#endif /* BIDIMENTIONALITEM_H_ */
