#include <stdio.h>
#include <stdlib.h>
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
};
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
void segregateEvenOdd(struct node **head){
	
	struct node *curr=*head,*end=*head,*prev=NULL,*new_end;
	
	while(end->next!=NULL){
		end=end->next;
	}
	
	new_end=end;
	
	
	while(curr!=end && curr->data%2!=0)
	{
		//prev=curr;
		new_end->next=curr;
		curr=curr->next;
		new_end->next->next=NULL;
		new_end=new_end->next;
	}
	if(curr->data%2==0){
	     
		 *head=curr;
		 
		 while(curr!=end){
		 	
		 	if(curr->data%2==0){
		 		prev=curr;
		 		curr=curr->next;
		 		
		 	}
		 	
		 	else{
		 		
		 		prev->next=curr->next;
		 		new_end->next=curr;
		 		curr->next=NULL;
		 		new_end=curr;
		 		curr=prev->next;
		 	}
		}
		 	
       }
       
       else{
       	  prev=curr;
       }
        
       	  
       	  if(new_end!=end && end->data%2!=0){
       	  	prev->next=end->next;
       	  	end->next=NULL;
       	  	new_end->next=end;
       	  	
			 }
       	
       	
       
	   //new_end->next=NULL;
	
	
	
	
	
	
	
	return;
}
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
 
    /* Let us create a sample linked list as following
     17->15->8->12->10->5->4->1->7->6->NULL*/
 
    push(&head, 6);
    push(&head, 7);
    push(&head, 1);
    push(&head, 4);
   push(&head, 5);
    push(&head, 10);
    push(&head, 12);
   push(&head, 8);
   push(&head, 15);
   push(&head, 17);
    printf("\nOriginal Linked list \n");
    printList(head);
 
    segregateEvenOdd(&head);
 
    printf("\nModified Linked list \n");
    printList(head);
 
    return 0;
}
