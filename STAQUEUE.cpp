#include<bits/stdc++.h>
using namespace std;
int siz;
/*class stk
{
public:
    int top;
    int *s;
    stk()
    {
        top=-1;
        s=new int[siz];
    }
    bool push(int x);
    void pop();
    int top1();
    bool isempty();
};

int stk::top1()
{
    return s[top];
}
bool stk::push(int x)
{
    if(top>=siz)
    {
        cout<<"Stack Overflow";
        return false;
    }
    else
    {
        s[++top]=x;
        return true;
    }
}

void stk::pop()
{
    if(top<0)
    {
        cout<<"Stack underflow";
        return;
    }
    else
    {
        --top;
    }
}

bool stk::isempty()
{
    return top<0;
}
*/
#define MAX 1000

class Stack
{
    int top;
public:
    int a[MAX];    //Maximum size of Stack

    Stack()  { top = -1; }
    int top1()
    {
        return a[top];
    }
    bool push(int x);
    void pop();
    bool isempty();
};

bool Stack::push(int x)
{
    if (top >= MAX)
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        return true;
    }
}

void Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow";
        return ;
    }
    else
    {
         a[top--];
    }
}

bool Stack::isempty()
{
    return (top < 0);
}
class que
{
    public:
    Stack s1,s2;
    void enqueue(int x);
    int dequeue();
    void display()
    {
        while(!s1.isempty())
        {
            s2.push(s1.top1());
            s1.pop();
        }
        while(!s2.isempty())
        {
            cout<<s2.top1()<<" ";
            s2.pop();
        }
    }
};

void que:: enqueue(int x)
{
    s1.push(x);
}

int que:: dequeue()
{
    int ret;
    while(!s1.isempty())
    {
        s2.push(s1.top1());
        s1.pop();
    }
    ret=s2.top1();
    s2.pop();
    while(!s2.isempty())
    {
        s1.push(s2.top1());
        s2.pop();
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout<<"\nEnter the size of queue"<<endl;
    cin>>siz;
    que q;
    int ch;
    char y;
    do
    {
        cout<<"Enter The choice"<<endl;
        cout<<"1.ENQUEUE"<<endl;
        cout<<"2.DEQUEUE"<<endl;
        cout<<"3.DISPLAY"<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
            {
                int x;
                cout<<"Enter the element:\n";
                cin>>x;
                q.enqueue(x);
                break;
            }
        case 2:
            {
                int x=q.dequeue();
                cout<<"DEQUEUED ELEMENT :  "<<x<<endl;
                break;
            }
        case 3:
            {
                cout<<"ELEMENTS ARE  ";
                q.display();
                cout<<endl;
                break;
            }
        case 4:
            {
                exit(0);
            }
        }
        cout<<"DO YOU WANT TO CONTINUE YES OR NO    ";
        cin>>y;
    }while(y!='N');
    cin.tie(NULL);
    return 0;

}
