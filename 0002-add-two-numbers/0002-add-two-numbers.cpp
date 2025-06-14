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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int cnt1 = 0,cnt2 = 0;
        ListNode* a = l1;
        ListNode* b = l2;
        while(a != nullptr){
            cnt1++;
            a = a -> next;
        }
        while(b != nullptr){
            cnt2++;
            b = b -> next;
        }
        if(cnt1 < cnt2){
            int n = cnt2 - cnt1;
            while(n--){
                ListNode* node = new ListNode(0);
                ListNode* temp = l1;
                while(temp -> next != nullptr)    temp = temp -> next;
                temp -> next = node; 
            } 
        }
        else{
            int n = cnt1 - cnt2;
            while(n--){
                ListNode* node = new ListNode(0);
                ListNode* temp = l2;
                while(temp -> next != nullptr)    temp = temp -> next;
                temp -> next = node; 
            } 
        }
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int rem = 0;
        ListNode* res = nullptr;
        while(temp1 != nullptr && temp2 != nullptr){
            int data1 = temp1->val,data2 = temp2->val;
            int tot = rem + data1 + data2;
            int t = tot%10;
            ListNode* node = new ListNode(t);
            if(res == nullptr)  res = node;
            else{
                ListNode* tempo = res;
                while(tempo->next != nullptr){
                    tempo = tempo->next;
                }
                tempo -> next = node;
            }
            rem = tot/10;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next; 
        }
        if(rem != 0){
            ListNode* node = new ListNode(rem);
            ListNode* tempo = res;
            while(tempo->next != nullptr){
                tempo = tempo->next;
            }
            tempo -> next = node;
        }
        return res;
    }
};