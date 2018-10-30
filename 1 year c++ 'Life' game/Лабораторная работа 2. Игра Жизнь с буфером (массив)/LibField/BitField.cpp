#include "Field.h"
//конструктуры
OneBitField::OneBitField(int _n)
{	n = 0;
	SetSize(_n);
}
OneBitField::OneBitField(const OneBitField &a){
	if ( this != &a)
	{
	n = a.n;
	m = a.m;
	p = new unsigned int[m];
	for (int i = 0; i < m; i++) p[i] = a.p[i];
	}
}
OneBitField::~OneBitField(void){ delete [] p;m=0;n=0; } 
unsigned int OneBitField::GetMask(int i, int value){
if (value==0) return ~(1<<(i));
else if (value==1) return 1<<(i);
} 
//операции с битами
void OneBitField::SetBit(int i, int value){
 if ((i <= n)&&(i>=0))
	{int x,y; //байт, в котором мы хотим изменить бит, бит в нём
 x = i / (OUR_SIZE);
 y = i % (OUR_SIZE);
 if (value == 0) p[x] &= GetMask(y, value);
 else if (value == 1) p[x] |= GetMask(y, value);
 }
}
unsigned int OneBitField::GetBit(int i) {
	if ((i < n)&&(i>=0))
	{unsigned int _m,_n, mask;
	_m = p[i/(OUR_SIZE)];
	_n = i%(OUR_SIZE);
	mask = GetMask(_n,1);
	_m &= mask;
	_m = _m >>i;
	return _m;}
	else return 2;}
//задает размер
void OneBitField::SetSize(int i){
	if (n > 0) delete [] p;
	n = i;
	m = i/(OUR_SIZE)+1;
	p = new unsigned int[m];
	MakeClear();
}
 // устанавливает везде нули
void OneBitField::MakeClear()
{
	int i;
	for (i = 0; i < m; i++) p[i] = 0;
}
//возвращает кол-во элементов
int OneBitField::Size() {return n;}
//возвращает 0, если есть ненулевые элементы, 1 если все нули
int OneBitField::IsItClear()
{
for (int i = 0; i < m; i++) {if (p[i] != 0) return 0; break;}
return 1;
}
//перегрузка приравнивания
void OneBitField::operator=(IBitField *b)
{
	int _n = b->Size();
	if (n != _n) this->SetSize(_n);
	unsigned int *pp = b->GetP();
	for (int i = 0; i<m;i++) p[i] = pp[i];
}
int OneBitField::MaxNumOfStates(){return 2;}





TwoBitField::TwoBitField(int _n)
{	n = 0;
	SetSize(_n);
}
TwoBitField::TwoBitField(const TwoBitField &a){
	n = a.n;
	m = a.m;
	p = new unsigned int[m];
	for (int i = 0; i < m; i++) p[i] = a.p[i];
}
TwoBitField::~TwoBitField(void){ delete [] p;m=0;n=0; } 
unsigned int TwoBitField::GetMask(int i, int value){
	
if (value==0) return ~(3<<(2*i));
else if (value==1) return 1<<(2*i);
else if (value==2) return 1<<(2*i+1);
else if (value==3) return 3<<(2*i);
} 
//операции с битами
void TwoBitField::SetBit(int i, int value){
 if ((i <= n)&&(i>=0))
	{int x,y; //байт, в котором мы хотим изменить бит, бит в нём
 x = i / (OUR_SIZE_TWO);
 y = i % (OUR_SIZE_TWO);
 if (value == 0) p[x] &= GetMask(y, value);
 else if (value == 1) {p[x] |= GetMask(y, 1); p[x] &= ~(GetMask(y,2));}
 else if (value == 2) {p[x] |= GetMask(y, 2);p[x] &= ~(GetMask(y, 1));}
 else if (value == 3) p[x] |= GetMask(y, value);
 }
}
unsigned int TwoBitField::GetBit(int i) {
	if ((i < n)&&(i>=0))
	{unsigned int _m,_n, mask;
	_m = p[i/(OUR_SIZE_TWO)];
	_n = i%(OUR_SIZE_TWO);
	mask = GetMask(_n,3);
	_m &= mask;
	_m = _m >>2*i;
	return _m;}
}
//задает размер
void TwoBitField::SetSize(int i){
	if (n > 0) delete [] p;
	n = i;
	m = i/(OUR_SIZE_TWO)+1;
	p = new unsigned int[m];
	MakeClear();
}
 // устанавливает везде нули
