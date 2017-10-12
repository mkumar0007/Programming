#include<bits/stdc++.h>
using namespace std;

typedef struct stak
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

void movedisk(char s,char d,int disk)
{
    cout<<s<<" "<<"move to "<<d<<" disk "<<disk<<endl;
}

void movediskutil(stk *src,stk *dest,char s,char d)
{
    int p1=pop(src);
    int p2=pop(dest);
    if(p1==-1)
    {
        push(src,p2);
        movedisk(d,s,p2);
    }
    else if(p2==-1)
    {
        push(dest,p1);
        movedisk(s,d,p1);
    }
    else if(p1>p2)
    {
        push(src,p1);
        push(src,p2);
        movedisk(d,s,p2);
    }
    else
    {
        push(dest,p2);
        push(dest,p1);
        movedisk(s,d,p1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int disks;
    cin>>disks;
    stk* src=create(disks);
    stk* dest=create(disks);
    stk* aux=create(disks);
    char s='S',d='D',a='A';
    if(disks%2==0)
    {
        char temp=d;
        d=a;
        a=temp;
    }
    int n=pow(2,disks)-1;
    for(int i=n;i>=1;i--)
    {
        push(src,i);
    }
    for(int i=0;i<=n;i++)
    {
        if(i%3==1)
        {
            movediskutil(src,dest,s,d);
        }
        else if(i%3==2)
        {
            movediskutil(src,aux,s,a);
        }
        else if(i%3==0)
        {
            movediskutil(aux,dest,a,d);
        }
    }
    cin.tie(NULL);
    return 0;
}
