#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void revers(struct Node **head)
{
    struct Node *prev=NULL;
    struct Node *cur= *head;
    struct Node *next;
    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    *head=prev;
}

void swapnodes(struct Node **head,int x,int y)
{
    if(x==y)
        return ;
    struct Node *prevX=NULL,*curX=*head;
    while(curX && curX->data != x)
    {
        prevX=curX;
        curX=curX->next;
    }
    struct Node *prevY=NULL,*curY=*head;
    while(curY && curY->data != y)
    {
        prevY=curY;
        curY=curY->next;
    }
    if(curX==NULL || curY==NULL)
        return ;
    if(prevX!=NULL)
        prevX->next=curY;
    else
        *head=curY;
    if(prevY!=NULL)
        prevY->next=curX;
    else
        *head=curX;

    struct Node *temp = curY->next;
    curY->next=curX->next;
    curX->next=temp;
    return ;
}

void insertnode(struct Node** head,int val)
{
    struct Node* newnode= (struct Node*)malloc(sizeof(struct Node));
    newnode->data=val;
    newnode->next=*head;
    *head=newnode;
    return ;
}

void append(struct Node** head,int val)
{
    struct Node* newnode= (struct Node*)malloc(sizeof(struct Node));
    newnode->data=val;
    newnode->next=NULL;
    struct Node *last=*head;
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=newnode;
    return ;
}

void insertafter(struct Node* prev,int data)
{
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    if(prev==NULL)
    {
        cout<<"PREV CANNOT BE NULL"<<endl;
        return;
    }
    newnode->next=prev;
    prev->next=newnode;
    return ;
}

void deletenode(struct Node **head,int data)
{
    struct Node *temp=*head,*prev;
    if(temp!=NULL && temp->data==data)
    {
        *head=temp->next;
        free(temp);
        return ;
    }
    while(temp!=NULL && temp->data!=data)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL || temp->next==NULL)
        return ;
    prev->next=temp->next;
    free(temp);
}

void deleteatpos(struct Node **head,int pos)
{
    struct Node *temp = *head;
    if(*head==NULL)
        return ;
    if(pos==0)
    {
        *head = temp->next;
        free(temp);
        return ;
    }
    for(int i=0;i<pos-1&&temp!=NULL;i++)
    {
        temp=temp->next;
    }
    if(temp==NULL || temp->next==NULL)
        return ;
    struct Node *next = temp->next->next;
    free(temp->next);
    temp->next=next;
    return ;
}

void display(struct Node **head)
{
    struct Node *temp = *head;
    cout<<"LINKED LIST ELEMENTS ARE  ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl<<endl<<endl;
    return ;
}

int  main()
{
    ios_base::sync_with_stdio(false);
    struct Node *head=NULL;
    int op;
    do
    {
        cout<<"ENTER THE CHOICE....."<<endl;
        cout<<"1.INSERTATBEGIN"<<endl;
        cout<<"2.INSERTAFTER"<<endl;
        cout<<"3.INSERTATEND"<<endl;
        cout<<"4.DELETEAKEY"<<endl;
        cout<<"5.DELETEAPOSITION"<<endl;
        cout<<"6.SWAPNODES"<<endl;
        cout<<"7.REVERSE"<<endl;
        cout<<"8.DISPLAY"<<endl;
        cout<<"9.EXIT"<<endl;
        cin>>op;
        int x,y,z,p,pos;
        switch(op)
        {
        case 1:
            cout<<"ENTER THE ELEMENT  :";
            cin>>x;
            insertnode(&head,x);
            display(&head);
            break;
        case 2:
            cout<<"ENTER THE ELEMENT   :";
            cin>>y;
            insertafter(head->next,y);
            display(&head);
            break;
        case 3:
            cout<<"ENTER THE ELEMENT   :";
            cin>>z;
            append(&head,z);
            display(&head);
            break;
        case 4:
            cout<<"ENTER THE ELEMENT   :";
            cin>>p;
            deletenode(&head,p);
            display(&head);
            break;
        case 5:
            cout<<"ENTER THE POSITION   :";
            cin>>pos;
            deleteatpos(&head,pos);
            display(&head);
            break;
        case 6:
        {
            int a,b;
            cout<<"ENTER THE ELEMENTS   :";
            cin>>a>>b;
            swapnodes(&head,a,b);
            display(&head);
            break;
        }
        case 7:
            revers(&head);
            display(&head);
            break;
        case 8:
            display(&head);
            break;
        case 9:
            exit(0);
        }
    }while(1);
    cin.tie(NULL);
    return 0;
}
