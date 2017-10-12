#include<bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    struct node *next;
};

void push(struct node **head,int x)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->val=x;
    newnode->next= *head;
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

void swaplist(struct node *head)
{
    struct node *curr=head;
    bool flag=true;
    while(curr->next!=NULL)
    {
        if(flag)
        {
            if(curr->val>curr->next->val)
            {
                swap(curr->val,curr->next->val);
            }
        }
        else
        {
            if(curr->val<curr->next->val)
            {
                swap(curr->val,curr->next->val);
            }
        }
        flag=!flag;
        curr=curr->next;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    struct node *head=NULL;
    push(&head,1);
    push(&head,2);
    push(&head,6);
    push(&head,8);
    push(&head,7);
    push(&head,3);
    push(&head,4);
    display(head);
    swaplist(head);
    cout<<endl;
    display(head);

    cin.tie(NULL);
    return 0;
}
