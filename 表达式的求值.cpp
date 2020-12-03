#include <stdio.h>
#include <stdlib.h>
  
#define ElemType char
#define STACKINCEMENT 10
#define STACK_INIT_SIZE 50 
#define Status int
#define OK 1
#define ERROR 0
#define OVERFLOW -2
  
typedef struct{
ElemType *base;
ElemType *top;
int stacksize;
}SqStack;
 
Status InitStack(SqStack &S){
S.top = S.base = (ElemType *)malloc(sizeof(ElemType) * STACK_INIT_SIZE);
if(!S.top)
exit(OVERFLOW);
S.stacksize = STACK_INIT_SIZE;
return OK;
}//InitStack
 
Status Push(SqStack &S, ElemType e){
if(S.top - S.base == S.stacksize){
S.base = (ElemType *)realloc(S.base, sizeof(ElemType) *
(S.stacksize + STACKINCEMENT));
 if(!S.base) exit(OVERFLOW);
 S.top = S.base + S.stacksize;
 S.stacksize += STACKINCEMENT;
}
*S.top++ = e;
return OK;
}//Push
 
Status Pop(SqStack &S, ElemType &e){
if(S.base == S.top) return ERROR;
  
e = *--S.top;
return OK;
}//Pop
  
ElemType GetTop(SqStack S){
if(S.base == S.top) return ERROR;
return *--S.top;
 }//GetTop
 
Status In(ElemType c){
if(c=='+'||c=='-'||c=='*'||c=='/'||c=='#'||c=='('||c==')'||c=='['||c==']')
return 1;
else
return 0;
}//In
 
char Precede(ElemType a, ElemType b){
if(a=='+'||a=='-'){
if(b=='+'||b=='-'||b=='>'||b=='#'||b==')'||b==']')
return '>';
else return '<';
}
if(a=='*'||a=='/'){
if(b=='('||b=='[')
return '<';
else return '>';
} 
if(a=='('){
if(b==')')
return '=';
else return '<';
}
if(a=='['){
if(b==']')
return '=';
else return '<';
}
if(a=='#'){
if(b=='#')
return '=';
else return '<';
}
}//Precede
 
ElemType Operate(ElemType a, ElemType x, ElemType b){
switch (x){
case '+':
return a  + b;
case '-':
return a  - b;
 case '*':
return a * b;
case '/':
return a / b;
}
}//Operator
  
ElemType EvaluateExpression(){
SqStack OPTR, OPND;
InitStack(OPTR); //²Ù×÷·û
Push(OPTR, '#');
InitStack(OPND); //²Ù×÷Êý
 
char x, c[100];
gets(c);
int i=0;
while(c[i] != '#' || GetTop(OPTR)!='#'){
if(!In(c[i])) {
if(i>0 && (c[i-1]>'0'&& c[i-1]<='9')){
Pop(OPND, x);
Push(OPND, 10*x + c[i] - '0');
}
else Push(OPND, c[i] - '0');
i++;
}
else
switch(Precede(GetTop(OPTR), c[i])){
case '<':
Push(OPTR, c[i]);
i++;
break;
case '=':
Pop(OPTR, x);
i++;
break;
case '>':
Pop(OPTR, x);
ElemType a, b;
Pop(OPND, b); Pop(OPND, a);
Push(OPND, Operate(a, x, b));
break;
}
}
return GetTop(OPND);
}//EvaluateExpression
 
int main(){
SqStack S;
InitStack(S);
printf("%d",EvaluateExpression());

return 0;
}
