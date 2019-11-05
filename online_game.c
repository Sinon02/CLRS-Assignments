#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    struct Node * left;
    struct Node * right;
    struct Node * parent;
    int time;
    int rank;
}Node;
Node * root=NULL;
void INSERT(Node *r,int t)//r means root, t means time to insert
{
    Node *p=r;
    Node *q=NULL;
    while(p!=NULL)
    {
        q=p;
        p->rank+=1;
        if(t>p->time)
            {
                p=p->right;
            }
        else
            {
                p=p->left;
            }
    }
    p=(Node *)malloc(sizeof(Node));
    p->time = t;
    p->left=NULL;
    p->right=NULL;
    p->parent=NULL;
    p->rank=1;
    if(q==NULL)
    root=p;
    else if(q->time>p->time)
        {
            q->left=p;
            p->parent=q;
        }
    else
        {
            q->right=p;
            p->parent=q;
        }

}
Node * TREESUCCESSOR(Node *r,Node *p,int del)
{
    Node *q = NULL;
    if(p->right!=NULL)
    {
        q=p->right;
        q->rank -= del;
        while(q->left!=NULL)
        {
            q=q->left;
            q->rank -= del;
        }
    }
    else
    {
        q=p->parent;
        while(p==q->right&&q!=NULL)
        {
            p=q;
            q=q->parent;
        }
    }
    return q;
    
}
void DELETE(Node * r,int t)
{
    Node *p=r;
    Node *q=NULL;
    Node *s=NULL;
    while(p->time!=t&&p!=NULL)
    {
        p->rank-=1;
        if(p->time>t)
        {
            p=p->left;
        }
        else
        {
            p=p->right;
        }
    }// now p is point to t
    if(p->left==NULL||p->right==NULL) 
        q=p;
    else
        q= TREESUCCESSOR(r,p,1);
    if (q->left!=NULL)
        s=q->left;
    else
    {
        s=q->right;
    }
    if(s!=NULL)
    {
        s->parent=q->parent;
    }
    if(q->parent==NULL)
    {
        root=s;
    }
    else if(q->time < q->parent->time)
    {
        q->parent->left=s;
    }
    else
    {
        q->parent->right=s;
    }
    if(q!=p)
    {
        p->rank -=1;
        p->time = q->time;
    }

}
int SEARCH(Node * x,int k)
{
    int rank=0;
    if(x->left!=NULL)
    {
        rank=x->left->rank+1;
    }
    else
    {
        rank=1;
    }
    if(rank==k) 
    {
        return x->time;
    }
    else if(k<rank)
    {
        return SEARCH(x->left,k);
    }
    else
    {
        return SEARCH(x->right,k-rank);
    }
    
}
void READIN(int n)
{
    int i =0;
    while(i<n)
    {
    char c;
    i++;
    int x=0;
    scanf("%c %d",&c,&x);
    getchar();
    switch (c)
    {
    case 'I':
        INSERT(root,x);
        break;
    case 'K':
        printf("%d\n",SEARCH(root,x));
        break;
    case 'D':
        DELETE(root,x);
        break;
    default:
        printf("Unknown Symbol!\n");
        break;
    }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    READIN(n);
    return 0;
}