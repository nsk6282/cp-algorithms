#include <bits/stdc++.h>
using namespace std;

class Sort{
public:
    void selectionSort(vector<int> &arr){
        int n = arr.size();
        for(int i=0;i<n-1;i++){
            int idx =i;
            for(int j=i;j<n;j++){
                if(arr[j]<arr[idx]){
                    idx = j;
                }
            }
            swap(arr[i],arr[idx]);
        }
    }
};