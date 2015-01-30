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
#include "kruskal.h"
#include "prim.h"
#include "Disjointset.h"
using namespace std;

const int maxn = 100000;
int s,e,n,m;
double w;
Edge E[maxn];
vector<Edge> treeedge;
Graph G;

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
    //use kruskal
    Kruskal K(E,n,m);
    cout<<K.getRes()<<endl;
    treeedge = K.getEdge();
    for (int i = 0; i < treeedge.size(); i++)
        cout<<treeedge[i].s<<' '<<treeedge[i].e<<' '<<treeedge[i].w<<endl;

    //use prim
    Prim p(G,n);
    cout<<p.getRes()<<endl;
    treeedge = p.getEdge();
    for (int i = 0; i < treeedge.size(); i++)
        cout<<treeedge[i].s<<' '<<treeedge[i].e<<' '<<treeedge[i].w<<endl;
}

