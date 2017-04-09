#include<iostream>
#include<map>
#include<vector>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};
Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
void diagonal(struct Node *root,map<int,vector<int> > &m,int hd){
	
	if(root==NULL)
	return ;
	
	
	m[hd].push_back(root->data);
	
	diagonal(root->left,m,hd+1);
	diagonal(root->right,m,hd);

	
}


void diagonalPrint(struct Node *root){
	
	map<int,vector<int> > m;
	
	diagonal(root,m,0);
	
	map<int,vector<int> >::iterator itr;
    vector<int>::iterator i;
	
	for(itr=m.begin();itr!=m.end();itr++){
		
		for(i=itr->second.begin();i!=itr->second.end();i++){
			
			cout<<(*i)<<" ";
			
		}
		cout<<"\n";
		
	}
	

	
}


	int main()
{
    Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
 
 
    diagonalPrint(root);
 
  
	return 0;
}
