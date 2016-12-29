//============================================================================
// Name        : GeneralTree.cpp
// Author      : Kendrick Kwok
// Version     : Eclipse 3.8.1
// Date        : 4/26/2016
// Description : Program that allow user to create a tree and perform simple
//               functions to it
//============================================================================

#include "GeneralTree.h"

//Constructor used to set GeneralTree to null when instantiated
GeneralTree::GeneralTree(){

    start = NULL;
}

//Copy constructor
GeneralTree::GeneralTree(const GeneralTree& other){

    //other = tree copying FROM
    //start = tree copying TO
    start = NULL;
    copyOther(other);
}

//Destructor
//Used to destroy contents of a tree before another object is called
GeneralTree::~GeneralTree(){

    clear();
}

//Assignment operator::
//..Used to assign a tree to copy it's contents
GeneralTree& GeneralTree :: operator= (const GeneralTree& other){

    //if this GeneralTree does not equal to otehr tree
    if (this != &other) {
        //clear the tree and copy other
        clear();
        copyOther(other);
    }

    //REPLACE with pointer,  pointing start of the other tree
    return *this;
}

//Insert function
TreeNode *GeneralTree::insert(char value, TreeNode* parent){

    TreeNode* newNode = new TreeNode();
    newNode->value = value;

    //parse through the whole list
           if (start != NULL && parent == NULL ){
            cout << "Parent cannot be null. Tree already has nodes. Error!" << endl;
            delete newNode;
            return 0;
        }

           //if parent is NOTHING, make start equal to newNode
             else if ( parent == NULL){
                 start = newNode;
                 return newNode;
             }

           //If nonne of these match, push the newNode into the vector of a node
                 else {
                     parent->children.push_back(newNode);
                 }

           //else insert(char value, parent->name)
           return newNode;
}

void GeneralTree::print()const{

    if (start == NULL) {
        return;
    }

    //print , TreeNode* parent out current node's value
    printFrom(start);
    cout << endl;
}


void GeneralTree::printFrom(TreeNode* start) const {

    //Only allow printing if start has a value
    if (start != NULL) {
        //Only allow printing if the vector has some kind of value
        if (!start->children.empty()){
        cout << "(";

      for(int i = 0; i < start->children.size(); i++){
          //If statement used to prevent user from leaf nodes
          if(start->children[i]->children.empty()){
              cout << start->children[i]->value;
          }
          //recurse
          printFrom(start->children[i]);
      }

        cout << ")";
            }
        }
    }

//Helper method
void GeneralTree::clear(){

    clearFrom(start);
    start = NULL;
}

void GeneralTree::clearFrom(TreeNode *start){

    if (start == NULL){
        return;
    }

    else{
        for (int i = 0; i < start->children.size() ; i++){
         //recurse the tree
            clearFrom(start->children[i]);
        }
        delete start;
    }
}

void GeneralTree::copyOther(const GeneralTree& other) {

    //take current start from tree and other start from tree to copy
    copyFrom(start, other.start);
}

void GeneralTree::copyFrom(TreeNode* start, TreeNode* other) {

    if (other == NULL) {
       return;
    }

    else {
        //insert value into the top of start to copy..
            //...while start captures the address of the new node
        start = insert(other->value, start);

        for(int i = 0; i < other->children.size(); i++){
            copyFrom(start, other->children[i]);
        }
    }
}

//function that returns start into the main program because start
//is private and cannot be accessed
TreeNode* GeneralTree::getStart() {

    return start;
}
