class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        vector<int>basket(fruits.size(),0);
        int l = 0, r = 0, maxlen = 0;
        int flag = 0;

        while (r < fruits.size()) {
            if(basket[fruits[r]]==0)
            flag++;
            basket[fruits[r]]++;
            

            while(flag>2){
                basket[fruits[l]]--;
                if(basket[fruits[l]]==0)
                flag--;
                l++;
            }
            maxlen=max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};
