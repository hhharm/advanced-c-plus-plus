#include "Servant.h"
#include <string>
using namespace std;



void Servant::MakeExpressNormal(string &buf)
{
	string::iterator  str_iter;
	
	//������ �������� �������
	int j;
	for (int i = 0; i < buf.size() - 1; i++)
		if (buf[i] == ' ')
		{
			j = i + 1;
			while (buf[j] == ' ')	
				{
					buf.erase(j,1);
				}
		}
	//������� �������� ��������� ������
	str_iter = buf.end() - 1;
	if ((*str_iter) == ' ') buf.erase(str_iter);
	//������� �������
	for (str_iter = buf.begin(); str_iter < buf.end(); str_iter++)
		if (*str_iter == ' ')
		{
			buf.erase(str_iter);
		}
	//�������� (- �� (0-
	for (str_iter = buf.begin(); str_iter != buf.end(); str_iter++)
		if (*str_iter == '(')
		{
			str_iter++;
			if (*str_iter == '-')
			buf.insert(str_iter, '0');
		}
			

}


void Servant::Parsing (string expression, QueueList <IToken*> &res)
{
	string temp_num;		//������� ����� (��� ������������� ��� �����)
	string temp_var;		//������� ��� ���������� (��� ������������� ��� �������)
	int t_int;				//���������� ��� �����
	int i;
	res.Clean();
	MakeExpressNormal(expression);
	
	int size_of_buf = expression.size();
	//���������� � ����� ��� ������� � ������
	for(i = 0; i < size_of_buf; i++)
		{
			//���� ��� ������
			if(isspace(expression[i]))
			{
				if(0 != temp_num.size())	//���� ���� ������� �����
					{
						t_int = atoi(temp_num.c_str());
						res.Push(new NumToken(t_int));	//������ ��� � ����
						temp_num.clear();				//���������� ��������
					}
				else 
				if(0 != temp_var.size())	//���� ���� ������� ��� ����������
					{
						if(0 != temp_var.size())	//���� ���� ������� ��� ����������
							{
								int i = 0;
						
								res.Push(new VarToken (temp_var));	//������ ��� � ����
								temp_var.clear();					//���������� ��������
							}
					}
			}						
			else 
				//���� ��� �����, ���������� � � �������� ����� ������
				if (isdigit(expression[i])) 
					{
						if (0 != temp_var.size()) temp_var += expression[i];
						else temp_num += expression[i];
					}
			else 
				//���� �����, ���������� � � �������� ����� ����������
				if (isalpha(expression[i])) temp_var += expression[i];
			else 
				//���� ��� ��������
				if(ispunct(expression[i]))
			{ 
				if(0 != temp_num.size())	//���� ���� ������� �����
					{
						t_int = atoi(temp_num.c_str());
						res.Push(new NumToken(t_int));	//������ ��� � ����
						temp_num.clear();				//���������� ��������
					}
				else 
				if(0 != temp_var.size())	//���� ���� ������� ��� ����������
					{
						if(0 != temp_var.size())	//���� ���� ������� ��� ����������
							{
								int i = 0;
						
								res.Push(new VarToken (temp_var));	//������ ��� � ����
								temp_var.clear();					//���������� ��������
							}
					}
				switch (expression[i]){
					case '(':
						{
							res.Push(new OpToken (open_bracket));
							break;
						}
					case ')':
						{
							res.Push(new OpToken (close_bracket));
							break;
						}
					case '+':
						{
							res.Push(new OpToken (plus));
							break;
						}
					case '-':
						{
							res.Push(new OpToken (minus));
							break;
						}
					case '*':
						{
							res.Push(new OpToken (mult));
							break;
						}
					case '/':
						{
							res.Push(new OpToken (divide));
							break;
						}
					default:
						break;
						};				
				}				
	}
//� ����� ���������, �������� �� ���-������ ������
	if(0 != temp_num.size())	//���� ���� ������� �����
			{
				t_int = atoi(temp_num.c_str());
				res.Push(new NumToken(t_int));	//������ ��� � ����
				temp_num.clear();				//���������� ��������
			}
	else 
		if(0 != temp_var.size())	//���� ���� ������� ��� ����������
			{
				int i = 0;				
				res.Push(new VarToken (temp_var));	//������ ��� � ����
				temp_var.clear();					//���������� ��������
			}
}





