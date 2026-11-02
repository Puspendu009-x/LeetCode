class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int sum=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            sum+=abs(nums[i]-nums[n/2]);
        }
        return sum;
    }
};