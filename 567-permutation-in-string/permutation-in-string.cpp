class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int freq1[26] = {0};
        int freq2[26] = {0};

        // s1 ki frequency
        for(char c : s1) {
            freq1[c - 'a']++;
        }

        int k = s1.size();

        // Sliding Window
        for(int i = 0; i < s2.size(); i++) {

            // Current character add
            freq2[s2[i] - 'a']++;

            // Window size k se badi ho gayi
            if(i >= k) {
                freq2[s2[i - k] - 'a']--;
            }

            // Window size k ho gayi
            if(i >= k - 1) {

                bool same = true;

                // freq1 aur freq2 compare
                for(int j = 0; j < 26; j++) {

                    if(freq1[j] != freq2[j]) {
                        same = false;
                        break;
                    }
                }

                if(same) {
                    return true;
                }
            }
        }

        return false;
    }
};