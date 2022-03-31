// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{   
    private:
    
    struct Node{
        int data;
        Node* left, *right;
        Node(int x){
            data=x;
            left=NULL;
            right=NULL;
        }
    };
    
    //for making a min Heap
    
    struct comp{
        bool operator()(Node* a, Node*b){
            return a->data>b->data;
        }
    };

	public:
	
	    //for encoding the alphabets
	    
	    void preorder(Node* root, vector<string>&ans, string C){
	        
	        if(root==NULL)
	        return ;
	        
	        if(root->left==NULL && root->right==NULL){
	            ans.push_back(C);
	            return ;
	        }
	        
	        preorder(root->left, ans, C+"0");
	        preorder(root->right, ans, C+"1");
	    }
	    
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    vector<string>ans;
		    priority_queue<Node*, vector<Node*>, comp>pq;
		    
		    //for creating a leaf nodes
		    
		    for(int i=0; i<f.size(); i++){
		        Node* temp=new Node(f[i]);
		        pq.push(temp);
		    }
		    
		    // creating a HUffman tree
		    
		    while(pq.size()>1){
		        Node* x=pq.top();
		        pq.pop();
		        
		        Node* y=pq.top();
		        pq.pop();
		        
		        Node* temp=new Node(x->data+y->data);
		        temp->left=x;
		        temp->right=y;
		        pq.push(temp);
		        
		    }
		    
		    preorder(pq.top(), ans, "");
		    
		    return ans;
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}  // } Driver Code Ends