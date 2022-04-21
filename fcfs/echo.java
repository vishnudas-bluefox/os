import java.net.*;
import java.io.*;
public class Server1
{
public static void main(String arg[]) throws IOException
{
ServerSocket serverSocket=null;
int port=1212;
try
{
serverSocket= new ServerSocket(port);
}
catch(IOException e)
{
System.err.println("Could not listern on port:"+port);
System.exit(1);
}
Socket clientSocket=null;
System.out.println(" connecting.......");
try
{
clientSocket=serverSocket.accept();
}
catch(IOException e)
{
System.err.println("Accept failed.");
System.exit(1);
}
System.out.println("connection successful");
System.out.println("waiting for input......");
PrintWriter out=new
PrintWriter(clientSocket.getOutputStream(),true);
BufferedReader in=new BufferedReader(new
InputStreamReader(clientSocket.getInputStream()));
String inputLine;
BufferedReader stdIn=new BufferedReader(new
InputStreamReader(System.in));
String userInput;
while((inputLine=in.readLine()) !=null)
{
System.out.println("Client Say:"+inputLine);
userInput=stdIn.readLine();
out.println(userInput);
if(inputLine.equals("quit"))
break;
}
out.close();
in.close();
stdIn.close();
clientSocket.close();
serverSocket.close();
}
}
CLIENT
import java.net.*;
import java.io.*;
public class Client1
{
public static void main(String arg[]) throws IOException
{
String serverHostname= new String("localhost");
int port=1212;
System.out.println("Attempting to connect to
host"+serverHostname+"on port"+port);
Socket echoSocket=null;
PrintWriter out=null;
BufferedReader in=null;
try
{
echoSocket=new Socket(serverHostname, port);
out=new PrintWriter(echoSocket.getOutputStream(), true);
in=new BufferedReader(new
InputStreamReader(echoSocket.getInputStream()));
}
catch(UnknownHostException e)
{
System.err.println(e);
System.exit(1);
}
catch(IOException e)
{
System.err.println(e);
System.exit(1);
}
BufferedReader stdIn=new BufferedReader(new
InputStreamReader(System.in));
String userInput;
while((userInput=stdIn.readLine()) !=null)
{
out.println(userInput);
System.out.println("Srever says:"+in.readLine());
}
out.close();
in.close();
stdIn.close();
}
}