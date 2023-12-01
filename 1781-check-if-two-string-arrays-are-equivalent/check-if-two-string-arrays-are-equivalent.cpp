class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& A, vector<string>& B) {
        string a, b;
        for (auto &x : A) a += x;
        for (auto &x : B) b += x;
        return a == b;
    }
};