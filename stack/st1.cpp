#include<bits/stdc++.h>

using namespace std;

// Implementation of stack
// 1.using array

// class stA{
//     int arr[100];
//     int top;

//     public:
//     stA(){
//         top = -1;
//     }

//     void push(int val){
//         if(top == 99){
//             cout<<"Stack overflow"<<endl;
//             return;
//         }
//         top++;
//         arr[top] = val;
//     }

//     void pop(){
//         if(top == -1){
//             cout<<"Stack underflow\n";
//             return;
//         }
//         cout<<"Popped" <<arr[top]<<endl;
//         top--;
//     }

//     int peek(){
//         if(top == -1){
//             cout<<"stack is empty\n";
//             return -1;
//         }

//         return arr[top];
//     }

//     bool isEmpty(){
//         return top == -1;
//     }

//     bool isFull(){
//         return top == 99;
//     }

//     void display(){
//         if(top == -1){
//             cout<<"Stack is empty\n";;
//             return;
//         }
//         for(int i = top; i>=0; i--){
//             cout<<arr[i]<<" ";
//         }

//         cout<<endl;
//     }
// };


class Node{
    public:
    int data ;
    Node* next;

    Node(){
        data = 0;
        next = NULL;
    }

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Stack{
    Node* top;

    public: 

    Stack(){
        top = NULL;
    }

    // push

    void push(int val){
        Node* newNode = new Node(val);

        newNode->next = top ;
        top = newNode;
    }

    // pop
    void pop(){
        if( top == NULL){
            cout<<"Stack Underflow\n";
            return;
        }
        Node* temp = top;

        cout<<"Popped: "<< temp->data<<endl;

        top = top->next;
    }

    // peek
    int peek(){
        if(top == NULL){
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

      bool isEmpty() {
        return top == NULL;
    }


    // Display
    void display() {

        if(top == NULL) {
            cout << "Stack is empty\n";
            return;
        }

        Node* temp = top;

        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {

    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout << "Stack: ";
    st.display();

    cout << "Top: " << st.peek() << endl;

    st.pop();

    cout << "After pop: ";
    st.display();

    cout << "Top: " << st.peek() << endl;

    cout << "Is empty? " << st.isEmpty() << endl;
    // cout << "Is full? " << st.isFull() << endl;

    return 0;
}