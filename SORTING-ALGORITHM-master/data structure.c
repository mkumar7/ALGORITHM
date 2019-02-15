#include <stdio.h>
#include <stdlib.h>
void random_shuffle(int arr[], int n);
void exchange_sort(int arr[], int n);
void insertion_sort(int arr[], int n);
void merge_sort(int arr[],int i,int j);
void merge(int arr[],int i1,int j1,int i2,int j2);
void quick_sort(int arr[],int i,int j);
int  divide(int arr[],int k,int l,int pivot);

int main()
{
      int n,i,choice;
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


    printf("\n 1.exchange_sort \n 2.insertion_sort \n 3.merge_sort \n 4.quick_sort");
    scanf("%d", &choice);

     for (i = 0; i < n; i++)
        arr[i] = i;
     random_shuffle(arr,n);
     printf("\n generated random number are : \n");
    for (i = 0; i < n; i++)
         printf("%d \t", arr[i]);

   switch (choice)
    {
    case 1:
     exchange_sort(arr,n);
     printf("\n sorted number are : \n");
    for (i = 0; i < n; i++)
         printf("%d \t", arr[i]);
        break;
       case 2:
        insertion_sort(arr,n);
     printf("\n sorted number are : \n");
    for (i = 0; i < n; i++)
         printf("%d \t", arr[i]);
        break;
        case 3:
    mergesort(arr,0,n-1);
     printf("\n sorted number are : \n");
    for (i = 0; i < n; i++)
         printf("%d \t", arr[i]);
        break;
        case 4:
         quicksort(arr,0,n-1);
     printf("\n sorted number are : \n");
    for (i = 0; i < n; i++)
         printf("%d \t", arr[i]);
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
void exchange_sort(int arr[], int n)
{
   int i,j,temp;
   for(i=0;i<n;i++)
    {
      for(j=0;j<n-i-1;j++)
        {
         if(arr[j]>arr[j+1])
        {
         temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
        }
    }
}
}
void insertion_sort(int arr[], int n)
 {
  int i,j,x,k;
  for(i=1;i<=n-1;i++)
    {
      j=i;
      x=arr[i];
  while(arr[j-1]>x && j>0)
  {
     arr[j]=arr[j-1];
      j=j-1;
  }
  arr[j]=x;
}
 }
void mergesort(int a[],int i,int j)
{
    int mid;

    if(i<j)
    {
        mid=(i+j)/2;
        mergesort(a,i,mid);
        mergesort(a,mid+1,j);
        merge(a,i,mid,mid+1,j);
    }
}

void merge(int a[],int i1,int j1,int i2,int j2)
{
    int temp[50];
    int i,j,k;
    i=i1;
    j=i2;
    k=0;

    while(i<=j1 && j<=j2)
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }

    while(i<=j1)
        temp[k++]=a[i++];

    while(j<=j2)
        temp[k++]=a[j++];

    for(i=i1,j=0;i<=j2;i++,j++)
        a[i]=temp[j];
}

void quicksort(int arr[],int i,int j)
{
        if(i < j) {
        int pivot = i;
            pivot = rand() % (j - i) + i ;
            pivot = divide(arr,i,j,pivot);
            quicksort(arr,i,pivot-1);
            quicksort (arr,pivot+1,j);
    }
}
int  divide(int arr[], int k,int l,int pivot){
        int itr,temp,next,next1;
        temp =arr[pivot];
        arr[pivot]=arr[k];
        arr[k]=temp;
        pivot =k;
        next =k+1;
        while(next<=l){
    if(arr[next]>arr[pivot]){
    temp = arr[next];
    next1 = next;
   while(next1!=pivot+1){
    arr[next1]=arr[next1-1];
         next1--;
        }
        arr[next1]=arr[pivot];
        arr[pivot]=temp;
            pivot++;
                }
        next++;
    }
return pivot;
}



