#include <bits/stdc++.h>
using namespace std;

// array intitialization and declaration

int arr[10]; //initialization of array with garbage values (int stack)
int *A = new int[10]; //initialization of array with garbage values (int heap)

class array_adt{
    public:
        int *A;
        int size; 
        int length;

        public:
        //constructor
            array_adt(){
                size = 10;
                length = 0;
                A = new int[size];
            }

            void display_arr(){
                for(int i = 0; i < length; i++){
                    cout<<A[i]<<" ";
                }
            }

            void insert(int idx, int x){
                if(idx  >=0 && idx <length){
                    for(int i = length; i > idx; i--){
                        A[i] = A[i-1];
                    }
                    A[idx] = x;
                    length++;
                }
            }

            void append(int x){
                if(length < size){
                    A[length++] = x;
                }
            }

            void delete_ele(int idx){
                if(idx >= 0 && idx < length){
                    for(int i = idx; i < length - 1; i++){
                        A[i] = A[i+1];
                    }
                    length--;
                }
            }
            bool linear_search(int *A, int n, int key){
                if(n == 0) return false;
                if(A[n-1] == key) return true;

                return linear_search(A, n-1, key);
             }

             bool binary_search(int *A, int l, int h, int key){
                 if(l <= h){
                    int mid = l+(h-l)/2;
                    if(A[mid] == key) return true;

                    else if(A[mid] > key) return binary_search(A, l, mid-1, key);

                    else return binary_search(A, mid+1, h, key);
                 }
                 return false;
                }

            ~array_adt(){
                delete []A;
            }

};




bool binary_search(int *A, int l, int h, int key){
    if(l <= h){
        int mid = l+(h-l)/2;
        if(A[mid] == key) return true;

        else if(A[mid] > key) return binary_search(A, l, mid-1, key);

        else return binary_search(A, mid+1, h, key);
    }
    return false;
}

int arr_sum(int *A, int n){
    if(n == 0) return 0;

    return(arr_sum(A, n-1) + A[n-1]);
}

int main(){

    array_adt arr1;
    arr1.append(10);
    arr1.append(20);
    arr1.append(30);


    arr1.insert(1, 15);

    arr1.delete_ele(2);
    arr1.display_arr();


    arr1.linear_search(arr1.A, arr1.length, 20) ? cout << "Found"<< endl : cout<<"Not Found"<<endl;
    
    arr1.binary_search(arr1.A, 0, arr1.length-1, 30) ? cout<<"Found"<<endl : cout<<"Not Found"<<endl;
    return 0;
}