#include<iostream>
#include<vector>
using namespace std;

struct Node{
	struct Node *left;
	struct Node *right;
	int data;
	
	Node(int x){
		data=x;
		left=right=NULL;
		
	} 
	
	
	
	
};

void printvec(vector<int> &v,int j){
	
	for(int i=j;i<v.size();i++){
		
		cout<<v[i]<<" ";
		
		
	}
	cout<<"\n";
	
	
}


void printKPath(struct Node *root,int k,vector<int> &v){
	
	
	
	if(!root)
	return ;
	
	v.push_back(root->data);
	
	
	printKPath(root->left,k,v);
	printKPath(root->right,k,v);
	
	int p=0;
	for(int j=v.size()-1;j>=0;j--)
    {
	   p=p+v[j];
	   
	   if(p==k)
	   printvec(v,j);	   
	   
	   
	   
	}	
	
	v.pop_back();
	
}


int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);
 
    vector<int> v;
    int k = 5;
    printKPath(root, k,v);
 
    return 0;
}
