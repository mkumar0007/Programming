#include<bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    struct node* next;
};

void push(struct node **head,int x)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->val=x;
    newnode->next=*head;
    *head=newnode;
}

void display(struct node *head)
{
    while(head)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
}

struct node* rev(struct node *head)
{
    struct node *prev=NULL,*cur=head,*next;
    while(cur)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    return prev;
}

struct node* add1util(struct node *head)
{
    struct node *res=head;
    int carry=1,sum;
    while(head!=NULL)
    {
        sum=((head->val)+carry);
        carry=sum/10;
        sum%=10;
        head->val=sum;
        head=head->next;
    }
    return res;
}

struct node* add1(struct node *head)
{
    head=rev(head);
    head=add1util(head);
    return rev(head);
}

int main()
{
    ios_base::sync_with_stdio(false);
    struct node *head=NULL;
    push(&head,9);
    push(&head,9);
    push(&head,9);
    push(&head,9);
    display(head);
    cout<<endl;
    struct node *res=add1(head);
    display(res);
    cin.tie(NULL);
    return 0;
}
