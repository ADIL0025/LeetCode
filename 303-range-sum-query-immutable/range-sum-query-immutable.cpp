class NumArray {
 public:
  NumArray(vector<int>& nums) : prefix(nums.size() + 1) {
    partial_sum(nums.begin(), nums.end(), prefix.begin() + 1);
  }

  int sumRange(int left, int right) {
    return prefix[right + 1] - prefix[left];
  }

 private:
  vector<int> prefix;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */