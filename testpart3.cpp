/*
 * CSE373
 * HW4: Disjoint Sets
 */
#include <stdio.h>
#include <fstream>
#include <iostream>
#include "Graph.h"
#include "Edge.h"
#include "EdgeHeap.h"
#include "kruskalForest.h"
#include "primforest.h"
#include "Disjointset.h"
using namespace std;

const int maxn = 100000;
int s,e,n,m;
double w;
Edge E[maxn];
vector<Edge> treeedge;
set<int> source;
Graph G;
int u,sourcenum;
int main()
{
    ifstream input;
    input.open("input.txt");
    input >> n >> m;
    G.init(n);
    for (int i = 0; i < m; i++)
    {
        input >> s >> e >> w;
        E[i].setEdge(s,e,w);
        G.insert(s,e,w);
        G.insert(e,s,w);
    }
    input >> sourcenum;
    source.clear();
    for (int i = 0; i < sourcenum; i++)
    {
        input >> u;
        source.insert(u);
    }
    cout<<"Use Kruskal"<<endl;
    //use kruskal
    KruskalForest K(E,n,m);
    set<Edge> E = K.mst(source);
    for (set<Edge>::iterator it = E.begin(); it != E.end(); it++) cout<<(*it).s<<' '<<(*it).e<<' '<<(*it).w<<endl;

    cout<<"Use Prim"<<endl;
    //use prim
    PrimForest p(G,n);
    E = p.mst(source);
    for (set<Edge>::iterator it = E.begin(); it != E.end(); it++) cout<<(*it).s<<' '<<(*it).e<<' '<<(*it).w<<endl;
}

