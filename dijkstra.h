#include <iostream>
#include <vector>
#include <limits>
#include <bits/stdc++.h>

using namespace std;

class vertex{
public:
    int numAdj;
    vertex* prev;
    int dist;
    vector<pair<vertex*, int>> adjList;
    vertex(){
        numAdj = 0;
    }
    void addEdge(vertex *v, int w){
        adjList.push_back(make_pair(v,w));
        numAdj++;
    }
};

class comp{
public:
    int operator() (const vertex* u, const vertex* v){
        return u->dist > v->dist;
    }
};

class graph{
public:
    int numVertex;
    int numEdges;

    vector<vertex*> vertices;

    graph(){
        numVertex = 0;
        numEdges = 0;
    }

    void addVertex(vertex &u){
        vertices.push_back(&u);
    };
    void addEdge(vertex &u, vertex &v, int w){
        u.addEdge(&v, w);
    }; 
    void dijkstra(vertex &s){
        initSS(&s);
        priority_queue<vertex*, vector<vertex*>, comp> Q;
        for(auto u: vertices){
            Q.push(u);
        }
        while(Q.empty()== false){
            vertex* u = Q.top();
            Q.pop();
            for(auto v: u->adjList){
                relax(u, v.first, v.second);
            }
        }
    }
private:
    void initSS(vertex* s){
        for(auto v: vertices){
            v->dist = numeric_limits<int>::max();
            v->prev = nullptr;
        }
        s->dist = 0;
    }

    void relax(vertex *u, vertex *v, int w){
        if(v->dist > u->dist + w && u->dist != numeric_limits<int>::max()){
            v->dist = u->dist + w;
            v->prev = u;
        }
    }
};