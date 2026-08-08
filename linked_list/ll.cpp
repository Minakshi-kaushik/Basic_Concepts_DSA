#include <bits/stdc++.h>

using namespace std;

class Node{
    public:

    int data;
    Node* next;

// nonparametrized constructor
    Node(){
        next = NULL;
    }
    
    // parametrized constructor

    Node( int data){
        this->data = data;
        next = NULL;
    }

    // convert array to linkedlist
    Node* arr_to_ll(vector<int>& arr){

        if(arr.empty()) return NULL;


        int n = arr.size();
        Node* head = new Node(arr[0]);
        Node* temp = head;

        for(int i = 1; i < n; i++){
            temp->next = new Node(arr[i]);
            temp = temp->next;
        }
        return head;
    }

    // traverse the linked list and print data of each node

    void display(Node* head){

        if(head == NULL) cout<<"The list is empty."<<endl;

        Node* temp = head;
        while(temp){
            cout<<temp->data<<endl;
            temp = temp->next;
        }
        
    }

    // count the length of Linked List

    int length(Node* head){

        if(head == NULL) return 0;

        Node* temp = head;
        int count = 0;

        while(temp){
            count++;
            temp = temp->next;
        }

        return count;
    }

    Node* insertNewNode(Node* head, int x, int pos){

        //if len = 0;
        if(head == NULL){
            if(pos == 0) return new Node(x);

            return NULL;
        }

        //before head
        if(pos == 0){
            Node* temp = new Node(x);
            temp ->next = head;
            head = temp;
            return head;
        }

        // any other position
        Node* p = head;
        for(int i = 0; i < pos-1; i++){

              if (p == NULL) return head;  
            p = p->next;
        }

        Node* temp = new Node(x);
        temp ->next = p->next;
        p->next = temp;
        
        return head;

    }

    Node* deleteNode(Node* head, int pos){

        if(head == NULL) return NULL;


        // deleting the head node;
        if(pos == 0){

            Node* newhead = head->next;
            
            delete head;
            return newhead;
        }

        // other positions
        Node* curr = head;
        for(int i = 0; i < pos-1; i++){
            curr = curr->next;
        }

        // position doesnot exist
        if(curr == NULL || curr->next == NULL){
            return head;
        }

        Node* temp = curr->next;
        curr ->next = curr ->next->next;
        delete temp;

        return head;
        
    }


    bool ifSorted(Node* head){
        if( head == NULL || head->next == NULL) return true;

        Node* curr = head;
        while(curr->next){
            if(curr->data > curr->next->data){
                return false;
            }
            curr = curr->next;
        }
        return true;

    }

    Node* insertInSorted(Node* head, int x) {

    Node* temp = new Node(x);

    // Empty list OR insert before head
    if (head == NULL || x <= head->data) {
        temp->next = head;
        return temp;
    }

    // Find position
    Node* curr = head;

    while (curr->next != NULL && curr->next->data < x) {
        curr = curr->next;
    }

    // Insert after curr
    temp->next = curr->next;
    curr->next = temp;

    return head;
}

// remove duplicates from linked list

Node* removeDuplicates(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* curr = head;

    while(curr->next ){
        if(curr->data == curr->next->data){
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }else{
            curr= curr->next;
        }
    }
    return head;
}
   
};


int main(){
    Node obj;
    vector<int> arr = {1,2,2,3,4,4,5};

    Node * head = obj.arr_to_ll(arr);
    // Display
    cout << "Original list: ";
    obj.display(head);

    // Length
    cout << "Length: " << obj.length(head) << endl;

    // Check if sorted
    if (obj.ifSorted(head))
        cout << "List is sorted" << endl;
    else
        cout << "List is not sorted" << endl;

    // Insert at position
    head = obj.insertNewNode(head, 10, 3);

    cout << "After inserting 10 at position 3: ";
    obj.display(head);

    // Delete node
    head = obj.deleteNode(head, 3);

    cout << "After deleting position 3: ";
    obj.display(head);

    // Insert while maintaining sorted order
    head = obj.insertInSorted(head, 3);

    cout << "After sorted insertion of 3: ";
    obj.display(head);

    // Remove duplicates
    head = obj.removeDuplicates(head);

    cout << "After removing duplicates: ";
    obj.display(head);
    

    return 0;
}