#pragma once
#include "List.h"
#include "Queue.h"
#include "Stacks.h"
#include "token.h"
#include <list>

//делает все вспомогательные действия
class Servant
{
public:
	//делает подготовительные работы со строкой
	static void MakeExpressNormal(string &buf);
public:
	
	enum state
{
	everything_is_fine,
	empty_expression,
	brackets_error,
	wrong_symbol,
	wrong_last_elem,
	other_error
};

	//разбивает на лексемы строку, изменяет очередь (там она и появляется)
	static void Parsing (string buf, QueueList <IToken*> &res);
	
	//возвращает список уникальных переменных, которые есть в списке
	//добавляет туда a1...a9
	static void GetVarList(QueueList <IToken*> &q, std::list <VarToken*> *vars);		


	//Изменяет expression!
	//возвращает нужную глубину стека
	//создаёт выражение  в польской записи в виде очереди
	static int MakePolsk(QueueList <IToken*> &expression, QueueList <IToken*> &res);

	//подсчитывает результат ( берет выражение из очереди, подставляет туда значение переменных и считает)
	static int Calculate(QueueList <IToken *> q, std::list <VarToken *> *var_list,  ArrStack <int> &stack);


	//переводит польскую очередь в строку
	static string GetExpress(QueueList <IToken *> q);

	//проверяет правильность
	static state Check(string exp);

};