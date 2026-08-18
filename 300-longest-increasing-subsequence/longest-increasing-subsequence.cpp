class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n  = nums.size();
        vector<int>dp;
        dp.push_back(nums[0]);
        int maxi=1;
        for(int i=0;i<n;i++){
            if(nums[i]<=dp.back()){
                int ind = lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
                dp[ind]=nums[i];
            }
            else{
                dp.push_back(nums[i]);
                maxi++;
            }
        }
        return maxi;
    }

};