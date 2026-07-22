class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int i= 0; i<n;i++){
            sum+=nums[i];
        }
        if (abs(target) > sum) return 0;

        if ((sum - target) % 2 != 0) return 0;

        int s = (sum - target)/2;

        vector<int>prev(s+1, 0);
        vector<int>curr(s+1, 0);
        if(nums[0]==0) prev[0]=2;
        else prev[0] = 1;

        if(nums[0] != 0 && nums[0]<=s)
        prev[nums[0]] = 1;

        for(int i = 1; i<n;i++){
            for(int t=0; t<=s; t++){
                int notTake = prev[t];
                int take = 0;
                if(nums[i]<=t) take =prev[t-nums[i]];

                curr[t] = take + notTake;
            }
            prev = curr;
        }
        return prev[s];
    }
};