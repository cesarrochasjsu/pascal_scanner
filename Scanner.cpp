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

using namespace std; 

Scanner::Scanner(string path)
{
    
    buffer = ' ';
    inputFile.open(path);
    // Set up the word bank
    Token temp;

    temp.set_token("and");
    temp.set_label("AND");
    word_table.push_back(temp);

    temp.set_token("array");
    temp.set_label("ARRAY");
    word_table.push_back(temp);
    temp.set_token("asm");
    temp.set_label("ASM");
    word_table.push_back(temp);
    temp.set_token("begin");
    temp.set_label("BEGIN");
    word_table.push_back(temp);    
    temp.set_token("break");
    temp.set_label("BREAK");
    word_table.push_back(temp);    
    temp.set_token("case");
    temp.set_label("CASE");
    word_table.push_back(temp);    
    temp.set_token("const");
    temp.set_label("CONST");
    word_table.push_back(temp);    
    temp.set_token("constructor");
    temp.set_label("CONSTRUCTOR");
    word_table.push_back(temp);    
    temp.set_token("destructor");
    temp.set_label("DESTRUCTOR");
    word_table.push_back(temp);    
    temp.set_token("div");
    temp.set_label("DIV");
    word_table.push_back(temp);    
    temp.set_token("do");
    temp.set_label("DO");
    word_table.push_back(temp);    
    temp.set_token("downto");
    temp.set_label("DOWNTO");
    word_table.push_back(temp);    
    temp.set_token("else");
    temp.set_label("ELSE");
    word_table.push_back(temp);    
    temp.set_token("end");
    temp.set_label("END");
    word_table.push_back(temp);
    temp.set_token("false");
    temp.set_label("FALSE");
    word_table.push_back(temp);    
    temp.set_token("file");
    temp.set_label("FILE");
    word_table.push_back(temp);    
    temp.set_token("for");
    temp.set_label("FOR");
    word_table.push_back(temp);    
    temp.set_token("function");
    temp.set_label("FUNCTION");
    word_table.push_back(temp);    
    temp.set_token("goto");
    temp.set_label("GOTO");
    word_table.push_back(temp);    
    temp.set_token("if");
    temp.set_label("IF");
    word_table.push_back(temp);
    temp.set_token("implementation");
    temp.set_label("IMPLEMENTATION");
    word_table.push_back(temp);
    temp.set_token("in");
    temp.set_label("IN");
    word_table.push_back(temp);    
    temp.set_token("inline");
    temp.set_label("INLINE");
    word_table.push_back(temp);    
    temp.set_token("interface");
    temp.set_label("INTERFACE");
    word_table.push_back(temp);    
    temp.set_token("label");
    temp.set_label("LABEL");
    word_table.push_back(temp);    
    temp.set_token("mod");
    temp.set_label("MOD");
    word_table.push_back(temp);    
    temp.set_token("nil");
    temp.set_label("NIL");
    word_table.push_back(temp);
    temp.set_token("not");
    temp.set_label("NOT");
    word_table.push_back(temp);
    temp.set_token("object");
    temp.set_label("OBJECT");
    word_table.push_back(temp);    
    temp.set_token("of");
    temp.set_label("OF");
    word_table.push_back(temp);    
    temp.set_token("on");
    temp.set_label("ON");
    word_table.push_back(temp);    
    temp.set_token("operator");
    temp.set_label("OPERATOR");
    word_table.push_back(temp);    
    temp.set_token("or");
    temp.set_label("OR");
    word_table.push_back(temp);    
    temp.set_token("packed");
    temp.set_label("PACKED");
    word_table.push_back(temp);    
    temp.set_token("procedure");
    temp.set_label("PROCEDURE");
    word_table.push_back(temp);    
    temp.set_token("program");
    temp.set_label("PROGRAM");
    word_table.push_back(temp);    
    temp.set_token("record");
    temp.set_label("RECORD");
    word_table.push_back(temp);    
    temp.set_token("repeat");
    temp.set_label("REPEAT");
    word_table.push_back(temp);    
    temp.set_token("set");
    temp.set_label("SET");
    word_table.push_back(temp);    
    temp.set_token("shl");
    temp.set_label("SHL");
    word_table.push_back(temp); 
    temp.set_token("shr");
    temp.set_label("SHR");
    word_table.push_back(temp);    
    temp.set_token("string");
    temp.set_label("STRING");
    word_table.push_back(temp);    
    temp.set_token("then");
    temp.set_label("THEN");
    word_table.push_back(temp);    
    temp.set_token("to");
    temp.set_label("TO");
    word_table.push_back(temp);    
    temp.set_token("true");
    temp.set_label("TRUE");
    word_table.push_back(temp);    
    temp.set_token("type");
    temp.set_label("TYPE");
    word_table.push_back(temp);    
    temp.set_token("unit");
    temp.set_label("UNIT");
    word_table.push_back(temp);    
    temp.set_token("until");
    temp.set_label("UNTIL");
    word_table.push_back(temp);    
    temp.set_token("uses");
    temp.set_label("USES");
    word_table.push_back(temp); 
    temp.set_token("var");
    temp.set_label("VAR");
    word_table.push_back(temp);    
    temp.set_token("while");
    temp.set_label("WHILE");
    word_table.push_back(temp);    
    temp.set_token("with");
    temp.set_label("WITH");
    word_table.push_back(temp);    
    temp.set_token("xor");
    temp.set_label("XOR");
    word_table.push_back(temp);    
    temp.set_token("(integer)");
    temp.set_label("INTEGER");
    word_table.push_back(temp);    
    temp.set_token("(real number)");
    temp.set_label("REAL");
    word_table.push_back(temp); 
    temp.set_token("(identifier)");
    temp.set_label("IDENTIFIER");
    word_table.push_back(temp);    
    temp.set_token("+");
    temp.set_label("PLUSOP");
    word_table.push_back(temp);    
    temp.set_token("-");
    temp.set_label("MINUSOP");
    word_table.push_back(temp);    
    temp.set_token("*");
    temp.set_label("MULTOP");
    word_table.push_back(temp);    
    temp.set_token("/");
    temp.set_label("DIVOP");
    word_table.push_back(temp);    
    temp.set_token(":=");
    temp.set_label("ASSIGN");
    word_table.push_back(temp);    
    temp.set_token("=");
    temp.set_label("EQUAL");
    word_table.push_back(temp);    
    temp.set_token("<>");
    temp.set_label("NE");
    word_table.push_back(temp);    
    temp.set_token("<=");
    temp.set_label("LTEQ");
    word_table.push_back(temp); 
    temp.set_token(">=");
    temp.set_label("GTEQ");
    word_table.push_back(temp);    
    temp.set_token("<");
    temp.set_label("LT");
    word_table.push_back(temp);    
    temp.set_token(">");
    temp.set_label("GT");
    word_table.push_back(temp);    
    temp.set_token("+=");
    temp.set_label("PLUSEQUAL");
    word_table.push_back(temp);    
    temp.set_token("-=");
    temp.set_label("MINUSEQUAL");
    word_table.push_back(temp);    
    temp.set_token("*=");
    temp.set_label("MULTEQUAL");
    word_table.push_back(temp);  
    temp.set_token("/=");
    temp.set_label("DIVEQUAL");
    word_table.push_back(temp);    
    temp.set_token("^");
    temp.set_label("CARAT");
    word_table.push_back(temp);    
    temp.set_token(";");
    temp.set_label("SEMICOLOR");
    word_table.push_back(temp);    
    temp.set_token(",");
    temp.set_label("COMMA");
    word_table.push_back(temp);    
    temp.set_token("(");
    temp.set_label("LPAREN");
    word_table.push_back(temp); 
    temp.set_token(")");
    temp.set_label("RPAREN");
    word_table.push_back(temp);    
    temp.set_token("[");
    temp.set_label("LBRACKET");
    word_table.push_back(temp);    
    temp.set_token("]");
    temp.set_label("RBARCKET");
    word_table.push_back(temp);    
    temp.set_token("{");
    temp.set_label("LBRACE");
    word_table.push_back(temp);    
    temp.set_token("}");
    temp.set_label("RBRACE");
    word_table.push_back(temp);    
    temp.set_token("(*");
    temp.set_label("LCOMMENT");
    word_table.push_back(temp);   
    temp.set_token("*)");
    temp.set_label("RCOMMENT");
    word_table.push_back(temp);  
    
}

