#include <bits/stdc++.h>
using namespace std;

class MajorityElement{
public:
    int majorityEle(vector<int>& nums) {
        int cnt=1,ele = nums[0];
        for(int i=1;i<nums.size();i++){
            if(cnt==0){
                ele = nums[i];
                cnt=1;
                continue;
            }
            cnt +=(nums[i]==ele)?1:-1;
        }
        return ele;
    }
};