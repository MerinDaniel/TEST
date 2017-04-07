abstract class Figure
{
	double area;
	abstract void area(int a);
	void displayarea()
	{
		System.out.println("Area is"+area);
	}
}
class square extends Figure
{
	void area(int a)
	{
		area=a*a;
	}
}
class circle extends Figure
{
	void area(int a)
	{
		area=3.14*a*a;
	}
}
class Demo
{
	public static void main(String args[])
	{
		square sub1=new square();
		sub1.area(10);
		sub1.displayarea();
		circle sub2=new circle();
		sub2.area(20);
		sub2.displayarea();
	}
}
	