void TwoBitField::MakeClear()
{
	int i;
	for (i = 0; i < m; i++) p[i] = 0;
}
//возвращает кол-во элементов
int TwoBitField::Size() {return n;}
//возвращает 0, если есть ненулевые элементы, 1 если все нули
int TwoBitField::IsItClear()
{
for (int i = 0; i < m; i++) {if (p[i] != 0) return 0; break;}
return 1;
}
//перегрузка приравнивания
void TwoBitField::operator=(IBitField *b)
{
	int _n = b->Size();
	if (n != _n) this->SetSize(_n);
	unsigned int *pp = b->GetP();
	for (int i = 0; i<m;i++) p[i] = pp[i];
}
int TwoBitField::MaxNumOfStates(){return 4;}


ThreeBitField::ThreeBitField(int _n)
{	n = 0;
	SetSize(_n);
}
ThreeBitField::ThreeBitField(const ThreeBitField &a){
	n = a.n;
	m = a.m;
	p = new unsigned int[m];
	for (int i = 0; i < m; i++) p[i] = a.p[i];
}
ThreeBitField::~ThreeBitField(void){ delete [] p;m=0;n=0; } 
unsigned int ThreeBitField::GetMask(int i, int value){
	
if (value==1) return 1<<(3*i);	//устанавливает 1 на первое место (справа)
else if (value==2) return 1<<(3*i+1); //устанавливает 1 на второе место
else if (value==4) return 1<<(3*i+2); //устанавливает 1 на 3е место
else if (value==7) return 7<<(3*i); //устанавливает 3 единицы
else if (value==3) return 3<<(3*i);//устанавливает 0 на 3ю поз.
else if (value == 5) return 5<<(3*i);//устанавливает 0 посередине
else if (value == 6) return 3<<(3*i+1); //устанавливает 0 на первое место
} 
//операции с битами
void ThreeBitField::SetBit(int i, int value){
 if ((i <= n)&&(i>=0))
	{int x,y; //байт, в котором мы хотим изменить бит, бит в нём
 x = i / (OUR_SIZE_THREE);
 y = i % (OUR_SIZE_THREE);
 if (value == 0) p[x] &= ~GetMask(y, 7);
 else if (value == 1) {p[x] |= GetMask(y, 1); p[x] &= ~(GetMask(y,6));}
 else if (value == 2) {p[x] |= GetMask(y, 2);p[x] &= ~(GetMask(y, 5));}
 else if (value == 3) {p[x] |= GetMask(y, 3); p[x] &= ~(GetMask(y,4));}
 else if (value == 4) {p[x] |= GetMask(y, 4);p[x] &= ~(GetMask(y, 3));}
 else if (value == 5) {p[x] |= GetMask(y, 5);p[x] &= ~(GetMask(y, 2));}
 else if (value == 6) {p[x] |= GetMask(y, 6); p[x] &= ~(GetMask(y,1));}
 else if (value == 7) p[x] |= GetMask(y, 7);
 }
}
unsigned int ThreeBitField::GetBit(int i) {
	if ((i < n)&&(i>=0))
	{unsigned int _m,_n, mask;
	_m = p[i/(OUR_SIZE_THREE)];
	_n = i%(OUR_SIZE_THREE);
	mask = GetMask(_n,7);
	_m &= mask;
	_m = _m >>3*_n;
	return _m;}
}
//задает размер
void ThreeBitField::SetSize(int i){
	if (n > 0) delete [] p;
	n = i;
	m = i/(OUR_SIZE_THREE)+1;
	p = new unsigned int[m];
	MakeClear();
}
 // устанавливает везде нули
void ThreeBitField::MakeClear()
{
	int i;
	for (i = 0; i < m; i++) p[i] = 0;
}
//возвращает кол-во элементов
int ThreeBitField::Size() {return n;}
//возвращает 0, если есть ненулевые элементы, 1 если все нули
int ThreeBitField::IsItClear()
{
for (int i = 0; i < m; i++) {if (p[i] != 0) return 0; break;}
return 1;
}
//перегрузка приравнивания
void ThreeBitField::operator=(IBitField *b)
{
	int _n = b->Size();
	if (n != _n) this->SetSize(_n);
	unsigned int *pp = b->GetP();
	for (int i = 0; i<m;i++) p[i] = pp[i];
}
int ThreeBitField::MaxNumOfStates(){return 8;}
