#include<stdio.h>
#include <iostream>
using namespace std;

// int func(int n){
//     if(n > 0) {
//         cout<< n << endl;
//         return func(n-1);
        

//     }
//     return 0;
// }

// int sum(int n){
//     if(n == 0) return 0;
//      return n + sum(n-1);
// }

// int fact(int n){
//     if( n == 0) return 1;
//      return n * fact(n-1);
// }


// int exponent(int a , int b){
//     if(b == 0) return 1;

//     if( b % 2 == 0){
//         return exponent(a * a, b/2);
//     }else{
//         return a * exponent(a * a, (b-1)/2);
//     }
// }

//taylor's series using recursion

// int e(int a, int b){
//     static int p = 1, f = 1;
//     int r;
//     if( b == 0) return 1;
//     else{
//         r = e(a, b-1);
//         p = p*a;
//         f = f*b;
//         return r + p/f;

//     }
// }

// int fib(int n){
//     if(n <=1 ) return n;
//     return fib(n-1)+fib(n-2);
// }

// int f[10];

// int fib(int n){
//     if(n <=1 ){
//         f[n] = n;
//         return n;
//     }else{
//         if(f[n-1] == -1){
//             f[n-1] = fib(n-1);
//         }if(f[n-2] == -1){
//             f[n-2] = fib(n-2);
//         }
//         return f[n-1] + f[n-2];
//     }
// }

// combination formula using recursion from Pascal's triangle

// Tower of Hanoi problem using recursion
void TOH(int n , int A, int B, int C){
    if(n > 0){
        TOH(n-1, A, C, B);
        cout<< "Move disk" <<n<< "from A to C" << endl;
        TOH(n-1, B, A, C);
    }
}

int c(int n, int r){
    if( r == 0 || n == r) return 1;
    return c(n-1, r-1) + c(n-1, r);
}
int main(){
   
    return 0;
}