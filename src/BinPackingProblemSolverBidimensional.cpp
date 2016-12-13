/*
 * BinPackingProblemSolverBidimensional.cpp
 *
 *  Created on: Oct 16, 2016
 *      Author: ppGodel
 */

#include "BinPackingProblemSolverBidimensional.h"

namespace bpp {

bool BinPackingProblemSolverBidimensional::SolveBPP()
{
	bool result = false;
	cout << "items :" << this->itemList.size() <<endl;
	for(int i= 0; i < (int)this->itemList.size(); i++)
	{
		bool inserted = false;
		cout << "item " << i << " Id:" << this->itemList[i].Id << " SizeX: " << this->itemList[i].sizeX << " SizeY: " << this->itemList[i].sizeY << endl ;
		for(int j = 0; j < (int)this->bins.size(); j++)
		{
//			cout <<"bin j " << j <<endl;
			int fl = this->bins[j].GetFreeXLenght();
//			cout << "Espacio libre en el bin " << fl <<endl;
			if(fl>= this->itemList[i].sizeX)
			{
//				cout <<"item i:"<< i <<" cabe en bin j: "<< j <<endl;
				this->bins[j].additem(this->itemList[i]);
				inserted = true;
				break;
			}
			else
			{
//				cout << "item no cabe en bin j " << j << endl;
				continue;
			}
		}
		if(!inserted)
		{
//			cout << "No insertó en bin existente, crear nuevo bind" << endl;

			bin<BidimentionalItem> * n;//= new bin<BidimentionalItem>(SizeX, SizeY);
			n= new bin<BidimentionalItem>(SizeX, SizeY);
//			cout << "se creo bin de tamaño: " << n->lenght << endl;
			BidimentionalItem aux = itemList[i];
			n->additem(aux);
//			cout <<"items en el bin creado " << bins.items.size() +1 << " :" << n->itemList.items.size() << endl;
			bins.AddItem(*n);
//			cout << "Bins totales Actual: "<< bins.items.size()<<endl;
		}
//		cout << "fin ciclo i:" << i << endl;
	}
//	cout << "fin de crear bins" << endl;
	int nb = bins.size();
	cout << "se crearon " << nb << endl;
	for(int i=0;i < nb; i++)
	{
		cout << "bin i: " << i << endl;
		cout << "espacio libre: " << bins[i].GetFreeXLenght() << endl;
		bins[i].createGraph();
	}
	return result;
}
bool BinPackingProblemSolverBidimensional::AddItem(BidimentionalItem I)
{
	return this->itemList.AddItem(I);
}
bool BinPackingProblemSolverBidimensional::AddItem(BidimentionalItem I[])
{
	return this->itemList.AddItem(I);
}
bool BinPackingProblemSolverBidimensional::AddItem(ItemList<BidimentionalItem> I)
{
	return this->itemList.AddItem(I);
}
Graph<BidimentionalItem> * BinPackingProblemSolverBidimensional::GetGraphBPP()
{
	Graph<BidimentionalItem> * result;
	result = new Graph<BidimentionalItem>();
	return result;
}



BinPackingProblemSolverBidimensional::BinPackingProblemSolverBidimensional():SizeX(1),SizeY(1)
{
	// TODO Auto-generated constructor stub

}
BinPackingProblemSolverBidimensional::BinPackingProblemSolverBidimensional(int psizex, int psizey):SizeX(psizex),SizeY(psizey)
{
	// TODO Auto-generated constructor stub

}
BinPackingProblemSolverBidimensional::BinPackingProblemSolverBidimensional(int psizex, int psizey,BidimentionalItem pItem):SizeX(psizex),SizeY(psizey)
{
	// TODO Auto-generated constructor stub
	this->AddItem(pItem);

}
BinPackingProblemSolverBidimensional::BinPackingProblemSolverBidimensional(int psizex, int psizey,BidimentionalItem pItem[]):SizeX(psizex),SizeY(psizey)
{
	// TODO Auto-generated constructor stub
	this->AddItem(pItem);

}
BinPackingProblemSolverBidimensional::BinPackingProblemSolverBidimensional(int psizex, int psizey,ItemList<BidimentionalItem> pItem):SizeX(psizex),SizeY(psizey)
{
	// TODO Auto-generated constructor stub
	this->AddItem(pItem);

}
BinPackingProblemSolverBidimensional::~BinPackingProblemSolverBidimensional() {
	// TODO Auto-generated destructor stub
}

} /* namespace bpp */
