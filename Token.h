#ifndef TOKEN_H
#define TOKEN_H

#include <string> 
using namespace std;
class Token
{
    private: 
        string token; 
        string label;

    public:
        Token();
        Token(string, string);

        void set_token(string);
        void set_label(string);

        string get_token();
        string get_label();



};




#endif
