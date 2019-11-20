#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	unsigned int id ;
	unsigned int math ;
	unsigned int english ;
	unsigned int total ;
}Student;

void swap(Student *s1, Student *s2)
{
	Student temp;
	temp = *s2;
	*s2 = *s1;
	*s1 = temp;
}

int main()
{
	int n=0,i=0,j=0;
	unsigned int id,math,english,total;
	int total_l,total_e,math_l,math_e,english_l,english_e,id_l,id_e; 
	Student * students;
	Student temp;
	scanf("%d",&n);
	getchar();
	students =(Student *)malloc(n*sizeof(Student));
	for(i=0;i<n;i++)
	{
		scanf("%u %u %u",&id,&math,&english);
		students[i].id = id;
		students[i].math = math;
		students[i].english = english;
		students[i].total = math + english;
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			total_l = (students[j].total < students[j+1].total);
			total_e = (students[j].total == students[j+1].total);
			math_l = (students[j].math < students[j+1].math);
			math_e = (students[j].math == students[j+1].math);
			english_l = (students[j].english < students[j+1].english);
			english_e = (students[j].english == students[j+1].english);
			id_l = (students[j].id < students[j+1].id);
			id_e = (students[j].id == students[j+1].id);
			if(total_l||(total_e&&math_l)||(total_e&&math_e&&english_l)||(total_e&&math_e&&english_e&&id_l))
			{
				swap(&students[j],&students[j+1]);
			}
						
		}
	}
	
	for(i=0;i<n;i++)
	{
		if(i!=n-1)
		printf("%u ",students[i].id);
		else
		printf("%u",students[i].id);
	}
	
	free(students);
	
	return 0;
} 
