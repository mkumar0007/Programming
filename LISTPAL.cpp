#include<bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    struct node *next;
};

bool compare(struct node *a,struct node *b)
{
    struct node* t1=a, *t2=b;
    while(t1&&t2)
    {
        if(t1->data==t2->data)
        {
            t1=t1->next;
            t2=t2->next;
        }
        else
            return false;
    }
    if(t1==NULL && t2==NULL)
        return true;
    return false;
}

void rev(struct node **head)
{
    struct node *prev=NULL;
    struct node *cur=*head,*next;
    while(cur)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    *head=prev;
}

void push(struct node **head,char x)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=*head;
    *head=newnode;
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

bool pal(struct node *head)
{
    struct node *slow=head,*fast=head;
    struct node *slowprev=head,*sec;
    struct node *mid=NULL;
    bool res=true;
    if(head!=NULL && head->next!=NULL)
    {
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slowprev=slow;
            slow=slow->next;
        }
        if(fast!=NULL)
        {
            mid=slow;
            slow=slow->next;
        }
        sec=slow;
        slowprev->next=NULL;
        rev(&sec);
        res=compare(head,sec);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    struct node *head=NULL;
    push(&head,'r');
    push(&head,'a');
    push(&head,'d');
    push(&head,'a');
    push(&head,'r');
    display(head);
    if(pal(head))
    {
        cout<<"YES";
        return 0;
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}
