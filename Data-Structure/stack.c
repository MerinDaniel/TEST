#include <stdio.h>
void display(int stk[],int top)

{
    int p;
    printf("the content in the stack are:\n \n");
    printf("top        value");
    for(p=4;p>=0;p--)
    {
        if(top==p)
            printf("\n%3d            %d\n",stk[top],p);
        else
            printf("\n%3d            \n",stk[p]);
    }
    if(top==-1)
        printf("\n%3d",top);
}
void push(int stk[],int*top)
{
    int elem;
    printf("\n enter the element pushed: \n");
    scanf("%d",&elem);
    (*top)++;
    stk[*top]=elem;
}
int pop(int stk[],int*top)
{
    int elem=stk[*top];
    (*top)--;
    return(elem);
}
int isfull(int top)
{
    if(top==4)
        return 0;
    else
        return 1;

}
int isempty(int top)
{
    if(top==-1)
        return 1;
    else
        return 0;
}
void main()
{
    int stk[5],top=-1,choice,elem;
    display(stk,top);
    for(;;)
    {
        printf("\n enter the choice:1 push 2 pop 3 exit");
        scanf("%d",&choice);
        if(choice==1)
        {
            if(isfull(top)==1)
               push(stk,&top);
            else
                printf("\n stack is full");
            display(stk,top);
        }
        if(choice==2)
        {
            if(isempty(top)==1)
            {
                printf("stack is empty");
            }
            else

                elem=pop(stk,&top);
                printf("element to be popped is%d",elem);
                display(stk,top);


        }
        if(choice==3)
        {
            exit(0);
        }
    }
}
