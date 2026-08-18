#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};

// node creation is ( Node* root = new Node( 10);)


// BST left < root < right
class BST{
    public:
    Node* insert(Node* root, int x){

        // if there is not existing node in BST
        if(root == nullptr){
            return new Node(x);
        }

        if( x < root->data){
            root->left = insert(root->left, x);
        }else{
            root->right = insert(root->right, x);
        }

        return root;
    }

    // tree traversals

    void inorder(Node* root){
        if(root == nullptr){
            return;
        }

        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    void preorder(Node* root){
         if (root == nullptr)
            return;

        cout<< root->data<<" ";
        preorder(root->left);
        preorder(root->right);

    }

    void postorder(Node* root){
         if (root == nullptr) return ;

         postorder(root->left);
         postorder(root->right);
         cout<< root->data<<" ";

    }

    bool search(Node* root, int x){
        if( root == nullptr){
            return false;
        }

        if (root->data == x)
            return true;

        if(x < root ->data){
            return search(root->left, x);
        }
        
        return search(root->right, x);
    }

    // minimum in bst is the left most node

    int mini(Node* root){
        while(root->left){
            root = root->left;
        }
        return root->data;
    }

    // maximum is the right most node
    int maximum(Node* root) {
    while (root->right != nullptr)
        root = root->right;

    return root->data;
    }

    int count(Node* root) {
    if (root == nullptr)
        return 0;

    return 1 + count(root->left) + count(root->right);
    }

    int height(Node* root){
        if(root == nullptr){
            return 0;
        }

        return 1 + max(height(root->left), height(root->right));
    }

    Node* deleteNode(Node* root, int x){
        if (root == nullptr) return nullptr;

        if(x < root->data){
            root->left = deleteNode(root->left, x);
        }else if(x > root->data){
            root->right= deleteNode(root->right, x);
        }else{

            // case1 : leaf node

            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }

            // case 2: only riht child
            if(root->left == nullptr){
                Node* temp = root->right;
                delete root;
                return temp;
            }

            // Case 2: Only left child
        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Node * temp = root->right;

        while(temp->left != NULL) temp = temp->left;

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }
};

int main(){
    BST tree;
    Node* root = nullptr;

    root = tree.insert(root, 50);
    root = tree.insert(root, 30);
    root = tree.insert(root, 70);
    root = tree.insert(root, 20);
    root = tree.insert(root, 40);

     cout << "Inorder: ";
    tree.inorder(root);

    cout << "\nPreorder: ";
    tree.preorder(root);

    cout << "\nPostorder: ";
    tree.postorder(root);


     // Search
    cout << "\n\nSearch 40: ";
    cout << (tree.search(root, 40) ? "Found" : "Not Found");

    // Minimum and Maximum
    cout << "\nMinimum: " << tree.mini(root);
    cout << "\nMaximum: " << tree.maximum(root);

    // Count
    cout << "\nNumber of nodes: " << tree.count(root);

    // Height
    cout << "\nHeight: " << tree.height(root);

    // Delete
    root = tree.deleteNode(root, 30);

    cout << "\n\nAfter deleting 30:";
    cout << "\nInorder: ";
    tree.inorder(root);

    return 0;
}