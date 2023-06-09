class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int idx = -1;
        
        int low = 0;
        int high = letters.size()-1;
        
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            
            
            //this is what we want , we need a letter that is greater than target , but we want the smaller one
            //letters[mid] could be a possible ans , but we want smaller char, so go in the left half 
            if(letters[mid] > target) 
            {
                idx = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        
        
        if(idx == -1 )
            return letters[0];
        else
            return letters[idx];
        
    }
};