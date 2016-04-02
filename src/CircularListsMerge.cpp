/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};

int length(struct node** head){

	int len = 0;
	struct node *curr = *head;
	if (*head == NULL)
		return 0;
	else{
		while (*head != curr->next){
			curr = curr->next;
			len++;
		}
		return len+1;
	}
}

int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .

	int len1 = length(head1),len;
	int len2 = length(head2);
	struct node *curr1 = *head1;
	struct node *curr2 = *head2;
	struct node *prev = NULL, *temp = NULL;

	if (*head1 == NULL && *head2 == NULL)
		return -1;

	else if (*head1 == NULL){
		head1 = head2;
		return len2;
	}
	else if (*head2 == NULL)
		return len1;
	else{

		while (*head1 != curr1->next && *head2 != curr2->next){



			if (curr1->data < curr2->data){
				if (prev == NULL){
					prev = temp = curr1;
					curr1 = curr1->next;
				}
				else{
					prev = prev->next;
					curr1 = curr1->next;
				}

			}
			else if (curr1->data > curr2->data){
				if (prev == NULL){
					prev =temp = curr2;
					curr2 = curr2->next;
					prev->next = curr1;
					
				}
				else{
					prev->next = curr2;
					prev = prev->next;
					curr2 = curr2->next;
					prev->next = curr1;
					
					
				}
			}

		}


		if (*head2 == curr2->next || *head1 == curr1->next){
			
			if (curr1->data < curr2->data){
				if (prev == NULL){
					prev = temp = curr1;
					curr1 = curr1->next;
				}
				else{
					prev = prev->next;
					curr1 = curr1->next;
				}

			}
			else if (curr1->data > curr2->data){
				if (prev == NULL){
					prev = temp = curr2;
					curr2 = curr2->next;
					prev->next = curr1;

				}
				else{
					prev->next = curr2;
					prev = prev->next;
					curr2 = curr2->next;
					prev->next = curr1;
					prev = prev->next;


				}
			}
		}

		while (*head2 != (curr2)->next){
			(prev)->next = curr2;
			(curr2) = (curr2)->next;
			(prev) = (prev)->next;

		
		}

		if (*head2 == (curr2)->next){
			(prev)->next = curr2;
			(curr2) = (curr2)->next;
			(prev) = (prev)->next;

		}

		(prev)->next = temp;
		*head1 = temp;
		len = length(head1);
		return len;

	}

}