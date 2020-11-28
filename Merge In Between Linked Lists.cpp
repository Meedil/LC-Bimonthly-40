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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        //pointer for moving around
        ListNode *ptr;
        ptr = list1;
        
        //find 'a' - 1
        for(int i = 0; i < a - 1; i++)
        {
            ptr = ptr->next;
        }
        
        //disconnect a form a-1 it, and connect a-1 to list2
        ListNode *pre_a;
        pre_a = ptr;
        
        ptr = ptr->next;
        pre_a -> next = list2;
        
        //find 'b', and remove everything on the way
        ListNode *post_b;
        post_b = ptr;
        ListNode *remove;
        remove = post_b;
        
        for(int i = a; i < b + 1; i++)
        {
            post_b = post_b->next;
            remove -> next = NULL;
            remove = post_b;
            //cout << "removed one 'in between'" << endl;
        }
        
        //place ptr in the place of b
        ListNode *ptrb = list2;
        
        //find end of list 2
        while(ptrb -> next != NULL){
            ptrb = ptrb -> next;
        }
        
        //attach list2 to 'a'
        ptrb -> next = post_b;
        return list1;
    }
};
