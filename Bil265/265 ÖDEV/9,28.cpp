#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}
};

template <typename T>
int countValue(Node* front, const T& item) {
    int count = 0;
    while (front) {
        if (front->data == item) {
            ++count;
        }
        front = front->next;
    }
    return count;
}

void writeLinkedList(Node* front) {
    while (front) {
        cout << front->data << " ";
        front = front->next;
    }
    cout << endl;
}

int main() {
    srand(time(0));

    Node* head = NULL;

    for (int i = 0; i < 20; ++i) {
        int num = rand() % 5;
        Node* newNode = new Node(num);
        newNode->next = head;
        head = newNode;
    }

    cout << "Linked list: ";
    writeLinkedList(head);

    for (int i = 0; i < 5; ++i) {
        cout << i << " occurs " << countValue(head, i) << " times" << endl;
    }

    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

