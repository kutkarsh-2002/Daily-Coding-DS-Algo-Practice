// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        
        Node* curr=head;
        Node* prev=NULL;
        
        while(curr){
            Node* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        
        
        head=prev;
        curr=head;
        //cout<<head->data<<endl;
    
       
        int c=0;
        curr->data+=1;
        Node* tail=NULL;
        
        while(curr!=NULL){
            curr->data+=c;
            if(curr->data>9){
                
                c=(curr->data)/10;
                curr->data=(curr->data)%10;
                
            }
            else{
                c=0;
            }
            
            tail=curr;
            curr=curr->next;
        }
        
        if(c>0){
            Node* temp=new Node(c);
            tail->next=temp;
            tail=tail->next;
            
        }
        
        tail->next=NULL;
        
        curr=head;
        Node* prv=NULL;
        
        while(curr){
            Node* temp=curr->next;
            curr->next=prv;
            prv=curr;
            curr=temp;
        }
        
        
        return prv;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends