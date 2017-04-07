#include<stdio.h>
struct node
{
    int num;
    struct node *next;
};
void addatbeg(struct node **start,int elem)
{
    struct node *nnode;
    nnode=(struct node *)malloc(sizeof(struct node));
    nnode->num=elem;
    nnode->next=*start;
    if(*start==NULL)
    {
        *start=nnode;
    }
    else
    {
        nnode->next=*start;
        *start=nnode;
    }

}
void searchlist(struct node *start,int elem)
{
    int count=0;
    if(start==NULL)
        return;
    while(start->num!=elem)
    {
        count++;
        start=start->next;
        if(start==NULL)
        {
            printf("\n%d not found",elem);
            return;
        }
    }
    printf("\nNUMBER OF COMPARISON IN LINKED LIST=%d",count);
}
void search(int elem,struct node *start,int pos)
{
    int count=1;
    if(start==NULL)
        return;
    while(start->num!=elem)
    {
        count++;
        start=start->next;
        if(start==NULL)
        {
            printf("\n%d Not found");
            return;
        }
    }
    printf("\n%d Found at pos %d And loc %d ",elem,pos,count);
    printf("\nNo. OF COMPARISON IN HASH TABLE=%d",count);
}
void display(struct node *start,int pos)
{
    printf("\n%d",pos);
    while(start!=NULL)
    {
        printf("%4d",start->num);
        start=start->next;
    }
    printf("\n");
}
void displaylist(struct node *start)
{
    int content;
    printf("Contents of the linked list is\n");
    while(start!=NULL)
    {
        content=start->num;
        printf(" %4d", content);
        start=start->next;
    }
}
void main()
{
    struct node *hashtab[10]={NULL},*start=NULL;
    int temp,p,size=10,choice,i,elem,pos;
    while(1)
    {
        printf("\n The table is\n");
        for(p=0;p<size;p++)
            display(hashtab[p],p);
        displaylist(start);
            printf("\n1.ADDITION  2.SEARCH  3.EXIT");
        printf("\n Enter your choice\n");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("\n Enter the element to be added");
            scanf("%d",&elem);
            p=elem%size;
            addatbeg(&hashtab[p],elem);
            addatbeg(&start,elem);
            for(p=0;p<size;p++)
                display(hashtab[p],p);
            displaylist(start);

        }
        else if(choice==2)
        {
            printf("\n Enter element to be searched");
            scanf("%d",&elem);
            p=elem%size;
            searchlist(start,elem);
            search(elem,hashtab[p],p);
            getch();
        }
        else
            break;



    }

}

