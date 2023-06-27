//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    
	    int largestIdx = 0;
	    int secondLargestIdx = -1;
	    
	    for(int i=1; i<n; i++)
	    {
	        if(arr[i] > arr[largestIdx]) //largest element got challanged
	        {
	            secondLargestIdx = largestIdx;
	            largestIdx = i;
	            
	        }
	        else if (arr[i] < arr[largestIdx] )
	        {
	            //do we have any second largest element ? if not assign it
	            if(secondLargestIdx == -1)
	                secondLargestIdx = i;
	                
	            if(arr[i] > arr[secondLargestIdx])
	                  secondLargestIdx = i;
	        }
	    }
	    
	    return secondLargestIdx == -1 ? -1 : arr[secondLargestIdx];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends