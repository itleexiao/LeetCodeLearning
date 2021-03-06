package day30;

public class day30_leetcode_206 {

      public class ListNode {
      int val;
      ListNode next;
      ListNode(int x) { val = x; }
  }


    public ListNode reverseList(ListNode head) {
        ListNode pre = null;
        ListNode cur = head;

        while (cur!=null){
            ListNode tmp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
}
