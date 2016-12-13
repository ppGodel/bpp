/*
 * Graph.cpp
 *
 *  Created on: Oct 15, 2016
 *      Author: ppGodel
 */

#include "Graph.h"
#include <typeinfo>

#ifndef GRAPH_CPP_
#define GRAPH_CPP_
namespace bpp {

	template<class T>
	Graph<T>::Graph() {
		// TODO Auto-generated constructor stub

	}

	template<class T>
	Graph<T>::~Graph() {
			// TODO Auto-generated destructor stub
	}

	template<class T>
	void Graph<T>::insert(Vertex<T>* v)
	{
//		cout << "v:" << v->name << typeid(*v).name()<< endl;
		vertices.AddItem(*v);
	}
	template<class T>
	void Graph<T>::printGraph()
	{
		//typename vector< Vertex<T>* >::iterator p1;
//		Vertex<T> *actualVertex = NULL;
		//for(p1 = vertices.begin(); p1 != vertices.end(); ++p1 )
		for(int i = 0; i < (int)vertices.size(); i++)
		{
			vertices[i].printEdges();
//			actualVertex = *p1;
//			actualVertex->printEdges();
		}
		//delete[] actualVertex;
		/*
		for(auto i:vertices){
		i->printEdges();
		};
		*/
		//for (int i = 0; i < vertices.size(); i++)
		//   vertices[i]->printEdges();
	}

//	template<class T>
//	Vertex<T>* Graph<T>::GetVertexByDistance(int dist)
//		{
//			Vertex<T> * result;
//			//typename std::vector<Vertex<T>*>::iterator it;
//			//it = vertices.begin();
//			//int s = vertices.size();
//	//		cout << "size:" << s << " dist:" << dist<< endl;
//			for(int i=0;i< (int)vertices.size(); i++)
//			{
//				if(s>dist)
//				{
//		//			cout << "Origen:" << (*it)->getName() << endl;
//					std::advance(it, dist);
//		//			cout << (*it)->getName() << endl;
//				}
//				else
//				{
//		//			cout << "fin graph" << endl;
//					it = --vertices.end();
//				}
//
//			}
//	//		cout << "Fin:" << (*it)->getName() << endl;
//			result = *it;
//	//		cout << "endf"<< endl;
//			return result;
//		}

} /* namespace bpp */

#endif// GRAPH_CPP_
