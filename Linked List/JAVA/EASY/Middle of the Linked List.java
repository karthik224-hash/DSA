//Middle of the Linked List
//https://leetcode.com/problems/middle-of-the-linked-list/


class Solution {
    public ListNode middleNode(ListNode head) {
        int c=0;
        ListNode n=head;
        while(head!=null)
        {
            c++;
            head=head.next;
        }
        head=n;
        c=c/2;
        while(c-->0)
        {
            head=head.next;
        }
        return head;
    }
}