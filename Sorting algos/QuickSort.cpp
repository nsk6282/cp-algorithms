#include <bits/stdc++.h>
using namespace std;
/*
1.Pick a pivot & place in its correct place in an sorted array. the choices for pivot are:-
    a) 1st element in the array
    b) last element in the array
    c) median of the array
    d) random element in the array
2. put smaller elements on the left and larger elements on right
3. for descending, put larger elements on thee left and smaller on right
*/

class Sort{
public:
    int partition(int low,int high,vector<int> &arr){
    int pivot = low;
    int i = low,j = high;
    while(i<j){
        while(arr[i]<=arr[pivot] && i<=high-1) i++;
        while(arr[j]>arr[pivot] && j>=low+1) j--;
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[pivot],arr[j]);
    return j;
}
void quickSort(int low,int high,vector<int> &arr){
    if(low<high){
        int pIndex = partition(low,high,arr);
        quickSort(low,pIndex-1,arr);
        quickSort(pIndex+1,high,arr);
    }
}
};