Servant::state Servant::Check(string exp)
{
	StackList <bool> stack;
	string::iterator strIt;
	int n;
	
	if (exp.size() == 0) return empty_expression;
	int j;
	//������ �������� �������
	for (int i = 0; i < exp.size() - 1; i++)
		if (exp[i] == ' ')
		{
			j = i + 1;
			while (exp[j] == ' ')	
				{
					exp.erase(j,1);
				}
		}
	//��������� �� ������ �������
	for (strIt = exp.begin(); strIt != exp.end(); strIt++)
	{
	if (!((*strIt >= '0' && *strIt <= '9') || (*strIt >= 'a') && (*strIt <= 'z') ||
		((*strIt >='A')&&(*strIt <='Z')) ||	(*strIt == '+') || (*strIt == '-')
		||(*strIt == '*')||(*strIt == '/') || (*strIt == '(')||(*strIt == ')')||
		(*strIt == ' '))) return wrong_symbol;
	}


	//��������� �� ���������� ������
	try 
	{
	for (strIt = exp.begin(); strIt != exp.end(); strIt++)
		if (*strIt == '(') stack.Push(true);
		else if (*strIt == ')') stack.Pop();
	}
	catch (...)
	{
		return brackets_error;
	}
	if (!stack.IsEmpty()) return brackets_error;
	
	string::iterator strIt1;	
	

	
	if (exp.size() == 1)
	{
		if (exp[0] == ' ') return empty_expression;
		else 
		{
			if (exp[0] == '*' || exp[0] == '/' || exp[0] == '-'|| exp[0] == '+'
				||exp[0] == '(' || exp[0] == ')')
				return wrong_last_elem;
			else return everything_is_fine;
		}
	}
	

	//���������, ����� �� ���� '����� �����' '����� �����' '����� �����' '����� ����� '
		n = exp.size() - 1;
		for (int i = 0; i < n; i++)
		if ((exp[i] >= 'a') && (exp[i] <= 'z') || ((exp[i] >='A')&&(exp[i] <='Z'))
			|| ((exp[i] >= '0') && (exp[i]<= '9')))
			{
				j = i + 1;
				if (exp[j] == ' ')
				{
				j++;
				if ((exp[j] >= '0') && (exp[j]<= '9') || ((exp[j] >= 'a') && (exp[j] <= 'z')) ||
					((exp[j] >='A')&&(exp[j] <='Z'))) return other_error;
				}
			}
	//���������, ����� �� ���� '����������'
	for (int i = 0; i < n; i++)
		{
		if ((exp[i] >= '0') && (exp[i] <= '9') )
			{
				j = i + 1;
				if ((exp[j] >= 'a') && (exp[j] <= 'z') ||
					(exp[j] >='A')&&(exp[j] <='Z')|| (exp[j] == '(')) return other_error;
			}
		}


	MakeExpressNormal(exp);
		n = exp.size() - 1;
	//���������, ����� �� ���� �����(, �����(
	for (int i = 0; i < n; i++)
		{
		if ((exp[i] >= 'a') && (exp[i] <= 'z') ||
					(exp[i] >='A')&&(exp[i] <='Z') || (exp[i] >= '0') && (exp[i] <= '9') )
			{
				j = i + 1;
				if (exp[j] == '(') return other_error;
			}
		}

	//��������� �� ��, ����� �� ���� ������ ���� ��������
	for (strIt = exp.begin(), strIt1 = strIt++; strIt != exp.end(); strIt++, strIt1++)
		if (((*strIt == '+') || (*strIt == '-')||(*strIt == '*')||(*strIt == '/'))
			&& ((*strIt1 == '+') || (*strIt1 == '-')||(*strIt1 == '*')||(*strIt1 == '/')))
			return other_error;

	//��������� �� ��, ����� �� ���� ()
	for (strIt = exp.begin(), strIt1 = strIt++; strIt != exp.end(); strIt++, strIt1++)
		if (((*strIt == '(') && (*strIt1 == ')')) || ((*strIt == ')')&&(*strIt1 == '(')))
			return other_error;

	//���������, ��� ��� )����� )����� 
	for (int i = 0; i < n; i++)
		{
		if (exp[i] == ')')
			{
				j = i + 1;
				if ((exp[j] >= 'a') && (exp[j] <= 'z') ||
					(exp[j] >='A')&&(exp[j] <='Z') || (exp[i] >= '0') && (exp[i] <= '9') ) return other_error;
			}
		}

	//���������, ��� ��� (+, (*, (/,
	for (strIt = exp.begin(), strIt1 = strIt++; strIt != exp.end(); strIt++, strIt1++)
		if ((*strIt1 == '(')	&& ((*strIt == '+') ||(*strIt == '*')||(*strIt == '/')))
			return other_error;
	
	//���������, ��� ��������� ������ ������\�����\����������
	n = exp.size()-1;
	if (exp[n] == '*' || exp[n] == '/' || exp[n] == '-'|| exp[n] == '+')
		return wrong_last_elem;


	return everything_is_fine;
}

void Servant::GetVarList(QueueList <IToken*> &q, std::list <VarToken*> *vars)
{	vars->clear();
	IToken* t;
	{
		VarToken **arr = new VarToken* [9] ;
		arr[0] = new VarToken ("a1");
		arr[1] = new VarToken ("a2");
		arr[2] = new VarToken ("a3");
		arr[3] = new VarToken ("a4");
		arr[4] = new VarToken ("a5");
		arr[5] = new VarToken ("a6");		
		arr[6] = new VarToken ("a7");
		arr[7] = new VarToken ("a8");
		arr[8] = new VarToken ("a9");


		for (int i = 0; i < 9; i++)
			vars->push_back(arr[i]);
	}

	for (int i = 0; i < q.GetSize(); i++)
		{
			t = q.ReadEl(i);
			if (t->GetType() == variable) 
				{
					bool f = true;
					
					for (std::list <VarToken*> ::iterator it = vars->begin();
							it != vars->end(); it++) 
						if ( (*it)->GetName() == (*(VarToken*)t).GetName())
							f = false;
					if (f) 
					{
						vars->push_back((VarToken*)t);
					}
				}
		}
}