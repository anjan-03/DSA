#include<stdio.h>
#include<stdlib.h>

#define MAX 5
int cur_size = 0;


void swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int val, int * heap_arr)
{
    int i = cur_size;
    if(cur_size == 0)
    {
        heap_arr[0] = val;
        cur_size++;
        return;
    }
    heap_arr[cur_size] = val;
    while(i!=0 && heap_arr[i] > heap_arr[(i-1)/2])
    {
        swap(&heap_arr[i], &heap_arr[(i-1)/2]);
        i = (i-1)/2;
    }
    heap_arr[i] = val;
    cur_size++;
}

void getMax(int * heap_arr)
{
    if(cur_size == 0)
    {
        printf("Empty heap\n");
        return;
    }
    printf("\nMax element: %d\n", heap_arr[0]);
}

int max_child(int index, int * heap_arr)
{
        if(heap_arr[2*index + 1] > heap_arr[2*index + 2])
            return 2*index+1;
        else
            return 2*index+2;
 }

void extractMax(int * heap_arr)
{
    int i = 0;
    if(cur_size == 0)
    {
        printf("Empty heap\n");
        return;
    }
    int temp = heap_arr[0];
    heap_arr[0] = heap_arr[cur_size - 1];
    cur_size--;
    while(i < cur_size && heap_arr[i] < heap_arr[max_child(i, heap_arr)])
    {
        int max = max_child(i, heap_arr);
        swap(&heap_arr[i], &heap_arr[max_child(i, heap_arr)]);
        i = max;
    }
}

void display(int * heap_arr)
{
    int i;
    for(i=0; i<cur_size; i++)
        printf("%d ", heap_arr[i]);
    printf("\n");
}


void increaseKey(int index, int val, int* heap_arr)
{
    if(index > cur_size-1)
        printf("Invalid index\n");
    heap_arr[index] = val;
    while(index!=0 && heap_arr[index] > heap_arr[(index-1)/2])
    {
        swap(&heap_arr[index], &heap_arr[(index-1)/2]);
        index = (index-1)/2;
    }
}


void del(int * heap_arr)
{
    int i;
    printf("Enter the index to be deld: \n");
    scanf("%d", &i);
    increaseKey(i, heap_arr[0]+1, heap_arr);
    extractMax(heap_arr);
}


int main()
{
    int i, index, val;
    int arr[] = {9, 5, 4, 2, 1};
    int * heap_arr = (int *)malloc(sizeof(int)*MAX);
    int ch = 1;
    for(i=0; i<MAX; i++)
        insert(arr[i], heap_arr);
    display(heap_arr);
    while(ch!=-1)
    {
        printf("\n\n1. Get the maximum element\n");
        printf("2. Extract the maximum element\n");
        printf("3. Increase the key\n");
        printf("4. Insert an element\n");
        printf("5. del an element\n");
        printf("Enter you choice(-1 to exit): \n");
        scanf("%d", &ch);
        if(ch==1)
            getMax(heap_arr);
        else if(ch == 2)
            extractMax(heap_arr);
        else if(ch==3)
        {
            printf("Enter an index to increase its value \n");
            scanf("%d", &index);
            printf("Enter the new value: \n");
            scanf("%d", &val);
            increaseKey(index, val, heap_arr);
        }
        else if(ch==4)
        {
           printf("Enter the element: \n");
           scanf("%d", &val);
           insert(val, heap_arr);
        }
        else if(ch==5)
            del(heap_arr);
        display(heap_arr);
    }
    free(heap_arr);  
    return(0);
}