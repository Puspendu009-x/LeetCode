class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans=0;
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }
        for(int i=0;i<n;i++){
            ans+=(maxi-nums[i]);
        }
        return ans;
    }
};