

class Linkedlist {
    class Node {
        int data;
        Node next;

        Node(int d) {
            data = d;
            next = null;
        }
    }

    Node head = null;

    void insertAtBeg(int value) {
        Node newNode = new Node(value);
        if (head == null) {
            head = newNode;
        } else {
            Node temp = head;
            head = newNode;
            head.next = temp;
        }
    }

    void insertAtPosition(int value, int pos) {
        Node newNode = new Node(value);
        Node temp = head;
        if (head == null) {
            head = newNode;
        } else {
            for (int i = 1; i < pos - 1; i++) {
                temp = temp.next;
            }
            // temp.next = newNode;
            newNode.next = temp.next;
            temp.next = newNode;
        }
    }

    void insertAtLast(int value) {
        Node newNode = new Node(value);
        Node temp = head;
        if (head == null) {
            insertAtBeg(value);
        } else {
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
            newNode.next = null;
            // temp = newNode;
        }
    }

    void display() {
        Node temp = head;
        if (head == null) {
            System.out.println("List is Empty");
        } else {
            while (temp != null) {
                System.out.print(temp.data + "-->");
                temp = temp.next;
            }
            System.out.println("Null");
        }
    }

    public static void main(String[] args) {
        Linkedlist linked = new Linkedlist();
        linked.insertAtBeg(12);
        linked.insertAtBeg(13);
        linked.insertAtBeg(11);
        linked.insertAtBeg(21);
        linked.insertAtBeg(43);
        linked.insertAtPosition(321, 3);
        linked.insertAtLast(900);
        linked.display();
    }
}