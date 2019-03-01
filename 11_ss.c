#include <stdio.h>
int main(void)
{
int n = 0,x = 0,y = 0;
scanf("%d", &n);
scanf("%d",&y);
for (int i=1;i<n;i++)
{
if ((i%2)==1)  
{
scanf("%d",&x); if (y>=x) printf("1\n"); else {printf("0\n");
}}
if ((i%2)==0){scanf("%d",&y); if(x>=y) printf("1\n"); else printf (" 0\n");}

}
}
