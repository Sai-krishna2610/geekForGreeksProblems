// Final function implementation
class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        int greaterEle=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<=k)
            {
               greaterEle++; 
            }
        }
        //Logic is window size is greaterEle move this window to right and find what is min swaps required to keep all Elements lessthan K
        
        // first check what is min swaps required when window is left most
        int i=0;
        int swapsNeeded=0;
        while(i<greaterEle)//check in first left Most window how many Swaps Needed to keep all elements less than K
        {
            if(arr[i]>k)
            {
                swapsNeeded++;
            }
            i++;
        }
        int ans=swapsNeeded;
        int j=greaterEle;
        i=0;
        while(j<arr.size())//Now moving window one by one right side checking in that window howmany swaps needed
        {
            if(arr[i]>k)
            {
                swapsNeeded--;
            }
            if(arr[j]>k)
            {
                swapsNeeded++;
            }
            i++;
            j++;
            ans=min(swapsNeeded,ans);
        }
        return ans;
    }
};
