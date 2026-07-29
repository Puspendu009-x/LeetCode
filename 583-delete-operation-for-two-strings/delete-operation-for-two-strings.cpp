class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int ls = lcs(word1,word2,n,m);

        return ((n+m)-(2*ls));
    }

    int lcs(string s1,string s2, int n, int m){
        vector<int>prev(m+1,0),curr(m+1,0);

        for(int j=0;j<=m;j++) prev[j]=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) curr[j] = 1+ prev[j-1];
                else curr[j]= max(prev[j],curr[j-1]);
            }
            prev = curr;
        }
        return prev[m];
    }
};