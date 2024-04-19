#include <bits/stdc++.h>
using namespace std;

class Sort{
public:
    // sort 0,1,2
    void sortColors(vector<int>& nums) {
        /*
            [0 - low-1] -> 0
            [low - mid-1]-> 1
            [mid - high -1] -> unsorted
            [high - n] -> 2
        */
        int n = nums.size();
        int low =0,mid = 0,high =n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
                
            }
        }
    }
};