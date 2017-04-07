class Complex
{
	int real,img;
	Complex(int r,int i)
	{
		real=r,img=i;
	}
void add(Complex B)
{
	int r,i,sum;
	r=real+B.real;
	i=img+B.img;
	sum=r+i;
	System.out.println("real"=+real+"img"+img);
}
void difference(Complex B)
{
	int r,i,difference;
	r=real-B.real;
	img=img-B.real;
	difference=r-i;
	System.out.println("real"=+real+"img"+img);
}
void product(Complex B)
{
	int r,i,product;
	r=real*B.real;
	i=img*B.img;
	product=r*i;
	System.out.println("real"=+real+"img"+img);
}
void division(Complex B)
{
	int r,i,division;
	r=real/B.real;
	i=img/B.img;
	division=r/i;
	System.out.println("real"=+real+"img"+img);
}
class Sample
{
	public static void main(String args[])
	Complex A=new Complex(4,7);
	Complex B=new Complex(2,8);
	A.add(B);
	A.difference(B);
	A.product(B);
	A.division(B);

	