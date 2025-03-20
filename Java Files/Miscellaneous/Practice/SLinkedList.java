import java.util.*;

class Node {
    int data;
    Node next = null;

    public Node(int data) {
        this.data = data;
    }
}

class SLinkedList {
    Node head;

    public void add(int data) {
        Node newNode = new Node(data);
        if (head == null) head = newNode;
        else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            } temp.next = newNode; } }

    public void del(int data) {
        if (head == null) System.out.println("List is empty");
        else if (head.data == data) head = head.next;
        else {
            Node temp = head;
            while(temp.next != null) {
                if (temp.next.data == data) {
                    temp.next = temp.next.next;
                    break; } temp = temp.next; } } }

    public void display() {
        Node temp = head;
        while(temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        } System.out.print("Null\n"); }

    public static void main(String[] args) {
        SLinkedList list = new SLinkedList();
        int choice = 0;
        Scanner in = new Scanner(System.in);
        do {
            System.out.print("1. Add a node\n2. Delete Node\n3. Display Node\n4. Exit\n");
            System.out.print("Enter choice: ");
            if(in.hasNextInt())  choice = in.nextInt();
            else {
                System.out.println("Invalid choice");
                in.next();
                continue;
            }
            switch(choice) {
                case 1:
                    System.out.print("Enter the data: ");
                    if(in.hasNextInt()) {
                        int data = in.nextInt();
                        list.add(data);}
                    else {
                        System.out.println("Invalid data");
                        in.next(); }
                    break;
                case 2:
                    System.out.print("Enter the data to delete: ");
                    if(in.hasNextInt()) {
                        int deldata = in.nextInt();
                        list.del(deldata);}
                    else {
                        System.out.println("Invalid data");
                        in.next(); }
                    break;
                case 3:
                    System.out.println("Linked List:");
                    list.display();
                    break;
                case 4:
                    System.out.print("Exiting");
                    try {
                        Thread.sleep(1000);
                        System.out.print(".");
                        Thread.sleep(1000);
                        System.out.print(".");
                        Thread.sleep(1000);
                        System.out.print(".");
                        Thread.sleep(1000); }
                    catch(InterruptedException e) {
                        System.out.println("Thread interrupted"); }
                    break;
                default:
                    System.out.println("Invalid choice");
                    break;
            }
        } while(choice != 4);
        in.close(); 
    }
}
