class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        if(is_sorted(nums.begin(),nums.end())) return 0;

        int k=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                if(k==INT_MIN) k=nums[i];
                else{
                    k=k & nums[i];
                }
            }
        }
        return k;
    }
};