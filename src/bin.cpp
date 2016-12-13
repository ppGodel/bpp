/*
* bin.cpp
*
*  Created on: Aug 23, 2016
*      Author: ppGodel
*/

#include "bin.h"
#include "ItemList.cpp"
#include "tools.h"
#include <iostream>
#include "Graph.h"
#include "Graph.cpp"
#include "BidimentionalItem.h"
#include "Vertex.h"
#include "Vertex.cpp"

namespace bpp
{
using namespace Tools;
using namespace std;

	template <class T>
	bin<T>::bin():lenghtX(1),lenghtY(1)
	{
		// TODO Auto-generated constructor stub
	}
	template <class T>
	bin<T>::bin(int lenX):lenghtX(lenX),lenghtY(1)
	{
		// TODO Auto-generated constructor stub
	}
	template <class T>
	bin<T>::bin(int lenX, int lenY):lenghtX(lenX),lenghtY(lenY)
	{
		// TODO Auto-generated constructor stub
	}
	template <class T>
	bin<T>::~bin()
	{
		// TODO Auto-generated destructor stub
	}
	template <class T>
	bool bin<T>::additem(T I)
	{
		itemList.AddItem(I);
		return true;
	}
	template <class T>
	bool bin<T>::additem(T I[])
	{
		itemList.AddItem(I);
		return true;
	}
	template <class T>
	int bin<T>::GetFreeXLenght()
	{
		int usedLenght = 0;
		int n = this->itemList.size();
		for(int i=0; i< n; i++)
		{
			usedLenght += this->itemList[i].sizeX;
		}
		return lenghtX - usedLenght;
	}
	template <class T>
	bool bin<T>::createGraph()
	{
		bool result = false;
		if(graphList.vertices.size()>0)
		{
			return result;
		}
		Vertex<T> *vertexpoint;
		Vertex<T> *auxptr;
		vertexpoint = new Vertex<T>[lenghtX+1];
		Vertex<T> av;
		for(int i = 0; i<=lenghtX; i++ )
		{
			av = Vertex<T>(i);
			auxptr = &av;			
			*(vertexpoint+i) = *auxptr;
			if(i>0)
			{
				(vertexpoint+i-1)->addEdge((vertexpoint+i), 1);
			}
			graphList.insert((vertexpoint+i));
		}
		int ni = itemList.size();
		if(ni>0)
		{
			int in = 0;
			for(int i = 0; i < ni; i++)
			{
				//AGREGAR ARISTA A VERTICE
//				cout << "agregar arista "<< endl;
				Vertex<T> vs ;
//				cout << "original lenght " << lenght<< endl;
//				cout << "inicio de arista: " << in << endl;

//				cout << "fin de arista: " << in + itemList.items[i].size << endl;
				vs = graphList.vertices[in];
				vs.element = itemList[i];
				in+=vs.element.sizeX;
				Vertex<T> vf = graphList.vertices[i];
//				cout << "preadd" << endl;
				vs.addEdge(&vf,itemList[i].sizeX);
//				cout << "done" << endl;

			}
		}
//		cout << "here print"<< endl;
		graphList.printGraph();
//		cout << "end print" << endl;
		//delete[] vertexpoint;
		result = true;
		return result;
	}
/*	bool bin::SolveBPP(){
		bool result = true;
		cout << "TODO: get a optimized bpp";
		//1. ordenar items de la lista de mayor a menor descartar los que sean de mayor tamaño que el bin
		std::sort(itemList.begin(),itemList.end());
		//2. Encontrar las posibles "combinaciones" de elementos deacuerdo al tamaño del bin
		//		y crear los nodos necesrios
		for (std::vector<bpp::Item>::iterator it=itemList.begin(); it!=itemList.end(); ++it)
		{
			int actualsize = lenght;
			if(it->size < actualsize)
			{
				
			}
		}
		//3. crear las aristas para los grafos creados y agregarlos

		//4. regresar el conjunto de bins solucion

		return result;
	}
	*/
} /* namespace bpp */
