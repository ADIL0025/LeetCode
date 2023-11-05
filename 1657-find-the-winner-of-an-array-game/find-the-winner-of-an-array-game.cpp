class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int currentMax = arr[0];
        int wins = 0;

        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > currentMax) {
                currentMax = arr[i];
                wins = 1;
            } else {
                wins++;
            }

            if (wins == k) {
                break;
            }
        }

        return currentMax;
    }
};