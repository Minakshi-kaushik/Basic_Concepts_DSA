#include<bits/stdc++.h>
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

int countNodes(Node* root){
    if(root == nullptr) return 0;

    return 1+countNodes(root->left) + countNodes(root->right);
}

int sumNodes(Node* root){
    if(root == NULL) return 0;

    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

int countLeaf(Node* root){
    if(root == NULL) return 0;

    if(root->left == NULL && root->right == NULL) return 1;

    return countLeaf(root->left) + countLeaf(root->right);
}

int httree(Node* root){
    if(root == NULL) return 0;

    return 1 +max(httree(root->left) , httree(root->right));
}

bool searchBT(Node* root, int val){
    if(root == nullptr) return false;

    if(root->data == val) return true;

    return searchBT(root->left, val) || searchBT(root->right, val);
}

int countOucc(Node* root, int target){
    if(root == NULL) return 0;

    int current = (root->data == target) ? 1 : 0;

    return current + countOucc(root->left, target) + countOucc(root->right, target);
}

int maxVal(Node* root){
    
    if(root == NULL) return INT_MIN;

    int maxl = maxVal(root->left);
    int maxr = maxVal(root->right);

    return max(root->data, max(maxl, maxr));
}

int main(){
    Node* root = new Node(10);

    Node* n1 =  new Node(5);

    Node* n2 = new Node(20);
    Node* n3 = new Node(2);
    Node* n4 = new Node(7);
    Node* n5 = new Node(30);

    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    n2->right = n5;

    // cout<<root->data<<endl;
    // cout<<root->left->data<<endl;

    // cout<<countNodes(root);

    // cout<<sumNodes(root);

    // cout<<countLeaf(root);/

    // cout<<httree(root);

    // cout<<countOucc(root, 30);

    cout<<maxVal(root);


    return 0;

}

