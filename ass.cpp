#include <iostream>
#include <list>

template <typename T>
class Queue {
private:
    std::list<T> data;

public:
    // Check if the queue is empty
    bool empty() const {
        return data.empty();
    }

    // Get the size of the queue
    size_t size() const {
        return data.size();
    }

    // Swap contents with another queue
    void swap(Queue& other) {
        data.swap(other.data);
    }

    // Access the front element
    T& front() {
        if (!data.empty()) return data.front();
        throw std::out_of_range("Queue is empty");
    }

    // Access the back element
    T& back() {
        if (!data.empty()) return data.back();
        throw std::out_of_range("Queue is empty");
    }

    // Push an element to the back of the queue
    void push(const T& value) {
        data.push_back(value);
    }

    // Pop an element from the front of the queue
    void pop() {
        if (!data.empty()) {
            data.pop_front();
        } else {
            throw std::out_of_range("Queue is empty");
        }
    }

    // Print all elements in the queue
    void print() const {
        for (const auto& elem : data) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue<int> q;

    // Test push
    q.push(10);
    q.push(20);
    q.push(30);

    // Print the queue
    std::cout << "Queue elements: ";
    q.print();

    // Test size
    std::cout << "Size of queue: " << q.size() << std::endl;

    // Test front and back
    std::cout << "Front element: " << q.front() << std::endl;
    std::cout << "Back element: " << q.back() << std::endl;

    // Test pop
    q.pop();
    std::cout << "Queue after pop: ";
    q.print();

    // Test empty
    std::cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << std::endl;

    // Test swap
    Queue<int> q2;
    q2.push(100);
    q2.push(200);
    std::cout << "Queue 2 before swap: ";
    q2.print();
    
    q.swap(q2);
    std::cout << "Queue 1 after swap: ";
    q.print();
    std::cout << "Queue 2 after swap: ";
    q2.print();

    return 0;
}
