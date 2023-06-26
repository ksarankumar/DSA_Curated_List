class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        if(points.empty() || points.size() == 0)
            return 0;
        
        int ans = 1; //there will be atleast one point given to us 
        
        int n = points.size();
        
        for(int i=0; i<n; i++)  //gives point 1 : (x1,y1)
        {
            for(int j=i+1; j<n; j++) //gives point 2 : (x2,y2) , j starts from i+1
            {
                //till now we have considered two points                 
                int count = 2;                
                //compute the slope of point 1 and point 2 : (y2-y1) / (x2-x1) : dy/dx
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                
                for(int k=0; k<n; k++) //loop for point 3 , (x3,y3)
                {
                    //this point should not be equal to point 1 and point 2
                    
                    if(k != i && k != j)
                    {
                        //compute the slope of point 3 with point 1 : y3-y1 / x3-x1
                        
                        int dx_3 = points[k][0] - points[i][0];
                        int dy_3 = points[k][1] - points[i][1];
                        
                        //if the slops are equal  dy/dx = dy_3/dx_3
                        
                        if(dy * dx_3 == dx * dy_3)
                        {
                            count++;
                        }
                        
                    }
                    
                }
                
                ans = max(ans,count); //update the ans
                
            }
            
        }
        
        return ans;
    }
};