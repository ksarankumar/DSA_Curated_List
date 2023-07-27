class Solution {
public:
    
    bool check(long long mid,int num,vector<int> &a)
    {
        long long tmp=0,res=0;
        
        for(int i=0;i<a.size();i++)
        {
            tmp+=a[i];
            
            if(tmp>=mid)
            {
                tmp=tmp-mid;
                res++;
            }
        }
        
        if(res>=num)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    long long maxRunTime(int n, vector<int>& batteries) 
    {
        long long start=0,end=1e16,res=-1;
        
        sort(batteries.begin(),batteries.end());
        
        while(start<=end)
        {
            long long val=start+(end-start)/2;
            
            
            if(check(val,n,batteries))
            {
                start=val+1;
                res=val;
            }
            else
            {
                end=val-1;
            }
        }
        
        return res;
    }
};