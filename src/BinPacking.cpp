//============================================================================
// Name        : BinPacking.cpp
// Author      : JAHS
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Graph.h"
#include "bin.h"
#include "BinPackingProblemSolver.h"
#include "ItemList.h"
#include "ItemList.cpp"
#include "Graph.h"
#include "Graph.cpp"
#include "Vertex.h"
#include "Vertex.cpp"
#include "bin.h"
#include "bin.cpp"

using namespace std;
using namespace bpp;
using namespace Tools;

int testGraph1() {

	Graph<int> g;

	Vertex<int> v1 = Vertex<int>(1);
	Vertex<int> v2 = Vertex<int>("Portland");
	Vertex<int> v3 = Vertex<int>("Everett");
	Vertex<int> v4 = Vertex<int>("Lynnwood");
	Vertex<int> v5 = Vertex<int>("Northgate");
	Vertex<int> v6 = Vertex<int>("Bellevue");
	Vertex<int> v7 = Vertex<int>("Arlington");
	Vertex<int> v8 = Vertex<int>("Bellingham");

	Vertex<int> *vp1 = &v1;
	Vertex<int> *vp2 = &v2;
	Vertex<int> *vp3 = &v3;
	Vertex<int> *vp4 = &v4;
	Vertex<int> *vp5 = &v5;
	Vertex<int> *vp6 = &v6;
	Vertex<int> *vp7 = &v7;
	Vertex<int> *vp8 = &v8;

	v1.addEdge(vp2, 100);
	v1.addEdge(vp6, 20);
	v2.addEdge(vp1, 100);
	v3.addEdge(vp1, 30);
	v3.addEdge(vp4, 10);
	v3.addEdge(vp7, 20);
	v4.addEdge(vp5, 15);
	v5.addEdge(vp1, 10);
	v6.addEdge(vp1, 20);
	v8.addEdge(vp7, 45);

	g.insert(vp1);
	g.insert(vp2);
	g.insert(vp3);
	g.insert(vp4);
	g.insert(vp5);
	g.insert(vp6);
	g.insert(vp7);
	g.insert(vp8);

	g.printGraph();
	v1.element = 1000;
	cout << v1.element << endl;
	return 1;
}
//
//int testGraph2()
//{
//	BinPackingProblemSolver bpps;
//	ItemList<BidimentionalItem> il;
//	bpps.itemList = Tools::GetRandomItemList<BidimentionalItem>(10, 0, 10, 1, 3);
//	int n = bpps.itemList.size();
//	return 1;
//}
//
//int testGraph3()
//{
//	BinPackingProblemSolver bpps(10);
//	ItemList<BidimentionalItem> il;
//	//std::srand((time(NULL)));
//	bpps.itemList = Tools::GetRandomItemList<BidimentionalItem>(10, 1, 10, 1, 3);
//	bpps.SolveBPP();
//	//	for(int i = 0; i< bpps.bins.items.size(); i++)
//	//	{
//	//		bpps.bins.items[i].graphList.printGraph();
//	//	}
//	return 1;
//}
//int testGraph4()
//{
//	BinPackingProblemSolver bpps(10, 10);
//	//std::srand((time(NULL)));
//	bpps.itemList = Tools::GetRandomItemList<BidimentionalItem>(15, 1, 10, 1, 10);
//	for (int i = 0; i < bpps.itemList.size(); i++)
//	{
//		cout << "Item " << bpps.itemList[i].Id << " x " << bpps.itemList[i].sizeX << " y " << bpps.itemList[i].sizeY << endl;
//	}
//	bpps.SolveBPPExact();
//	return 1;
//}

int testfileopen()
{
	BinPackingProblemSolver bpps("C:\\CppWorkspace\\BinPacking\\src\\chris1.dat");
	bpps.SolveBPPExact();
	return 1;
}

int main()
{
	cout << "Current start time " << Tools::currentDateTime() << endl;
	cout << "Prueba" << endl;
	testfileopen();
	cout << "Current end time " << Tools::currentDateTime() << endl;
	return 1;
}
