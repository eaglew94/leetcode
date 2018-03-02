class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int len=nums.size();
        for(int n=0;n<len;n++)
        {
            for(int m=n+1;m<len;m++)
            {
                if(nums[n]+nums[m]==target)
                {
                    vector<int> res;
                    res.push_back(n);
                    res.push_back(m);
                    return res;
                }
            }
        }
        
    }
};