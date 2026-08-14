class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int l=0,r=0,res=INT_MIN;
        vector<int>freq(26,0);

        while(r<n){
            freq[s[r]-'a']++;

            while(freq[s[r]-'a']>2){
                freq[s[l]-'a']--;
                l++;
            }
            res=max(res,r-l+1);
            r++;
        }
        return res;
    }
};