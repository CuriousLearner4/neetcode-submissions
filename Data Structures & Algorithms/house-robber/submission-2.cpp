class Solution {
    int solve(int i, vector<int>& nums,vector<int> &dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i] = max(nums[i]+solve(i+2,nums,dp),solve(i+1,nums,dp));
    }
public:
    int rob(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;
        for(int i = nums.size()-1 ; i>=0; --i){
            int temp = max(nums[i]+rob2,rob1);
            rob2 = rob1;
            rob1 = temp;
        }
        return rob1;
    }
};
