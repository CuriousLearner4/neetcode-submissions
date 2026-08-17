class Solution {
    int solve(int i, vector<int>& nums,vector<int> &dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(nums[i]+solve(i+2,nums,dp),solve(i+1,nums,dp));
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+2,0);
        for(int i = nums.size()-1 ; i>=0; --i){
            dp[i] = max(nums[i]+dp[i+2],dp[i+1]);
        }
        return dp[0];
    }
};
