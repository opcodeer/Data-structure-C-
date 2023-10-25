#include<iostream>
using namespace std;
class ListNode {
public:
	int data;
	ListNode* next;

	ListNode(int data) {
		this->data = data;
		this->next = NULL;
	}
};
void insertAtTail(ListNode* &head,int val){// we are having reference of head pointer here because we are gonna change Linked List in this function
    ListNode* newnode = new ListNode(val);
    if(head==NULL){
        head = newnode;
        return;
    }
    ListNode* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}
ListNode* reverse(ListNode *head) {
	ListNode* prevNode = NULL, *currentNode = head;
	while (currentNode != NULL) {
		ListNode* nextNode = currentNode->next;
		currentNode->next = prevNode;
		prevNode = currentNode;
		currentNode = nextNode;
	}
	return prevNode;
}
ListNode* reverseLinkedListRange(ListNode* head, int left, int right) {
	ListNode* currentNode = head;
	ListNode* startNode;
	ListNode* lastNode;
	int i = 1;
	while (currentNode != NULL) {
		if (i > right) {
			break;
		}
		if (i < left) {
			startNode = currentNode;
		}
		if (i == right) {
			lastNode = currentNode;
		}
		currentNode = currentNode->next;
		i++;
	}
	lastNode->next = NULL;
	if (left == 1) {
		lastNode = head;
		head = reverse(head);
	} else {
		lastNode = startNode->next;
		startNode->next = reverse(startNode->next);
	}
	lastNode->next = currentNode;
	return head;
}
void display(ListNode* head){
    ListNode* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    ListNode* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    reverseLinkedListRange(head,2,4);
    display(head);
}