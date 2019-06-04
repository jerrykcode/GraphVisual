# OOGraph

## Graph

![graph_uml](http://wx1.sinaimg.cn/mw690/006XXwaCgy1g2ztcv8hq5j30ns0l7wj4.jpg)

Graph�����ඨ��ͼ�ṹ�Ĳ���������UNWGraph�������ʾ��Ȩͼ������WGraph`<T>`��ʾ��Ȩͼ��TΪ�ߵ�Ȩ�ء�UNWGraph�ֱ����ڽӱ���ڽӾ���ʵ��ΪListUNWGraph���MatrixUNWGraph�࣬WGraph`<T>`�ֱ����ڽӱ���ڽӾ���ʵ��ΪListWGraph`<T>`���MatrixWGraph`<T>`�ࡣ

Graph�������ж��崿�麯��:

```virtual Iterator * getAdjIterator(Vertex v) = 0;```

���ڷ��ض���v���ڽӵ��������ͬʱIterator����Ϊ�����࣬���崿�麯����

```virtual AdjNode * next() = 0;```

AdjNode�����ڽӵ㣬������UNWAdjNode��ʾ��Ȩͼ��һ��������ڽӵ㣻WAdjNode<T>��ʾ��Ȩͼ��һ��������ڽӵ㡣


Iterator���4������ֱ��ӦGraph���4��ʵ�����ࡣ

ʹ��Iteratorģʽ�ɱ���һ��������ڽӵ�:

```cpp
//����ͼGraph * p_graph�ж���v���ڽӵ�
Iterator * it = p_graph->getAdjIterator(v);
for (AdjNode * p_adj_node = it->next(); p_adj_node != NULL; p_adj_node = it->next()) {
	Vertex adj_v = p_adj_node->getAdjVertex(); //�ڽӵ�
}
```

����Graph��������������ʹ�����ϴ�������ڽӵ㣬p_graph����getAdjIterator(v)�����p_graphָ����ڴ����ĸ������ʵ��������Ӧ��Iteartor������࣬it����next()�ֻ����itָ��ľ�������ִ����ʵ�ֵ�next������

������ȨͼWGraph`<T>`*�����Եõ�v���ڽӵ�֮��ߵ�Ȩ�أ�

```cpp
Iterator * it = p_graph->getAdjIterator(v);
for (AdjNode * p_adj_node = it->next(); p_adj_node != NULL; p_adj_node = it->next()) {
	Vertex adj_v = p_adj_node->getAdjVertex(); //�ڽӵ�
	T adj_weight = ((WAdjNode<T> *)p_adj_node)->getAdjWeight(); //�ڽӱ�Ȩ��
}
```
p_graphΪWGraph`<T>`�������ָ�룬�����getAdjIterator(v)���ص�Iteratorָ��ָ����ڴ�һ����ListWIterator`<T>`��MatrixWIterator`<T>`��ʵ������ôit����next()���ص�AdjNodeָ��ָ����ڴ�һ����WAdjNode`<T>`��ʵ�������Խ�p_adj_node cast��WAdjNode`<T>`ָ�뼴�ɵ���getAdjWeight()�����õ���Ȩ��

## Algorithm

���Graphʵ�ֵ�ͼ���㷨

### SSSP (Single source shortest path ��Դ���·��)

* Dijkstra

* A*

### MST (Minimum spanning tree ��С������)

* Prim

### SCC (Strongly connected component ǿ��ͨ����)

* Tarjan

### MF (Maximum flow �����)

* Dinic

### TopSort (Topological sort ��������)

* DAG(�ж��Ƿ��л��� ����������)

* Critical path(����AOEͼ�Ĺؼ�·��)