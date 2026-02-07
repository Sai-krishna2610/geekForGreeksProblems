// User function Template for C++

class Solution {
  public:
    int rotationCount(long long R, long long D) {
        long long ans=0;
        while(R)
        {
            long long rotationsRequired=abs(R%10-D%10);
            if(rotationsRequired>5)
            rotationsRequired=10-rotationsRequired;
            ans+=rotationsRequired;
            R/=10;
            D/=10;
        }
        return ans;
        
    }
};