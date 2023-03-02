#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <vector> 
#include <string> 
#include <algorithm>
#include <cctype>
#include <cstring> 
#include "Token.h"
#include <iostream>
#include "Scanner.h"
#include "Node.h"
using namespace std; 


class Parser
{
    private: 
    string input;  
    public: 
    Parser(string);
    void set_input(string);
    
};

Parser::Parser(string par_str){
    cout<<par_str;
}
void Parser::set_input(string i){
    input = i;    
}

#endif
