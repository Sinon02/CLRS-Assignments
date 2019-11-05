#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int num;
	int freq;
}Input;
int main()
{
	int i=0,j=0,n=0,valid_num=0,pos=0,num=0;
	Input value;
	scanf("%d",&n);
	getchar();
	Input * Num = (Input *)malloc(n*sizeof(Input));
	for (i=0;i<n;i++)
	{
		Num[i].num = 0;
		Num[i].freq = 0;
	}
	for (i=0;i<n;i++)
	{
		scanf("%d",&num);
		getchar();
		pos = valid_num;
		for(j=0;j<valid_num;j++)
		{
			if(Num[j].num == num)
			{	pos = j;
				valid_num--; 
				break;
			}
		}
		Num[pos].num = num;
		Num[pos].freq ++;
		valid_num++;
	}
	
	for(i=0;i<valid_num;i++)
	{
		for(j=0;j<valid_num-i;j++)
		{
			if(Num[j].freq<Num[j+1].freq)
			{
				value = Num[j];
				Num[j] = Num[j+1];
				Num[j+1] = value;
			}
			else if (Num[j].freq == Num[j+1].freq)
			{
				if(Num[j].num > Num[j+1].num)
				{
					value = Num[j];
					Num[j] = Num[j+1];
					Num[j+1] = value;
				}
			}
		}
	}
	for(i=0;i<valid_num;i++)
	{
		printf("%d %d\n",Num[i].num,Num[i].freq);
	}
	
	return 0;
} 
