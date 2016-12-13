/*
 * BinPackingProblemSolverBidimensional.h
 *
 *  Created on: Oct 16, 2016
 *      Author: ppGodel
 */
#include "bin.h"
#include "bin.cpp"
#include "ItemList.h"
#include "BidimentionalItem.h"

#ifndef BINPACKINGPROBLEMSOLVERBIDIMENSIONAL_H_
#define BINPACKINGPROBLEMSOLVERBIDIMENSIONAL_H_

namespace bpp {
using namespace Tools;
using namespace std;
class BinPackingProblemSolverBidimensional {
public:
	int SizeX;
	int SizeY;
	ItemList< bin<BidimentionalItem> > bins;
	ItemList<BidimentionalItem> itemList;
	bool SolveBPP();
	bool AddItem(BidimentionalItem I);
	bool AddItem(BidimentionalItem I[]);
	bool AddItem(ItemList<BidimentionalItem> I);
	Graph<BidimentionalItem> * GetGraphBPP();

	BinPackingProblemSolverBidimensional();
	BinPackingProblemSolverBidimensional(int ,int );
	BinPackingProblemSolverBidimensional(int ,int , BidimentionalItem );
	BinPackingProblemSolverBidimensional(int ,int , BidimentionalItem []);
	BinPackingProblemSolverBidimensional(int ,int , ItemList<BidimentionalItem> );
	virtual ~BinPackingProblemSolverBidimensional();
};

} /* namespace bpp */

#endif /* BINPACKINGPROBLEMSOLVERBIDIMENSIONAL_H_ */
