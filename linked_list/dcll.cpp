#include <bits/stdc++.h>
using namespace std;

// Circular Doubly Linked List
class Node {

public:
    int data;
    Node* prev;
    Node* next;

    // Constructor

    Node(){
        data = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }

    // Display forward
    void display(Node* head) {

        if(head == NULL)
            return;

        Node* temp = head;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while(temp != head);

        cout << endl;
    }

    // Display backward
    void reverseDisplay(Node* head) {

        if(head == NULL)
            return;

        Node* last = head->prev;
        Node* temp = last;

        do {
            cout << temp->data << " ";
            temp = temp->prev;
        } while(temp != last);

        cout << endl;
    }


    // Insert at beginning
    Node* insertAtBeginning(Node* head, int val) {

        Node* newNode = new Node(val);

        // Empty list
        if(head == NULL) {

            newNode->next = newNode;
            newNode->prev = newNode;

            return newNode;
        }

        Node* last = head->prev;

        // Connect new node
        newNode->next = head;
        newNode->prev = last;

        // Connect old last and old head
        last->next = newNode;
        head->prev = newNode;

        // Update head
        head = newNode;

        return head;
    }


    // Insert at end
    Node* insertAtEnd(Node* head, int val) {

        Node* newNode = new Node(val);

        // Empty list
        if(head == NULL) {

            newNode->next = newNode;
            newNode->prev = newNode;

            return newNode;
        }

        Node* last = head->prev;

        // Connect new node
        newNode->next = head;
        newNode->prev = last;

        // Connect old last and head
        last->next = newNode;
        head->prev = newNode;

        return head;
    }


    // Delete from beginning
    Node* deleteBeginning(Node* head) {

        if(head == NULL)
            return NULL;

        // Only one node
        if(head->next == head) {

            delete head;
            return NULL;
        }

        Node* last = head->prev;
        Node* temp = head;

        head = head->next;

        // Fix connections
        head->prev = last;
        last->next = head;

        delete temp;

        return head;
    }


    // Delete from end
    Node* deleteEnd(Node* head) {

        if(head == NULL)
            return NULL;

        // Only one node
        if(head->next == head) {

            delete head;
            return NULL;
        }

        Node* last = head->prev;
        Node* newLast = last->prev;

        // Fix connections
        newLast->next = head;
        head->prev = newLast;

        delete last;

        return head;
    }
};


int main() {

    Node obj;
    Node* head = NULL;


    // ---------------- INSERT AT BEGINNING ----------------

    head = obj.insertAtBeginning(head, 10);
    head = obj.insertAtBeginning(head, 20);
    head = obj.insertAtBeginning(head, 30);

    cout << "After inserting at beginning:" << endl;
    obj.display(head);


    // ---------------- INSERT AT END ----------------

    head = obj.insertAtEnd(head, 40);
    head = obj.insertAtEnd(head, 50);

    cout << "After inserting at end:" << endl;
    obj.display(head);


    // ---------------- FORWARD DISPLAY ----------------

    cout << "Forward traversal:" << endl;
    obj.display(head);


    // ---------------- BACKWARD DISPLAY ----------------

    cout << "Backward traversal:" << endl;
    obj.reverseDisplay(head);


    // ---------------- DELETE BEGINNING ----------------

    head = obj.deleteBeginning(head);

    cout << "After deleting beginning:" << endl;
    obj.display(head);


    // ---------------- DELETE END ----------------

    head = obj.deleteEnd(head);

    cout << "After deleting end:" << endl;
    obj.display(head);


    // ---------------- DELETE MORE ----------------

    head = obj.deleteBeginning(head);
    head = obj.deleteEnd(head);

    cout << "After more deletions:" << endl;
    obj.display(head);


    return 0;
}