#include <iostream>

using namespace std;

// Node structure for the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// LinkedList class
class LinkedList {
private:
    Node* head;

public:
    // Constructor to initialize an empty list
    LinkedList() : head(nullptr) {}

    // Destructor to clean up the list
    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // 1. Create a new node at the end of the list
    void create(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // 2. Display the list
    void display() const {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // 3. Insert a new node after a specific value
    void insert(int afterValue, int newValue) {
        Node* temp = head;
        while (temp && temp->data != afterValue) {
            temp = temp->next;
        }
        if (temp) {
            Node* newNode = new Node(newValue);
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            cout << "Value " << afterValue << " not found in the list." << endl;
        }
    }

    // 4. Delete a node with a specific value
    void deleteNode(int value) {
        if (!head) return;
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        } else {
            cout << "Value " << value << " not found in the list." << endl;
        }
    }

    // 5. Sort the list
    void sort() {
        if (!head || !head->next) return;
        Node* i = head;
        while (i) {
            Node* j = i->next;
            while (j) {
                if (i->data > j->data) {
                    swap(i->data, j->data);
                }
                j = j->next;
            }
            i = i->next;
        }
    }

    // 6. Search for a value in the list
    bool search(int value) const {
        Node* temp = head;
        while (temp) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // 7. Reverse the list
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    // 8. Concatenate another list to this list
    void concatenate(LinkedList& other) {
        if (!head) {
            head = other.head;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = other.head;
        }
        other.head = nullptr; // Other list should not delete the concatenated part
    }
};

int main() {
    LinkedList list1;
    LinkedList list2;

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

    // Searching in list1
    cout << "20 found: " << (list1.search(20) ? "Yes" : "No") << endl;

    // Sorting list1
    list1.sort();
    list1.display();

    // Reversing list1
    list1.reverse();
    list1.display();

    // Creating list2
    list2.create(5);
    list2.create(15);
    list2.create(25);
    list2.display();

    // Concatenating list2 into list1
    list1.concatenate(list2);
    list1.display();
    list2.display(); // list2 should now be empty

    return 0;
}
