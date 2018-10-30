#include "Servant.h"




int Servant::MakePolsk(QueueList <IToken*> &expression, QueueList <IToken*> &res)
{
	StackList <IToken*> operation_stack;
	int max_size = 0;
	int temp_size = 0;
	IToken *temp;
	res.Clean();
	while (!expression.IsEmpty())
	{
		temp = expression.Pop();
		switch (temp->GetType())
		{
		case operation:
			{
				switch ( (*(OpToken*) temp).GetValue())
				{
				case open_bracket:
					{
						operation_stack.Push(temp);
						temp_size++;
						if (temp_size > max_size) max_size = temp_size;
						break;
					}
				case close_bracket:
					{
						op some_op;
						some_op = (* (OpToken*) operation_stack.ReadEl(operation_stack.GetEnd())).GetValue();
						//пока не дойдем до первой открывабющейся скобки
						while (some_op != open_bracket)				
						{
						//извлекаем операцию из стека
						 some_op = (* (OpToken*) operation_stack.Pop()).GetValue();
						//пересылаем её в результат
						res.Push(new OpToken(some_op));
						some_op = (* (OpToken*) operation_stack.ReadEl(operation_stack.GetEnd())).GetValue();
						}
						//выкидываем скобку
						operation_stack.Pop();
						
						break;
					}										
				default:
					{
						if (!operation_stack.IsEmpty())
						{
						op some_op;
						//проверяем, является ли операция на вершине стека правильного приоритета
						some_op = (* (OpToken*) operation_stack.ReadEl(operation_stack.GetEnd())).GetValue();
						int prior = HelpWithToken::GetPriority((* (OpToken*) temp).GetValue());
						bool f = HelpWithToken::GetPriority(some_op) > prior;
						
						while (f && !operation_stack.IsEmpty())					
						{
						//извлекаем операцию из стека
						 some_op = (* (OpToken*) operation_stack.Pop()).GetValue();
						 temp_size--;
						//пересылаем её в результат
						res.Push( new OpToken (some_op));
						if (!operation_stack.IsEmpty())
							{
								some_op = (* (OpToken*) operation_stack.ReadEl(operation_stack.GetEnd())).GetValue();
								f = HelpWithToken::GetPriority(some_op) > prior;
							}
						}
						}
						operation_stack.Push(new OpToken((* (OpToken*)temp).GetValue()));						
						temp_size++;
						if (temp_size > max_size) max_size = temp_size;
						break;
					}
				}
			break;
			}
		case number:
			{
				res.Push(temp);
				break;
			}
		case variable:	
			{
				res.Push(temp);
				break;
			}
		}		
	}
	//в финале вытолкнуть всё из стека
		while (!operation_stack.IsEmpty())
			res.Push(operation_stack.Pop());

	return max_size+1;
}


string Servant::GetExpress(QueueList <IToken *> q)
{
	string res;
	int size = q.GetSize();
	for (int i = 0; i< size; i++)
		res += (q.ReadEl(i))->GetString();

	return res;
}