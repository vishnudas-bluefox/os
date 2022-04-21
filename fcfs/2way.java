SERVER
import java.net.*;
import java.io.*;
public class server{
public static void main(String args[]) throws
IOException
{
ServerSocket ss=new ServerSocket(5000);
Socket s=ss.accept();
PrintWriter out=new
PrintWriter(s.getOutputStream(),true);
BufferedReader in=new BufferedReader(new
InputStreamReader(s.getInputStream()));
while(true){
String a=in.readLine();
System.out.println("clint says:"+a);
out.println(a);
}
}
}
CLIENT
import java.net.*;
import java.io.*;
public class client{
public static void main(String arg[]){
Socket s=new Socket("localhost",5000);
PrintWriter out=new
PrintWriter(s.getOutputStream(),true);
BufferedReader in=new BufferedReader(new
InputStreamReader(s.getInputStream()));
BufferedReader kln=new BufferedReader(new
InputStreamReader(System.in));
while(true)
{
String userInput=kln.readLine();
out.println(userInput);
System.out.println("server says:"+in.readLine());
}
}
}