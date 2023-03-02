#ifndef SCANNER_H
#define SCANNER_H

#include <iostream>
#include <fstream>
#include <vector> 
#include <string> 
#include <algorithm>
#include <cctype>
#include <cstring> 
#include "Token.h"
#include <iostream>

using namespace std; 


bool is_word(char);
bool is_num(char);
bool is_symbol(char);


class Scanner
{
    private: 
        vector<Token> word_table;
        char buffer;
        ifstream inputFile; 
            //two boolean varaibels to check if the word is a string or not
         bool beginstring = false;
         bool endstring = false;
    public: 
        Scanner(string);
        string nexttoken();
        
        Scanner getwordtable();
    
        void print(string str);
        void match(string var);
        bool isspecial(string var);
        bool isinteger(string& var);
        bool isreal(string var);
};




#endif
