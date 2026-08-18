// Parent       = (i - 1) / 2
// Left child   = 2*i + 1
// Right child  = 2*i + 2;  where i is the index of array

#include<bits/stdc++.h>
using namespace std;

class maxHeap{
    vector<int> heap;

    public:
    void insert(int x){
        heap.push_back(x);

        int i = heap.size()-1;

        // heapify up

        while( i > 0){
            int parent = (i-1)/2;

            if(heap[parent] >= heap[i]) break;

            swap(heap[parent], heap[i]);
            i = parent;
        }
    }

    int getMax(){
        if(heap.empty()){
            return -1;
        }
        return heap[0];
    }
    int extractMax() {
        if (heap.empty())
            return -1;

        int ans = heap[0];

        heap[0] = heap.back();
        heap.pop_back();

        // Heapify Down
        int i = 0;

        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < heap.size() && heap[left] > heap[largest])
                largest = left;

            if (right < heap.size() && heap[right] > heap[largest])
                largest = right;

            if (largest == i)
                break;

            swap(heap[i], heap[largest]);
            i = largest;
        }

        return ans;
    }


    bool isEmpty() {
        return heap.empty();
    }

    void display() {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }

};



int main() {
    maxHeap h;

    h.insert(50);
    h.insert(30);
    h.insert(40);
    h.insert(10);
    h.insert(20);
    h.insert(60);

    cout << "Heap: ";
    h.display();

    cout << "Maximum: " << h.getMax() << endl;

    cout << "Deleted: " << h.extractMax() << endl;

    cout << "Heap after deletion: ";
    h.display();

    return 0;
}