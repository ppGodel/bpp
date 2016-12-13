/*
 * Edge.h
 *
 *  Created on: Oct 15, 2016
 *      Author: ppGodel
 */

#ifndef EDGE_H_
#define EDGE_H_

namespace bpp {

template<class T>
class Edge
{
public:
	Edge();
	~Edge();
    Edge(T * org, T * dest, int dist)
    {
        origin = org;
        destination = dest;
        distance = dist;
    }

    T* getOrigin() {return origin;}
    T* getDestination() {return destination;}
    int getDistance() {return distance;}
private:
    T* origin;
    T* destination;
    int distance;
};

} /* namespace bpp */

#endif /* EDGE_H_ */
