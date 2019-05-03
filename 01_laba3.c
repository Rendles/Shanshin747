#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
double count = 0;
double quickSort(int *numbers, int left, int right)
{
  int pivot; // разрешающий элемент
  int l_hold = left; //левая граница
  int r_hold = right; // правая граница
  pivot = numbers[left];
  while (left < right) // пока границы не сомкнутся
  {
    while ((numbers[right] >= pivot) && (left < right)){
      right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
    count++;
        
    }
    if (left != right) // если границы не сомкнулись
    {count++;
      numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
      left++; // сдвигаем левую границу вправо
      count ++;
    }
    while ((numbers[left] <= pivot) && (left < right)){
      left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
    
        count++;
    }
    
    if (left != right) // если границы не сомкнулись
    {
        count++;
      numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
      right--;
      count ++;// сдвигаем правую границу вправо
    }
  }
  numbers[left] = pivot; // ставим разрешающий элемент на место
  pivot = left;
  left = l_hold;
  right = r_hold;
  count ++;
  if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
    quickSort(numbers, left, pivot - 1);
  if (right > pivot)
    quickSort(numbers, pivot + 1, right);
}
int main()
{
int c = 19;
int a[20];
int j[20];
for (int i = 0;i < 20; i ++)
{
a[i] =  i;
j[i] = c;
c --;
} 
quickSort(a,0,19);
for (int i = 0;i<20;i++)
printf("%d ",a[i]);
printf("\n%f \n",count);
count = 0;
quickSort(j,0,19);
for (int i = 0;i<20;i++)
printf("%d ",j[i]);
printf("\n%f\n",count);
}

