class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        
        int noOfTasks = logs.size();
        
        int startTime = 0; //given that the tasks start at time 0
        
        int minId = 0;
        int maxTimeSoFar = 0;
        
        for(int i=0; i<noOfTasks; i++)
        {
            int currTime = logs[i][1] - startTime;
            
            if(currTime > maxTimeSoFar) //we got an employee who is doing longer task
            {
                minId = logs[i][0];
                maxTimeSoFar = currTime;
            }
            else if (currTime == maxTimeSoFar) //its tie , so check for the min employee id
            {
                if(minId > logs[i][0])
                {
                     minId = logs[i][0];
                }
            }
            else
            {
                //do nothing
            }
            
            //reset the startTime for the next iteration , current job end time will be the start time for next job
            startTime =  logs[i][1] ;           
        }
        
        return minId;
        
    }
};