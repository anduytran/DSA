#include <vector>
#include <iostream>

/*
 A max heap is a binary tree where each node has a value that is greater than its children.
 It is typically used when you need quick access to the greatest value in a data structure.
 It is also a commonly used solution for the kth smallest value problem.
 */


class MaxHeap{
    std::vector<int> v;
    void heapifyUp(int &nodeIndex, int val){ // required when pushing a node because when pushing to a max heap,
        if(nodeIndex == 0){                  // the node is inserted in the bottom right, so we need to check the
            return;                          // parents, grandparents, and ancestors until the node is in the right
        }                                    // place

        if(v[nodeIndex] > v[(nodeIndex + 1) / 2 - 1]){ // swap if needed
            v[nodeIndex] = v[(nodeIndex + 1) / 2 - 1];
            v[(nodeIndex + 1) / 2 - 1] = val;
            nodeIndex = (nodeIndex + 1) / 2 - 1;
            heapifyUp(nodeIndex, val); // recursive call
        }
    }

    void heapifyDown(int &nodeIndex, int val){
        if(nodeIndex == 0){ // base case
            return;
        }
        if(v[nodeIndex * 2 + 1] > v[nodeIndex] || v[nodeIndex * 2] > v[nodeIndex]){
            v[nodeIndex] = v[std::max(2 * nodeIndex, 2 * nodeIndex + 1)]; // std::max(2 * nodeIndex, 2 * nodeIndex + 1)
            v[std::max(2 * nodeIndex, 2 * nodeIndex + 1)] = val;          // gives the greater of the two children
            nodeIndex = std::max(2 * nodeIndex, 2 * nodeIndex + 1);       // to swap with
            heapifyDown(nodeIndex, val);
        }
    }

public:
    MaxHeap(){
        std::vector<int> vec;
        v = vec;
    }
    void push(int x){
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
    void pop(){
        v[0] = v[v.size() - 1]; // push last element in heap to the top
        v.resize(v.size() - 1); // resize
        int index = 0;
        heapifyDown(index, v[0]);
    }
    bool empty(){
        return v.empty();
    }
    int size(){
        return v.size();
    }
    int top(){
        return v[0];
    }
    void swap(MaxHeap& heap){
        if(heap.size() != size()){ // two heaps have to be the same size for them to swap elements
            return;
        }
        std::vector<int> temp = heap.v;
        heap.v = v;
        v = temp;
        return;
    }
    void print(){
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
    return 0;
}

// sample output
// 5, 1, 3
// 6, 2, 4
// 6, 2, 4
// 5, 1, 3