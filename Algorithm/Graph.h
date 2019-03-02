#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define NO_VALUE -1

typedef int Vertex;

template<typename T>
class Edge {
public:
	Edge() {}
	Edge(Vertex v, Vertex w, T weight) : v(v), w(w), weight(weight) {}
	~Edge() {}
	void getVertexes(Vertex *pV, Vertex *pW) {
		*pV = v;
		*pW = w;
	}
	T getWeight() { return weight; }
private:
	Vertex v, w;
	T weight;
};

template<typename T>
class AdjNode {
public:
	AdjNode(Vertex adjVertex, T adjWeight) : adjVertex(adjVertex), adjWeight(adjWeight)	 {}
	~AdjNode() {}

	Vertex getAdjVertex() { return adjVertex; }
	T getAdjWeight() { return adjWeight; }
	void increaseAdjWeight(T weight) { adjWeight += weight; }
private:
	Vertex adjVertex;
	T adjWeight;
};

template<typename T>
class Graph {
public:
	Graph() {}
	Graph(int nVertexes, bool isDirected) : nVertexes_(nVertexes), nEdges_(0), isDirected_(isDirected) {}
	~Graph() {}

	int getVertexesNum() { return nVertexes_; }
	int getEdgesNum() { return nEdges_; }
	bool isGraphDirected() { return isDirected_; }

	virtual void insertEdge(Edge<T> edge) = 0;
	virtual T getEdgeWeight(Vertex v, Vertex w) = 0;
	virtual void increaseEdgeWeight(Vertex v, Vertex w, T weight) = 0;
	virtual AdjNode<T> adj_iter_begin(Vertex v) = 0;
	virtual AdjNode<T> adj_iter_next() = 0;
	virtual void clear() = 0;
protected:
	int nVertexes_;
	int nEdges_;
	bool isDirected_;
};


