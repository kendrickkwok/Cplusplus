//============================================================================
// Name        : main.cpp
// Author      : Kendrick Kwok (912351666)
// Version     : Eclipse 3.8.1
// Date        : Graph 5/11/16
// Description : Graph of tree nodes. This was used to implement the algorithm
//               for shortest path.
//============================================================================

#include "graph.h"
using namespace std;

//main provided for us
int main()
{
    // Create a graph
    Graph<string> g;
    Node<string>* a = g.insert("a");
    Node<string>* b = g.insert("b");
    Node<string>* c = g.insert("c");
    Node<string>* d = g.insert("d");
    Node<string>* e = g.insert("e");
    Node<string>* f = g.insert("f");
    Node<string>* h = g.insert("h");
    Node<string>* i = g.insert("i");
    Node<string>* j = g.insert("j");
    Node<string>* k = g.insert("k");

    //Node<int>* 26 = g.insert(21);
    g.connect(a, b);
    g.connect(c, d);
    g.connect(b, e);
    g.connect(c, e);
    g.connect(a, c);
    g.connect(a, d);
    g.connect(b, c);
    g.connect(k, e);
    g.connect(h, d);
    g.connect(i, k);

    cout << "Graph 1" << endl;
    g.print();
    cout << "-----" << endl;

    // Find the shortest path from "a" to "e".

    vector<Node<string>*> path = g.shortestPath("k", "a");
    cout << "Graph 1: path from k to a: ";

    for (int i = 0; i < path.size(); i++) {
        cout << path[i]->value << " ";
    }

    cout << endl;
    cout << "----" << endl;

    // Create another graph, which is initially
    // just a copy of the first graph, and connect
    // "a" and "e" directly.
    Graph<string> g2(g);
    g2.connect("a", "e");

    cout << "Graph 1 again" << endl;

    g.print();

    cout << "-----" << endl;

    cout << "Graph 2" << endl;

    g2.print();

    cout << "-----" << endl;

    // Find the shortest path from "a" to "e"
    // in both graphs.
    path = g.shortestPath("a", "k");

    cout << "Graph 1: path from a to k: ";

    for (int    i = 0; i < path.size(); i++) {
        cout << path[i]->value << " ";
    }

    cout << endl;
    cout << "----" << endl;

    path = g2.shortestPath("a", "e");

    cout << "Graph 2: path from a to e: ";

    for (int i = 0; i < path.size(); i++) {
        cout << path[i]->value << " ";
    }

    cout << endl;
    cout << "----" << endl;

    // Create a third graph.
    Graph<string> g3;
    g3.insert("z");         // this should get overwritten
    g3.insert("y");         // and this
    g3.connect("y", "z");   // also this

    // Set the third graph equal to the first
    // graph (making it a copy of the first
    // graph).
    g3 = g;
    g3.connect("a", "e");

    cout << "Graph 1 a third time" << endl;

    g.print();

    cout << "-----" << endl;

    cout << "Graph 3" << endl;
    g3.print();
    cout << "-----" << endl;

    // Find the shortest path from "a" to "e"
    // in the first and third graphs.
    path = g.shortestPath("a", "e");
    cout << "Graph 1: path from a to e: ";

    for (int i = 0; i < path.size(); i++) {
        cout << path[i]->value << " ";
    }

    cout << endl;
    cout << "----" << endl;

    path = g3.shortestPath("a", "e");
    cout << "Graph 3: path from a to e: ";

    for (int i = 0; i < path.size(); i++) {
        cout << path[i]->value << " ";
    }

    cout << endl;
    cout << "----" << endl;

    Graph<int> kendrick;
    Node<int>* m = kendrick.insert(23);
    Node<int>* n = kendrick.insert(42);
    Node<int>* o = kendrick.insert(36);
    Node<int>* p = kendrick.insert(46);
    Node<int>* q = kendrick.insert(51);
    Node<int>* r = kendrick.insert(12);
    Node<int>* s = kendrick.insert(52);
    Node<int>* t = kendrick.insert(24);
    Node<int>* u = kendrick.insert(125);
    Node<int>* v = kendrick.insert(252);

    //Node<int>* 26 = g.insert(21);
    kendrick.connect(m, n);
    kendrick.connect(o, p);
    kendrick.connect(q, r);
    kendrick.connect(s, t);
    kendrick.connect(u, v);
    kendrick.connect(u, s);
    kendrick.connect(s, q) ;
    kendrick.connect(m, v);
    kendrick.connect(p, o);
    kendrick.connect(s, v);
    cout << "Graph kendrick " << endl;
    kendrick.print();
    cout << "-----" << endl;

    vector<Node<int>*> pathpath = kendrick.shortestPath(24, 125);
    cout << "Graph 1: path from 24 to 125: ";

    for (int i = 0; i < pathpath.size(); i++) {
        cout << pathpath[i]->value << " ";
    }

    cout << endl;
    cout << "----" << endl;


    return 0;

}
