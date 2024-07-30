#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> elements;

public:
    // Push an element onto the stack
    void push(int value) {
        elements.push_back(value);
    }

    // Pop an element from the stack
    void pop() {
        if (!elements.empty()) {
            elements.pop_back();
        } else {
            std::cout << "Stack is empty. Cannot pop.\n";
        }
    }

    // Get the top element of the stack
    int top() const {
        if (!elements.empty()) {
            return elements.back();
        } else {
            std::cout << "Stack is empty. No top element.\n";
            return -1; // Returning -1 to indicate no element is present
        }
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return elements.empty();
    }
};

int main() {
    Stack stack;

    // Push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Display the top element
    std::cout << "Top element: " << stack.top() << std::endl;

    // Pop an element from the stack
    stack.pop();

    // Display the top element after pop
    std::cout << "Top element after pop: " << stack.top() << std::endl;

    // Pop all elements from the stack
    stack.pop();
    stack.pop();

    // Attempt to pop from an empty stack
    stack.pop();

    return 0;
}
