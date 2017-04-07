#include<stdio.h>
typedef struct tnode
{
    struct tnode *lchild;
    int num;
    struct tnode *rchild;
};
void inorder(struct tnode *root)
{
    if(root==NULL)
        return;
        else
        {
            inorder(root->lchild);
            printf("  %5d   ",root->num);
            inorder(root->rchild);
        }
}
void preorder(struct tnode *root)
{
    if(root==NULL)
        return;
        else
        {
            printf("%5d",root->num);
            preorder(root->lchild);
            preorder(root->rchild);
        }
}
void postorder(struct tnode *root)
{
    if(root==NULL)
        return;
        else
        {

            postorder(root->lchild);
            postorder(root->rchild);
            printf("%5d",root->num);
        }
}
struct tnode* findparent(struct tnode *root, int val)
{
    struct tnode* par;
    struct tnode* child;
    par=root;
    if(par->num>val)
        child=par->lchild;
    else
        child=par->rchild;
    while(child!=NULL)
    {
        par=child;
        if(par->num>val)
            child=par->lchild;
        else
            child=par->rchild;
    }
    return(par);
}
void addnode(struct tnode *rootptr,int val)
{
    struct tnode *nnodeptr =(struct tnode *)malloc(sizeof( struct tnode));
    nnodeptr->lchild=nnodeptr->rchild=NULL;
    nnodeptr->num=val;
    struct tnode* par;
    par=findparent(rootptr,val);
    printf("parent=%d",par->num);
    if(rootptr==NULL)  //very first node in the tree
        rootptr=nnodeptr;
    else //no left child and no right child
    {
      if(val<par->num)//to be added left
      {
           printf("\n to the left");
           (par)->lchild=nnodeptr;
      }
      else
      {
            printf("\n to the right");
            (par)->rchild=nnodeptr;
      }
    }
}
void findvalue(struct tnode *root, int val,struct tnode **parptr,struct tnode**childptrptr)
{
    struct tnode* par;
    struct tnode* child;
    par=root;
    if(par->num>val)
        child=par->lchild;
    else
        child=par->rchild;
    while(child!=NULL &&child->num!=val)
    {
        par=child;
        if(par->num>val)
            child=par->lchild;
        else
            child=par->rchild;
    }
    *parptr=par;
    *childptrptr=child;
}
void delnode(struct tnode *rootptr,int val)
{
    struct tnode* gchild;
    struct tnode* par;
    struct tnode* child;
    struct tnode* succ;
    struct tnode* parsucc;
    findvalue(rootptr,val,&par,&child);
    if(child->lchild==NULL && child->rchild==NULL)//case 0
    {
        if(val<par->num)
            par->lchild=NULL;
        else
            par->rchild=NULL;
        free(child);
    }
    else if(child->lchild==NULL || child->rchild==NULL)//case 1
    {
        if(child->lchild==NULL)
            gchild=child->rchild;
        else
            gchild=child->lchild;
        if(par->lchild==child)
        {
            par->lchild=gchild;
        }
        else
            par->rchild=gchild;
        free(child);
    }
    else if(child->lchild!=NULL && child->rchild!=NULL)
    {
        printf("In case 2");
        printf("child =%d",child->num);
        parsucc=child;
        succ=child->rchild;
        while(succ->lchild!=NULL)
        {
            parsucc=succ;
            succ=succ->lchild;
        }
        printf("succ =%d",succ->num);
        if(parsucc->lchild==succ)
            parsucc->lchild=succ->rchild;
        else
            parsucc->rchild=succ->rchild;
        child->num=succ->num;
        free(succ);
    }

}
void main()
{
    struct tnode *root=NULL,*nnodeptr;
    int val,elem;
    nnodeptr=(struct tnode*)malloc(sizeof(struct tnode));
    nnodeptr->num=100;
    nnodeptr->lchild=NULL;
    nnodeptr->rchild=NULL;
    root=nnodeptr;
    printf("\nThe inorder traversal is:\n");
    inorder(root);
    printf("\nThe preorder traversal is:\n");
    preorder(root);
    printf("\nThe postorder traversal is:\n");
    postorder(root);
    printf("\nEnter the value to be inserted\n");
    scanf("\n%d",&val);
    addnode(root,val);
    printf("\n");
    inorder(root);
    printf("\nEnter the value to be inserted\n");
    scanf("\n%d",&val);
    addnode(root,val);
    printf("\n");
    printf("\nThe inorder traversal is:\n");
    inorder(root);
    printf("\nThe preorder traversal is:\n");
    preorder(root);
    printf("\nThe postorder traversal is:\n");
    postorder(root);
    printf("\nEnter the value to be inserted\n");
    scanf("\n%d",&val);
    addnode(root,val);
    printf("\n");
    printf("\nThe inorder traversal is:\n");
    inorder(root);
    printf("\nThe preorder traversal is:\n");
    preorder(root);
    printf("\nThe postorder traversal is:\n");
    postorder(root);
    printf("\nEnter the value to be inserted\n");
    scanf("\n%d",&val);
    addnode(root,val);
    printf("\n");
    printf("\nThe inorder traversal is:\n");
    inorder(root);
    printf("\nThe preorder traversal is:\n");
    preorder(root);
    printf("\nThe postorder traversal is:\n");
    postorder(root);
    printf("\nEnter the value to be inserted\n");
    scanf("\n%d",&val);
    addnode(root,val);
    printf("\n");
    printf("\nThe inorder traversal is:\n");
    inorder(root);
    printf("\nThe preorder traversal is:\n");
    preorder(root);
    printf("\nThe postorder traversal is:\n");
    postorder(root);
    printf("\nEnter the value to be deleted\n");
    scanf("\n%d",&elem);
    delnode(root,elem);
    inorder(root);
     printf("\nEnter the value to be deleted\n");
    scanf("\n%d",&elem);
    delnode(root,elem);
    inorder(root);
     printf("\nEnter the value to be deleted\n");
    scanf("\n%d",&elem);
    delnode(root,elem);
    inorder(root);
}
