class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if (k >= n) {
            return *max_element(arr.begin(), arr.end());
        }
        
        int currentMax = arr[0];
        int wins = 0;
        int i = 1;
        
        while (wins < k) {
            if (arr[i] > currentMax) {
                currentMax = arr[i];
                wins = 1;
            } else {
                wins++;
            }
            i = (i + 1) % n;
        }
        
        return currentMax;
    }
};