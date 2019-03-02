#pragma once
#include "Graph.h"

template<typename T>
class MGraph : public Graph<T> {
public:
	MGraph(int nVertexes, bool isDirected) : Graph<T>(nVertexes, isDirected) {		
		matrix_ = new T*[nVertexes];
		for (int i = 0; i < nVertexes; i++) {
			matrix_[i] = new T[nVertexes];
			fill(matrix_[i], matrix_[i] + nVertexes, NO_VALUE);
		}
	}
	~MGraph() {
		clear();
	}

	virtual void insertEdge(Edge<T> edge) {
		Vertex v, w;
		edge.getVertexes(&v, &w);
		T weight = edge.getWeight();
		matrix_[v][w] = weight;
		this->nEdges_++;
		if (!this->isDirected_) {
			matrix_[w][v] = weight;
			this->nEdges_++;
		}
	}
	
	virtual T getEdgeWeight(Vertex v, Vertex w) {
		return matrix_[v][w];
	}

	virtual void increaseEdgeWeight(Vertex v, Vertex w, T weight) {
		matrix_[v][w] += weight;
	}

	virtual AdjNode<T> adj_iter_begin(Vertex v) {
		iter_v = v;
		for (iter_w = 0; iter_w < this->nVertexes_; iter_w++)
			if (matrix_[iter_v][iter_w] != NO_VALUE)
				return AdjNode<T>(iter_w, matrix_[iter_v][iter_w]);
		return AdjNode<T>(NO_VALUE, NO_VALUE);
	}
	
	virtual AdjNode<T> adj_iter_next() {
		for (iter_w++; iter_w < this->nVertexes_; iter_w++)
			if (matrix_[iter_v][iter_w] != NO_VALUE)
				return AdjNode<T>(iter_w, matrix_[iter_v][iter_w]);
		return AdjNode<T>(NO_VALUE, NO_VALUE);
	}

	virtual void clear() {
		for (int i = 0; i < this->nVertexes_; i++)
			free(matrix_[i]);
		free(matrix_);
	}
private:
	T **matrix_;

	Vertex iter_v;
	Vertex iter_w;
};