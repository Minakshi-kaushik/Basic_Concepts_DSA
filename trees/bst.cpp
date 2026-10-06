#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data; 
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = right = nullptr;
    }
};

bool searchBST(Node* root, int target){
    if(root == NULL) return false;

    if(root->data == target) return true;

    if(root->data > target) return searchBST(root->left, target);

    if(root->data < target) return searchBST(root->right, target);

    return false;
}

Node* insertBST(Node* root, int value){
    if(root == NULL) return new Node(value);

    if(value < root->data){
        root->left = insertBST(root->left, value);
    }else{
        root->right = insertBST(root->right, value);
    }

    return root;
}



Node* deleteBST(Node* root, int value){
    if(root == NULL) return NULL;

    if(value < root->data){
        root->left = deleteBST(root->left, value);
    }else if( value > root->data){
        root->right = deleteBST(root->right, value);
    }

    else{
        // node to be deleted found
        // case1: no child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //case2: one child
        if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //case2: two child(replace root with inorder successor)
        Node* temp = root->right;
        while(temp->left != NULL){
            temp = temp ->left;
        }

        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);

    }
    return root;
}


void inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node* r1 = new Node(40);
    Node* r2 = new Node(20);
    Node* r3 = new Node(60);
    Node* r4 = new Node(10);
    Node* r5 = new Node(30);
    Node* r6 = new Node(50);
    Node* r7 = new Node(70);

    r1->left = r2;
    r1->right = r3;

    r2->left = r4;
    r2->right = r5;

    r3->left = r6;
    r3->right = r7;

    // cout<<searchBST(r1, 50)<<endl;
    // insertBST(r1, 55);

    deleteBST(r1, 20);


    inorder(r1);

    return 0;

}