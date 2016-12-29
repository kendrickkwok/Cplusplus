//============================================================================
// Name        : GeneralTree.h
// Author      : Kendrick Kwok
// Version     : Eclipse 3.8.1
// Date        : 4/26/2016
// Description : A tree of characters used to store char, and different functions
//             : that allows the user to interact with the tree
//============================================================================

#ifndef GENERALTREE_H_
#define GENERALTREE_H_

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct TreeNode{
    char value;
    //used for unlimited nodes in one TreeNode
    vector<TreeNode*> children;
};

class GeneralTree{

public:
//default constructor
//--initialize tree and set start to NULL
    GeneralTree();

//copy constructor
//----default copies shallow copy and not deep copy, end sharing same heaps
//----need copy constructor for evoking new classes with same values
    GeneralTree(const GeneralTree& other);

//overloaded assignment operator
//----shallow copy evoked. address is being copied over, not individual arrays
//----overloading class has own respective copies of pointers in heap
//----go foward of having own individual things happen to these pointers
    GeneralTree& operator=(const GeneralTree& other);

//destructor
//-----need destructor for class to delete data that referenced to heap
    ~GeneralTree();

//insertion method
//----1. PARENT = NULL, start = !NULL, throw exception
   //-2. PARENT = NULL, start = NULL, fine
    //3. PARENT = VALUE, start = VALUE, fine
    TreeNode* insert(char value, TreeNode* parent);

//print method
//----1. prints the tree with parantheses for non-leaf modes
  //--2. prints the tree with just the character value for leaf nodes
    void print() const;

//retrieve start of tree
//---Used because start is not accessible due to start being private
    TreeNode* getStart();


private:
//private pointer to start of the tree
    TreeNode *start;

//helper methods
    //clears the tree
    void clear();
    //copies from another tree
    void copyOther(const GeneralTree& other);
    //print from the parent node down to the bottom
    void printFrom(TreeNode* start) const;
    //copy from the parent node down to the bottom
    void copyFrom(TreeNode* start, TreeNode* parent);
    // Recursively delete all nodes in the tree.
    void clearFrom(TreeNode* start);

};

#endif /* GENERALTREE_H_ */
