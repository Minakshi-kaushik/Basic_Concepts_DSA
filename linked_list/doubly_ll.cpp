#include <bits/stdc++.h>
using namespace std;


// class for doubly linked lists
class Node{
    public:

    Node* prev;
    int data;
    Node* next;

// non parameterised constructor
    Node(){
        data = 0;
        prev = NULL;
        next = NULL;
    }

    Node(int data){
        this->data = data;
        prev = NULL;
        next = NULL;
    }

    int length(Node* head){
        int l = 0;
        Node* temp = head;
        while(temp){
            l++;
            temp= temp->next;
        }
        return l;
    }

    Node* insertInDll(Node* head, int pos, int val){

        
        Node* temp = new Node(val);
        // Insert at beginning
        if(pos == 0){
            
            temp->next = head;
            if(head){
                head->prev = temp;
            }
            
            head= temp;
            return head;
        }
           int i = 0;
           Node* curr = head;
           while(i < pos-1){
            curr = curr->next;
            i++;
           }

        if(curr == NULL){
            delete temp;
            return head;
        }

        //    connecting nodes;
        
        temp->next = curr->next; temp->prev = curr;
        if(curr->next){
            curr->next->prev = temp;
        }
           curr->next = temp;
           

        
        return head;
    }


    Node* deleteFromDll(Node* head, int pos);

    // traverse DLL
    void traverseDll(Node* head){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }
    

    Node* reverseDll(Node* head);

};

// deleting node from Dll

Node* Node::deleteFromDll(Node* head, int pos){

    if(head == NULL) return NULL;
    // deleting first Node

    if(pos == 0){
        Node* temp = head;
        head = head->next;

        if(head != NULL) head->prev = NULL;

        delete temp;
        return head;
    }

    Node* curr = head;

    for(int i = 0; i < pos-1; i++){
        curr = curr->next;
    }

    Node* temp = curr->next;

    curr->next = temp->next;

    if(temp->next != NULL){
    temp->next->prev = curr;
   }
    delete temp;

    return head;

}

// definition of reverseDll

Node* Node::reverseDll(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* curr = head;
    Node* temp = NULL;

    while(curr != NULL){
        // swap prev and next;
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        // move to next node(which is now prev)
        curr = curr->prev;
    }

    // temp is at old head's prev
    // new head is temp->prev

    head = temp->prev;
    return head;
}

int main() {

    Node obj;
    Node* head = NULL;

    head = obj.insertInDll(head, 0, 10);
    head = obj.insertInDll(head, 1, 20);
    head = obj.insertInDll(head, 2, 30);
    head = obj.insertInDll(head, 3, 40);

    cout << "Original DLL:\n";
    obj.traverseDll(head);

    cout << "\nLength: " << obj.length(head) << endl;

    head = obj.insertInDll(head, 2, 25);

    cout << "\nAfter inserting 25 at index 2:\n";
    obj.traverseDll(head);

    head = obj.deleteFromDll(head, 0);

    cout << "\nAfter deleting index 0:\n";
    obj.traverseDll(head);

    head = obj.deleteFromDll(head, 2);

    cout << "\nAfter deleting index 2:\n";
    obj.traverseDll(head);

    head = obj.reverseDll(head);

    cout << "\nAfter reversing:\n";
    obj.traverseDll(head);

    return 0;
}