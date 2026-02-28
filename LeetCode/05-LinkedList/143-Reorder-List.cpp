/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {

        if(!head || !head->next) return;
        ListNode* fast = head;
        ListNode* slow = head;
        // 1.when fast at end slow is at mid
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next; 
        }
        // break from mid
        ListNode* second = slow->next;
        slow->next = NULL;
        // 2.we reversed the 2nd half
        ListNode* prev = NULL;
        while(second){
            ListNode* nextNode = second->next;
            second->next = prev;

            prev = second;
            second = nextNode; 
        }

        //3.now just merge 2 sorted list in zig zag
        ListNode* first = head;
        ListNode* secondHalf = prev;

        while(secondHalf){
            ListNode* temp1 = first->next;
            ListNode* temp2 = secondHalf->next;

            first->next = secondHalf;
            secondHalf->next = temp1; 

            first = temp1;
            secondHalf  = temp2;
        }

    }
};