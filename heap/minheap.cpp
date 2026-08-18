#include <bits/stdc++.h>
using namespace std;

class MinHeap {
    vector<int> heap;

public:

    void insert(int x) {
        heap.push_back(x);

        int i = heap.size() - 1;

        // Heapify Up
        while (i > 0) {
            int parent = (i - 1) / 2;

            if (heap[parent] <= heap[i])
                break;

            swap(heap[parent], heap[i]);
            i = parent;
        }
    }

    int getMin() {
        if (heap.empty())
            return -1;

        return heap[0];
    }

    int extractMin() {
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
            int smallest = i;

            if (left < heap.size() && heap[left] < heap[smallest])
                smallest = left;

            if (right < heap.size() && heap[right] < heap[smallest])
                smallest = right;

            if (smallest == i)
                break;

            swap(heap[i], heap[smallest]);
            i = smallest;
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
    MinHeap h;

    h.insert(50);
    h.insert(30);
    h.insert(40);
    h.insert(10);
    h.insert(20);
    h.insert(60);

    cout << "Heap: ";
    h.display();

    cout << "Minimum: " << h.getMin() << endl;

    cout << "Deleted: " << h.extractMin() << endl;

    cout << "Heap after deletion: ";
    h.display();

    return 0;
}