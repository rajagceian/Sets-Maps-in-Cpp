class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int,int> mp;
        for(int ele : nums){
            int rev = 0;
            int temp = ele;
            while(temp){
                rev = rev*10 + temp%10;
                temp /=10;
            }
            mp[ele - rev]++;
        }
        long long cnt = 0;
        for(auto &pair : mp){
            long long f = pair.second;
            cnt += f*(f-1)/2;
        }
        cnt %= 1000000007;
        return cnt;
    }
};
