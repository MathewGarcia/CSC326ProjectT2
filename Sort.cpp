#include "Sort.h"
#include <iostream>

using namespace std;

void Sort::SetMax(int num) {
    n = num;
}

int Sort::GetMax() {
    return n;
}

void Sort::print() {
    for (int i = 0; i < n; i++) {
	    std::cout << data[i] << " ";
    }
    cout << endl;
}

void Sort::setData(int Arr[]) {
    for (int i = 0; i < n; i++) {
        data[i] = Arr[i];
    }
}

void Sort::fillArray(int *A, int len) {
    for (int i = 0; i < len; i++) {
        A[i] = i + 1;
    }
}
void Sort::randomFillArray(int *A, int len) {
    for (int i = 0; i < len; i++) {
        A[i] = (rand() % (len - 1 + 1) + 1);
    }
}


