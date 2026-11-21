class Solution {
public:
    int minimumPushes(string word) {
        int x=word.size();

        if(x<=8){
            return x;
        }
        else if(x<=16){
            return (8+(x-8)*2);
        }
        else if(x<=24){
            return (8+16+(x-16)*3);
        }
        else{
            return (8+16+24+(x-24)*4);
        }
    }
};