/* Start of a loop in a linked list: https://leetcode.com/problems/linked-list-cycle-ii/

https://www.youtube.com/watch?v=-YiQZi3mLq0

suppose slow pointer moves N distance from head  --> Nodes leading to the start of the loop -> D
								     				Nodes leading to the meeting point--> K

				For the slow pointer, N = D + K + C(i)   C: cycles made, i-> No of cycles made
				For the fast pointer, 2N = D + K + C(j)

				therefore, D = C(2i-j) - K   --> IF we move D from the meeting point, the node will be K short of making another cycle  --> It will be at the 
				starting point of the loop

*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return NULL;
        
        ListNode* slow=head, *fast =head;
        
        while(fast!=NULL){
            slow = slow->next;
            if(!fast->next)
                return NULL;
            fast = fast->next->next;
                
            if(fast==slow)
                break;
        }

        // Find out the position at which these two pointers meet  --> Now if we move slow from head and fast from meeting point
        // They are going to meet at the start of the loop. 
        
        if(fast==NULL)
            return NULL;
        slow = head;
        while(fast!=slow){
            slow = slow->next;
            fast = fast->next;
        }
        
        return fast;
    }
};