class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        vector<int>leftSmall(n);
        vector<int>rightSmall(n);
        for(int i=0;i<n;i++){
            while(!st.empty()&& heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty()) leftSmall[i]=0;
            else leftSmall[i]=st.top()+1;
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty()&& heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty()) rightSmall[i]=n-1;
            else rightSmall[i]=st.top()-1;
            st.push(i);
        }

        int maxA=INT_MIN;
        for(int i=0;i<n;i++){
            maxA = max(maxA, (heights[i]*(rightSmall[i]-leftSmall[i]+1)));
        }
        return maxA;
    }
};