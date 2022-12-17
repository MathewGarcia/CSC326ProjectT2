// CSC326 Project Task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Mathew Garcia - Did bubble sort and merge sort
//Jawad Rada - Did Insertion and Quick sort
//Nick Talledo - Did Heap and Selection Sort
//We all put the project together.

#include <iostream>
#include <chrono>
#include "Sort.h"

using namespace std;

int input;
int len;
int* A;
int* B;
char response;
int tally = 0;
int totalTime;
int totalTime2;
int totalTime3;
int totalTime4;
int totalTime5;
int totalTime6;
long long int totalSteps;
long long int totalSteps2;
long long int totalSteps3;
long long int totalSteps4;
long long int totalSteps5;
long long int totalSteps6;



void BubbleSort(int arr[], int n);
void Swap(int i, int j,int *A);
void MergeSort(int* arr, int begin, int end);
void Merge(int* arr, int begin, int mid, int end);
int NextInput(int num);
void ResetArrayB();

Sort s;

void Swap(int i, int j,int *arr) {

    int tmp = 0;
    if (i >= 0 && i < len) {
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

void BubbleSort(int arr[], int n) {
    long int steps = 0;
    auto start = std::chrono::high_resolution_clock::now();

        steps++;
    for (int i = 1; i < n; i++) {
                steps+=3;
        for (int j = 0; j <= n - i - 1; j++) {
                        steps+=3;
            if (arr[j] > arr[j + 1]) {
                Swap(j, j + 1,arr);
                                steps+=3;
            }
        }
                steps++;
    }
        steps++;

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::microseconds> (stop - start);
    totalTime += duration.count();
	totalSteps+=steps;
    duration.zero();
}



void MergeSort(int* arr, int begin, int end) {
    //if being passes end or if end is out of bounds, stop.
    if (begin < end) {
        //we call begin < end
        totalSteps2++;
        int mid = (begin + end) / 2;
        //before merge sort
        totalSteps2++;
        MergeSort(arr, begin, mid);
        //before merge sort again
        totalSteps2++;
        MergeSort(arr, mid + 1, end);
        //before merging
        totalSteps2++;
        Merge(arr, begin, mid, end);
    }
    //if begin < end is false
    totalSteps2++;
    return;
}


void Merge(int* arr, int begin, int mid, int end) {
    int steps;
    int* arrB = new int[end - begin + 1];
    int i = begin;
    int j = mid + 1;
    int k = 0;

    steps = 0;

    k = 0;

    while (i <= mid && j <= end) {
        steps++;
        if (arr[i] <= arr[j]) {
            arrB[k] = arr[i];
            i++;
            steps++;
        }
        else {
            steps++;
            arrB[k] = arr[j];
            j++;
        }
        steps++;

        k++;
    }

    while (i <= mid) {
        arrB[k] = arr[i];
        i++;
        k++;
        steps++;
    }
    steps++;
    while (j <= end) {
        arrB[k] = arr[j];
        j++;
        k++;
        steps++;
    }
    steps++;

    s.setData(arr);

    k = 0;
    steps++;
    for (int i = begin; i <= end; i++) {
        arr[i] = arrB[k];
        k++;
        steps += 2;
    }
    steps++;

    delete[] arrB;

    totalSteps2 += steps;

}

int NextInput(int num) {
    switch (num) {
    case 0: return 100;
    case 1: return 300;
    case 2: return 500;
    case 3: return 1000;
    case 4: return 3000;
    case 5: return 5000;
    case 6: return 10000;
    case 7: return 50000;
    default: return 0;
    }
}


void ResetArrayB() {
    for (int i = 0; i < len; i++) {
        B[i] = A[i];
    }
}


void insertionsort(int A[], int size)
{

    auto start = std::chrono::high_resolution_clock::now();

    int steps = 0;

    steps++;
    for (int i = 1; i <= size - 1; i++)
    {
        steps += 4;
        int temp = A[i];

        for (int j = i - 1; j >= 0 && temp < A[j]; j--)
        {
            steps += 5;
            A[j + 1] = A[j];
            A[j] = temp;
        }
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::microseconds> (stop - start);
    totalTime3 += duration.count();
    duration.zero();
    totalSteps3 += steps;
}

int partition(int A[], int begin, int end)
{
    int steps = 0;
    steps += 3;
    int pivot = A[end];
    int index = (begin - 1);

    for (int j = begin; j <= end - 1; j++)
    {
        steps += 3;
        if (A[j] < pivot)
        {
            steps += 4;
            index++;
            swap(A[index], A[j]);
        }
    }

    steps += 4;
    swap(A[index + 1], A[end]);
    totalSteps4 += steps;
    return (index + 1);
}

void quickSort(int A[], int begin, int end)
{
    int steps = 0;

    steps++;
    if (begin < end)
    {
        steps++;
        int p = partition(A, begin, end);

        steps++;
        quickSort(A, begin, p - 1);

        steps++;
        quickSort(A, p + 1, end);
    }
    totalSteps4 += steps;
}


void selectionSort(int selectionArray[], int n) {
    int min;
    auto start = std::chrono::high_resolution_clock::now();

    int steps = 0;
    steps++;
    for (int k = 0; k < n - 1; k++) {
        min = k;
        steps += 4;
        for (int j = k + 1; j < n; j++) {
            if (selectionArray[j] < selectionArray[min]) {
                min = j;
                steps+=4;
            }

        }
        swap(selectionArray[min], selectionArray[k]);
        steps += 3;
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<std::chrono::microseconds> (stop - start);
    totalTime5 += duration.count();
    duration.zero();
    totalSteps5 += steps;
}


void heapify(int heapArray[], int n, int i) {
    int largest = i;
    int steps = 0;

    int l = 2 * i + 1;
    int r = 2 * i + 2;
    steps += 3;
    if (l < n && heapArray[l] > heapArray[largest])
        largest = l;
    steps++;
    if (r < n && heapArray[r] > heapArray[largest])
        largest = r;
    steps++;
    if (largest != i) {
        swap(heapArray[i], heapArray[largest]);
        heapify(heapArray, n, largest);
        steps += 2;
    }
    totalSteps6 += steps;
}

void heapSort(int heapArray[], int n) {

    int steps = 0;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(heapArray, n, i);
    steps += 4;
    for (int i = n - 1; i > 0; i--) {
        swap(heapArray[0], heapArray[i]);
        heapify(heapArray, i, 0);
        steps +=7;
    }
    totalSteps6 += steps;

}


const int INSERTION_SORT_THRESHOLD = 32;

void merge(int* array, int size, int* temp) {
    int middle = size / 2;
    int i = 0, j = middle, k = 0;
    while (i < middle && j < size) {
        if (array[i] < array[j]) {
            temp[k++] = array[i++];
        }
        else {
            temp[k++] = array[j++];
        }
    }
    while (i < middle) {
        temp[k++] = array[i++];
    }
    while (j < size) {
        temp[k++] = array[j++];
    }
    for (int i = 0; i < size; i++) {
        array[i] = temp[i];
    }
}

void merge_sort_combine(int* array, int size, int* temp) {
    if (size <= INSERTION_SORT_THRESHOLD) {
        return;
    }
    int middle = size / 2;
    merge_sort_combine(array, middle, temp);
    merge_sort_combine(array + middle, size - middle, temp);
    merge(array, size, temp);
}

void combine_merge_sort_and_insertion_sort(int* array, int size) {
    if (size <= INSERTION_SORT_THRESHOLD) {
        // Use insertion sort for small arrays
        insertionsort(array, size);
    }
    else {
        // Use merge sort for larger arrays
        int* temp = new int[size];
        merge_sort_combine(array, size, temp);
        delete[] temp;
    }
}


int main() {



    srand(unsigned(time(0)));

     totalTime = 0;
    totalTime2 = 0;
    totalTime3 = 0;
    totalTime4 = 0;
    totalTime5 = 0;
    totalTime6 = 0;
    int totalTime7 = 0;
    totalSteps = 0;
    totalSteps2 = 0;
    totalSteps3 = 0;
    totalSteps4 = 0;
    totalSteps5 = 0;
    totalSteps6 = 0;


    do {
        
        input = NextInput(tally);


        cout << "Size of array currently is: " << input << endl;

        s.SetMax(input);

        len = s.GetMax();

        A = new int[len];
        B = new int[len];

        for (int i = 0; i < 50; i++) {

            s.randomFillArray(A, len);

            //Bubble Sort In Order

            ResetArrayB();

            BubbleSort(B, len);

            s.setData(B);

            //s.print();

            //End Bubble Sort In Order

            //Begin Merge Sort

            ResetArrayB();


            chrono::high_resolution_clock::time_point start1 = chrono::high_resolution_clock::now();

            MergeSort(B, 0, len - 1);

            auto stop1 = std::chrono::high_resolution_clock::now();
            chrono::high_resolution_clock::time_point end1 = chrono::high_resolution_clock::now();
            chrono::duration<double, std::micro> timeRequired2 = (end1 - start1);
            totalTime2 += timeRequired2.count();


            s.setData(B);

            //s.print();
            //End Merge Sort

            //Begin Insertion Sort
            ResetArrayB();

            insertionsort(B, len);

            s.setData(B);

            //s.print();
            //End Insertion Sort

            //Begin Quick Sort

			ResetArrayB();

            auto start2 = std::chrono::high_resolution_clock::now();


            quickSort(B, 0, len - 1);

            auto stop2 = std::chrono::high_resolution_clock::now();
            auto duration2 = chrono::duration_cast<std::chrono::microseconds> (stop2 - start2);
            totalTime4 += duration2.count();
            duration2.zero();


            s.setData(B);

            //s.print();

            //End Quick Sort

            //Begin Selection Sort
            ResetArrayB();

            selectionSort(B, len);

            s.setData(B);

            //s.print();
            //End Selection Sort

            //Begin HeapSort
            ResetArrayB();

            auto start3 = std::chrono::high_resolution_clock::now();


            heapSort(B, len);


            auto stop3 = std::chrono::high_resolution_clock::now();
            auto duration3 = chrono::duration_cast<std::chrono::microseconds> (stop3 - start3);
            totalTime6 += duration3.count();
            duration3.zero();


            s.setData(B);

            //s.print();
            //End HeapSort

            //combine merge and insertion sort
        	ResetArrayB();
            auto start4 = std::chrono::high_resolution_clock::now();

            combine_merge_sort_and_insertion_sort(B, len);

            auto stop4 = std::chrono::high_resolution_clock::now();
            auto duration4 = chrono::duration_cast<std::chrono::microseconds> (stop4 - start4);
            totalTime7 += duration4.count();
            duration4.zero();

            s.setData(B);


            // end combine merge and insertion
        }


         
        cout << "AVG Bubble Sort Steps: " << totalSteps / 50 << " For size :" << input << endl;
        cout << "AVG Bubble Sort Time: " << totalTime / 50 << " For size: " << input  << endl;
        cout << "AVG Merge Sort Steps: " << totalSteps2 / 50 << " For size: " << input << endl;
        cout << "AVG Merge Sort Time: " << totalTime2 / 50 << " For size: " << input << endl;
        cout << "AVG Insertion Sort Steps: " << totalSteps3 / 50 << " For size: " << input << endl;
        cout << "AVG Insertion Sort Time: " << totalTime3 / 50 << " For size: " << input << endl;
        cout << "AVG Quick Sort Steps: " << totalSteps4 / 50 << " For size: " << input << endl;
        cout << "AVG Quick Sort Time: " << totalTime4 / 50 << " For size: " << input << endl;
        cout << "AVG Selection Sort Steps: " << totalSteps5 / 50 << " For size: " << input << endl;
        cout << "AVG Selection Sort Time: " << totalTime5 / 50 << " For size: " << input << endl;
        cout << "AVG Heap Sort Steps: " << totalSteps6 / 50 << " For size: " << input << endl;
        cout << "AVG Heap Sort Time: " << totalTime6 / 50 << " For size: " << input << endl;
        cout << "AVG Merge Sort and Insertion Sort Time: " << totalTime7 / 50 << " For size: " << input << endl;

        delete A;
        delete B;


        tally++;



        cout << "\n";

    } while (input < MAX);



    return 0;
}

