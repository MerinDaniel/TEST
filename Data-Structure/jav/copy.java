import java.io.*;
class copy
{
	public static void main(String args[])
	{
		int b;
		try
		{
			FileInputStream fin=new FileInputStream("1.txt");
			FileOutputStream fout=new FileOutputStream("2.txt");
			b=fin.read();
			while(b!=-1)
			{
				fout.write((char)b);
				b=fin.read();
			}
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
}	}

		