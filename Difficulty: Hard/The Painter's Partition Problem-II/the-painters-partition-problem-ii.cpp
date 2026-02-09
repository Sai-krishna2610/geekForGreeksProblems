// User function template for C++

class Solution {
  public:
    bool canAllocate(vector<int>&arr,int maxLength,int totalpainters)
    {
        int currentlength=0;
        int painters=1;
        for(auto i:arr)
        {
            if(i>maxLength)
            {
                return false;
            }
            if(currentlength+i>maxLength)
            {
                painters++;
                currentlength=i;
                if(painters>totalpainters)//total painters means the painters available to paint given in problem as k 
                return false;//if painters is greater than totalpainters means we return false because we cannot assign new painters than available 
            }
            else
            {
                currentlength+=i;
            }
        }
        return true;
    }
    int minTime(vector<int>& arr, int k) {
        
        int start=INT_MIN,end=0;
        for(auto i:arr)
        {
            start=max(start,i);
            end+=i;
        }
        if(k==1)
        return end;
        
        int ans;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(canAllocate(arr,mid,k))
            {
                ans=mid;
                //cout<<mid<<endl;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return ans;
    }
};
