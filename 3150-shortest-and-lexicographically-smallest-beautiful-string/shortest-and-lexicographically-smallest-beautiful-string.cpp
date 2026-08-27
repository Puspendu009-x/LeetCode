class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l=0; int r=0;
        string mini ="";
        int cnt=0;
        while(r<n){
            if(cnt==0 && s[r]=='0'){
                l++;
            }
            else if(s[r]=='1'){
                cnt++;
            }
            while(cnt==k){
                string st = s.substr(l,(r-l)+1);
                if(st.length()==k) return st;
                if(st.length()<mini.length() || mini.length()==0 ||(st.size()==mini.size()&&st<mini)){
                    mini = st;
                }
                if(s[l]=='1') {
                    cnt--;
                    l++;
                }
                while(s[l]=='0'){
                    l++;
                }
            }
            r++;
        }
        return mini;
    }
};