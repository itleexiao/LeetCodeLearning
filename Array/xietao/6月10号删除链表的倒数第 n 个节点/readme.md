```

给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？
https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
```

*总结：

​	 自己在做这道题的时候竟然删除错了位置，一直纠结倒数第二个，不知道应该定位到倒数第三个就可以了。直接让倒数第三个的next指向倒数第一个。  

