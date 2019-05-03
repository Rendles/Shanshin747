#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
double count = 0;
// Функция "просеивания" через кучу - формирование кучи
void siftDown(int *numbers, int root, int bottom)
{
  int maxChild; // индекс максимального потомка
  int done = 0; // флаг того, что куча сформирована
  // Пока не дошли до последнего ряда
  while ((root * 2 <= bottom) && (!done)) 
  {
    if (root * 2 == bottom) 
    {// если мы в последнем ряду,
      maxChild = root * 2;
      count++;
        
    }// запоминаем левый потомок
    // иначе запоминаем больший потомок из двух
    else if (numbers[root * 2] > numbers[root * 2 + 1])
     { maxChild = root * 2; count++;}
    else
      {maxChild = root * 2 + 1;count++;}
    // если элемент вершины меньше максимального потомка
    if (numbers[root] < numbers[maxChild]) 
    { count ++;
      int temp = numbers[root]; // меняем их местами
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
      count++;
    
    }
    else // иначе
      done = 1; // пирамида сформирована
  }
}
// Функция сортировки на куче
double heapSort(int *numbers, int array_size) 
{
  // Формируем нижний ряд пирамиды
  for (int i = (array_size / 2) - 1; i >= 0; i--)
    siftDown(numbers, i, array_size - 1);
  // Просеиваем через пирамиду остальные элементы
  for (int i = array_size - 1; i >= 1; i--)
  {
      count++;
    int temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    siftDown(numbers, 0, i - 1);
  }
}
int main()
{
int c = 200;
int a[200];
int j[200];
for (int i = 0;i < 200; i ++)
{
a[i] =  i;
j[i] = c;
c --;
} 
heapSort(a,200);
for (int i = 0;i<200;i++)
printf("%d ",a[i]);
printf("\n%f \n",count);
count = 0;
heapSort(j,200);
for (int i = 0;i<200;i++)
printf("%d ",j[i]);
printf("\n%f\n",count);
}
