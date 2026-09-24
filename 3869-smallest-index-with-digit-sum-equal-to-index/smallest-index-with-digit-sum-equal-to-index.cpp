class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        for(int i=0;i<n;i++){
            int c=0;
            while(nums[i]>0){
                c+=nums[i]%10;
                nums[i]/=10;
            }
            if(c==i) return i;
        }
        return -1;
    }
};