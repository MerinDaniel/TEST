#include<stdio.h>
#define size 4

void display(int que[],int front,int back)
{
    int i;
    printf(" \nthe elem in que are  \n");
    for( i=0;i<4;i++)
        printf(" %4d ",que[i]);
    printf("\n front=%d and back =%d",front,back);
}
void add(int que[size],int *front,int *back)
{


    int elem;
    printf("the element to be added");
    scanf("%d",&elem);
    if((*front)==-1)
    {
        (*front)++;
        (*back)++;
        que[*back]=elem;
    }
    else
    {

        (*back)++;
        que[*back]=elem;
    }
}
int isempty(int front)
{
    if((front)==-1)
        return 1;
    else
        return 0;
}
int isfull(int back)
{
    if(back==size-1)
        return 1;
    else
        return 0;
}
void  del(int que[],int*front,int *back)
{
    int elem;
    elem= que[*front];
    printf("deleted element is %d",elem);
    if(*front==*back)
    {
        *front=-1;
        *back=-1;
    }
    else
        (*front)++;
    return elem;
}

void main()
{
    int que[size],front=-1,back=-1,elem,ch;

      display(que,front,back);

    for(;;)
    {
       printf("\n MAIN MENU\n 1. ADDITION \n 2.DELETION 3. EXIT\n");
       printf("\n ENTER YOUR CHOICE\n");
       scanf("%d",&ch);
       if(ch==1)
       {

           if(isfull(back)==0)
           {
               add(que,&front,&back);
               display(que,front,back);
           }
           else
                printf("\n queue is full");
       }
       else if(ch==2)
       {

           if(isempty(front)==0)
           {
               del(que,&front,&back);
               display(que,front,back);
           }
           else
                printf("\n queue is empty");
       }
       else
            exit(0);
    }

}
