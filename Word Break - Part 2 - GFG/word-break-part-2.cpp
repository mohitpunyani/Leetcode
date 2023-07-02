//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// NOTE -> SIMILAR TO WORD BREAK 1 problem
class Solution{
public:
vector<string>ans;

void recursive(string s,set<string>st,int i,string temp)
{
    if(i>=s.size())
    {
        temp.pop_back();
        ans.push_back(temp);
        return ;
    }
    
    for(int j=i;j<s.size();j++)
    {
        string str=s.substr(i,j-i+1);
        
        if(st.find(str)!=st.end())
        {
            recursive(s,st,j+1,temp+str+" ");
        }
        
    }
    return ;
}
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code herew
        
        // recursive
        
        set<string>st;
        for(auto it:dict)
        {
            st.insert(it);
        }
        recursive(s,st,0,"");
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends