/*
 * HyperEdge.h
 *
 *  Created on: Oct 15, 2016
 *      Author: ppGodel
 */
#include <vector>
#ifndef HYPEREDGE_H_
#define HYPEREDGE_H_

namespace bpp {
using namespace std;
template<class T>
class HyperEdge
{
public:
	HyperEdge();
	~HyperEdge();
	HyperEdge(T * org, vector<T> dest, int dist)
    {
        origin = org;
        destination = dest;
        distance = dist;
    }

    T* getOrigin() {return origin;}
    vector<T> getDestination() {return destination;}
    int getDistance() {return distance;}
private:
    T* origin;
    vector<T> destination;
    int distance;
};

} /* namespace bpp */

#endif /* HYPEREDGE_H_ */
