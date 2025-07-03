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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* node = head;
        int ct = 1;
        ListNode* rev = nullptr;
        ListNode* l = nullptr;
        ListNode* r = nullptr;
        while(node != nullptr){
            if(ct >= left && ct <= right){
                if(rev == nullptr){
                    ListNode* n = new ListNode(node->val);
                    rev = n;
                }
                else{
                    ListNode* n = new ListNode(node->val);
                    ListNode* temp = rev;
                    while(temp->next != nullptr){
                        temp = temp->next;
                    }
                    temp -> next = n;
                }
            }
            else if(ct < left){
                if(l == nullptr){
                    ListNode* n = new ListNode(node->val);
                    l = n;
                }
                else{
                    ListNode* n = new ListNode(node->val);
                    ListNode* temp = l;
                    while(temp->next != nullptr){
                        temp = temp->next;
                    }
                    temp -> next = n;
                }
            }
            else{
                if(r == nullptr){
                    ListNode* n = new ListNode(node->val);
                    r = n;
                }
                else{
                    ListNode* n = new ListNode(node->val);
                    ListNode* temp = r;
                    while(temp->next != nullptr){
                        temp = temp->next;
                    }
                    temp -> next = n;
                }
            }
            node = node->next;
            ct++; 
        }
        ListNode* n_rev = nullptr;
        ListNode* temp1 = rev;
        while(temp1 != nullptr){
            if(n_rev == nullptr){
                ListNode* node = new ListNode(temp1->val);
                n_rev = node;
            }
            else{
                ListNode* node = new ListNode(temp1->val);
                node -> next = n_rev;
                n_rev = node;
            }
            temp1 = temp1 -> next;
        }
        ListNode* ans = nullptr;
        ListNode* tem = l;
        while(tem != nullptr){
            if(ans == nullptr){
                ListNode* n = new ListNode(tem->val);
                ans = n;
            }
            else{
                ListNode* n = new ListNode(tem->val);
                ListNode* temp = ans;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp -> next = n;
            }
            tem = tem -> next;
        } 
        ListNode* tem1 = n_rev;
        while(tem1 != nullptr){
            if(ans == nullptr){
                ListNode* n = new ListNode(tem1->val);
                ans = n;
            }
            else{
                ListNode* n = new ListNode(tem1->val);
                ListNode* temp = ans;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp -> next = n;
            }
            tem1 = tem1 -> next;
        }
        ListNode* tem2 = r;
        while(tem2 != nullptr){
            if(ans == nullptr){
                ListNode* n = new ListNode(tem2->val);
                ans = n;
            }
            else{
                ListNode* n = new ListNode(tem2->val);
                ListNode* temp = ans;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp -> next = n;
            }
            tem2 = tem2 -> next;
        }
        return ans;
    }
};