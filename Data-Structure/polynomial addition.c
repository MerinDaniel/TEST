#include<stdio.h>
struct node
{
    int coeff;
    int pow;
    struct node *link;
};
void addatend(struct node **start,struct node **end,int coeff,int pow)
{
    struct node*nnodeptr=(struct node*)malloc(sizeof (struct node));
    nnodeptr->coeff=coeff;
    nnodeptr->pow=pow;
    nnodeptr->link=NULL;
    if(*start==NULL)
        *start=*end=nnodeptr;
    else
    {
        (*end)->link=nnodeptr;
        *end=nnodeptr;
    }
}
void traverse(struct node *rider,int num)
{
    printf("\n the %d th polynomial is\n",num);
    while(rider!=NULL)
    {
        if(rider->pow==0)
        {
            printf("%4d",rider->coeff);
            rider=rider->link;
        }
        else if(rider->pow==1)
        {
            printf("%4dx",rider->coeff);
            rider=rider->link;
        }
        else
        {
            printf("%4dx^%d",rider->coeff,rider->pow);
            rider=rider->link;
        }
    }
}
void polyadd(struct node *firststart,struct node*secondstart,struct node *resultstart,struct node *resultend)
{
    while(firststart!=NULL && secondstart!=NULL)
    {
        if(firststart->pow>secondstart->pow)
        {
            addatend(resultstart,resultend,firststart->coeff,firststart->pow);
            firststart=firststart->link;

        }
        else if(firststart->pow==secondstart->pow)
        {
            addatend(resultstart,resultend,(firststart->coeff+secondstart->coeff),firststart->pow);
            firststart=firststart->link;
            secondstart=secondstart->link;
        }
        else
        {
            addatend(resultstart,resultend,secondstart->coeff,secondstart->pow);
            secondstart=secondstart->link;
        }
    }
    while(firststart!=NULL)
    {
        addatend(resultstart,resultend,firststart->coeff,firststart->pow);
        firststart=firststart->link;
    }
    while(secondstart!=NULL)
    {
        addatend(resultstart,resultend,secondstart->coeff,secondstart->pow);
        secondstart=secondstart->link;
    }
}
void main()
{
    struct node *firststart=NULL,*firstend=NULL,*secondstart=NULL,*secondend=NULL,*resultstart=NULL,*resultend=NULL;
    //first=13x5+15x3+10x2+11x1
    //second=8x5+15x3+5
    addatend(&firststart,&firstend,13,5);
    addatend(&firststart,&firstend,15,3);
    addatend(&firststart,&firstend,10,2);
    addatend(&firststart,&firstend,11,1);
    traverse(firststart,1);
    addatend(&secondstart,&secondend,8,5);
    addatend(&secondstart,&secondend,15,3);
    addatend(&secondstart,&secondend,5,0);
    traverse(secondstart,2);
    polyadd(firststart,secondstart,&resultstart,&resultend);
    traverse(resultstart,3);
}
