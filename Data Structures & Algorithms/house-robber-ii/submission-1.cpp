class Solution {
    int solve(vector<int>&nums,int start,int end){
        int rob1 = 0, rob2 = 0;
        for(int i = end ; i>=start; --i){
            int temp = max(nums[i]+rob2,rob1);
            rob2 = rob1;
            rob1 = temp;
        }
        return rob1;
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        return max(solve(nums,0,nums.size()-2),solve(nums,1,nums.size()-1));
    }
};