// it will take inputs from the test-in.txt (input file) and read it, then pass the varaibles into the match(string var) until it reaches the end of file
string Scanner::nexttoken()
{
    string current_token;
    char c, token_front;
     
   
    // CHECK IF ANYTHING IS IN BUFFER FROM PREVIOUS TOKEN(S)
    if (!isspace(buffer))
    {
        current_token += buffer;
        buffer = ' ';
    }
    else 
        inputFile.get(c);
    
    
    
    while (iscntrl(c))
    {    
        inputFile.get(c);
    }
    token_front = c;
    
    
    // CHECK IF TOKEN IS A WORD, NUMBER, OR SYMBOL
    if (is_word(token_front))
    {
        // Keep appending on current token while character 
        // satisfies WORD RULES
        while(!isspace(c) && !is_symbol(c))
        {
            current_token += c;
            inputFile.get(c);
        }
    }

    else if (is_num(token_front))
    {
        // Keep appending on current token while character 
        // satisfies INTEGER RULES
        while(!isspace(c) && !is_word(c) && !is_symbol(c))
        {
            
            current_token += c;
            inputFile.get(c);
        }
    }

    else if (is_symbol(token_front))
    {
        // Keep appending on current token while character 
        // satisfies SYMBOL RULES
        while(!isspace(c) && !is_num(c) && !is_word(c))
        {
            current_token += c;
            inputFile.get(c);
        }
    }
    
    else 
    {    
       
        cout << "ERROR: " << c << endl;
        
    }
    // Save last character in buffer
    if (c != '\n')
        buffer = c;
    
    // cout<<current_token<<endl;
    
    match(current_token);
    return  current_token;
}

