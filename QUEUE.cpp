#include<bits/stdc++.h>
using namespace std;

struct Queue
{
    int capacity;
    int size;
    int front;
    int rear;
    int *arr;
};

struct Queue* create(int capacity)
{
    struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
    q->capacity=capacity;
    q->size=0;
    q->front=0;
    q->rear=capacity-1;
    q->arr=new int[capacity];
    return q;
}

bool isfull(struct Queue *q)
{
    return q->size==q->capacity;
}

bool isempty(struct Queue *q)
{
    return q->size==0;
}

void enqueue(struct Queue *q,int ele)
{
    if(isfull(q))
    {
        cout<<"OVERFLOW";
        return ;
    }
    else
    {
        q->rear=(q->rear+1)%q->capacity;
        q->arr[(q->rear)]=ele;
        q->size++;
    }
}

void dequeue(struct Queue *q)
{
    if(isempty(q))
    {
        cout<<"UNDERFLOW";
        return ;
    }
    else
    {
        cout<<"DEQUEUED ELEMENT   :";
        cout<<q->arr[q->front]<<endl;
        q->front=(q->front+1)%q->capacity;
        q->size--;
    }
}

void fron(struct Queue *q)
{
    if(isempty(q))
    {
        return ;
    }
    else
    {
        cout<<"FRONT  :"<<q->arr[q->front];
        cout<<endl;
    }
}

void rea(struct Queue *q)
{
    if(isempty(q))
    {
        return;
    }
    else
    {
        cout<<"REAR  :"<<q->arr[q->rear];
        cout<<endl;
    }
}

void display(struct Queue *q)
{
    for(int i=q->front;i<=q->rear;i++)
    {
        cout<<q->arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    struct Queue *q=create(5);
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    display(q);
    fron(q);
    rea(q);
    dequeue(q);
    rea(q);
    display(q);
    fron(q);
    return 0;
}
