class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int ele : nums){
            if(ele < k) return -1;
            else if(ele > k) mp[ele]++;
        }
        return mp.size();
    }
};
