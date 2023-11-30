class Solution {
 public:
  int minimumOneBitOperations(int n) {
    
    if (n == 0)
      return 0;
    
    int x = 1;
    while (x * 2 <= n)
      x <<= 1;
    return minimumOneBitOperations(n ^ (x | x >> 1)) + 1 + x - 1;
  }
};