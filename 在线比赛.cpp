#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct Node{
    struct Node * left;
    struct Node * right;
    struct Node * parent;
    int time;
}Node;
Node * root=NULL;
void INSERT(Node *r,int t)//r means root, t means time to insert
{
    Node *p=r;
    Node *q=NULL;
    while(p!=NULL)
    {
        q=p;
        if(t>p->time)
            p=p->right;
        else
            p=p->left;
    }
    p=(Node *)malloc(sizeof(Node));
    p->time = t;
    p->left=NULL;
    p->right=NULL;
    if(q=NULL)
    root=p;
    else if(q->time>p->time)
        q->left=p;
    else
        q->right=q;

}
Node * TREESUCCESSOR(Node *r,Node *p)
{
    Node *r = NULL;
    if(p->right!=NULL)
    {
        r=p->right;
        while(r->left!=NULL)
        {
            r=r->left;
        }
    }
    else
    {
        r=p->parent;
        while(p==r->right&&r!=NULL)
        {
            p=r;
            r=r->parent;
        }
    }
    return r;
    
}
void DELETE(Node * r,int t)
{
    Node *p=r;
    Node *q=NULL;
    while(p->time!=t&&p!=NULL)
    {
        if(p->time>t)
        {
            p=p->left;
        }
        else
        {
            p=p->right;
        }
    }
    

    


}
void READIN(int n)
{
    char buf[MAX];
    fgets(buf,MAX,stdin);
    switch (buf[0])
    {
    case 'I':
        break;
    
    case 'K':
        break;
    case 'D':
        break;
    default:
        break;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    READIN(n);
    return 0;
}