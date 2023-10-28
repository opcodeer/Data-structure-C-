// C++ program to get intersection point of two linked list
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class node {
public:
	int data;
	node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};
node* getIntesectionnode(node* head1, node* head2)
{
	while (head2) {
		node* temp = head1;
		while (temp) {
			if (temp == head2)
				return head2;
			temp = temp->next;
		}
		head2 = head2->next;
	}
	return NULL;
}

// Driver Code
int main()
{
	/*
		Create two linked lists

		first linked list--> 3->6->9->15->30
		second linked list--> 10->15->30

		15 is the intersection point
	*/

	node* newnode;
	node* head1 = new node(10);

	node* head2 = new node(3);

	newnode = new node(6);
	head2->next = newnode;

	newnode = new node(9);
	head2->next->next = newnode;

	newnode = new node(15);
	head1->next = newnode;
	head2->next->next->next = newnode;

	newnode = new node(30);
	head1->next->next = newnode;
    head1->next->next->next = NULL;
    node* intersectionPoint = getIntesectionnode(head1, head2);
    if (!intersectionPoint)
		cout << " No Intersection Point \n";
	else
		cout << "Intersection Point: "<< intersectionPoint->data << endl;
}
