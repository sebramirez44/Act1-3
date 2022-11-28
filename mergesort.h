#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
using namespace std;
class mergesort{
private:
    vector<Item> v = {};
public:
    
    mergesort(vector<Item> vec){
        this->v = vec;
        vector<Item> helper = this->v;
        mergesortC(helper, 0, v.size()-1);
    }
    void mergesortC(vector<Item>helper, int low, int high){
        int middle = (low + high)/2;
        mergesortC(helper,low,middle);
        mergesortC(helper,middle+1,high);
        merge(helper,low,middle,high);
    }
    void merge(vector<Item> helper, int low, int middle, int high){
        for (int i = low; i <= high; i++){
            helper[i] = this->v[i];
        }
        int helperLeft = low;
        int helperRight = middle + 1;
        int current = low;
        while (helperLeft <= middle && helperRight <= high){
            if (helper[helperLeft].compare(helper[helperLeft],helper[helperRight]) == 1 || helper[helperLeft].compare(helper[helperLeft],helper[helperRight]) == 2){
                this->v[current] = helper[helperLeft];
                helperLeft++;
            }
            else{
                this->v[current] = helper[helperRight];
                helperRight++;
            }
            current++;
        }
        int remaining = middle - helperLeft;
        for (int i = 0; i < remaining; i++){
            this->v[current+i] = helper[helperLeft+i];
        }
    }
    vector<Item> getV(){
        return this->v;
    }
    vector<Item> setV(vector<Item> newV){
        this->v = newV;
    }

};