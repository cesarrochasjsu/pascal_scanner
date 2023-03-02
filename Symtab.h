#ifndef SYMTAB_H
#define SYMTAB_H

#include <iostream>
#include <vector> 
#include <string> 
#include "Token.h"

using namespace std; 

struct entry 
{
    string var_name; 
    int value;
};

class Symtab
{
    private: 
        vector<entry> table;

    public: 
        Symtab();
        
        void enter(string, int);    
        int search(string);
        void update(string, int);
};


#endif