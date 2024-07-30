#include <iostream>

using namespace std;

// Node structure for the circular linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// CircularLinkedList class
class CircularLinkedList {
private:
    Node* head;

public:
    // Constructor to initialize an empty list
    CircularLinkedList() : head(nullptr) {}

    // Destructor to clean up the list
    ~CircularLinkedList() {
        if (head) {
            Node* temp = head->next;
            while (temp != head) {
                Node* delNode = temp;
                temp = temp->next;
                delete delNode;
            }
            delete head;
        }
    }

    // 1. Create a new node at the end of the list
    void create(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            newNode->next = head; // Circular reference
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // 2. Display the list
    void display() const {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    }

    // 3. Insert a new node after a specific value
    void insert(int afterValue, int newValue) {
        Node* temp = head;
        do {
            if (temp->data == afterValue) {
                Node* newNode = new Node(newValue);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Value " << afterValue << " not found in the list." << endl;
    }

    // 4. Delete a node with a specific value
    void deleteNode(int value) {
        if (!head) return;

        if (head->data == value && head->next == head) {
            // Only one node in the list
            delete head;
            head = nullptr;
        } else if (head->data == value) {
            // Deleting the head node
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            Node* delNode = head;
            temp->next = head->next;
            head = head->next;
            delete delNode;
        } else {
            Node* temp = head;
            while (temp->next != head && temp->next->data != value) {
                temp = temp->next;
            }
            if (temp->next->data == value) {
                Node* delNode = temp->next;
                temp->next = delNode->next;
                delete delNode;
            } else {
                cout << "Value " << value << " not found in the list." << endl;
            }
        }
    }

    // 5. Concatenate another circular linked list
    void concatenate(CircularLinkedList& other) {
        if (!head) {
            head = other.head;
        } else if (other.head) {
            Node* temp1 = head;
            while (temp1->next != head) {
                temp1 = temp1->next;
            }
            Node* temp2 = other.head;
            while (temp2->next != other.head) {
                temp2 = temp2->next;
            }
            temp1->next = other.head;
            temp2->next = head;
        }
        other.head = nullptr; // Avoid double deletion
    }
};

int main() {
    CircularLinkedList list1;
    CircularLinkedList list2;

    // Creating list1
    list1.create(10);
    list1.create(20);
    list1.create(30);
    list1.display();

    // Inserting in list1
    list1.insert(20, 25);
    list1.display();

    // Deleting from list1
    list1.deleteNode(10);
    list1.display();

    // Creating list2
    list2.create(40);
    list2.create(50);
    list2.create(60);
    list2.display();

    // Concatenating list2 into list1
    list1.concatenate(list2);
    list1.display();
    list2.display(); // list2 should now be empty

    return 0;
}
