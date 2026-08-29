class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans = 0;

        for(int i = 0; i < arr.size() - 1; i++) {
            if(arr[i] < arr[i + 1]) {
                ans = i + 1;
            }
        }

        return ans;
    }
};