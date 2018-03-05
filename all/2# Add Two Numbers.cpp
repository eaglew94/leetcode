/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head=ListNode(0);
        ListNode* p= &head;
        int offset=0;
        do{
            p->next=new ListNode(0);
            p=p->next;
            
            int a=l1?l1->val:0;
            int b=l2?l2->val:0;
            int sum=a+b+offset;
            p->val=sum%10;
            offset=sum/10;
            l1= l1? l1->next:NULL;
            l2= l2? l2->next:NULL;
            
        } while(offset||l1||l2);
        return head.next;
    }
};
