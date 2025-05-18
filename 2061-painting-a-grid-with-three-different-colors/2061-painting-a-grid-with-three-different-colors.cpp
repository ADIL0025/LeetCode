class Solution {
public:
    int colorTheGrid(int m, int n) {
        auto isValidState = [&](int state) {
            int lastColor = -1;
            for (int i = 0; i < m; ++i) {
                int currentColor = state % 3;
                if (currentColor == lastColor) {
                    return false;
                }
                lastColor = currentColor;
                state /= 3;
            }
            return true;
        };

        auto areValidNeighbors = [&](int state1, int state2) {
            for (int i = 0; i < m; ++i) {
                if (state1 % 3 == state2 % 3) {
                    return false;
                }
                state1 /= 3;
                state2 /= 3;
            }
            return true;
        };

        const int mod = 1e9 + 7;
        int maxStates = pow(3, m);

        unordered_set<int> validStates;
        vector<int> stateCounts(maxStates);

        for (int i = 0; i < maxStates; ++i) {
            if (isValidState(i)) {
                validStates.insert(i);
                stateCounts[i] = 1;
            }
        }
        unordered_map<int, vector<int>> neighborStates;
        for (int i : validStates) {
            for (int j : validStates) {
                if (areValidNeighbors(i, j)) {
                    neighborStates[i].push_back(j);
                }
            }
        }

        for (int k = 1; k < n; ++k) {
            vector<int> newCounts(maxStates);
            for (int i : validStates) {
                for (int j : neighborStates[i]) {
                    newCounts[i] = (newCounts[i] + stateCounts[j]) % mod;
                }
            }
            stateCounts = move(newCounts);
        }

        int answer = 0;
        for (int count : stateCounts) {
            answer = (answer + count) % mod;
        }

        return answer;
    }
};