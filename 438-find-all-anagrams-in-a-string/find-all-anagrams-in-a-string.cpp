class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        int k = p.length();

        if(p.length() > s.length()) {
    return ans;
}

        int freq1[26] = {0};

        for(char c : p) {
            freq1[c - 'a']++;
        }

        int freq2[26] = {0};

        // First window
        for(int i = 0; i < k; i++) {
            freq2[s[i] - 'a']++;
        }

        // Check first window
        if(equal(freq1, freq1 + 26, freq2)) {
            ans.push_back(0);
        }

        // Sliding window
        for(int i = k; i < s.length(); i++) {

            // Remove old character
            freq2[s[i - k] - 'a']--;

            // Add new character
            freq2[s[i] - 'a']++;

            // Check current window
            if(equal(freq1, freq1 + 26, freq2)) {
                ans.push_back(i - k + 1);
            }
        }

        return ans;
    }
};