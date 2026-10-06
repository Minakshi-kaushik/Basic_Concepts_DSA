#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// preorder traversal
void preorder(Node* root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// inorder traversal
void inorder(Node* root){
    if (root == NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// postorder traversal
void postorder(Node* root){
    if(root == NULL) return;
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

// level order traversal
void levelOrderByLevel(Node* root) {

    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        int size = q.size();

        for (int i = 0; i < size; i++) {

            Node* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left != nullptr)
                q.push(current->left);

            if (current->right != nullptr)
                q.push(current->right);
        }

        cout << endl;
    }
}

int main(){
    Node* r1 = new Node(10);

    Node* r2 = new Node(30);
    Node* r3 = new Node(20);

    Node* r4 = new Node(40);
    Node* r5 = new Node(50);
    Node* r6 = new Node(60);

    r1->left = r2;
    r1->right = r3;
    r2->left = r4;
    r2->right = r5; 
    r3->right = r6;

    // preorder(r1);
    // cout<<endl;

    // inorder(r1);
    // cout<<endl; 

    // postorder(r1);
    // cout<<endl;

    levelOrderByLevel(r1);
    cout<<endl;

    return 0;
}