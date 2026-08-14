class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<int>freqs(26,0);
        vector<int>freqp(26,0);

        for(int i =0;i<m;i++){
            freqp[p[i]-'a']++;
        }

        int l=0,r=0;
        vector<int>ans;
        while(r<n){
            freqs[s[r]-'a']++;

            if((r-l+1)==m){
                bool flag=true;
                for(int i=l;i<=r;i++){
                    if(freqs[s[i]-'a']!=freqp[s[i]-'a']){
                        flag=false;
                        break;
                    }
                }
                if(flag==true){
                    ans.push_back(l);
                }
                freqs[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return ans;

    }
};