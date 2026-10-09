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

// bool searchBST(Node* root, int target){
//     if(root == NULL) return false;

//     if(root->data == target) return true;

//     if(root->data > target) return searchBST(root->left, target);

//     if(root->data < target) return searchBST(root->right, target);

//     return false;
// }

// Node* insertBST(Node* root, int value){
//     if(root == NULL) return new Node(value);

//     if(value < root->data){
//         root->left = insertBST(root->left, value);
//     }else{
//         root->right = insertBST(root->right, value);
//     }

//     return root;
// }



// Node* deleteBST(Node* root, int value){
//     if(root == NULL) return NULL;

//     if(value < root->data){
//         root->left = deleteBST(root->left, value);
//     }else if( value > root->data){
//         root->right = deleteBST(root->right, value);
//     }

//     else{
//         // node to be deleted found
//         // case1: no child
//         if(root->left == NULL && root->right == NULL){
//             delete root;
//             return NULL;
//         }

//         //case2: one child
//         if(root->right == NULL){
//             Node* temp = root->left;
//             delete root;
//             return temp;
//         }
//         if(root->left == NULL){
//             Node* temp = root->right;
//             delete root;
//             return temp;
//         }

//         //case2: two child(replace root with inorder successor)
//         Node* temp = root->right;
//         while(temp->left != NULL){
//             temp = temp ->left;
//         }

//         root->data = temp->data;
//         root->right = deleteBST(root->right, temp->data);

//     }
//     return root;
// }


// void inorder(Node* root){
//     if(root == NULL) return;

//     inorder(root->left);
//     cout<<root->data<<" ";
//     inorder(root->right);
// }

// int smallest(Node* root){
//     if(root == NULL) return -1 ;

//     while(root->left != nullptr){
//         root= root->left;
//     }
//     return root->data;
// }

// int max(Node* root){
//     if(root == nullptr) return -1;

//     while(root->right != nullptr){
//         root = root->right;
//     }
//     return root->data;
// }

// Node* searchBST(Node* root, int key) {
//     if (root == nullptr || root->data == key)
//         return root;

//     if (key < root->data)
//         return searchBST(root->left, key);

//     return searchBST(root->right, key);
// }


// Insert into BST
Node* insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find the smallest node in a subtree
Node* minimumNode(Node* root) {
    if (root == nullptr)
        return nullptr;

    while (root->left != nullptr)
        root = root->left;

    return root;
}

// Find the largest node in a subtree
Node* maximumNode(Node* root) {
    if (root == nullptr)
        return nullptr;

    while (root->right != nullptr)
        root = root->right;

    return root;
}

// Find a node by its value
Node* searchBST(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;

    if (key < root->data)
        return searchBST(root->left, key);

    return searchBST(root->right, key);
}

Node* inorderPredecessor(Node* root, int value){
    Node*  node = searchBST(root, value);

    if(node == nullptr) return nullptr;

    if(node->left != nullptr){
        return maximumNode(node->left);
    }

    // case 2: If the node has no left subtree, we need to find the deepest ancestor for which the given node would be in the right subtree.

    Node* predecessor = nullptr;
    Node* current = root;

    while(current != nullptr){
        if(value > current->data){
            predecessor = current;
            current = current->right;

        }else if(value < current->data){
            current = current->left;
        }else{
            break;
        }
    }
    return predecessor;

}

Node* inorderSuccessor(Node* root, int value){
    Node* node = searchBST(root, value);

    if(node == nullptr) return nullptr;

    if(node->right != nullptr){
        return minimumNode(node->right);
    }

    // case 2: If the node has no right subtree, we need to find the deepest ancestor for which the given node would be in the left subtree.

    Node* successor = nullptr;
    Node* current = root;

    while(current != nullptr){
        if(value < current->data){
            successor = current;
            current = current->left;
        }else if(value > current->data){
            current = current->right;
        }else{
            break;
        }
    }
    return successor;
}

bool isValidBST(Node* root, long long low, long long high){
    if(root == nullptr) return true;

    if(root->data  <= low || root->data >= high) return false;

    return isValidBST(root->left, low, root->data) && isValidBST(root->right, root->data, high);
}


// idea-> if both are smaller than root, then find in left subtree, if both are greater than root, then find in right subtree, else root is the lca
Node* lca(Node* root, Node* p, Node* q){
    if(root == nullptr) return nullptr;

    if(p->data < root->data && q->data < root->data) return lca(root->left, p, q);

    if(p->data > root->data && q->data > root->data) return lca(root->right, p, q);

    return root;
}


//kth smallest element in BST

void kthsmallesthelper(Node* root,int k, int& count, int & result){
    if(root == nullptr) return;

    kthsmallesthelper(root->left, k, count, result);

    count++;
    if(count == k){
        result = root->data;
        return;
    }

    kthsmallesthelper(root->right, k, count, result);
}

int kthsmallest(Node* root, int k){
    int count = 0; 
    int result = -1; // Initialize result to -1 or any other value indicating "not found"
    kthsmallesthelper(root, k, count, result);
    return result;
}

//finding values in given range in BST
void findvaluesinrange(Node* root, int l , int h){ 
    if(root == nullptr) return;

    if(root->data >= l && root->data <= h){
        cout<<root->data<<" ";
    }

    if(root->data > l){
        findvaluesinrange(root->left, l, h);
    }
    if(root->data < h){
        findvaluesinrange(root->right, l, h);
    }
}

void deleteTree(Node* root){
    if(root == nullptr) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
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

    // deleteBST(r1, 20);


    // inorder(r1);

    return 0;

}