//LeetCode 2442

// method - 1
class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        int maxEle = INT_MIN;
        for(int i=0;i<n;i++){
            int revNum = 0;
            int num = nums[i];
            while(num){
                revNum = 10*revNum + (num%10);
                num /=10;
            }
            nums.push_back(revNum);
            maxEle = max(maxEle , max(revNum , nums[i]));
        } 
        vector <bool> freq(maxEle+1 , false);
        int cnt = 0;
        for(int ele : nums){
            if(!freq[ele]) {
             freq[ele] = true;
             cnt++;
        }}
       return cnt;
    }
};

// *********************** method - 2 **************
class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_set <int> us;
        for(int i=0;i<n;i++){
             us.insert(nums[i]);
            int revNum = 0;
            int num = nums[i];
            while(num){
                revNum = 10*revNum + (num%10);
                num /=10;
            }
            us.insert(revNum);
        } 
       return us.size();
    }
};
