/*
 * BidimentionalItem.cpp
 *
 *  Created on: Oct 15, 2016
 *      Author: ppGodel
 */

#include "BidimentionalItem.h"

#ifndef BIDIMENTIONALITEM_CPP_
#define BIDIMENTIONALITEM_CPP_
namespace bpp {

BidimentionalItem::BidimentionalItem():sizeX(1),sizeY(1)  {
	// TODO Auto-generated constructor stub
}

BidimentionalItem::BidimentionalItem(string pid, int psizex, int psizey):Id(pid), sizeX(psizex), sizeY(psizey)
{

}
BidimentionalItem::~BidimentionalItem() {
	// TODO Auto-generated destructor stub
}


std::ostream& operator<<(std::ostream& os, const BidimentionalItem& bi)
{
	os << "Id:" << bi.Id << " X:" << bi.sizeX << " Y" << bi.sizeY;
    return os;
}
} /* namespace bpp */
#endif /* BIDIMENTIONALITEM_CPP_ */
