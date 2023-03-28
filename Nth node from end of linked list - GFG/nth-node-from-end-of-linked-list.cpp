//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to find the data of nth node from the end of a linked list.
int count(Node*temp,int n)
{
    int ct=0;
    while(temp!=NULL)
    {
        ct++;
        temp=temp->next;
    }
    return ct;
    
}
int getNthFromLast(Node *head, int n)
{
       // Your code here
       int ct=count(head,n);
       int start=ct-n;
       Node*temp1=head;
       int counting=0;
       while(counting!=start)
       {
               counting++;
               temp1=temp1->next;
               if(temp1==NULL)
                   return -1;
           
       }
       return temp1->data;
}

