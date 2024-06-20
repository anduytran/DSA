#include <vector>
#include <iostream>

/*
 A max heap is a binary tree where each node has a value that is greater than its children.
 It is typically used when you need quick access to the greatest value in a data structure.
 It is also a commonly used solution for the kth smallest value problem.
 */

class MaxHeap{
    std::vector<int> v;
    void heapifyUp(int &nodeIndex, int val){
        if(nodeIndex == 0){
            return;
        }
        int parentIndex = (nodeIndex + 1) / 2 - 1;
        if(v[nodeIndex] > v[parentIndex]){ // swap if needed
            v[nodeIndex] = v[parentIndex];
            v[parentIndex] = val;
            nodeIndex = parentIndex;
            heapifyUp(nodeIndex, val);
        }
    }

    void heapifyDown(int &nodeIndex, int val){
        if(nodeIndex == 0){
            return;
        }
        if(v[nodeIndex * 2 + 1] > v[nodeIndex] || v[nodeIndex * 2] > v[nodeIndex]){
            int greater = std::max(2 * nodeIndex, 2 * nodeIndex + 1);
            v[nodeIndex] = v[greater];
            v[greater] = val;
            nodeIndex = greater;
        }
    }

public:
    MaxHeap(){
        std::vector<int> vec;
        v = vec;
    }
    void push(int x){ // O(log n)
        if(v.empty()){ // if the vector is empty
            v.push_back(x); // no further work needs to be done
            return;
        }
        else{
            v.push_back(x); // if the vector isn't empty, push and heapify up
            int index = v.size() - 1;
            heapifyUp(index, x);
        }

    }
    void pop(){ // O(log n)
        v[0] = v[v.size() - 1];
        v.resize(v.size() - 1);
        int index = 0;
        heapifyDown(index, v[0]);
    }
    bool empty(){ // O(1)
        return v.empty();
    }
    int size(){ // O(1)
        return v.size();
    }
    int top(){ // O(1)
        return v[0];
    }
    void swap(MaxHeap& heap){ // O(n) with n being the size of the vectors
        if(heap.size() != size()){
            return;
        }
        std::vector<int> temp = heap.v;
        heap.v = v;
        v = temp;
        return;
    }
    void print(){ // O(n) with n being the size of the vectors
        std::string temp = "";
        for(int i = 0; i < v.size(); i++){
            temp += std::to_string(v[i]);
            temp += ", ";
        }
        temp.pop_back();
        temp.pop_back();
        std::cout << temp << std::endl;
    }
};

int main() {
    MaxHeap heap;
    heap.push(1);
    heap.push(3);
    heap.push(5);
    heap.print();

    MaxHeap heap2;
    heap2.push(2);
    heap2.push(4);
    heap2.push(6);
    heap2.print();

    heap.swap(heap2);
    heap.print();
    heap2.print();

    // 5, 1, 3
    // 6, 2, 4
    // 6, 2, 4
    // 5, 1, 3

    return 0;
}
