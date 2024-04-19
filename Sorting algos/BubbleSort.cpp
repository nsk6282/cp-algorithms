#include <bits/stdc++.h>
using namespace std;
class Sort{
public:
    void bubbleSort(vector<int> &arr){
        int n = arr.size();
        for(int i=n-1;i>=1;i--){
            for(int j=0;j<i;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
        }
        return;
    }
};