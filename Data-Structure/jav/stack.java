class stack
{
	int stk[6],top=-1,elem;
}
void push()
{
	if(top==5)
		System.out.println("stack is full);
	else
		(top)++;
		stack[top]=elem;
}
void pop()
{
	if(top==-1)
		System.out.println("stack is empty");
	else
		elem=stack[top];
		(top)--;
}
void display(int stk[],int top)

{
    int p;
    System.out.println("the content in the stack are:\n \n");
    System.out.println("top        value");
    for(p=6;p>=0;p--)
    {
        if(top==p)
		System.out.println("stack[p]");
	else
		
 
public static void main(String args)
{
	int stk[6],top=-1,elem,choice;
	
  