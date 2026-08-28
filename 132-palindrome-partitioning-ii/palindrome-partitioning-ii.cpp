class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int minCost=INT_MAX;
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s)){
                    int cost = 1+ dp[j+1];
                    minCost = min(minCost,cost);
                }
            }
            dp[i] = minCost;
        }
        return dp[0]-1;
    }

    bool isPalindrome(int i,int j,string &st){
        while(i<j){
            if(st[i]!=st[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};