#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    struct Node * left;
    struct Node * right;
    struct Node * parent;
    int value;
    int color; //0 means black and 1 means red
}Node;
Node * root=NULL;
Node * INSERT(Node *r,int t)//r means root, t means value to insert
{
    Node *p=r;
    Node *q=NULL;
    while(p!=NULL)
    {
        q=p;
        if(t>p->value)
            {
                p=p->right;
            }
        else
            {
                p=p->left;
            }
    }
    p=(Node *)malloc(sizeof(Node));
    p->value = t;
    p->left=NULL;
    p->right=NULL;
    p->parent=NULL;
    if(q==NULL)
    root=p;
    else if(q->value>p->value)
        {
            q->left=p;
            p->parent=q;
        }
    else
        {
            q->right=p;
            p->parent=q;
        }
    return p;

}
void RBINSERT(Node * r, int x)
{
    Node *p=NULL;
    p=INSERT(r,x);
    p->color=1;
    
}
Node * TREESUCCESSOR(Node *r,Node *p)
{
    Node *q = NULL;
    if(p->right!=NULL)
    {
        q=p->right;
        while(q->left!=NULL)
        {
            q=q->left;
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
Node * TREEPredecessor(Node *r,Node *p)
{
    Node *q = NULL;
    if(p->left!=NULL)
    {
        q=p->left;
        while(q->right!=NULL)
        {
            q=q->right;
        }
    }
    else
    {
        q=p->parent;
        while(p==q->left&&q!=NULL)
        {
            p=q;
            q=q->parent;
        }
    }
    return q;
    
}

int SEARCH(Node * r,int k)
{
    Node *p=r;
    Node *q;
    int is_left=0;
    while(p!=NULL) 
    {
        q=p;
        if(p->value==k)
        return k;
        if(k<p->value)
        {
            p=p->left;
            is_left=1;
        }
        else
        {
            p=p->right;
            is_left=0;
        }
    }
    if (is_left)
    return (TREEPredecessor(r,q)->value);
    else
    {
        return q->value;
    }
    
}
void ReadIn()
{
	int id;
	char str[100];
	char *Seq = str, *pch;
	int temp;
	while (strcmp(Seq, "EXIT"))
	{
		fgets(str, 100, stdin);
		pch = strtok(str, "\n");
		Seq = strtok(pch, " ");
		if (!strcmp(Seq, "INSERT"))
		{
			pch = strtok(NULL, " ");
			id = atoi(pch);
            INSERT(root,id);
		}
		else if (!strcmp(Seq, "FIND"))
		{
			pch = strtok(NULL, " ");
			id = atoi(pch);
            printf("%d\n",SEARCH(root,id));
		}
	}
}
int main()
{
	ReadIn();
	return 0;
}