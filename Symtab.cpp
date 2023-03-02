#include <iostream>
#include <vector> 
#include <string> 
#include "Token.h"
#include "Symtab.h"

using namespace std; 

void Symtab::enter(string name, int val)
{
    entry temp;
    temp.var_name = name; 
    temp.value = val;
    table.push_back(temp); 
}

int Symtab::search(string name)
{
    for(int i=0; i<table.size(); i++)
    {
        if (name.compare(table[i].var_name) == 0)
            return table[i].value;
        else 
            cout << "Identifier not in symtab." << endl;
    }
}

void Symtab::update(string name, int val)
{
    int index; 
    for(int i=0; i<table.size(); i++)
    {
        if (name.compare(table[i].var_name) == 0)
        {
            table[i].value = val;
            break;
        }

        else 
            cout << "Identifier not in symtab." << endl;
    }
}