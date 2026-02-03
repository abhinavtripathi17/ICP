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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;

        while(temp->next != nullptr){
            temp = temp->next;
            cnt++;
        }

        temp = head;
        int ans = 0;

        while(temp != nullptr){
            int v = temp->val;
            ans += v*pow(2 , cnt);
            cnt--;
            temp = temp->next;
        }
        return ans;
    }

    int pow(int x , int y){
        int ans = 1;
        while(y != 0){
            ans *= x;
            y--;
        }
        return ans;
    }
};