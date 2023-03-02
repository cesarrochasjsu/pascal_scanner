#include <iostream>
#include <vector> 
#include <string> 
#include "Token.h"
#include "Node.h"
using namespace std; 


Node::Node(NodeType nt)
{
    type = nt;
}
// Node Node::get_node(){
//     return Node hi;
// }