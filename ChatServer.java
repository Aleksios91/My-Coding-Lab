import java.io.*;
import java.net.*;
import java.util.*;


public class ChatServer {  
    private static Set<PrintWriter> clientWriters = new HashSet<>();   // Set of all connected clients' output streams; HashSet prevents objects of PrintWriter (output stream) to be displayed more than once.
    




 // While program is active, it's connected to a port displayed below. That way, it "listens" to new connections.
// Only one program on this machine can occupy this port at a time, but multiple clients can connect through it.
// Each new client that connects is handled by a separate ClientHandler thread, allowing simultaneous conversations.


    public static void main(String[] args) {   
        System.out.println("Chat server started...");
        try (ServerSocket serverSocket = new ServerSocket(12345)) {
            while (true) {
                new ClientHandler(serverSocket.accept()).start();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    // Each client that connects will be managed by its own ClientHandler thread
    private static class ClientHandler extends Thread {
        private Socket socket;
        private PrintWriter out;
        private BufferedReader in;   // Lets the server read text messages sent by this client

        public ClientHandler(Socket socket) {
            this.socket = socket;
        }

        public void run() {
            try {    
                // Prepare to read from and write to the client's socket
                in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                out = new PrintWriter(socket.getOutputStream(), true);

                // Add this client's writer to the shared set so they can receive broadcasts
                synchronized (clientWriters) {
                    clientWriters.add(out);
                }

                String message;
                while ((message = in.readLine()) != null) {
                    System.out.println("Received: " + message);
                    broadcast(message);
                }
            } catch (IOException e) {     // Handle any connection errors
                e.printStackTrace();
            } finally {
                try {
                    socket.close();     // Close this client's connection when they're done
                } catch (IOException e) {
                    e.printStackTrace();
                }
                synchronized (clientWriters) {   // Remove this client from the broadcast list when they disconnect
                    clientWriters.remove(out);
                }
            }
        }
         // Broadcasts a message to ALL connected clients
        private void broadcast(String message) {
            synchronized (clientWriters) {
                for (PrintWriter writer : clientWriters) {
                    writer.println(message);   // Each client receives the same message
                }
            }
        }
    }
}



