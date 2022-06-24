// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        
        // int n=0, m=0;
        // struct Node* prev1=NULL, *curr1=first;
        
        // //reversing the first linkedlist
        
        // while(curr1!=NULL){
        //     struct Node* temp=curr1->next;
        //     curr1->next=prev1;
        //     prev1=curr1;
        //     curr1=temp;
        //     n++;
        // }
        
        // struct Node* prev2=NULL, *curr2=second;
        
        // //reversing the second linkedlist
        
        // while(curr2!=NULL){
        //     struct Node* temp=curr2->next;
        //     curr2->next=prev2;
        //     prev2=curr2;
        //     curr2=temp;
        //     m++;
        // }
        
        
        
        // struct Node* head=NULL *curr=NULL;
        
        
        
        // //if n2>n1
        
        // if(m>n){
            
        //     curr=prev2;
        //     int carry=0, rem=0;
            
        //     //This loop will run until one of the linkedlist finishes
            
        //     while(prev2!=NULL && prev1!=NULL){
                
        //         if(head==NULL){
                    
        //         }
                
        //         int val=prev1->data+prev2->data+carry;
                
        //         if(val>9){
                    
        //             carry=val/10;
        //             rem=val%10;
        //             prev2->data=rem;
                    
        //         }else{
        //             prev2->data=val;
        //         }
                
        //         //update
        //         prev2=prev2->next;
        //         prev1=prev1->next;
        //     }
        //     //Here only second linkedlist data is remaining which needed to work
            
        //     while(prev2!=NULL){
                
        //         int val=prev2->data+carry;
                
        //         if(val>9){
        //             carry=val/10;
        //             rem=val%10;
        //             prev2->data=rem;
        //         }else{
        //             prev2->data=val;
        //         }
        //         prev2=prev2->next;
        //     }
            
        //     struct Node* prev=NULL;
            
            
        //     while(curr!=NULL){
        //         struct Node* temp=curr->next;
        //         curr->next=prev;
        //         prev->next=curr;
        //         curr=temp;
        //     }
        //     return prev;
        // }
        
        // // If n1>n2
        
        // else{
            
        //     curr=prev1;
        //     int carry=0, rem=0;
            
        //     while(prev2!=NULL && prev1!=NULL){
                
        //         int val=prev1->data+prev2->data+carry;
                
        //         if(val>9){
        //             carry=val/10;
        //             rem=val%10;
        //             prev1->data=rem;
                    
        //         }else{
        //             prev1->data=val;
        //         }
        //         //update
        //         prev2=prev2->next;
        //         prev1=prev1->next;
        //     }
            
        //     while(prev1!=NULL){
                
        //         int val=prev1->data+carry;
                
        //         if(val>9){
        //             carry=val/10;
        //             rem=val%10;
        //             prev1->data=rem;
        //         }else{
        //             prev1->data=val;
        //         }
        //         prev1=prev1->next;
        //     }
            
        //     struct Node* prev=NULL;
            
        //     while(curr!=NULL){
        //         struct Node* temp=curr->next;
        //         curr->next=prev;
        //         prev->next=curr;
        //         curr=temp;
        //     }
        //     return prev;
        // }
        
        struct Node* prev=NULL;
        //Reversing a first linkedlist
        
        while(first){
            struct Node* temp=first->next;
            first->next=prev;
            prev=first;
            first=temp;
        }
        
        struct Node* head1=prev, *head2=NULL;
        prev=NULL;
        
        while(second){
            struct Node* temp=second->next;
            second->next=prev;
            prev=second;
            second=temp;
        }
        
        head2=prev;
        
        struct Node* head=NULL, *tail=NULL;
        int c=0;
        
        while(head1 && head2){
            int val=head1->data+head2->data+c;
            c=(val>9)?(val/10):0;
            val=(val>9)?(val%10):val;
            
            Node* temp=new Node(val);
            
            if(head==NULL){
                head=temp;
                tail=temp;
            }else{
                tail->next=temp;
                tail=tail->next;
            }
            
            head1=head1->next;
            head2=head2->next;
        }
        
        while(head1){
            int val=head1->data+c;
            c=(val>9)?(val/10):0;
            val=(val>9)?(val%10):val;
            struct Node* temp=new Node(val);
            
            if(head==NULL){
                head=temp;
                tail=temp;
            }else{
                tail->next=temp;
                tail=tail->next;
            }
            
            head1=head1->next;
        }
        
        while(head2){
            int val=head2->data+c;
            c=(val>9)?(val/10):0;
            val=(val>9)?(val%10):val;
            struct Node* temp=new Node(val);
            
            if(head==NULL){
                head=temp;
                tail=temp;
            }else{
                tail->next=temp;
                tail=tail->next;
            }
            
            head2=head2->next;
        }
        
        if(c>0){
            struct Node* temp=new  Node(c);
            tail->next=temp;
            tail=tail->next;
            
        }
        
        tail->next=NULL;
        
        struct Node* curr=head;
        prev=NULL;
        
        while(curr){
            struct Node* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        
        return prev;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends