#include <iostream>
#include <list>

using namespace std;

class Queue {
private:
    list<int> elements;

public:
    // Enqueue an element to the queue
    void enqueue(int value) {
        elements.push_back(value);
    }

    // Dequeue an element from the queue
    void dequeue() {
        if (!elements.empty()) {
            elements.pop_front();
        } else {
            cout << "Queue is empty. Cannot dequeue.\n";
        }
    }

    // Get the front element of the queue
    int front() const {
        if (!elements.empty()) {
            return elements.front();
        } else {
            cout << "Queue is empty. No front element.\n";
            return -1; // Returning -1 to indicate no element is present
        }
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return elements.empty();
    }
};

int main() {
    Queue queue;

    // Enqueue elements to the queue
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    // Display the front element
    cout << "Front element: " << queue.front() << endl;

    // Dequeue an element from the queue
    queue.dequeue();

    // Display the front element after dequeue
    cout << "Front element after dequeue: " << queue.front() << endl;

    // Dequeue all elements from the queue
    queue.dequeue();
    queue.dequeue();

    // Attempt to dequeue from an empty queue
    queue.dequeue();

    return 0;
}
