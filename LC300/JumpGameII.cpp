class Solution {
public:
    
    int jump(vector<int>&nums){
        int n = nums.size();
        int dp[n];
        for(int i = 0; i<n; i++)
            dp[i] = INT_MAX;
        dp[0] = 0;
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                if(j+nums[j]>=i)
                    dp[i] = min(dp[i], dp[j]+1);                
            }
        }
        return dp[n-1];
    }
    /*int res = INT_MAX;
    int jump(vector<int> nums, int i, int step){
        if(i==nums.size()-1)
            return step;
        if(i>=nums.size())
            return INT_MAX;
        for(int k = 1; k<=nums[i]; k++){
            res = min(res, jump(nums, i+k, step+1)); // problem in the way res is updated
        }
        return res;
    }
    int jump(vector<int>& nums) {
        return jump(nums, 0, 0);    
    }*/
};
