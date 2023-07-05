//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  // this is also a question of fixed size sliding window
  
    int countOfSubstrings(string S, int K)
    {
        // code here
        
        int i=0;
        int j=0;
        int ans=0;
        
        unordered_map<int,int>mp;
        while(j<S.size())
        {
            mp[S[j]]++;
            if(j-i+1<K){
                j++;
            }
            else if(j-i+1==K)
            {
                if(mp.size()==K-1)
                {
                    ans++;
                }
                mp[S[i]]--;
                if(mp[S[i]]==0){
                    mp.erase(S[i]);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}
// } Driver Code Ends