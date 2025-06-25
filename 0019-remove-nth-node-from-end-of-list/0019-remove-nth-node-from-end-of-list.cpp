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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* res = nullptr;
        int k = 0;
        ListNode* temp = head;
        while(temp!=nullptr){
            k++;
            temp = temp->next;
        }
        int d = k-n+1;
        int ct = 1;
        ListNode* temp1 = head;
        while(temp1!= nullptr){
            if(ct != d){
                int e = temp1->val;
                ListNode* node = new ListNode(e);
                ListNode* tempo = res;
                if(tempo == nullptr)    res = node;
                else{
                    while(tempo->next!=nullptr){
                        tempo = tempo->next;
                    }
                    tempo->next = node;
                }
            }
            temp1= temp1->next;
            ct++;
        }
        return res;
    }
};