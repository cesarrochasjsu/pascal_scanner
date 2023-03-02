#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector> 
#include <string> 
#include "Token.h"
using namespace std; 

enum class NodeType 
{
    PROGRAM, COMPOUND, ASSIGN, LOOP, TEST, WRITE, WRITELN, ADD, SUBTRACT, 
    MULTIPLY, DIVIDE, EQ, NE, LT, GT, LE, GE, VARIABLE, INTEGER_CONSTANT, REAL_CONSTANT, STRING_CONSTANT
};



class Node
{
    private: 
        int level;
        NodeType type; 
        Token values;
        Node* parent;
        vector<Node *> children;

    public: 
        Node(NodeType);
        Node get_node();
};

#endif