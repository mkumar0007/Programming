#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void push(struct node **head,int x)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=*head;
    *head=newnode;
}

struct node *rev(struct node *head,int k)
{
    struct node *cur=head,*prev=NULL,*next=NULL;
    int c=0;
    while(cur!=NULL && c<k)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
        c++;
    }
    if(next!=NULL)
    {
        head->next=rev(next,k);
    }
    return prev;
}

void display(struct node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return ;
}

int main()
{
    struct node *head=NULL;
    struct node *res=NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);
    push(&head,6);
    res=rev(head,2);
    display(res);
    return 0;
}
