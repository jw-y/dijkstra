#include <iostream>

using namespace std;

#include "dijkstra.h"

int main(){
    graph G;
    vertex s, t, x, y, z;
    vertex A, B, C;

    G.addVertex(A);
    G.addVertex(B);
    G.addVertex(C);

    G.addEdge(A, C, 2);
    G.addEdge(A, B, 5);
    G.addEdge(B, C, -10);

    G.dijkstra(A);

    cout << "A: "<<A.dist<<endl;
    cout << "B: " << B.dist << endl;
    cout << "C: " << C.dist << endl;

    /*
    
    G.addVertex(s);
    G.addVertex(t);
    G.addVertex(x);
    G.addVertex(y);
    G.addVertex(z);

    G.addEdge(s, t, 10);
    G.addEdge(s, y, 5);
    G.addEdge(t, x, 1);
    G.addEdge(t, y, 2);
    G.addEdge(y, t, 3);
    G.addEdge(y, x, 9);
    G.addEdge(y, z, 2);
    G.addEdge(z, s, 7);
    G.addEdge(z, x, 6);

    G.dijkstra(&s);

    cout << "s: "<< s.dist<<endl;
    cout << "t: " << t.dist << endl;
    cout << "x: " << x.dist << endl;
    cout << "y: " << y.dist << endl;
    cout << "z: " << z.dist << endl;
    */

    return 0;
}