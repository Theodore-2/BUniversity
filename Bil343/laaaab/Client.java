import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) {
        try (Socket socket = new Socket("10.7.121.190", 12345)) {
            System.out.println("Connected to the server!");

            BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter output = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader consoleInput = new BufferedReader(new InputStreamReader(System.in));

            String messageFromServer, messageToServer;
            while (true) {
                System.out.print("You: ");
                messageToServer = consoleInput.readLine();
                output.println(messageToServer);

                messageFromServer = input.readLine();
                if (messageFromServer == null) break;
                System.out.println("Server: " + messageFromServer);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}