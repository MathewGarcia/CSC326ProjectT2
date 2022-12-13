#pragma once


int const MAX = 50000;

class Sort {
public:
    void SetMax(int num);
    int GetMax();
    void print();
    void setData(int Arr[]);
    void fillArray(int* A, int len);
    void randomFillArray(int* A, int len);
private:
    //number of integers to be sorted
    int n;

    //data array
    int data[MAX];



};