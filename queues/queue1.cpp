#include<bits/stdc++.h>
using namespace std;

// implementation of queue adt using array

// class Queue{
//     int arr[100];
//     int front, rear;

//     public:

//     Queue(){
//         front = 0; 
//         rear = -1;
//     }

//     void enqueue(int x){
//         if( rear == 99){
//             cout<< "Queue overflow.\n";
//             return;
//         } 
//         arr[++rear] = x;
//     }

//     void dequeue(){
//         if(front > rear){
//             cout<<"Queue is empty\n";
//             return;
//         }
//         front++;
//     }

//     int peek(){
//         if(front > rear){
//             cout<<"Queue is empty\n";
//             return -1;
//         }
//         return arr[front];
//     }

//     bool isEmpty(){
//         return front > rear;
//     }
    
//     void display(){
//         for(int i = front; i <= rear; i++){
//             cout<< arr[i]<<" ";
//         }
//         cout<<endl;
//     }
// };


// implementation of queue adt using linked list

class Queue{
    struct Node{
        int data;
        Node* next;

        Node(int x){
            data = x;
            next = nullptr;
        }
    };

    Node*front, *rear;

    public:
    Queue(){
        front = rear = nullptr;
    }

    void enqueue(int x){
        Node* temp = new Node(x);

        if(rear == nullptr){
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    void dequeue(){
        if(front == nullptr){
            cout<< "Queue Underflow\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        if(front == nullptr) rear = nullptr;

        delete temp;
    }

    int peek(){
        if(front == nullptr){
            cout<< "Queue Empty\n";
            return -1;
        }

        return front->data;
    }

    bool isEmpty(){
        return front == nullptr;
    }

    void display(){
        Node *temp = front;
        while(temp != NULL){
            cout<< temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
        
    }


};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();        // 10 20 30

    cout << q.peek();   // 10

    q.dequeue();

    cout << "\n";
    q.display();        // 20 30
}