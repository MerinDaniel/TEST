#include<stdio.h>

struct node
{
   struct node *blink;
    int num;
   struct node *flink;
};

void ftraverse(struct node *rider)    /////forward traversing
{
    printf("\n the list in the forward directions\n");
    while(rider!=NULL)
    {
        printf("%5d",rider->num);
        rider=rider->flink;
    }
}

void btraverse(struct node *rider)
{
    printf("\n the list in the backward directions\n");  ////backward traversing
    while(rider!=NULL)
    {
        printf("%5d",rider->num);
        rider=rider->blink;
    }
}

void addatbeg(struct node **startptrptr,struct node **endptrptr)   ////add at begining
{
    struct node*nnodeptr=(struct node*)malloc(sizeof(struct node));
    printf("\nenter the value to first node ");
    scanf("%d",&nnodeptr->num);
    if(*startptrptr==NULL)
    {
        nnodeptr->flink=NULL;
        nnodeptr->blink=NULL;
        *startptrptr=nnodeptr;
        *endptrptr=nnodeptr;
    }
    else
    {
        nnodeptr->blink=NULL;
        nnodeptr->flink=*startptrptr;
        (*startptrptr)->blink=nnodeptr;
        *startptrptr=nnodeptr;

    }
}

void addatend(struct node **startptrptr,struct node **endptrptr)  ////add at end
{
    struct node*nnodeptr=(struct node*)malloc(sizeof(struct node));
    printf("\nenter the value to end of node ");
    scanf("%d",&nnodeptr->num);
    if(*startptrptr==NULL)
    {
        nnodeptr->flink=NULL;
        nnodeptr->blink=NULL;
        *startptrptr=nnodeptr;
        *endptrptr=nnodeptr;
    }
    else
    {
        nnodeptr->flink=NULL;
        nnodeptr->blink=*endptrptr;
        (*endptrptr)->flink=nnodeptr;
        *endptrptr=nnodeptr;

    }
}
struct node* findpos(struct node *rider,int val)   ////finding position
{
    while(rider->num!=val)
        rider=rider->flink;
    return (rider);
};


void addafter(struct node *pos)    ////add after function
{
    struct node*nnodeptr=(struct node*)malloc(sizeof(struct node));
    printf("\nenter the value to node ");
    scanf("%d",&nnodeptr->num);
    nnodeptr->flink=pos->flink;
    nnodeptr->blink=pos;
    (pos->flink)->blink=nnodeptr;
    pos->flink=nnodeptr;
}


void addbefore(struct node *pos)   ///add before function
{
    struct node*nnodeptr=(struct node*)malloc(sizeof(struct node));
    printf("\nenter the value to node ");
    scanf("%d",&nnodeptr->num);
    nnodeptr->flink=pos;
    nnodeptr->blink=(pos->blink);
    (pos->blink)->flink=nnodeptr;
    pos->blink=nnodeptr;

}
void deletebeg(struct node **startptrptr,struct node **endptrptr)    ///delete at  begining
{
    int temp;
    temp=*startptrptr;
    *startptrptr=(*startptrptr)->flink;
    (*startptrptr)->blink=NULL;
    free(temp);

}
void deleteend(struct node **startptrptr,struct node **endptrptr)  ///delete  at end
{
    int temp;
    temp=*startptrptr;
    *endptrptr=(*endptrptr)->blink;
    (*endptrptr)->flink=NULL;
    free(temp);
}


void deletenode(int value,struct node *pos,struct node **startptrptr,struct node **endptrptr)  ///delete any node
{
    int elem,flag=0;

    while(pos!=NULL)
    {
        if(pos->num==value)
        {
            flag=1;
            break;
        }
        else
            pos=pos->flink;
    }
    if(flag==1)
    {
        if(pos!=*startptrptr&&pos!=*endptrptr)
        {
            (pos->blink)->flink=pos->flink;
            (pos->flink)->blink=pos->blink;
        }
        else if(pos==(*startptrptr))
        {
            if((*startptrptr)==(*endptrptr))
            {
                *startptrptr=*endptrptr=NULL;
            }
            else
            {
                *startptrptr=(*startptrptr)->flink;
                (*startptrptr)->blink=NULL;
            }
        }
        else
        {
            *endptrptr=(*endptrptr)->blink;
            (*endptrptr)->flink=NULL;
        }
    }
    else
    {
        printf("no such element");
    }

}



void main()    ///main function
{
    int val,ch,pos,temp;
    struct node *start=NULL,*end=NULL;
    ftraverse(start);
    btraverse(end);

    while(1)
    {
        printf("\nenter choice\n1.add at beg\t2.add at end\t 3.add after\t 4.add before\t5.deletebegining\t6.deleteend\t7.deletenode\t8exit\t");
        scanf("%d",&ch);
        if(ch==1)
        {
            addatbeg(&start,&end);
            ftraverse(start);
            btraverse(end);


        }
        if(ch==2)
        {
            addatend(&start,&end);
            ftraverse(start);
            btraverse(end);

            addatend(&start,&end);
            ftraverse(start);
            btraverse(end);
        }
        if(ch==3)
        {
            printf("\nenter the node after which new node to be added  ");
            scanf("%d",&val);
            struct node *pos=findpos(start,val);
            addafter(pos);
            ftraverse(start);
            btraverse(end);

        }
        if(ch==4)
        {
            printf("\nenter the node before which new node to be added  ");
            scanf("%d",&val);
            struct node *pos=findpos(start,val);
            addbefore(pos);
            ftraverse(start);
            btraverse(end);
        }
        if(ch==5)
        {
            deletebeg(&start,&end);
            ftraverse(start);
            btraverse(end);

        }
        if(ch==6)
        {
            deleteend(&start,&end);
            ftraverse(start);
            btraverse(end);

        }
        if(ch==7)
        {
            printf("\nenter the node to be deleted ");
            scanf("%d",&val);
            struct node *pos=findpos(start,val);

            deletenode(val,&pos, &start, &end);
            ftraverse(start);
            btraverse(end);
        }
        if(ch==8)
        {
            break;
        }
    }












}


