class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> ps(n+1,0);
        
        int i = 1;
        for(auto num : nums){
            ps[i] = num + ps[i-1];
            i++;
        }

        for(int i = 1; i <= n; ++i){
            if(ps[i]==(ps[n]-ps[i-1])){
                return i-1;
            }
        }
        return -1;
    }
};