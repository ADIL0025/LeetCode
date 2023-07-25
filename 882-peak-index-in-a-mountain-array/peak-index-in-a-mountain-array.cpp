class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        
        int low = 0;
        int up = A.size()-1;
        int cur = A.size()/2;
        
        while(true){
        
            if(A[cur-1] < A[cur] && A[cur] < A[cur+1]){
                low = cur;
                cur = (cur+up)/2;
            }else if(A[cur-1] > A[cur] && A[cur] > A[cur+1]){
                up = cur;
                cur = (cur+low)/2;
            }else{
                return cur;
            }
        }
    }
};