/* 
    tc- o(nlogn)
    sc- o(n)
*/
#include <bits/stdc++.h>
using namespace std;

class Sort{
public:
    void merge(int low,int mid,int high,vector<int> &arr){
        vector<int> temp(high-low+1);
        for(int i=low;i<=high;i++){
            temp[i-low] = arr[i];
        }
        int i=low,j=mid+1; int k=low;
        while(i<=mid && j<=high){
            if(temp[i-low]<temp[j-low]){
                arr[k++] = temp[i++ - low];
            }
            else arr[k++] = temp[j++ - low];
        }
        while(i<=mid) arr[k++] = temp[i++ - low];
        return;
    }
    void mergeSort(int low,int high,vector<int> &arr){
        if(low==high) return;
        int mid = (low+high)/2;
        mergeSort(low,mid,arr);
        mergeSort(mid+1,high,arr);
        merge(low,mid,high,arr);

    }
};