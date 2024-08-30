package 设计模式.行为型模式.中介者模式;

import java.util.ArrayList;
import java.util.List;

/**
 * @author robbie
 * @date Created in 2024/08/16
 */

class User {
    private String name;
    private ChatRoom chatRoom;

    public User(String name, ChatRoom chatRoom) {
        this.name = name;
        this.chatRoom = chatRoom;
        chatRoom.register(this);
    }

    public void SendMessage(String message) {
        System.out.printf("%s send message:\n\t%s\n", name, message);
        chatRoom.forwardMessage(this, message);
    }

    public void ReceiveMessage(String message) {
        System.out.printf("%s receive message:\n\t%s\n", name, message);
    }
}

class ChatRoom {
    private List<User> users = new ArrayList<>();

    public boolean register(User user) {
        if (users.contains(user)) {
            return false;
        } else {
            users.add(user);
            return true;
        }
    }

    public void forwardMessage(User user, String message) {
        for (User receiver : users) {
            if (receiver != user) {
                receiver.ReceiveMessage(message);
            }
        }
    }
}

public class 中介者模式 {
    public static void main(String[] args) {
        ChatRoom chatRoom = new ChatRoom();
        User user1 = new User("Alice", chatRoom);
        User user2 = new User("Bob", chatRoom);
        User user3 = new User("Carl", chatRoom);

        user1.SendMessage("hello, guys!");
    }
}
