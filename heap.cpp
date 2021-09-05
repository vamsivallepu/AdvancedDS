#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
class MinHeap{
    vector<int> heap;
    public:
        MinHeap(){
            heap.push_back(-1);
        }
        void heapify(int i, int n){
            int left=2*i;
            int right=2*i+1;
            int t=i;
            if(left<n && heap[left]<heap[i]){
                t=left;
            }
            if(right<n && heap[right]<heap[i]){
                t=right;
            }
            if(t!=i){
                swap(heap[i], heap[t]);
                heapify(t,n);
            }
        }
        void insert(int data){
            heap.push_back(data);
            int index=heap.size()-1;
            int parent=index/2;
            while(index>1 && heap[parent]>heap[index]){
                swap(heap[index], heap[parent]);
                index=parent;
                parent=parent/2;
            }
        }
        void heapSort(){
            for(int i=heap.size(); i>0; i--){
                swap(heap[1], heap[i]);
                heapify(1, i-1);
            }
        }
        void pop(){
            int last=heap.size()-1;
            swap(heap[1], heap[last]);
            heap.pop_back();
            heapify(1, heap.size());
        }
        int top(){
            return heap[1];
        }
        void printHeap(){
            for(int i=1; i<heap.size(); i++)
                cout<<heap[i]<<" ";
            cout<<"\n";
        }
};
int main()
{
    /* code */
    MinHeap h;
    h.insert(21);
    h.insert(7);
    h.insert(1);
    h.insert(29);
    h.insert(11);
    h.insert(6);
    h.printHeap();
    // cout<<h.top();
    h.pop();
    h.printHeap();
    h.heapSort();
    h.printHeap();
    return 0;
}
