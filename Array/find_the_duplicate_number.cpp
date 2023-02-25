// https://leetcode.com/problems/find-the-duplicate-number/description/

#include <bits/stdc++.h>
using namespace std;

int floyds_tortoise_and_hare(vector<int> &nums){
    int slow = nums[0], fast = nums[0];

    do{
        slow = nums[slow]; // move one step
        fast = nums[nums[fast]]; //move two steps
    } while (slow != fast);

    fast = nums[0];

    while (slow != fast){
        slow = nums[slow]; // move one step
        fast = nums[fast]; // move one step
    }

    return fast;
}

int hashMap(vector<int> &nums){
    vector<int> temp(nums.size(), 0);

    for (int i = 0; i < temp.size(); i++){
        temp[nums[i]]++;
    }
    int ans;
    for (int i = 1; i < temp.size(); i++){
        if (temp[i] > 1){
            ans = i;
            break;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }

    int floyds_tortoise_and_hare_value = floyds_tortoise_and_hare(nums);
    cout<<"FLoyd's tortoise and hare method: " << floyds_tortoise_and_hare_value<<endl;

    int hashMapValue = hashMap(nums);
    cout<<"Hashmap method: "<<hashMapValue<<endl;

    return 0;
}