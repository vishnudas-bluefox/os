import java.io.*;
import java.net.*;
import java.util.Scanner;

public class echoclient{
    public static void main(String[] args){
        System.out.println("Clinet Connected...");
        try {
            InetAddress localHost = InetAddress.getLocalHost();
            Socket socket = new Socket(localHost,8088);
            PrintWriter out = new PrintWriter(socket.getOutputStream(),true);
            BufferedReader buffer = new BufferedReader(new InputStreamReader(socket.getInputStream()));

            System.out.println("Connected to server ..");

            Scanner scanner = new Scanner(System.in);

            while(true){
                System.out.println("Enter the message");
                String input =scanner.nextLine();
                if("exit".equalsIgnoreCase(input)){
                    break;

                }
            
            out.println(input);
            String response =buffer.readLine();
            System.out.println("Server Response is " + response);
        }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}