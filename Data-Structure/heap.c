#include<stdio.h>
void insert(int *heap,int *p)
{
    int elem,c,temp;
    c=(*p);
    printf("enter the element");
    scanf("%d",&elem);
    heap[*p]=elem;
    (*p)++;

    while(c/2!=0)
    {
        if(heap[c]>heap[c])
        {
            temp=heap[c];
            heap[c]=heap[c];
            heap[c]=temp;
        }
        c=c/2;
    }
}
void deletion(int *heap,int *p)
{
    int r,temp;
    (*p)--;
    heap[1]=heap[*p];
    r=1;
    while((2*r)<(*p))
    {
        if(heap[2*r]>heap[2*r+1])
        {
            if(heap[r]<heap[2*r])
            {
                temp=heap[r];
                heap[r]=heap[r*2];
                heap[r*2]=temp;
            }
            r=r*2;
        }
        else
        {
            if(heap[r]<heap[2*r+1])
            {
                temp=heap[r];
                heap[r]=heap[r*2+1];
                heap[r*2+1]=temp;
            }
            r= r*2+1;
        }
    }
}
void display(int heap[],int p)
{
    int i;
    printf("\nthe heap is\n");
    for(i=1;i<p;i++)
    {
        printf("%4d\n",heap[i]);
    }
}
void main()
{
    int heap[10],p=1;
    insert(heap,&p);
    insert(heap,&p);
    insert(heap,&p);
    insert(heap,&p);
    insert(heap,&p);
    display(heap ,p);
    printf("\nafter deletion");
    getch();
    deletion(heap,&p);
    getch();
    display(heap ,p);
    deletion(heap,&p);
    getch();
    display(heap ,p);
    deletion(heap,&p);
    getch();
    display(heap ,p);
    deletion(heap,&p);
    getch();
    display(heap ,p);
    deletion(heap,&p);
    getch();
    display(heap ,p);
}
