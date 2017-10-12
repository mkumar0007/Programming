#include<bits/stdc++.h>
using namespace std;
typedef struct stack
{
    int capacity;
    int top;
    int *arr;
}stk;

stk* create(int c)
{
    stk* s=new stk;
    s->capacity=c;
    s->top=-1;
    s->arr=(int *)malloc(s->capacity * (sizeof(int)));
    return s;
}

bool isfull(stk* s)
{
    return s->top==s->capacity-1;
}

bool isempty(stk *s)
{
    return s->top==-1;
}

int peek(stk* s)
{
    return s->arr[s->top];
}

void push(stk *s,int x)
{
    s->arr[++(s->top)]=x;
}

int pop(stk* s)
{
    if(isempty(s))
    {
        return -1;
    }
    return s->arr[s->top--];
}

void print(stk *s)
{
    while(!isempty(s))
    {
        cout<<s->arr[s->top]<<" ";
        pop(s);
    }
    cout<<endl;
}

void func(stk* s,int x)
{
    if(isempty(s)  || x < peek(s))
    {
        push(s,x);
        return ;
    }
    int temp=pop(s);
    func(s,x);
    push(s,temp);
}
void sortstk(stk *s)
{
    if(!isempty(s))
    {
        int x=pop(s);
        sortstk(s);
        func(s,x);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    stk* s=create(4);
    push(s,4);
    push(s,2);
    push(s,3);
    push(s,1);
    sortstk(s);
    print(s);
    cin.tie(NULL);
    return 0;
}
