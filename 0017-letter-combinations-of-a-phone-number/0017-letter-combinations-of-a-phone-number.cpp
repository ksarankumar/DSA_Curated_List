class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> result;
        vector<string> numpad =  {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        string temp;
        
        if(digits.size() == 0)
            return result;
        
        solve(numpad,digits,temp,result,0);
        
        return result;
    }
    
    void solve(vector<string> &numpad,string &digits,string &temp,vector<string> &result,int i )
    {
        if(i == digits.size())
        {
            result.push_back(temp);
           return ;
        }
        
        //get the string corresponding to current digit 
        string numpadString = numpad[digits[i]-'0'];
        
        //for each char in num pad string , append the char to temp ans , recur , undo
        for(auto s:numpadString)
        {
            temp = temp+s;
            solve(numpad,digits,temp,result,i+1);
            temp.pop_back();
        }
        
        
               
    }
};