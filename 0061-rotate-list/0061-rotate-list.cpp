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
    ListNode* rotateRight(ListNode* head, int k) {
        //brute force mle
        if(head == nullptr) return head;
        int n = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            n++;
            temp = temp -> next;
        }
        int d = k % n;
        while(d != 0){
            ListNode* temp1 = head;
            ListNode* temp2 = head;
            while(temp2->next != nullptr)   temp2 = temp2 -> next;
            ListNode* t = new ListNode(temp1->val);
            temp1->val = temp2->val;
            ListNode* tem = head;
            tem = tem->next;
            while(tem != nullptr){
                ListNode* to = new ListNode(tem->val);
                tem -> val = t->val;
                t -> val = to -> val;
                tem = tem -> next;
            }
            d--;
        }
        return head;
    }
};