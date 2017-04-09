#include <stack>
#include<iostream>

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
bool isleaf(struct Node *root){
	if(root->left==NULL && root->right==NULL)
	return true;
	
	else
	return false;
	
	
	
}



bool leaves(struct Node *root1,struct Node *root2){
	
	stack<Node *> s1;
	stack<Node *> s2;
		s1.push(root1);
		s2.push(root2);
	
	while(!s1.empty() || !s2.empty()){
		
		if(s1.empty()||s2.empty())
		return false;
		
	
	
		
		Node *temp1=s1.top();
		
		s1.pop();
		while(temp1!=NULL && !isleaf(temp1)){
			if(temp1->right)
			s1.push(temp1->right);
			
			if(temp1->left)
			s1.push(temp1->left);
			
			temp1=s1.top();
			s1.pop();
		}
		
	
		
		
		Node *temp2=s2.top();
		s2.pop();
		
		while(temp2!=NULL && !isleaf(temp2)){
			if(temp2->right)
			s2.push(temp2->right);
			
			if(temp2->left)
			s2.push(temp2->left);
			
			temp2=s2.top();
			s2.pop();
		}
		
		if(temp1==NULL && temp2!=NULL)
		return false;
		
		if(temp1!=NULL && temp2==NULL)
		return false;
		
		if(temp1!=NULL && temp2!=NULL)
	    {
	    	if(temp1->data!=temp2->data)
	    	return false;
	    	
	    	
		}

	}
  return true;
}

	int main()
{
   Node *root1 = newNode(1);
      root1->left = newNode(2);
      root1->right = newNode(3);
      root1->left->left = newNode(4);
      root1->right->left = newNode(6);
      root1->right->right = newNode(7);
 
      Node *root2 = newNode(0);
      root2->left = newNode(1);
      root2->right =  newNode(5);
      root2->left->right = newNode(4);
      root2->right->left =  newNode(7);
      root2->right->right =  newNode(6);
 
 
    cout<<leaves(root1,root2);
 
  
	return 0;
}
