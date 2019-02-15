#include <stdio.h>
#include <stdlib.h>
void random_shuffle(int arr[], int n);
void heap_sort(int[],int);
void heapify(int[],int);
void adjust(int[],int);
int largest(int a[], int n);
radix_sort(int arr[], int n);

int main()
{
      int n,i,j,choice;
    printf("\n enter the value of n :  ");
    scanf("%d", &n);
    if((n>0) && (n<=1000))
    {
    printf("\n enter your choice ");
    }
    else
    {
        printf("error message");
        exit(0);
    }

    int *arr= malloc(n*sizeof(int));


    printf("\n 1.heap_sort \n 2.radix_sort \n ");
    scanf("%d", &choice);

     for (i = 0; i < n; i++)
        arr[i] = i;
     random_shuffle(arr,n);
     printf("\n generated random number are : \n");
    for (i = 0; i < n; i++)
    {
        if (n<= 20)
        {
            for (j=0; j<arr[i]; j++)
                printf("*");
            printf("\n");
        }
        else
        {
         printf("%d \t", arr[i]);
        }
    }

   switch (choice)
    {
    case 1:
     heap_sort(arr,n);
     printf("\n sorted number are : \n");
    for (i = 0; i < n; i++)
    {
        if (n<= 20)
        {
            for(j=0; j<arr[i]; j++)
            printf("*");
            printf("\n");
        }
        else
        {
            printf("%d \t", arr[i]);
        }
    }
        break;
       case 2:
        radix_sort(arr,n);
     printf("\n sorted number are : \n");
    for (i = 0; i < n; i++)
    {
        if(n<= 20)
    {
        for(j=0; j<arr[i];j++)
            printf("*");
        printf("\n ");
    }
    else{
         printf("%d \t", arr[i]);
    }
    }
        break;
        default:
        printf("\n invalid choice");
        break;
    }
            return (0);
}
void random_shuffle(int arr[], int n)
{
    srand(time(NULL));
    int i, j, temp;
    for (i = n - 1; i > 0; i--)
    {
        j = rand()%(i + 1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void heap_sort(int a[],int n)
{
 int i,t;

 heapify(a,n);

 for(i=n-1;i>0;i--)
 {
  t = a[0];
  a[0] = a[i];
  a[i] = t;
  adjust(a,i);
 }
}


void heapify(int a[],int n)
{
 int k,i,j,item;

 for(k=1;k<n;k++)
 {
  item = a[k];
  i = k;
  j = (i-1)/2;

  while((i>0)&&(item>a[j]))
  {
   a[i] = a[j];
   i = j;
   j = (i-1)/2;
  }
  a[i] = item;
 }
}

void adjust(int a[],int n)
{
 int i,j,item;

 j = 0;
 item = a[j];
 i = 2*j+1;

 while(i<=n-1)
 {
  if(i+1 <= n-1)
   if(a[i] <a[i+1])
    i++;
  if(item<a[i])
  {
   a[j] = a[i];
   j = i;
   i = 2*j+1;
  }
  else
   break;
 }
 a[j] = item;
}
int largest(int a[], int n)
{
    int large = a[0], i;
    for(i = 1; i < n; i++)
    {
        if(large < a[i])
            large = a[i];
    }
    return large;
}

radix_sort(int arr[], int n)
{
    int bucket[100][100], bucket_count[100];
    int i, j, k, remainder, NOP=0, divisor=1, large, pass;

    large = largest(arr, n);
    printf("The large element %d\n",large);
    while(large > 0)
    {
        NOP++;
        large/=10;
    }

    for(pass = 0; pass < NOP; pass++)
    {
        for(i = 0; i < 100; i++)
        {
            bucket_count[i] = 0;
        }
        for(i = 0; i < n; i++)
        {
            remainder = (arr[i] / divisor) % 10;
            bucket[remainder][bucket_count[remainder]] = arr[i];
            bucket_count[remainder] += 1;
        }

        i = 0;
        for(k = 0; k < 100; k++)
        {
            for(j = 0; j < bucket_count[k]; j++)
            {
                arr[i] = bucket[k][j];
                i++;
            }
        }
        divisor *= 10;

        for(i = 0; i < n; i++)
            printf("%d  ",arr[i]);
        printf("\n");
    }
}



