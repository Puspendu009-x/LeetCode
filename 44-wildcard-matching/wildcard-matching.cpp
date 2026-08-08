class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();

        vector<bool>prev(m+1,false),curr(m+1,0);

        prev[0] = true;
        for(int j=1;j<=m;j++){
            prev[j]=false;
        }

        for(int i=1;i<=n;i++){
            bool flag = true;
            for(int ii=1;ii<=i;ii++){
                if(p[ii-1]!='*'){
                    flag = false;
                    break;
                }
            }
            curr[0]=flag;
            for(int j=1;j<=m;j++){
                if(p[i-1]==s[j-1] || p[i-1]=='?'){
                    curr[j]=prev[j-1];
                }
                else if(p[i-1]=='*'){
                    curr[j] = prev[j]|curr[j-1];
                }
                else{
                    curr[j]= false;
                }
            }
            prev =curr;
        }
        return prev[m];
    }
};