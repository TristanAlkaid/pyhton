#include<stdio.h> 
#include <string.h>

#define StackSize 10
#define MAXSIZE 10

typedef struct
{
    char data[StackSize];
    int top; 
}SqStack;

//初始化栈 
void InitStack(SqStack *S)
{ 
    S->top=-1;
}

//栈的判空 
int StackEmpty(SqStack S)
{ 
    if (S.top==-1)
        return 1;
    else
        return 0;
}

//进栈 
int Push(SqStack *S,char e)
{
    if(S->top == StackSize -1)
    {
        return 0;
    }
    S->top++;
    S->data[S->top]=e;
    return 1;
}

//出栈 
char Pop(SqStack *S)
{ 
    if(S->top==-1)
        return 0;
    char e=S->data[S->top];
    S->top--;
    return e;
}

int JudgeHuiWen(char *str)
{
	SqStack s;
	InitStack(&s);
	int i; 
	char temp;
	int len=strlen(str);
	for(i=0;i<len/2;i++)
		Push(&s,str[i]);
	if(len%2==1)i++;//当字符个数为奇数时跳过中间字符 
	while(!StackEmpty(s))
	{
		temp=Pop(&s);
		if(temp!=str[i]) return 0;
		else i++;
	}
	return 1;
}
int main()
{
	char str[MAXSIZE];
	gets(str);
	int judge=JudgeHuiWen(str);
	if(judge==1)
		printf("此字符序列是回文！");
	else
		printf("此字符序列不是回文！");
} 