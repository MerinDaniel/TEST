#include <stdio.h>
//#include <alloc.h>

struct node
{
    int num;
    struct node *next;
};

void display(struct node *start)
{
    int content;
    printf("Contents of the linked list is\n");
    while (start!=NULL)
    {
        content=start->num;
        printf("%4d", content);
        start=start->next;
    }
}

struct node* addatbeg(struct node *start)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node*));
    int elem;
    printf("\nEnter element to insert to beg of linked list\n");
    scanf("%d", &elem);
    newnode->num=elem;
    newnode->next=start;
    start=newnode;
    return (start);


}


struct node* findpos(struct node *rider, int elem)
{
    while (rider->num!=elem)
    {
        rider=rider->next;
    }
    return (rider);
}

int isthere(struct node *rider, int elem)
{
    int flag=0;
    while (rider!=NULL)
    {
        if (rider->num==elem)
            flag=1;
        rider=rider->next;
    }

    if (flag==1)
        return 1;
    else
        return 0;
}

struct node* delatbeg(struct node *start)
{
   int elem;
   elem=start->num;
   printf("\nDeleted element is %d", elem);
   start=start->next;
   return(start);
}

struct node* delatend(struct node *start)
{
   int elem;
   while (start->next->next!=NULL)
   {
       start=start->next;
   }
   elem=start->num;
   printf("\nDeleted element is %d", elem);
   start->next=NULL;
   return(start);
}

struct node* insertafter(struct node *start, int el)
{
    int data;
    printf("Enter");
    while (start->num!=el)
    {
        start=start->next;
    }
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node*));
    printf("\nEnter element to insert to linked list\n");
    scanf("%d", &data);
    newnode->num=data;
    /*newnode->next=start;
    start=newnode;
    return (start);
    */
}


void main()
{
    struct node *start=NULL, *newnode, *end=NULL, *pos;
    display(start);

    //Initialising first node
    newnode=(struct node*)malloc(sizeof(struct node*));
    int elem, ch;
    printf("\nEnter element to insert to linked list\n");
    scanf("%d", &elem);
    newnode->num=elem;
    newnode->next=NULL;
    start=newnode;
    end=newnode;
    display(start);


    do//Interactive Menu
    {
        printf("\nSelect an option\n");
        printf("1) Addtobeg 2) Addtoend 3) Display 4) Find POS 5) Delete from start 6) Delete from end 7) Insert after 10)Exit\n");
        scanf("%d", &ch);

        if (ch==1)
        {
            start=addatbeg(start);
            display(start);
        }

        else if (ch==2)
        {
            end=addatend(end);
            display(start);
        }

        else if (ch==3)
        {

            display(start);
        }

        else if (ch==4)
        {
            int val, check1;
            printf("Enter element to search\n");
            scanf("%d", &check1);
            val=isthere(start, check1);
            printf("%d \n", val);
            display(start);
            if (val==1)
            {
                pos=findpos(start, check1);
                printf("\nPosition: %u", pos);
            }


            else
                printf("\nElement not found\n");
        }

        else if (ch==5)
        {
            start=delatbeg(start);
            display(start);
        }

        else if (ch==6)
        {
            end=delatend(start);
            display(start);
        }

        else if (ch==7)
        {
            int el;
            printf("Which element must the node be entered after\n");
            scanf("%d", &el);
            if (isthere(start, el)==1)
            {
                insertafter(start, el);
                display(start);
            }
            else
                printf("Element not found");

        }
    }while(ch!=10);

}
