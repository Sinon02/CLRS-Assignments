#include<stdio.h>
#include<stdlib.h>
// if [a,b] overlap with [c,d] then [a,c,b,d]
typedef struct Node 
{
    int value;
    int dir; // 0 means left and 1 means right
    struct Node *left;
    struct Node *right;
    struct Node *parent;
    int color; //0 means black and 1 means red
}Node;

Node *root = NULL;
Node *IF_INSERT(Node *r, int t) //this function is to return a his parent if I insert it
{
    Node *p = r;
    Node *q = NULL;
    while (p != NULL)
    {
        q = p;
        if (t > p->value)
        {
            p = p->right;
        }
        else
        {
            p = p->left;
        }
    }
    return q;
}
Node *INSERT(Node *r, int t,int dir) //r means root, t means value to insert
{
    Node *p = NULL;
    Node *q = NULL;
    q=IF_INSERT(r,t);
    p = (Node *)malloc(sizeof(Node));
    p->value = t;
    p->left = NULL;
    p->right = NULL;
    p->parent = NULL;
    p->dir = dir;
    if (q == NULL)
        root = p;
    else if (q->value > p->value)
    {
        q->left = p;
        p->parent = q;
    }
    else
    {
        q->right = p;
        p->parent = q;
    }
    return p;
}
void LeftRotate(Node *p)
{
    Node *q = p->right;
    p->right = q->left;
    if (q->left != NULL)
        q->left->parent = p;
    q->parent = p->parent;
    if (p->parent == NULL)
    {
        root = q;
    }
    else if (p == p->parent->left)
    {
        p->parent->left = q;
    }
    else
    {
        p->parent->right = q;
    }
    q->left = p;
    p->parent = q;
}
void RightRotate(Node *p)
{
    Node *q = p->left;
    p->left = q->right;
    if (q->right != NULL)
    {
        q->right->parent = p;
    }
    q->parent = p->parent;
    if (p->parent == NULL)
    {
        root = q;
    }
    else if (p->parent->left == p)
    {
        p->parent->left = q;
    }
    else
    {
        p->parent->right = q;
    }
    q->right = p;
    p->parent = q;
}
int Color(Node *p)
{
    if(p==NULL)
        return 0;
    else
        return p->color;
}
void RBINSERT(Node *r, int x,int dir)
{
    Node *p = NULL;
    Node *q = NULL;
    p = INSERT(r, x,dir);
    p->color = 1;
    while (p != root && (Color(p->parent) == 1))
    {
        if (p->parent == p->parent->parent->left)
        {
            q = p->parent->parent->right;
            if (Color(q) == 1)
            {
                p->parent->color = 0;
                q->color = 0;
                p->parent->parent->color = 1;
                p = p->parent->parent;
            }
            else
            {
                if (p == p->parent->right)
                {
                    p = p->parent;
                    LeftRotate(p);
                }
                p->parent->color = 0;
                p->parent->parent->color = 1;
                RightRotate(p->parent->parent);
            }
        }
        else
        {
            q = p->parent->parent->left;
            if (Color(q) == 1)
            {
                p->parent->color = 0;
                q->color = 0;
                p->parent->parent->color = 1;
                p = p->parent->parent;
            }
            else
            {
                if (p == p->parent->left)
                {
                    p = p->parent;
                    RightRotate(p);
                }
                p->parent->color = 0;
                p->parent->parent->color = 1;
                LeftRotate(p->parent->parent);
            }
        }
    }
    root->color = 0;
}
Node *TREESUCCESSOR(Node *r, Node *p)
{
    Node *q = NULL;
    if (p->right != NULL)
    {
        q = p->right;
        while (q->left != NULL)
        {
            q = q->left;
        }
    }
    else
    {
        q = p->parent;
        while ( q != NULL&& p == q->right)
        {
            p = q;
            q = q->parent;
        }
    }
    return q;
}
Node *TREEPredecessor(Node *r, Node *p)
{
    Node *q = NULL;
    if (p->left != NULL)
    {
        q = p->left;
        while (q->right != NULL)
        {
            q = q->right;
        }
    }
    else
    {
        q = p->parent;
        while (q != NULL&&p == q->left)
        {
            p = q;
            q = q->parent;
        }
    }
    return q;
}
int Judge_Overlap(Node *r,int left,int right)
{
    if(root==NULL)
    {
        return 0;
    }
    Node *p=IF_INSERT(r,left);
    Node *t=TREESUCCESSOR(r,p);
    Node *q=TREEPredecessor(r,p);
    if(q==NULL||t==NULL)
    {
        if(q==NULL&&t==NULL)
        {
            printf("error!");
        }
        if(q==NULL)// now we should judge [left,right] and [p,t]
        {
            if(left<=t->value&&p->value<=right)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
        else //now we should judge [left,right] and [q,p]
        {
            if(left<=p->value&&q->value<=right)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }

    }
    else
    {
        if(p->dir==0)
        {
            if(left>q->value&&right<p->value)
            {
                return 0;
            }
            else
            {
                return -1;
            }
            
        }
        else
        {
            if(left>p->value&&right<t->value)
            {
                return 0;
            }
            else
            {
                return -1;
            }
            
        }
        
        
    }
    


}
int main()
{
    FILE *fr = fopen("10.in", "r");
    FILE *fw = fopen("10_out.out", "w");
    int num=0;
    fscanf(fr,"%d", &num);
    // scanf("%d", &num);
    int a,b,i,result;
    for(i=0;i<num;i++)
    {
        fscanf(fr,"%d %d",&a,&b);
        // scanf("%d %d",&a,&b);
        result= Judge_Overlap(root,a,b);
        if(result==0)
        {   RBINSERT(root,a,0);
            RBINSERT(root,b,1);
            fprintf(fw,"0\n");
            // printf("0\n");
        }
        else
        {
            fprintf(fw,"-1\n");
            // printf("-1\n");
        }
    }
    fclose(fr);
    fclose(fw);
    return 0;
}