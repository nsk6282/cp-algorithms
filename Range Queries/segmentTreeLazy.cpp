#include <bits/stdc++.h>
using namespace std;
class segmentTree{
    vector<int> st,lazy;
public:
    segmentTree(int n){
        st.resize(4*n+1);
        lazy.resize(4*n+1,0);
    }
    void build(int i,int low,int high,vector<int> &nums){
        if(low==high){
            st[i] = nums[low];
            return;
        }
        int mid = (low+high)/2;
        build(2*i+1,low,mid,nums);
        build(2*i+2,mid+1,high,nums);
        st[i]= st[2*i+1] + st[2*i+2];
    }
    void update(int i,int low,int high,int l,int r,int val){
        if(lazy[i]){
            st[i]+=(high-low+1)*lazy[i];
            if(low!=high){
                lazy[2*i+1] +=lazy[i];
                lazy[2*i+2] += lazy[i];
            }
            lazy[i]=0;
        }
        if(low>r || high<l) return;
        else if(low>=l && high<=r){
            st[i]+= (high-low+1)*val;
            if(low!=high){
                lazy[2*i+1] +=lazy[i];
                lazy[2*i+2] += lazy[i];
            }
            return;
        }
        int mid = (low+high)/2;
        update(2*i+1,low,mid,l,r,val);
        update(2*i+2,mid+1,high,l,r,val);
        st[i]= st[2*i+1] + st[2*i+2];
    }
    int query(int i,int low,int high,int l,int r){
        if(lazy[i]){
            st[i]+=(high-low+1)*lazy[i];
            if(low!=high){
                lazy[2*i+1] +=lazy[i];
                lazy[2*i+2] += lazy[i];
            }
            lazy[i]=0;
        }
        if(low>r || high<l) return 0;
        else if(low>=l && high<=r){
            return st[i];
        }
        int mid = (low+high)>>1;
        int left = query(2*i+1,low,mid,l,r);
        int right = query(2*i+2,mid+1,right,l,r);
        return left+right;
    }
};



int main(){
    int x;
    cin>>x;
    cout<<"HEY "<<x;
}
