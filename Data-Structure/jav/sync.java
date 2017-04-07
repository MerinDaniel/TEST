class Callee
{
	void call(String msg)
	{
		try
		{
			System.out.println("[" +msg);
			Thread.sleep(1000);
		}
		catch(Interrupted Exception e)
		{
			System.out.println("e);
		}
		System.out.println(" ]");
		}
}
class caller implements Runnable
{
	callee target;
	Thread t;
	String message;
	caller(caller t,string msg)
	{
		t=new Thread(this);
		target=c;
		message=msg;
		t.start();
	}
	public void run()
	{
		target.call(message);
	}
}
class Thread sync Demo
{
	Public static void main(String args[]);
	{
		callee t=new callee();
		caller c1=new caller(t,"hello");
		caller c2=new caller(t,"synchronized");
		caller c3=new caller (t,"world");
		try
		{
			c1.join();
			c2.join();
			c3.join();
		}
		catch(Interrupted Exception e)
		{
			System.out.println(e);
		}
	}
}
