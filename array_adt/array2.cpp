#include<bits/stdc++.h>
using namespace std;

int *reverse(int *A, int n){
    int i = 0; int j = n-1;

    while(i < j){
        swap(A[i], A[j]);
        i++;
        j--;
    }
    return A;
}


int *left_rotate(int *A, int n){
    int temp = A[0];
    for(int i = 0; i < n-1; i++){
        A[i] = A[i+1];
    }
    A[n-1] = temp;
    return A;
}


int *insert_s(int* A, int n, int x){
    int i = 0;

    while(i < n-1 && A[i] < x){
        i++;
    }
    
    for(int j = n-1; j > i; j--){
        A[j] = A[j-1];
    }

    A[i] = x;
    return A;

}

bool is_sorted(int *A, int n){
    for(int i = 0; i < n-1; i++){
        if(A[i] > A[i+1]) return false;
    }

    return true;
}

int * neg_on_side(int* A, int n){
    int  i = 0; int j = n-1;
    while(i < j){
        while(A[i] < 0) i++;
        while(A[j] >= 0) j--;
        if(i < j) swap(A[i], A[j]);
    }
    return A;
}

int *merge(int *A, int n, int * B, int m){
    int i = 0; int j = 0; int k = 0;
    int *C = new int[n+m];
    while(i < n && j < m){
        if(A[i] < B[j]){
            C[k++] = A[i++];
        }else{
            C[k++] = B[j++];
        }
    }
    while(i < n){
        C[k++] = A[i++];
    }

    while(j < m){
        C[k++] = B[j++];
    }
    return C;
}

int find_missing(int * A, int n){
    int total = (n+1)*(n+2)/2;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += A[i];
    }
    return total - sum;
}

int main(){
     int arr[6] = {36,78,89,96,101,103};
     int arr1[4] = {2, 4, 6, 8};
    //  int *ptr = reverse(arr, 6);

    //  int *ptr1 = insert_s(arr, 6, 6);
    //  for(int i = 0; i < 6; i++){
    //     cout<<ptr1[i]<<" ";
    //  }
    // int *ptr2 = neg_on_side(arr, 6);
    // for(int i = 0; i < 6; i++){
    //     cout<<ptr2[i]<<" ";
    // }
      int *ptr3 = merge(arr, 6, arr1, 4);
        for(int i = 0; i < 10; i++){
            cout<<ptr3[i]<<" ";
        }
    return 0;
}