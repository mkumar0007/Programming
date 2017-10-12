#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct Queue
{
    struct node *stk;
};

void push(struct node **head,int x)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
        return;
    newnode->data=x;
    newnode->next=*head;
    *head=newnode;
}
int pop(struct node** top_ref)
{
    int res;
    struct node *top;
    if(*top_ref == NULL)
    {
        printf("Stack overflow \n");
        getchar();
        exit(0);

    }
    else
    {
    top = *top_ref;
    res = top->data;
    *top_ref = top->next;
    free(top);
    return res;
    }
}


void enqueue(struct Queue *Q,int x)
{
    push(&(Q->stk),x);
}

int dequeue(struct Queue *q)
{
    int x,res;
    if((q->stk)==NULL)
    {
        cout<<"EMPTY";
        exit(0);
    }
    else if((q->stk->next)==NULL)
    {
        int y=pop(&q->stk);
        return y;
    }
    else
    {
        x=pop(&q->stk);
        res=dequeue   (q);
        push(&q->stk,x);
        return res;
    }
}

int main()
{
    struct Queue *q=(struct Queue *)malloc(sizeof(struct Queue));
    q->stk=NULL;
    enqueue(q,1);
    cout<<endl;
    enqueue(q,2);
    cout<<endl;
    enqueue(q,3);
        cout<<endl;
    cout<<dequeue(q);
        cout<<endl;
    cout<<dequeue(q);
        cout<<endl;
    cout<<dequeue(q);
        cout<<endl;
    dequeue(q);
    return 0;
}
