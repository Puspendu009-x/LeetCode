class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;

        int l=0,r=0,res=INT_MIN;

        while(r<n){
            mp[nums[r]]++;
            while(mp[nums[r]]>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            res = max(res,r-l+1);
            r++;
        }
        return res;
    }
};