class Solution {
public:

     void solve(vector<int>& nums,vector<int>& ds,int freq[],vector<vector<int>>& ans){
        if(ds.size()==nums.size()){
            if(find(ans.begin(), ans.end(), ds) == ans.end())
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i]=1;
                solve(nums,ds,freq,ans);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++) freq[i]=0;
        solve(nums,ds,freq,ans);
        return ans;
    }
};