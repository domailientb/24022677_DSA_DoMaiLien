
#include <iostream>
using namespace std;

class List {
private:
    int data[1000]; // O(1)
    int a;      // O(1)

public:
    List() {
        a = 0; // O(1)
    } // =>  O(1)

    bool isEmpty() {
        return a == 0; // O(1)
    } // =>  O(1)

    int size() {
        return a; // O(1)
    } // =>  O(1)

    int get(int pos) {
        if (pos < 0 || pos >= a) return -1; // O(1)
        return data[pos]; // O(1)
    } // =>  O(1)

    void insert(int pos, int value) {
        if (pos < 0 || pos > a || a == 1000) return; // O(1)

        for (int i = a; i > pos; --i) { // O(n)
            data[i] = data[i - 1];          // O(1) 
        }

        data[pos] = value; // O(1)
        a++;            // O(1)
    } // =>  O(n)

    int erase(int pos) {
        if (pos < 0 || pos >= a) return -1; // O(1)

        int value = data[pos]; // O(1)

        for (int i = pos; i < a - 1; ++i) { // O(n)
            data[i] = data[i + 1];              // O(1)
        }

        a--;       // O(1)
        return value;  // O(1)
    } // =>  O(n)

    void addLast(int value) {
        insert(a, value); // O(1) khi chen cuoi
    } // =>  O(1)

    int removeLast() {
        return erase(a - 1); // O(1) khi xoa cuoi
    } // =>  O(1)

    int removeFirst() {
        return erase(0); // O(n) 
    } // =>  O(n)
};

class StackList {
private:
    List items; // O(1)

public:
    bool isEmpty() {
        return items.isEmpty(); // O(1)
    } // =>  O(1)

    int size() {
        return items.size(); // O(1)
    } // =>  O(1)

    void push(int value) {
        items.addLast(value); // O(1)
    } // =>  O(1)

    int pop() {
        if (isEmpty()) return -1; // O(1)
        return items.removeLast(); // O(1)
    } // =>  O(1)

    int top() {
        if (isEmpty()) return -1; // O(1)
        return items.get(items.size() - 1); // O(1)
    } // =>  O(1)
};

class QueueList {
private:
    List items; // O(1)

public:
    bool isEmpty() {
        return items.isEmpty(); // O(1)
    } // =>  O(1)

    int size() {
        return items.size(); // O(1)
    } // =>  O(1)

    void enqueue(int value) {
        items.addLast(value); // O(1)
    } // =>  O(1)

    int dequeue() {
        if (isEmpty()) return -1; // O(1)
        return items.removeFirst(); // O(n)
    } // =>  O(n)

    int front() {
        if (isEmpty()) return -1; // O(1)
        return items.get(0); // O(1)
    } // =>  O(1)
};

int main() {
    StackList st;
    QueueList qu;

    for (int x : {5, 15, 25}) { // O(1) 
        st.push(x);    // O(1)
        qu.enqueue(x); // O(1)
    }

    cout << "Stack: " << st.top() << '\n'; // O(1)
    cout << st.pop() << '\n';              // O(1)
    cout << st.size() << '\n';             // O(1)

    cout << "Queue: " << qu.front() << '\n'; // O(1)
    cout << qu.dequeue() << '\n';            // O(n)
    cout << qu.size() << '\n';               // O(1)

    return 0; // O(1)
} // =>  O(1) voi so phan tu co dinh