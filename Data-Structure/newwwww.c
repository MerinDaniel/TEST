#include<stdio.h>
void  del(int que[],int*front,int *back)
{
    int elem;
    elem= que[*front];
    if(*front==*back)
    {
        *front=1;
        *back=1;
    }
    else
        (*front)++;
    return elem;
}
void add(int que[],int *front;int *rear)
{

    int elem;
    printf("the element to be added")
    scanf("%d",&elem);
    if(*front==-1)
    {
        (*front)++;
        (*back)++;
    }
    else
        (* back++);
    que(*back)=elem;
}
int is empty(int front)
{
    if(*front==-1)
        return 1;
    else
        return 0;
}
int is full(int back)
{
    if(back=size-1)
        return 1;
    else
        return 0;
}
void main()
{
    int que[size],front=-1;back=-1,elem,ch;
    display(que,front,back);
    for(;;)
    {
       printf("\n main menu\n 1. addtion \n 2.deletion 3. exist\n");
       printf("enter your choice");
       scanf("%d",&ch);
       if(ch==1)
       {

           if(!is full(back))
           {
               add(que,&front,&back);
               display(que,front,back)
           }
           else
                printf("\n queue is full")
       }
    }



