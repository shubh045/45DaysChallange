// https://leetcode.com/problems/sort-colors/description/

#include <bits/stdc++.h>
using namespace std;

void pointer_method(vector<int> &nums){
    int i=0, mid=0,j=nums.size()-1;

        while(mid<=j){
            if(nums[mid]==0){
                swap(nums[mid],nums[i]);
                i++;
                mid++;
            }else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid],nums[j]);
                j--;
            }
            
        }
}

void counter_method(vector<int> &nums){
    int count0=0, count1=0, count2=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            count0++;
        }else if(nums[i]==1){
            count1++;
        }else if(nums[i]==2){
            count2++;
        }
    }
    int i=0;
    for(;i<count0;i++){
        nums[i] = 0;
    }
    for(;i<count0+count1;i++){
        nums[i] = 1;
    }
    for(;i<nums.size();i++){
        nums[i] = 2;
    }
}

void printSortedArray(vector<int> &nums){
    for(int i=0;i<nums.size();i++){
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

    // pointer_method(nums);
    counter_method(nums);
    printSortedArray(nums);
    return 0;
}