#include<stdio.h>
#include<stdlib.h>
unsigned long Hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

int main()
{
    int n,k,i;
    unsigned char str[6];
    unsigned long *Input=(unsigned long *)malloc(sizeof(unsigned long)*n);
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    {
        scanf("%s",str);
        Input[i] = Hash(str);
    }
    

}