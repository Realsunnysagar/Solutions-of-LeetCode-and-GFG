class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0 , right = 0, maxLen = 0, maxf = 0;
        int hash[26] = {0};

        while(right < s.size()){
            hash[s[right] - 'A']++;
            maxf = max(maxf, hash[s[right] - 'A']);
            if((right - left + 1) - maxf > k){
                hash[s[left] - 'A']--; maxf = 0;
                left = left + 1;
            }
            if((right -left + 1) > maxf <= k)
                maxLen = max(maxLen, (right - left + 1));
            right ++;
        } 
        return maxLen;
    }
};