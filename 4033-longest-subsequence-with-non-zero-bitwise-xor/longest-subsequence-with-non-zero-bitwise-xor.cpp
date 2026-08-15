class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int len = nums.size();
        bool nonZero=false;
        int tot=0;

        for(int n:nums){
            nonZero |= n>0;
            tot^= n;
        }

        if(tot!=0) return len;

        if(nonZero){
            return len-1;
        }

        return 0;
    }
};