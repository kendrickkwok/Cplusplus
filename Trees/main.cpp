//============================================================================
// Name        : main.cpp
// Author      : Kendrick Kwok
// Version     : Eclipse 3.8.1
// Date        : 4/26/2016
// Description : Program that allow user to create a tree and perform simple
//               functions to it
//============================================================================
#include "GeneralTree.h"
#include <sstream>
using namespace std;

void parseRecursive(stringstream& ss, GeneralTree& gt, TreeNode* parent)
{
    char nextChar;
    while (true) {
        ss >> nextChar;
        if (ss.fail())
            return;

        if (nextChar == ')')
            return;

        if (nextChar == '(') {
            TreeNode* newNode = gt.insert(' ', parent);
            parseRecursive(ss, gt, newNode);
        } else {
            gt.insert(nextChar, parent);
        }
    }
}

void parseExpression(const string& expr, GeneralTree& gt)
{
    stringstream ss;
    ss << expr;

    parseRecursive(ss, gt, NULL);
}

int main()
{
    //Test print to see if tree has null if it would crash
    GeneralTree gt;
    cout << "Test 1: ";
    gt.print();

    //Test print to test insert functions of a tree
    //..This should print (c(ab))
    TreeNode* grandparent = gt.insert('.', NULL);
    TreeNode* parent1 = gt.insert('c', grandparent);
    TreeNode* parent2 = gt.insert('.', grandparent);
    TreeNode* kid1 = gt.insert('a', parent2);
    TreeNode* kid2 = gt.insert('b', parent2);
    gt.print();
    TreeNode* gkid3 = gt.insert('d', kid1);
    cout << "Test 2: ";
    gt.print();
    //TreeNode* kid3 = gt.insert('b', parent2);
    //gt.print();

    //Test print to test Assignment operations
    // This should print:
    // (c(ab))
    GeneralTree gt3 = gt;
    //Used to insert into the new tree
    TreeNode *gt3start = new TreeNode();
    gt3start = gt3.getStart();
    gt3.insert('d',gt3start->children[1]);
    cout << "Test 3: ";
    gt3.print();

    // Test print to test copy constructor
    // This should print:
    // (abab(cd)d(ef(g(h))))
    GeneralTree gt2;
    parseExpression("(abab(cd)d(ef(g(h))))", gt2);
    GeneralTree gt4(gt2);
    cout << "Test 4: ";
    gt4.print();

    return 0;
}
