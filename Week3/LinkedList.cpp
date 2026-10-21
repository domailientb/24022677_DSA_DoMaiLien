
#include <iostream>
using namespace std;

class LinkedList {
private:
    struct Node {
        int value;    // O(1)
        Node* next;   // O(1)

        Node(int x) : value(x), next(nullptr) {}
        // => O(1)
    };

    Node* firstNode; // O(1)
    Node* lastNode;  // O(1)
    int length;      // O(1)

public:
    LinkedList() {
        firstNode = lastNode = nullptr; // O(1)
        length = 0;                     // O(1)
    } // => O(1)

    ~LinkedList() {
        while (firstNode != nullptr) { // O(n)
            Node* temp = firstNode;    // O(1)
            firstNode = firstNode->next; // O(1)
            delete temp;               // O(1) 
        }
        lastNode = nullptr; // O(1)
        length = 0;         // O(1)
    } // => O(n)

    bool isEmpty() {
        return length == 0; // O(1)
    } // => O(1)

    int size() {
        return length; // O(1)
    } // => O(1)

    void addFront(int x) {
        Node* p = new Node(x); // O(1)
        p->next = firstNode;   // O(1)
        firstNode = p;         // O(1)

        if (lastNode == nullptr) { // O(1)
            lastNode = p;          // O(1)
        }

        length++; // O(1)
    } // => O(1)

    void addBack(int x) {
        Node* p = new Node(x); // O(1)

        if (lastNode == nullptr) { // O(1)
            firstNode = lastNode = p; // O(1)
        } else {
            lastNode->next = p; // O(1)
            lastNode = p;       // O(1)
        }

        length++; // O(1)
    } // => O(1)

    int removeFront() {
        if (isEmpty()) return -1; // O(1)

        Node* temp = firstNode; // O(1)
        int result = temp->value; // O(1)
        firstNode = firstNode->next; // O(1)
        delete temp; // O(1)
        length--; // O(1)

        if (firstNode == nullptr) { // O(1)
            lastNode = nullptr;     // O(1)
        }

        return result; // O(1)
    } // => O(1)

    int frontValue() {
        if (isEmpty()) return -1; // O(1)
        return firstNode->value;  // O(1)
    } // => O(1)
};

class StackLinkedList {
private:
    LinkedList items; // O(1)

public:
    bool isEmpty() {
        return items.isEmpty(); // O(1)
    } // => O(1)

    int size() {
        return items.size(); // O(1)
    } // => O(1)

    void push(int x) {
        items.addFront(x); // O(1)
    } // => O(1)

    int pop() {
        return items.removeFront(); // O(1)
    } // => O(1)

    int top() {
        return items.frontValue(); // O(1)
    } // => O(1)
};

class QueueLinkedList {
private:
    LinkedList items; // O(1)

public:
    bool isEmpty() {
        return items.isEmpty(); // O(1)
    } // => O(1)

    int size() {
        return items.size(); // O(1)
    } // => O(1)

    void enqueue(int x) {
        items.addBack(x); // O(1)
    } // => O(1)

    int dequeue() {
        return items.removeFront(); // O(1)
    } // => O(1)

    int front() {
        return items.frontValue(); // O(1)
    } // => O(1)
};

int main() {
    StackLinkedList st; // O(1)
    QueueLinkedList qu; // O(1)

    for (int x : {8, 18, 28}) { // O(1) voi so phan tu co dinh
        st.push(x);    // O(1)
        qu.enqueue(x); // O(1)
    }

    cout << "Stack: " << st.top() << '\n'; // O(1)
    cout << st.pop() << '\n';              // O(1)
    cout << st.size() << '\n';             // O(1)

    cout << "Queue: " << qu.front() << '\n'; // O(1)
    cout << qu.dequeue() << '\n';            // O(1)
    cout << qu.size() << '\n';               // O(1)

    return 0; // O(1)
} // => O(1) voi so phan tu co dinh
