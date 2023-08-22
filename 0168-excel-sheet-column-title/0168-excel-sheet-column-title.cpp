class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string ans = "";
        
        while(columnNumber != 0)
        {
            columnNumber--; //to bring it down to the  mapping A->0 , B->1 so that we can use /26 and %26
            
            ans = ans + (char)(columnNumber%26+'A');
            
            columnNumber = columnNumber/26;
        }
        
      reverse(ans.begin(),ans.end());
        
      return ans;
        
    }
};