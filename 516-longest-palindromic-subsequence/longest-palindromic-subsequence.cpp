class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(),s2.end());
        return lcs(s,s2);
    }

    int lcs(string s1, string s2){
        int n=s1.size();
        int m = s2.size();

        vector<int>prev(m+1,0);
        vector<int>cur(m+1,0);

        for(int j=0;j<=m;j++)
        prev[j] = 0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) cur[j]=1+prev[j-1];
                else cur[j] = max(prev[j],cur[j-1]);
            }
            prev= cur;
        }
        return prev[m];
    }
};