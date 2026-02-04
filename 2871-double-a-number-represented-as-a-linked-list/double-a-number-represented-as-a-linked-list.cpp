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
    ListNode* doubleIt(ListNode* head) {
        ListNode* rev = reverse(head);
        // return prev;

        int carry = 0;
        ListNode* temp = rev;

        while(temp != nullptr){
            int x = temp->val*2 + carry;
            int rem =  x%10;
            carry = x/10;
            temp->val = rem;

            if(temp->next == nullptr){
                break;
            }
            temp = temp->next;

        }
        if(carry != 0){
            ListNode* nn = new ListNode(carry);
            temp->next = nn;
          
        }
        
        return reverse(rev);

    }
    ListNode * reverse(ListNode * head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* temp = head;
        ListNode* curr;
        ListNode* prev = nullptr;
        while(temp != nullptr){
            curr = temp->next;
            temp->next = prev;
            prev = temp;
            temp = curr;
        }
        return prev;
    }
};