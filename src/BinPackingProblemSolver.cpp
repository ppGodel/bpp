/*
 * BinPackingProblemSolver.cpp
 *
 *  Created on: Sep 30, 2016
 *      Author: ppGodel
 */

#include "BinPackingProblemSolver.h"
#include "TemplateTools.h"
#include "ItemList.cpp"
#include "bin.h"
#include "bin.cpp"
#include "BidimentionalItem.h"
#include <math.h>
#include "tools.h"

namespace bpp {
bool BinPackingProblemSolver::SolveBPP() {
	bool result = false;
	result = SolveBPPByHeuristic();
	return result;
}
bool BinPackingProblemSolver::SolveBPPExact() {
	bool result = false;
	cout << "start Solver" << endl;
	// print Items
	int n = itemList.size();
	ItemList<bitype<bitype<int, int>, int > > summ;
	for (int i = 0; i<n;i++)
	{
		cout << "Id:" << itemList[i].Id << " sizeX: " << itemList[i].sizeX << " sizeY: " << itemList[i].sizeY << endl;
		bitype<int, int> biaux(itemList[i].sizeX, itemList[i].sizeY);
		int z =summ.find(&bitype<bitype<int, int>, int >::value1, biaux);
		if (z > 0) 
		{
			summ[z].value2++;
		}
		else
		{
			bitype<bitype<int, int>, int > triaux(biaux, 1);
			summ.AddItem(triaux);
		}
	}
	// print summarize
	cout << "Summarize types" << endl;
	for (int i = 0; i < summ.size(); i++)
	{
		cout << " sizeX: " << summ[i].value1.value1 << " sizeY: " << summ[i].value1.value2 << " count: " << summ[i].value2 << endl;
	}

	//create hypergraph
	Graph<ItemList<BidimentionalItem> > hg;
	string nom = "Root: " + Tools::to_string(this->SizeY) + "x"
			+ Tools::to_string(this->SizeX);
	Vertex<ItemList<BidimentionalItem> > vp(nom);
	vp.element = itemList;
	hg.insert(&vp);
//	cout << hg.vertices[0].name << endl;
	this->CreateHyperVertex(&hg, 0, SizeX, SizeY);

	hg.printGraph();
	//	//parentGraph->vertices
	//	Vertex<ItemList<T> > vp(nom);
	// shortest path BF de los items ya analizados para obtener todas las combinaciones posibles
	// TODO algoritmo dynamico para solucionar bpp
	// http://www.geeksforgeeks.org/dynamic-programming-set-23-bellman-ford-algorithm/
	// resolver sistema lineal para saber que cantidad de cada combinacion
	// Crear los bins con las soluciones
	// regresar el resultado

	return result;
}
template<class T>
bool BinPackingProblemSolver::CreateHyperVertex(
		Graph<ItemList<T> >* parentGraph, int parentIndex, int sizex, int sizey) {
	// "Summarize" items para ver los posibles tamaños de items
	ItemList<bitype<int, int> > sumy = parentGraph->vertices[parentIndex].element.Summarize(&T::sizeY).getElements(&bitype<int,int>::value1, sizey, std::less_equal<int>()) ;
	int yn = sumy.size();
	string nom;
	for (int i = 0; i < yn; i++) {
		vector<Vertex<ItemList<T> > > vv;
		Vertex<ItemList<T> > * pv1, * pv2;
		int res = sizey - sumy[i].value1;
		nom = Tools::to_string(sumy[i].value1) + "x" + Tools::to_string(sizex);
		int e = parentGraph->vertices.find(&Vertex<ItemList<T> >::name, nom);
		if(e>0)
		{
			pv1 = &parentGraph->vertices[e];

		}
		else
		{
			pv1 = new Vertex<ItemList<T> >(nom);
			pv1->element = parentGraph->vertices[parentIndex].element.getElements(&T::sizeY, sumy[i].value1, std::equal_to<int>());
			parentGraph->insert(pv1);
		}
		vv.push_back(*pv1);
		if (res > 0)
		{
			nom = Tools::to_string(res) + "x" + Tools::to_string(this->SizeX);
			bool change = false;
			e = parentGraph->vertices.find(&Vertex<ItemList<T> >::name, nom);
			cout << "here"<< endl;
			if(e>0)
			{
				// revisar que los "elementos" sean diferentes
				ItemList<bitype<int, int> > res_sumy = parentGraph->vertices[e].element.Summarize(&T::sizeY);
				ItemList<bitype<int, int> > act_sumy = parentGraph->vertices[parentIndex].element.getElements(&T::sizeY, sumy[i].value1, std::not_equal_to<int>()).Summarize(&T::sizeY);
				cout << "e " << e << " res_sumy " << res_sumy.size() << " act_sumy " << act_sumy.size() << endl;
				if (res_sumy.size() == act_sumy.size())
				{
					cout << "true"<< endl;
					if (res_sumy == act_sumy)
					{
						pv2 = &parentGraph->vertices[e];
					}
					else
					{
						change = true;
					}
				}
				else
				{
					cout << "fa"<< endl;
					change = true;
				}
				
			}
			else
			{
				change = true;
			}

			if (change==true) 
			{
				cout << "chng"<< endl;
				Vertex<ItemList<T> > v2(nom);
				v2.element = parentGraph->vertices[parentIndex].element.getElements(&T::sizeY, sumy[i].value1, std::less_equal<int>());
				pv2 = &v2;
				parentGraph->insert(pv2);
				int o = parentGraph->vertices.find(pv2);
				this->CreateHyperVertex(parentGraph, o, sizex, res);
				cout << "heref?"<< endl;
			}
			

			vv.push_back(*pv2);
		}
		parentGraph->vertices[parentIndex].addHyperEdge(vv, 1);
	}
	//hg.printGraph();
	return true;
}

bool BinPackingProblemSolver::SolveBPPByHeuristic() {
	bool result = false;
	int sumx = 0, sumy = 0;
	int in = this->itemList.size();
	ItemList<Tools::bitype<int, int> > cn;
	cout << "items :" << in << endl;
	for (int i = 0; i < in; i++) {
		bool inserted = false;
		ItemList<int> f = cn.find(&Tools::bitype<int, int>::value1,
				this->itemList[i].sizeY);
		if (f.size() < 0) {
			bitype<int, int> ac(this->itemList[i].sizeY, f.size());
			cn.AddItem(ac);
		}
		sumx += this->itemList[i].sizeX;
		sumy += this->itemList[i].sizeY;

		cout << "item " << i << " Id:" << this->itemList[i].Id << " SizeX: "
				<< this->itemList[i].sizeX << " SizeY: "
				<< this->itemList[i].sizeY << " Area: "
				<< this->itemList[i].sizeX * this->itemList[i].sizeY << endl;
		if (i + 1 == in) {
//			double suma  = itemList.Aggregate(&BidimentionalItem::sizeX, std::plus<double>());
//			cout << "SumaX: " << suma << endl;
//			double sumy  = itemList.Sum(&BidimentionalItem::sizeY);
			double SumArea = sumx * sumy;
			double binArea = SizeX * SizeY;
			int minbins = round(((SumArea / binArea) / in) + .49);
			int maxbin = (int) itemList.size();
			cout << "SumX: " << sumx << " SumY: " << sumy << " Area: "
					<< sumx * sumy << endl;
			cout << "Bins min: " << minbins << " Bins Max: " << maxbin << endl;
			cout << "Y values:" << endl;
			for (int d = 0; d < cn.size(); d++) {
				cout << "Y: " << cn[d].value1 << " count: " << cn[d].value2
						<< endl;
			}
		}
		for (int j = 0; j < (int) this->bins.size(); j++) {
//			cout <<"bin j " << j <<endl;
			int ul = this->bins[j].itemList.Sum(&BidimentionalItem::sizeX);
			int tl = this->bins[j].lenghtX;
			int fl = tl - ul;
//			cout << "Espacio libre en el bin " << fl <<endl;
			if (fl >= this->itemList[i].sizeX) {
//				cout <<"item i:"<< i <<" cabe en bin j: "<< j <<endl;
				this->bins[j].additem(this->itemList[i]);
				inserted = true;
				break;
			} else {
//				cout << "item no cabe en bin j " << j << endl;
				continue;
			}
		}
		if (!inserted) {
//			cout << "No insertó en bin existente, crear nuevo bind" << endl;

			bin<BidimentionalItem> * n = new bin<BidimentionalItem>(SizeX);
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
	cout << "se crearon " << bins.size() << endl;
	for (int i = 0; i < (int) bins.size(); i++) {
		cout << "bin i: " << i << endl;
		cout << "espacio libre: " << bins[i].GetFreeXLenght() << endl;
		bins[i].createGraph();
	}
	return result;
}
bool BinPackingProblemSolver::AddItem(BidimentionalItem I) {
	return this->itemList.AddItem(I);
}
bool BinPackingProblemSolver::AddItem(BidimentionalItem I[]) {
	return this->itemList.AddItem(I);
}
bool BinPackingProblemSolver::AddItem(ItemList<BidimentionalItem> I) {
	return this->itemList.AddItem(I);
}

Graph<BidimentionalItem> * BinPackingProblemSolver::GetGraphBPP() {
	Graph<BidimentionalItem> * result;
	result = new Graph<BidimentionalItem>();
	return result;
}
BinPackingProblemSolver::BinPackingProblemSolver() :
		SizeX(1), SizeY(1) {
	// TODO Auto-generated constructor stub

}
BinPackingProblemSolver::BinPackingProblemSolver(string filename)
{
	// TODO Auto-generated constructor stub
	cout << filename << endl;
	vector<vector<string> > file = Tools::file_toString(filename);
	int l = 0, w = 0;
	if (file.size() > 0 && file[0].size()> 1)
	{
		l = std::atoi(file[0][1].c_str());
		w = std::atoi(file[0][2].c_str());
	}
	SizeX = l;
	SizeY = w;
	//ItemList<BidimentionalItem> il;
	for (int i = 1; i < (int)file.size() && file[i].size()>3; i++)
	{
		string ii = file[i][0];
		int li = strtol(file[i][1].c_str(),NULL,0);
		int wi = strtol(file[i][2].c_str(),NULL,0);
		int ti = strtol(file[i][3].c_str(),NULL,0);
		//int li = atoi(file[i][1].c_str());
		//int wi = atoi(file[i][2].c_str());
		//int ti = atoi(file[i][3].c_str());
		for (int j = 0; j < ti; j++)
		{
			string auxi = ii + Tools::to_string(j);
			BidimentionalItem bi(auxi, li, wi);
			itemList.AddItem(bi);
		}
	}
	//itemList = il;
}
BinPackingProblemSolver::BinPackingProblemSolver(int psizex) :
		SizeX(psizex), SizeY(1) {
	// TODO Auto-generated constructor stub

}
BinPackingProblemSolver::BinPackingProblemSolver(int psizex, int psizey) :
		SizeX(psizex), SizeY(psizey) {
	// TODO Auto-generated constructor stub

}
BinPackingProblemSolver::BinPackingProblemSolver(int psize,
		BidimentionalItem pItem) :
		SizeX(psize), SizeY(1) {
	this->AddItem(pItem);
}
BinPackingProblemSolver::BinPackingProblemSolver(int psize,
		BidimentionalItem pItem[]) :
		SizeX(psize), SizeY(1) {
	this->AddItem(pItem);
}
BinPackingProblemSolver::BinPackingProblemSolver(int psize,
		ItemList<BidimentionalItem> pItem) :
		SizeX(psize), SizeY(1) {
	this->AddItem(pItem);
}

BinPackingProblemSolver::~BinPackingProblemSolver() {
	// TODO Auto-generated destructor stub
}

} /* namespace bpp */
