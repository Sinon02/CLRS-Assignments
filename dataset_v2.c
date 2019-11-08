#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
    struct Node *left;
    struct Node *right;
    struct Node *parent;
    int value;
    int color; //0 means black and 1 means red
} Node;
Node *root = NULL;
Node *INSERT(Node *r, int t) //r means root, t means value to insert
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
    p = (Node *)malloc(sizeof(Node));
    p->value = t;
    p->left = NULL;
    p->right = NULL;
    p->parent = NULL;
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
void RBINSERT(Node *r, int x)
{
    Node *p = NULL;
    Node *q = NULL;
    p = INSERT(r, x);
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
        while (p == q->right && q != NULL)
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

int SEARCH(Node *r, int k)
{
    Node *p = r;
    Node *q;
    int is_left = 0;
    while (p != NULL)
    {
        q = p;
        if (p->value == k)
            return k;
        if (k < p->value)
        {
            p = p->left;
            is_left = 1;
        }
        else
        {
            p = p->right;
            is_left = 0;
        }
    }
    if (is_left)
    {
        Node *x = TREEPredecessor(r, q);
        if(x)
            return (x->value);
        else
            return 0;
    }
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
    while (strcmp(Seq, "EXIT"))
    {
        fgets(str, 100, stdin);
        pch = strtok(str, "\n");
        Seq = strtok(pch, " ");
        if (!strcmp(Seq, "INSERT"))
        {
            pch = strtok(NULL, " ");
            id = atoi(pch);
            RBINSERT(root, id);
        }
        else if (!strcmp(Seq, "FIND"))
        {
            pch = strtok(NULL, " ");
            id = atoi(pch);
            printf("%d\n", SEARCH(root, id));
        }
    }
}
int main()
{
    ReadIn();
    return 0;
}