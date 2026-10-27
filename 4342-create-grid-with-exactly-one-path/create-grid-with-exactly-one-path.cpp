class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        string m0="";
        string a="";
        for(int i=0;i<n;i++){
            m0+=".";
            if(i==(n-1)) a+=".";
            else a+="#";
        }

        ans.push_back(m0);
        for(int i=1;i<m;i++){
            ans.push_back(a);
        }
        return ans;
    }
};