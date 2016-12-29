//============================================================================
// Name        : graph.h
// Author      : Kendrick Kwok (912351666)
// Version     : Eclipse 3.8.1
// Date        : Graph 5/11/16
// Description : Graph of tree nodes. This was used to implement the algorithm
//               for shortest path.
//============================================================================

#ifndef _GRAPH_H
#define _GRAPH_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stdexcept>

/*
 * Exception for trying to find
 * a path between two nodes if
 * at least one of the nodes
 * doesn't exist.
 */
class NonExistentNodeException : public std::exception
{
 public:
      virtual const char* what() const throw() {
         return "At least one of those nodes doesn't exist!";
    }
};

/*
 * Exception for trying to find
 * a path between two nodes when
 * no path exists.
 */
class NoPathException : public std::exception
{
public:
        virtual const char* what() const throw() {
           return "No path exists between those two nodes!";
       }
};

/*
 * Node
 * -----
 * Represents a node in a graph. T is
 * the type of value held in the node.
 */
template <typename T>
class Node
{
public:
      Node(const T& value) : value(value) {}

    /*
     * Why is an unordered_set better than
     * a vector for the list of adjacent
     * nodes?
     */
      std::unordered_set<Node<T>*> adjacents;
      T value;

      bool marked = true;
};

/*
 * Graph
 * -----
 * Represents a bi-directional (undirected)
 * graph. Nodes can have values of any type,
 * so long as that type:
 *   - can be used as a key in a map, and;
 *   - can be inserted into cout.
 *
 * The graph does not have to be connected.
 * Values must be unique.
 */
template <typename T>
class Graph
{
public:
    Graph() {}

    /*
     * Since we dynamically allocate each node,
     * we need the big 3!
     *
     * - destructor
     * - copy constructor
     * - assignment operator
     */

    ~Graph() {
        clear();
    }

    Graph(const Graph<T>& other) {
             copyOther(other);
    }

    Graph<T>& operator=(const Graph<T>& other) {

              if (this != &other) {
                   clear();
                   copyOther(other);
              }

        return *this;
    }

    /*
     * Common graph operations.
     */
    Node<T>* insert(const T& value) {
        if (nodes.find(value) != nodes.end()) {
            return NULL;
        }

        Node<T>* newNode = new Node<T>(value);
        nodes[value] = newNode;
        return newNode;
    }

    // Two versions of connect! One that takes
    // node pointers, another that takes node
    // values.
    void connect(Node<T>* first, Node<T>* second) {
        first->adjacents.insert(second);
        second->adjacents.insert(first);
    }

    void connect(const T& first, const T& second) {
        if (nodes.find(first) == nodes.end() ||
            nodes.find(second) == nodes.end()) {
            throw NonExistentNodeException();
        }

        connect(nodes[first], nodes[second]);
    }

    // Unmarks all nodes. Important for the shortest
    // path algorithm!
    void unmarkAll() {
        for (auto iter = nodes.begin();
             iter != nodes.end();
                 iter++) {
            iter->second->marked = true;
        }
    }

    // Prints a list of nodes in the graph, and
    // prints a list of adjacent nodes next to each
    // node.
    void print() {
        for (auto iter = nodes.begin();
             iter != nodes.end();
                 iter++) {
            std::cout << iter->first << ": ";

            for (auto neighborsIter = iter->second->adjacents.begin();
                      neighborsIter != iter->second->adjacents.end();
                                neighborsIter++) {

                std::cout << (*neighborsIter)->value << " ";
            }
            std::cout << std::endl;
        }
    }

    //data structure declarations for Dijkstra's algorithm
        std::queue <std::vector<Node<T>*>> myQueue;
        std::vector<Node<T>*> myVector;
        std::vector<Node<T>*> v;
        std::vector<Node<T>*> tempVector;
        std::vector<Node<T>*> vectorCheck;

