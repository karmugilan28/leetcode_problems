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
        ListNode* rev = nullptr;
        ListNode* temp = head;
        while(temp != nullptr){
            ListNode* temp1 = new ListNode(temp->val);
            if(rev == nullptr)  rev = temp1;
            else{
                temp1 -> next = rev;
                rev = temp1;
            }
            temp = temp -> next;
        }
        return rev;
    }
};