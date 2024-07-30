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
    LinkedList() : head(nullptr) {}

    // Destructor to clean up the list
    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Create a new linked list
    void create(int arr[], int size) {
        for (int i = 0; i < size; ++i) {
            insertAtEnd(arr[i]);
        }
    }

    // Display the list
    void display() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Insert a new node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Insert a new node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Delete a node with a specific value
    void deleteNode(int value) {
        if (head == nullptr) return;

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
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
    }

    // Sort the linked list
    void sortList() {
        if (!head || !head->next) return;

        Node* sorted = nullptr;

        while (head) {
            Node* current = head;
            head = head->next;

            if (!sorted || sorted->data >= current->data) {
                current->next = sorted;
                sorted = current;
            } else {
                Node* temp = sorted;
                while (temp->next && temp->next->data < current->data) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
        }
        head = sorted;
    }

    // Search for a value in the list
    bool search(int value) const {
        Node* temp = head;
        while (temp) {
            if (temp->data == value) return true;
            temp = temp->next;
        }
        return false;
    }

    // Reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // Concatenate another list
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
        other.head = nullptr;
    }
};

int main() {
    LinkedList list1, list2;

    int arr1[] = {3, 1, 4, 1, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {9, 2, 6, 5, 3};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    // Create lists
    list1.create(arr1, size1);
    list2.create(arr2, size2);

    // Display lists
    cout << "List 1: ";
    list1.display();

    cout << "List 2: ";
    list2.display();

    // Insert element in list1
    list1.insertAtEnd(7);
    cout << "List 1 after insertion at end: ";
    list1.display();

    list1.insertAtBeginning(0);
    cout << "List 1 after insertion at beginning: ";
    list1.display();

    // Delete element from list1
    list1.deleteNode(4);
    cout << "List 1 after deleting 4: ";
    list1.display();

    // Sort list1
    list1.sortList();
    cout << "List 1 after sorting: ";
    list1.display();

    // Search in list1
    int value = 5;
    cout << "Is " << value << " present in list1? " << (list1.search(value) ? "Yes" : "No") << endl;

    // Reverse list1
    list1.reverse();
    cout << "List 1 after reversing: ";
    list1.display();

    // Concatenate list2 to list1
    list1.concatenate(list2);
    cout << "List 1 after concatenation with List 2: ";
    list1.display();

    return 0;
}