    std::vector<Node<T>*> shortestPath(const T& start, const T& end) {

    //From the map to the end, if you cannot find the node in start or end, throw
    //---node excecption that you cannot find the node
        if (nodes.find(start) == nodes.end() ||
            nodes.find(end) == nodes.end()) {
            throw NonExistentNodeException();
        }

        if (nodes.find(start)->second->adjacents.empty() ||
            nodes.find(end)->second->adjacents.empty()) {
             throw NoPathException();
        }

        //iter to find the start node in the map
        auto iter = nodes.find(start);
        //iter to find the end node in the map
        auto iter1 = nodes.find(end);



        //test to see if iter has found the start node and end node in the map
        std::cout << "start node= " << iter->first << " " << std::endl;
        std::cout << "end node= "<< iter1->first << " " << std::endl;

        //takes care of the first partial path
        //----If the start node is equal to the end node, return the vector with this node
            if (start == end){
                myVector.push_back(iter->second);
                return myVector;
                myVector.clear();
            }

            //before parsing through the whole map, unmark all nodes to make sure nodes is able to parsed
            unmarkAll();

            //while the iteration for the start node is marked true....
            while (iter->second->marked) {
            //for the iteration, find what the start node is
                //for all the adjacent nodes in the iteration of stat node..
                for (auto neighborsIter = iter->second->adjacents.begin(); neighborsIter != iter->second->adjacents.end(); neighborsIter++) {
                      //clear the vector if there is any contents
                      myVector.clear();
                      //push back start node pointer into the vector
                      myVector.push_back(iter->second);
                      //push back the adjacent node pointer into the vector
                      myVector.push_back(*neighborsIter);
                      //push back into the queue
                      myQueue.push(myVector);
                 }
                 //mark as false to break out of the while loop
                iter->second->marked = false;
             }

            myVector.clear();

            //declare nextElement node pointer
            Node<T>* nextElement;

            //keep parsing while the queue is NOT empty..
            while(!myQueue.empty()){
            //find the front of the Queue, and make myVector equal to that vector
                myVector = myQueue.front();
                //if myvector is not empty, the next element pointer points to the last element of myVector
                if (!myVector.empty()) {
                    nextElement = myVector.back();
                }

                //if nextElement is equal to the last element of myVector,
                //----then the shortest path is FOUND.
                //--pop all the vectors in the queue
                if (nextElement == iter1->second){
                    while (!myQueue.empty()){
                        myQueue.pop();
                    }
                    return myVector;
                 }

                 //while nextElement is marked true...
                while (nextElement->marked) {
                    //for all the adjacents in nextElement, your going to push the adjacents into myVector
                    for (auto neighborsIter = nextElement->adjacents.begin(); neighborsIter != nextElement->adjacents.end(); neighborsIter++) {
                    //push_back the one of the adjacent element into the vector
                    myVector.push_back(*neighborsIter);
                    //push the newly pushed vector into the queue
                    myQueue.push(myVector);
                    //erase the last element of the vector to get ready for the next loop of the adjacent nodes
                    myVector.erase(myVector.end()-1);
                     }
                 //mark nextElement as false to get out of the loop
                 nextElement->marked = false;
                }
                //while the queue is still not empty, pop everything to exit the loop
                myQueue.pop();
            }
            //return the vector that contains the node
            return std::vector<Node<T>*>();
    }

private:
    std::unordered_map<T, Node<T>*> nodes;  // for uniqueness and lookup

    void copyOther(const Graph<T>& other) {

        // First, insert each node as an island
        // (no edges yet).
        for (auto iter = other.nodes.begin();
             iter != other.nodes.end();
                 iter++) {
            insert(iter->first);
        }

        // Then, connect each pair of nodes that
        // has an edge in the other graph.
        for (auto iter = other.nodes.begin();
             iter != other.nodes.end();
                 iter++) {
            auto adjacents = iter->second->adjacents;
            for (auto neighborsIter = adjacents.begin();
                 neighborsIter != adjacents.end();
                     ++neighborsIter) {
                // Need to connect the values here!
                // Connecting iter->second and *neighborsIter
                // would re-connect the nodes in the old graph
                // (so this would do nothing)
                connect(iter->first, (*neighborsIter)->value);
            }
        }
    }

    void clear() {
        for (auto iter = nodes.begin();
             iter != nodes.end();
                 iter++) {
            delete iter->second;
        }

        nodes.clear();
    }
};

#endif
