import java.io.*;
import java.net.*;

public class Client {
    public static void main(String[] args) throws IOException {
        // Step 1: Connect to the server on localhost, port 12345
        Socket socket = new Socket("localhost", 12345);
        System.out.println("Connected to server.");

        // Step 2: Create input and output streams for communication
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

        // Step 3: Send a message to the server
        out.println("Hello from Client!");

        // Step 4: Read response from the server
        String response = in.readLine();
        System.out.println("Server: " + response);

        // Step 5: Close connection
        socket.close();
    }
}
