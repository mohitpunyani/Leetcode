//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

   bool recursive(vector<int>&arr,int sum,int n,int index)
   {
       if(sum==0){
           return true;
       }
       if(sum<0){
           return false;
       }
       if(index==0)
       {
           if(sum==arr[0])
           {
               return true;
           }
           else{
               return false;
           }
           
           
       }
       
       bool include;
       if(arr[index]<=sum){
          include=recursive(arr,sum-arr[index],n,index-1);
       }
       bool exclude=recursive(arr,sum,n,index-1);
       bool ans=include or exclude;
       return ans;
   }
    bool topdowndp(vector<int>&arr,int sum,int n,int index,vector<vector<int>>&dp)
   {
       if(sum==0){
           return true;
       }
      if(sum<0){
          return false;
      }
      if(index==0)
       {
           if(sum==arr[0])
           {
               return true;
           }
           else{
               return false;
           }
           
           
       }
       if(dp[index][sum]!=-1)
       {
           return dp[index][sum];
       }
    
       bool include=false;
       if(arr[index]<=sum){
          include=topdowndp(arr,sum-arr[index],n,index-1,dp);
       }
       bool exclude=topdowndp(arr,sum,n,index-1,dp);
       bool ans=include || exclude;
       dp[index][sum]=ans;
       return dp[index][sum];
   }
    bool isSubsetSum(vector<int>arr, int sum)
    {
        // code here
        
        int n=arr.size();
        // return recursive(arr,sum,n,n-1
        
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        
        return topdowndp(arr,sum,n,n-1,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends