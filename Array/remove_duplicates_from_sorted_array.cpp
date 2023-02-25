// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

#include<bits/stdc++.h>
using namespace std;

int two_pointer_approach(vector<int> &nums){
    int j=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
}

void print_unique_array(vector<int> &nums, int j){
    for(int i=0;i<j;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    int j = two_pointer_approach(nums);
    print_unique_array(nums,j);
    return 0;
}