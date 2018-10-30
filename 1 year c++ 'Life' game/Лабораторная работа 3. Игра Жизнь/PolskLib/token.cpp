#include "token.h"
#include "List.h"
#include <string>

NumToken::NumToken(int val)		  {value = val;}
token_type NumToken::GetType(){return number;}
int NumToken::GetValue()	  {return value;}
void NumToken::Init(int* val){value = * val;}
string NumToken::GetString() {
	char text[256]="";
	_itoa_s(value,text,10);
	string s = text;
	return s+" ";
}

OpToken::OpToken(op val)	  {value = val;}
token_type OpToken::GetType() {return operation;}
op OpToken::GetValue()		  {return value;}
void OpToken::Init(op* val)	  {value = * val;}
int OpToken::Op (int a, int b)
{
	switch (value)
	{
	case minus:		return a - b;
	case plus:		return a + b;
	case divide:	return a / b;
	case mult:		return a * b;
	};
}
string OpToken::GetString() 
{
	switch (value)
	{
	case minus:		return "- ";
	case plus:		return "+ ";
	case divide:	return "/ ";
	case mult:		return "* ";
	};

}


VarToken::VarToken(string n, int val) : name(n), value (val){}
VarToken::~VarToken()		   {}
token_type VarToken::GetType()		{return variable;}
string VarToken::GetName()			{return name;}		
int VarToken::GetValue()			{return value;}
void VarToken::InitName(string n)	{name = n;}
void VarToken::InitValue(int v)		{value = v;}
string VarToken::GetString()		{return name+" ";}


int HelpWithToken::GetPriority(op a)
{
	switch (a)
	{
		case open_bracket:  return -1;
		case close_bracket: return -1;
		case minus:			return 1;
		case plus:			return 1;			
		case mult:			return 2;
		case divide:		return 2;
	}

}

