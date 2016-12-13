/*
 * Vertex.cpp
 *
 *  Created on: Oct 15, 2016
 *      Author: ppGodel
 */

#include "Vertex.h"
#include "Edge.h"
#include "Edge.cpp"
#include "HyperEdge.h"
#include "HyperEdge.cpp"
#include "tools.h"
#include "tools.cpp"

#ifndef VERTEX_CPP_
#define VERTEX_CPP_
namespace bpp
{
using namespace std;

	template<class T>
	Vertex<T>::Vertex() {
		// TODO Auto-generated constructor stub

	}
	template<class T>
	Vertex<T>::Vertex(string id):name(id)
	{
		//cout << "Created:"  << id << endl;
	}

	template<class T>
	Vertex<T>::Vertex(int id):name("Vertex " + Tools::to_string(id))
	{

	}
	template<class T>
	void Vertex<T>::printEdges()
	{
		cout << " " << name << ":" << endl;
		cout << "ObjValue: " << Tools::to_string(element) << endl;
		if (hyperedges.size() == 0 && edges.size() == 0)
		{
			cout << "No Edges" << endl;
		}
		else
		{
			for (int i = 0; i < (int)edges.size(); i++)
			{
				Edge< Vertex<T> > e = edges[i];
				cout << " " << e.getDestination()->getName() <<
					" - " << e.getDistance() << endl;
			}
			for (int i = 0; i < (int)hyperedges.size(); i++)
			{
				cout << "HyperEdge " << i << ":" << endl;
				HyperEdge< Vertex<T> > e = hyperedges[i];
				vector<Vertex<T> > vv = e.getDestination();
				if (vv.size() == 0)
				{
					cout << "No HyperEdges" << endl;
				}
				else
				{
					for (int j = 0; j < (int)vv.size(); j++)
					{
						cout << " " << vv[j].getName() << " - " << e.getDistance() << endl;
					}
				}
			}
			cout << endl;
		}
	}
	template<class T>
	void Vertex<T>::addEdge(Vertex<T> *v, int dist)
    {
        Edge< Vertex<T> > newEdge(this, v, dist);
        edges.push_back(newEdge);
    }
	template<class T>
	void Vertex<T>::addHyperEdge(vector< Vertex<T> > v, int dist)
    {
        HyperEdge< Vertex<T> > newEdge(this, v, dist);
        hyperedges.push_back(newEdge);
    }
	template<class T>
	Vertex<T>::~Vertex() {
		// TODO Auto-generated destructor stub
	}

} /* namespace bpp */
#endif// VERTEX_CPP_

