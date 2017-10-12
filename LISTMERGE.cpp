#include<bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    struct node* next;
};

struct node *merge(struct node *a,struct node *b)
{
    struct node *result;
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;
    if(a->val<=b->val)
    {
        result=a;
        result->next=merge(a->next,b);
    }
    else
    {
        result=b;
        result->next=merge(a,b->next);
    }
    return result;
}

void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =        (struct node*) malloc(sizeof(struct node));

    /* put in the data  */
    new_node->val  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

void display(struct node *head)
{
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    return ;
}
int main()
{
    ios_base::sync_with_stdio(false);
    struct node *a=NULL;
    struct node *b=NULL;
    struct node *res=NULL;
 push(&a, 15);
    push(&a, 10);
    push(&a, 5);

    push(&b, 20);
    push(&b, 3);
    push(&b, 2);
  /*  int x,y;
    cout<<"Enter size of a";
    cin>>x;
    for(int i=0;i<x;i++)
    {
        cin>>y;
        push(&a,y);
    }
    display(a);
    int p,q;
    cout<<"Enter size of b";
    cin>>p;
    for(int i=0;i<p;i++)
    {
        cin>>q;
        push(&b,q);
    }
    display(b);
    */
    res=merge(a,b);
    display(res);
    cin.tie(NULL);
    return 0;
}
