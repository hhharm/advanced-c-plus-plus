#include "Servant.h"

int Servant::Calculate(QueueList <IToken *> q, std::list <VarToken*> *var_list, ArrStack <int> &stack)
{
	int n = q.GetSize();
	int t;		//переменная для вычислений
	int res;	//переменная для результата вычислений
	IToken *temp;

	for (int i = 0; i < n; i++)
	{
		temp = q.Pop();
		switch (temp->GetType())
		{
			case variable:	
			{
				for (std::list <VarToken*> ::iterator it = var_list->begin();
							it != var_list->end(); it++) 
				{
					string 
						temp_name	   = (* (VarToken *) temp).GetName(),
						name_from_list = (*it)-> GetName();
					if (temp_name == name_from_list) 
					{
						stack.Push((*it) -> GetValue());
						break;
					}
				}
			break;}
		case operation: 
			{
				t = stack.Pop();
				res = (* (OpToken *)temp).Op(stack.Pop(),t);
				stack.Push(res);
			break;
			}
		case number:
			{
			stack.Push((*(NumToken *)temp).GetValue());
			break;
			}


		}
	}


	res = stack.Pop();
	if (stack.IsEmpty()) return res;
	else throw "ATTENTION! SOMETHING WENT WRONG";
}
