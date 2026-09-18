class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<int>last(26,-1);
        vector<int>first(26,-1);
        vector<int>freq(26,0);
        vector<int>order;
        for(int i=0;i<n;i++){
            if(freq[s[i]-'a']==0){
                first[s[i]-'a']=i;
                order.push_back(s[i]-'a');
            }
            freq[s[i]-'a']++;
            last[s[i]-'a']=i;
        }

        vector<string>ans;
        deque<vector<int>>q;
        
        for(int c:order){
            q.push_front({first[c],last[c],freq[c]});
            int left = INT_MAX;
            int right = INT_MIN;
            int total = 0;

            for(auto&item:q){
                total+=item[2];
                left=min(left,item[0]);
                right = max(right,item[1]);

                if(total == right-left+1)
                break;
            }

            if(total == right - left +1){
                ans.push_back(s.substr(left,right-left+1));
                q.clear();
            }
        }
        return ans;
    }
};