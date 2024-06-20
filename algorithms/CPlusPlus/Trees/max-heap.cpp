#include <vector>
#include <iostream>

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
        v[0] = v[v.size() - 1];
        v.resize(v.size() - 1);
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
        if(heap.size() != size()){
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
