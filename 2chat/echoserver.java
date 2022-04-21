import java.io.*;
import java.net.*;
import java.util.Scanner;

public class echoserver{
    public static void main(String args[]){
        System.out.println("Server started ... ");

        try(ServerSocket echoserver = new ServerSocket(8080)){
            Socket clientsocket = echoserver.accept();
            System.out.println("We are connected to client..");
            BufferedReader bufferReader = new BufferedReader(new InputStreamReader(clientsocket.getInputStream()));
            PrintWriter output =new PrintWriter(clientsocket.getOutputStream(),true);
            String line;
            Scanner scanner = new Scanner(System.in);
            while((line=bufferReader.readLine()) != null){
                System.out.println("Server: "+line);
                output.println(line);
            }
        }
        catch(Exception e){
            e.printStackTrace();
        }
    }
}