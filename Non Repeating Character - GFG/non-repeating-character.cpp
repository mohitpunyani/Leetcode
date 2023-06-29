//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
       
       char ans='$';
       unordered_map<char,int>mp;
       
       for(int i=0;i<S.size();i++){
           mp[S[i]]++;
       }
       for(int i=0;i<S.size();i++)
       {
           int count=mp[S[i]];
           if(count==1)
           {
               ans=S[i];
               break;
           }
           else{
               continue;
           }
       }
       return ans;
    }


};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends