#include "Token.h"
#include "Scanner.h"
#include "Parser.h"
#include <iostream>
#include <fstream> 

using namespace std; 

int main()
{       
        remove("test-out.text");
        Scanner newScanner("HelloWorld-2.txt");
        string test;
        Parser newParser(test);
        for (int i=0; i<50; i++){
            test =newScanner.nexttoken();
            newParser.set_input(test);    
        }  
} 
