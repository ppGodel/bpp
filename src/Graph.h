/*
 * Graph.h
 *
 *  Created on: Oct 15, 2016
 *      Author: ppGodel
 */
#include <vector>
#include "Vertex.h"
#include "ItemList.h"

#ifndef GRAPH_H_
#define GRAPH_H_

namespace bpp {
using namespace std;
template<class T>
class Graph
{
	public:
		Graph();
		void insert( Vertex<T>* );
		void printGraph();
		Vertex<T>* GetVertexByDistance(int dist);
		~Graph();
//	private:
		Tools::ItemList< Vertex<T> > vertices;
};

} /* namespace bpp */

#endif /* GRAPH_H_ */
