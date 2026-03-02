/*
Problem Name : 206. Reverse Linked List
Topic        : Linked List
Difficulty   : Easy
Link         : https://leetcode.com/problems/reverse-linked-list/description/

Time Complexity : O(n)
Space Complexity: O(1)
*/

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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        // ListNode* next = NULL;
        ListNode* prev = NULL;
        ListNode* tail = head;
        while(curr != NULL){
            ListNode* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        head = prev;
        return head;
    }
    
};