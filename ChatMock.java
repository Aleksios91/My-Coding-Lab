import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class ServerField {
    private List<String> messages = new ArrayList<>();  // This is where the messages are stored and displayed. 

    public void receiveMessage(String user, String message) {
        String formatted = user + ": " + message;
        messages.add(formatted);    //Format incoming messages in format given above
        displayMessages();
    }

    private void displayMessages() {
        System.out.println("\n--- Chat Room ---");
        for (String msg : messages) {
            System.out.println(msg);
        }
        System.out.println("-----------------\n");
    }
}

class ClientSimulator {
    private String username;
    private ServerField server;

    public ClientSimulator(String username, ServerField server) {
        this.username = username;
        this.server = server;
    }

    public void sendMessage(String message) {
        server.receiveMessage(username, message);
    }
}

public class ChatMock {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ServerField server = new ServerField();

        System.out.println("Mock Chat Simulator");
        System.out.println("Type /exit to quit\n");

        while (true) {
            System.out.print("Enter your username: ");
            String user = scanner.nextLine();
            if (user.equalsIgnoreCase("/exit")) break;

            System.out.print("Enter your message: ");
            String message = scanner.nextLine();
            if (message.equalsIgnoreCase("/exit")) break;

            ClientSimulator client = new ClientSimulator(user, server);
            client.sendMessage(message);
        }

        System.out.println("Simulation ended.");
        scanner.close();
    }
}

    

