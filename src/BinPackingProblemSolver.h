/*
 * BinPackingProblemSolver.h
 *
 *  Created on: Sep 30, 2016
 *      Author: ppGodel
 */
#include "bin.h"
#include "ItemList.h"
#include "BidimentionalItem.h"

#ifndef BINPACKINGPROBLEMSOLVER_H_
#define BINPACKINGPROBLEMSOLVER_H_

namespace bpp {
using namespace Tools;
class BinPackingProblemSolver
{
	public:
		int SizeX;
		int SizeY;
		ItemList< bpp::bin<BidimentionalItem> > bins;
		ItemList<BidimentionalItem> itemList;
		bool SolveBPP();
		bool SolveBPPExact();
		bool SolveBPPByHeuristic();
		bool AddItem(BidimentionalItem I);
		bool AddItem(BidimentionalItem I[]);
		bool AddItem(ItemList<BidimentionalItem> I);
		Graph<BidimentionalItem> * GetGraphBPP();
		template<class T>
		bool  CreateHyperVertex(Graph<ItemList<T> >* parentGraph, int parentIndex, int sizex, int sizey);

		BinPackingProblemSolver();
		BinPackingProblemSolver(string);
		BinPackingProblemSolver(int);
		BinPackingProblemSolver(int, int);
		BinPackingProblemSolver(int, BidimentionalItem );
		BinPackingProblemSolver(int, BidimentionalItem []);
		BinPackingProblemSolver(int, ItemList<BidimentionalItem> );
		BinPackingProblemSolver(int, int, BidimentionalItem []);
		BinPackingProblemSolver(int, int, ItemList<BidimentionalItem> );
		virtual ~BinPackingProblemSolver();
		int GetNumberItems();
};

} /* namespace bpp */

#endif /* BINPACKINGPROBLEMSOLVER_H_ */
