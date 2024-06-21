class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int i=0,j=0,ans=0,sum=0;
        while(j<customers.size())
        {
            if(grumpy[j]==1)
            sum+=customers[j];
            if(j-i+1!=minutes)
            j++;

            else if(j-i+1==minutes)
            {
                ans=max(sum,ans);
                if(grumpy[i]==1)
                sum-=customers [i];
                i++;
                j++;
            } 
        }

        for(int i=0;i<customers.size();i++)
        {
            if(grumpy[i]==0)
            ans+=customers[i];
        }

        return ans;
    }
};

