
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
int count = 0;
double find(int step) 
{ 
step = (int)(step / 1.247); 
if (step < 1)
{
step = 1;
count ++;
    
}
return step; 
} 

int sort (int arr[], int N)
{
int step = N; 
while (1) 
{ 
step = find(step); 
int swap=0; 
for(int i = 0; i <N-step; i++) 
{ 
int j = i + step; 
if (arr[i] > arr[j])
{
count ++;
int t= arr[i];
arr[i]=arr[j];
arr[j]=t;
swap=1;
count++;
}
}
if (step==1 && !swap)
{count++;
break;
}
    
}
}
int main()
{
int n [200];
int c = 200;
for (int i = 0;i < 200; i ++)
{
n[i] = c;
c--;
} 
sort(n,200);

for (int i = 0;i <200;i++)
{
printf("%d ",n[i]);
}
printf("\n%d\n",count);
}

