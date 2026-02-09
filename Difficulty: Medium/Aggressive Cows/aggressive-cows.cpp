// User function Template for C++

class Solution {
  public:

    int aggressiveCows(vector<int> &stalls, int k) {
          sort(stalls.begin(), stalls.end());
          int end = stalls.back()- stalls.front();
          int ans = 0;
          int start = 1;
          
          while (start <= end){
              int mid = start + (end -start)/2;
              
              int cowCount = 1, prevPos = stalls[0];
              for(int i =1; i<stalls.size(); i++){
                  if(stalls[i] - prevPos >= mid){
                      cowCount++;
                      prevPos = stalls[i];
                  }
              }
              if (cowCount >= k) ans = mid, start = mid +1;
              else end = mid-1;
          }
          return ans;
    }
};
