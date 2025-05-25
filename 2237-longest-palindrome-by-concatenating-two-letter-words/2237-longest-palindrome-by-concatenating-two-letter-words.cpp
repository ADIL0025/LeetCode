class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> wordCount;
      
        for (auto& word : words) {
            wordCount[word]++;
        }
        int longestLength = 0, middleInserted = 0;

        for (auto& [key, value] : wordCount) {
            string reversedKey = key;
            reverse(reversedKey.begin(), reversedKey.end());

            if (key[0] == key[1]) {
                middleInserted += value & 1;
                longestLength += (value / 2) * 2 * 2; 
            } else if (wordCount.count(reversedKey)) {  
                longestLength += min(value, wordCount[reversedKey]) * 2;
            }
        }
        if (middleInserted > 0) {
            longestLength += 2;
        }
      
        return longestLength;
    }
};