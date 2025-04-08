class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map <int,int> mp;
        for(int ele : nums){
            mp[ele]++;
        }
        int cnt = 0;
        while(nums.size()){
            if(nums.size() == mp.size()){
                return cnt;
            }
            else{
                for(int j=0;j<3 && j<nums.size();j++){
                    mp[nums[j]]--;
                    if(mp[nums[j]] == 0) mp.erase(nums[j]);
                }
                if(nums.size()>=3) nums.erase(nums.begin(),nums.begin()+3);
                else nums.erase(nums.begin(),nums.end());
                cnt++;
            }
        }
        return cnt;
    }
};
