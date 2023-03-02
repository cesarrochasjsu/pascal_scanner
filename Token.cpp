#include <string> 
#include "Token.h"
using namespace std;


Token::Token()
{
    token = "";
    label = "";
}

Token::Token(string t, string l)
{
    token = t; 
    label = l;
}

void Token::set_token(string t)
{
    token = t;
}

void Token::set_label(string l)
{
    label = l;
}

string Token::get_token()
{
    return token;
}

string Token::get_label()
{
    return label;
}
