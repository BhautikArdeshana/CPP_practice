class HelloWorld
{
	static {
		System.loadLibrary("hello");
	}
	private  native void sayhello();

	public static void main(String args[])
	{
		System.out.println("Hello World Bhautik");
		HelloWorld h=new HelloWorld();
		h.sayhello();
	}
}
