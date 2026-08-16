#include<bits/stdc++.h>
using namespace std;

// singly circular linked list
class Node{

    public:
    int data;
    Node* next;

    Node(){
        data = 0;
        next = NULL;
    }

    Node(int val){
        data = val;
        next = NULL;
    }

    void display(Node* head){
        if(head == NULL) return;

        Node* temp = head;
        // important to use do-while here
        do{
            cout<< temp->data<<" ";
            temp = temp->next;
        }while(temp != head);

        cout<<endl;
    }

    // insert at beginning
        Node* insertAtBeginning(Node* head, int val) {

        Node* newNode = new Node(val);

        // Empty list
        if(head == NULL) {
            newNode->next = newNode;
            return newNode;
        }

        Node* last = head;

        while(last->next != head) {
            last = last->next;
        }

        newNode->next = head;
        last->next = newNode;

        head = newNode;

        return head;
    }

    Node* insertAtEnd(Node* head, int val) {

        Node* newNode = new Node(val);

        if(head == NULL) {
            newNode->next = newNode;
            return newNode;
        }

        Node* last = head;

        while(last->next != head) {
            last = last->next;
        }

        last->next = newNode;
        newNode->next = head;

        return head;
    
    }
    

    Node* deleteBeginning(Node* head) {

    if(head == NULL)
        return NULL;

    // Only one node
    if(head->next == head) {
        delete head;
        return NULL;
    }

    Node* last = head;

    while(last->next != head) {
        last = last->next;
    }

    Node* temp = head;

    head = head->next;
    last->next = head;

    delete temp;

    return head;
    }

    Node* deleteEnd(Node* head) {

    if(head == NULL)
        return NULL;

    if(head->next == head) {
        delete head;
        return NULL;
    }

    Node* prev = NULL;
    Node* curr = head;

    while(curr->next != head) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = head;

    delete curr;

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


    // ---------------- DELETE FROM BEGINNING ----------------

    head = obj.deleteBeginning(head);

    cout << "After deleting from beginning:" << endl;
    obj.display(head);


    // ---------------- DELETE FROM END ----------------

    head = obj.deleteEnd(head);

    cout << "After deleting from end:" << endl;
    obj.display(head);


    // ---------------- DELETE UNTIL ONE NODE ----------------

    head = obj.deleteBeginning(head);
    head = obj.deleteBeginning(head);
    head = obj.deleteBeginning(head);

    cout << "After deleting until one node:" << endl;
    obj.display(head);


    // ---------------- DELETE LAST NODE ----------------

    head = obj.deleteBeginning(head);

    cout << "After deleting last node:" << endl;
    obj.display(head);


    // ---------------- INSERT AGAIN INTO EMPTY LIST ----------------

    head = obj.insertAtEnd(head, 100);

    cout << "After inserting into empty list:" << endl;
    obj.display(head);


    return 0;
}

