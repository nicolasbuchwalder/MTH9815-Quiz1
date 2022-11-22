//
//  MaxHeap.h
//  MTH9815-quiz1
//
//  Created by Nicolas Buchwalder on 22.11.22.
//

#ifndef MaxHeap_h
#define MaxHeap_h

#include <vector>
#include <iostream>


class MaxHeap{
    
private:
    
    int _size;               // size of heap
    std::vector<int> _vec;        // vector to contain heap
    
    // getting the parent
    int _parent(int idx){ return idx / 2; };
    
public:
    
    // constructor
    MaxHeap()
        : _size{0}
    {};
    
    // method to add new number to heap
    void Add(int num){
        // augmenting the size of the heap and adding the element
        _size += 1;
        _vec.push_back(num);
        
        
        int idx = _size - 1;
        int p = _parent(idx);
        
        // putting the child higher while it is bigger than parent
        while (idx != 0 && _vec[idx] > _vec[p]){
            std::swap(_vec[idx], _vec[p]);
            idx = p;
            p = _parent(idx);
        }
        
    }
    void print(){
        std::cout << "[";
        for (auto elem : _vec) std::cout << elem << " ";
        std::cout << "]" << std::endl;
    }
};

#endif /* MaxHeap_h */
