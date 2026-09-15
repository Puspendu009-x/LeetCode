class Solution {
private:
    // Optimized to check in-place without creating or reversing substrings
    bool isPalin(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        int ans = 0;
        
        if (k == 1) return n;

        int i = 0;
        while (i <= n - k) {
            // Greedy Choice 1: Can we make a palindrome of exactly length k?
            if (isPalin(s, i, i + k - 1)) {
                ans++;
                i += k; // Jump entirely past this palindrome to prevent overlaps
            } 
            // Greedy Choice 2: Can we make a palindrome of exactly length k+1?
            else if (i + k < n && isPalin(s, i, i + k)) {
                ans++;
                i += k + 1; // Jump entirely past this palindrome
            } 
            else {
                // If neither length k nor k+1 works starting here, slide the window by 1
                i++;
            }
        }
        
        return ans;
    }
};