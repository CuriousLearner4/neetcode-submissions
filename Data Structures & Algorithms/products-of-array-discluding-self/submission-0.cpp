class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int productofarray = 1;
        int countofzero = 0;
        for(auto num : nums){
            if(num==0){
                countofzero++;
                continue;
            }
            productofarray *=num;
        }

        vector<int> result;

        for(auto num:nums){
            if(countofzero>0){
                if(countofzero == 1){
                    if(num==0)
                    result.push_back(productofarray);
                    else result.push_back(0);
                }else if(countofzero>1){
                    result.push_back(0);
                }
                    
            }else{
                result.push_back(productofarray/num);
            }
            
        }
        return result;
    }
};