bool is_word(char w){
    if (isalpha(w))
        return true; 
    else 
        return false;
}

bool is_num(char n)
{
    if (isdigit(n))
        return true; 
    else 
        return false;
}

bool is_symbol(char s){
    if (ispunct(s))
        return true; 
    else 
        return false;

    
}

string Looower(string data){
    transform(data.begin(), data.end(), data.begin(),
    [](unsigned char c){ return tolower(c); });
    
    return data;
}

// it will take the variable var, compare it with every 
void Scanner::match(string var)
{   
    
    ofstream outfile;
    
    outfile.open("test-out.text", std::ios_base::app);
  
    //inthebank will check if the var matches any cryteria in the word bank
    bool inthebank = false;
    string tempt;
    for(int i=0;i<word_table.size();i++)
    {   
         if(isalpha(var[0])){
            tempt=Looower(var);
            if(beginstring ==true){
                cout<<"String: \t"<<var<<endl;
                outfile << "String: \t"<<var<<endl;
                inthebank  =true;
                break;
            }
            else if(tempt ==word_table[i].get_token()){
                cout<<word_table[i].get_label()<<": \t"<< var <<endl;
                outfile<<word_table[i].get_label()<<": \t"<< var <<endl;
                inthebank=true;
                break;
            }
        }
        else if(isinteger(var)){
               cout<<"Integer: \t"<<var<<endl;
               outfile<<"Integer: \t"<<var<<endl;
               inthebank=true;
               break;
            } 
        else {
            if(var==word_table[i].get_token()){
                cout<<word_table[i].get_label()<<": \t"<<var<<endl;
                outfile<<word_table[i].get_label()<<": \t"<<var<<endl;
                inthebank=true;
                break;
            }
            //condtions for string variables
            else if(var=="\'"&&beginstring==false){
                beginstring = true;
                 inthebank  =true;
                break;
            }
            else if(var=="\'"&&beginstring ==true){
                beginstring = false;
                 inthebank  =true;
                break;
            }
           
        }
     
    }
    if(!inthebank){
        cout<<"Identifier: \t"<<var<<endl;
        outfile<<"Identifier: \t"<<var<<endl;
    }
}


bool Scanner:: isreal(string str){
    int int_version = abs(stoi(str));
    double flt_version = abs(stof(str));

    if ((flt_version - int_version) == 0)
            return false;
    else
            return true;
}


bool Scanner:: isinteger( string& str)
{
    for (char const &c : str) {
        //additional condition to bypass negative numbers
        if(c=='-'){
            continue;
        }
        else if (std::isdigit(c) == 0) return false;
    }
    return true;
}



