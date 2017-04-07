class Complex
{
	int real,img;
	Complex(int r,int i)
	{
		real=r;img=i;
	}
	void add(Complex B)
	{
		int r,i,sum;
		r=this.real+B.real;
		i=this.img+B.img;
		System.out.println("real="+r+"img"+i);
	}
	void difference(Complex B)
	{
		int r,i,difference;
		r=this.real-B.real;
		i=this.img-B.real;
		System.out.println("real="+r+"img"+i);
	}
	void product(Complex B)
	{
		int r,i,product;
		r=this.real*B.real;
		i=this.img*B.img;
		product=r*i;
		System.out.println("real="+r+"img"+i);
	}
	void division(Complex B)
	{
		int r,i,division;
		r=this.real/B.real;
		i=this.img/B.img;
		division=r/i;
		System.out.println("real="+r+"img"+i);
	}
}
class Sample
{
	public static void main(String args[])
	{
		Complex A=new Complex(4,7);
		Complex B=new Complex(2,8);
		A.add(B);
		A.difference(B);
		A.product(B);
		A.division(B);
	}
}
	