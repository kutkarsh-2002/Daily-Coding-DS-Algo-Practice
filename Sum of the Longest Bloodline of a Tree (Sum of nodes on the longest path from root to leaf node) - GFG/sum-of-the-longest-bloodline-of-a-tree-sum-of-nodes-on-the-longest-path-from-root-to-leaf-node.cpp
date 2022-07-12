// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    
    /*void longestPath(Node* root, int currsum, int &maximum){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            currsum+=root->data;
            maximum=max(maximum, currsum);
            return ;
        }
        currsum+=root->data;
        longestPath(root->left, currsum, maximum);
        longestPath(root->right, currsum, maximum);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int maximum=INT_MIN;
        
        longestPath(root, 0, maximum);
        return maximum;
    }*/
    
    pair<int, int> getAns(Node *root){
        if(!root)
            return {0, 0};
        pair<int, int>L=getAns(root->left);
        pair<int, int>R=getAns(root->right);
        
        if(L.second>R.second){
            return {root->data+L.first, 1+L.second};
        }else if(L.second<R.second){
            return {root->data+R.first, 1+R.second};
        }
        
        return {max(root->data+L.first, root->data+R.first), 1+L.second};
    }
    
    
    int sumOfLongRootToLeafPath(Node *root){
        if(root==NULL)
            return 0;
        
        return getAns(root).first;
        
        
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        int res = obj.sumOfLongRootToLeafPath(root);
        cout << res << "\n";
    }
    return 0;
}  // } Driver Code Ends