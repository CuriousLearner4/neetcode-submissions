class NumArray {
    vector<int> prefixSum;
public:
    NumArray(vector<int>& nums) {
        prefixSum.resize(nums.size(),0);
        int i =0;
        for(auto num : nums){
            if(i>0) prefixSum[i]+=prefixSum[i-1];
            prefixSum[i]+=nums[i];
            i++;
        }
    }
    //-2 -2 1 -4
    int sumRange(int left, int right) {
        return left == 0?prefixSum[right]: prefixSum[right]-prefixSum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */