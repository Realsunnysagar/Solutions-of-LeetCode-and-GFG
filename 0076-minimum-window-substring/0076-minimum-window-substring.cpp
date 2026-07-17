class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0, sInd = -1, cnt = 0;
        int n = s.size(), m = t.size();
        int minLen = INT_MAX;
        vector<int> hash(256,0);
        for(int i = 0; i<m ;i++) hash[t[i]]++;

        while(right < n){

            if(hash[s[right]] > 0){
                cnt = cnt + 1;
            }
            hash[s[right]]--;
            while(cnt == m){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    sInd = left;
                }
                hash[s[left]]++;
                if(hash[s[left]] > 0) cnt = cnt - 1;
                left++;
            }
            right++;
        }
        return sInd == -1 ? "" : s.substr(sInd,minLen);
    }
};