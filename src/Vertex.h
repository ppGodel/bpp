/*
 * Vertex.h
 *
 *  Created on: Oct 15, 2016
 *      Author: ppGodel
 */
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include "Edge.h"
#include "HyperEdge.h"
#include "tools.h"


#ifndef VERTEX_H_
#define VERTEX_H_

namespace bpp {
using namespace std;
template<class T>
class Vertex
{
public:
	Vertex();
	Vertex(int);
    Vertex(string);
    void addEdge(Vertex<T>* , int);
    void addHyperEdge(vector< Vertex<T> > , int);

    void printEdges();

    string getName() {return name;}
    vector< Edge<T> > getEdges() {return edges;}
    vector< Edge<T> > getHyperEdges() {return hyperedges;}
    T element;

	~Vertex();
//private:
    string name;
    vector< Edge<Vertex<T> > > edges;
    vector< HyperEdge<Vertex<T> > > hyperedges;
};

} /* namespace bpp */

#endif /* VERTEX_H_ */
