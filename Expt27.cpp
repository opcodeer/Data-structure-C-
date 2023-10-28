#include <iostream>
using namespace std;
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int value){
        val = value;
        next = NULL;
    }
};

ListNode* reverse(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    ListNode* prev = head;
    ListNode* curr = head->next;

    while (curr != NULL) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head->next = NULL;
    head = prev;

    return head;
}

ListNode* getMid(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

bool isPalindrome(ListNode* head) {
    ListNode* firstHalfEnd = getMid(head);
    ListNode* firstHalfStart = head;
    ListNode* secondHalfStart = reverse(firstHalfEnd->next);

    while (secondHalfStart != NULL) {
        if (secondHalfStart->val != firstHalfStart->val)
            return false;

        firstHalfStart = firstHalfStart->next;
        secondHalfStart = secondHalfStart->next;
    }

    return true;
}

int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(2);
    list1->next->next->next = new ListNode(1);

    if(isPalindrome(list1)){
        cout<<"Yes the given linked list is a palindrome"<<endl;
    }else{
        cout<<"No the given linked list is not a palindrome"<<endl;
    }

    return 0;
}
