class MyThread extends Thread
{
	String name;
	MyThread(String nam)
	{
		super(nam);
		name=nam;
		System.out.println("presently executing"+name);
		start();
	}
	
	public void run()
	{
		try
		{
			if(name=="one")
				for(int i=0;i<5;i++)
				{
					System.out.println("First count : "+i);
					Thread.sleep(500);
				}
			if(name=="two")
				for(int i=0;i<5;i++)
				{
					System.out.println("Second count : "+i);
					Thread.sleep(500);
				}
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	
	}
}
class Demo
{
	public static void main(String args[])
	{
		MyThread t2 = new MyThread("one");
		MyThread t1 = new MyThread("two");
		try
		{
			t1.join();
			t2.join();
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
}

			
		 