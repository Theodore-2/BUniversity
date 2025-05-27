import java.io.*;
import java.net.*;

public class Server {
    public static void main(String[] args) {
        try (ServerSocket serverSocket = new ServerSocket(12345)) {
            System.out.println("Server is listening on port 12345...");
            Socket socket = serverSocket.accept();
            System.out.println("Client connected!");

            Thread readThread = new Thread(() -> {
                try (BufferedReader input = new BufferedReader(new InputStreamReader(socket.getInputStream()))) {
                    String messageFromClient;
                    while ((messageFromClient = input.readLine()) != null) {
                        System.out.println("Client: " + messageFromClient);
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            });

            Thread writeThread = new Thread(() -> {
                try (PrintWriter output = new PrintWriter(socket.getOutputStream(), true);
                     BufferedReader consoleInput = new BufferedReader(new InputStreamReader(System.in))) {
                    String messageToClient;
                    while ((messageToClient = consoleInput.readLine()) != null) {
                        output.println(messageToClient);
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            });

            readThread.start();
            writeThread.start();

            
            readThread.join();
            writeThread.join();

        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}