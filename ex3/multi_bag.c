#include<stdio.h>
#include<stdlib.h>
typedef struct Bag
{
    int wi;
    int vi;
}Bag;

int main()
{
    int n,W,num;
    scanf("%d ",&n,&W);
    int i;
    Bag * B =malloc(n*sizeof(Bag));
    int wi,vi,numi;
    num=n;
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&(B[i].wi),&(B[i].vi),&numi);
        num+=numi-1;   
    }

}
