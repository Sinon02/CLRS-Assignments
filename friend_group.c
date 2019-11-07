#include<stdio.h>
#include<stdlib.h>
void LINK(int *A,int *R,int f1,int f2)
{
    if(R[f1]>R[f2])
    {
        A[f2]=f1;
    }
    else
    {
        if(R[f1]==R[f2])
        {
            R[f2]+=1;
        }
        A[f1]=f2;
    }
    
}
int FindSet(int *A,int x)
{
    if(x!=A[x])
    {
        A[x]=FindSet(A,A[x]);
    }
    return A[x];
}
void Union(int *A,int *R,int f1,int f2)
{
    LINK(A,R,FindSet(A,f1),FindSet(A,f2));
}
void MakeSet(int *A,int *R,int x)
{
    A[x]=x;
    R[x]=0;
}
void Build_Friend(int *A,int *R,int f1,int f2)
{
    if(A[f1]==-1)
    {
        if(A[f2]==-1)
        {
            A[f1]=f1;
            A[f2]=f1;
            R[f1]=1;
            R[f2]=0;
        }
        else
        {
            A[f1]=f2;
        }
    }
    else
    {
        if(A[f2]==-1)
        {
            A[f2]=f1;
        }
        else
        {
            Union(A,R,f1,f2);
        } 
    }
    
}
int Check_Friend(int *A,int f1,int f2)
{
    if(A[f1]==-1||A[f2]==-1)
    {
        return 0;
    }
    int p1,p2;
    p1=FindSet(A,f1);
    p2=FindSet(A,f2);
    return (p1==p2);
}
int main()
{
    int n,k,m;
    scanf("%d %d %d",&n,&k,&m);
    int * A = malloc(sizeof(int)*n); 
    int * R = malloc(sizeof(int)*n); 
    int i,f1,f2;
    for(i=0;i<n;i++) 
    {
        A[i]=-1;
    }
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&f1,&f2);
        Build_Friend(A,R,f1,f2);
    }
    for(i=0;i<k;i++)
    {
        scanf("%d %d",&f1,&f2);
        printf("%d ",Check_Friend(A,f1,f2));
    }
    return 0;
}