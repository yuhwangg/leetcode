# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # 常见排序方法:
        # 插入排序，选择排序，堆排序，快速排序，冒泡排序，归并排序，桶排序等等
        # 它们的时间复杂度不尽相同，而这里题目限定了时间必须为O(nlgn)，
        # 符合要求只有快速排序，归并排序，堆排序，而根据单链表的特点，最适于用归并排序
        
        # 解题思路：
        # 归并排序，链表的中点可以通过“快慢指针”法求得
        
        if not head or not head.next:
            return head
        
        mid = self.get_mid(head)
        rhead = mid.next
        mid.next = None
        return self.merge(self.sortList(head), self.sortList(rhead))
        
        
    def merge(self, lhead, rhead):
        # dummy node
        dummy = ListNode(0)
        head = dummy
        while lhead and rhead:
            if lhead.val < rhead.val:
                head.next = lhead
                lhead = lhead.next
            else:
                head.next = rhead
                rhead = rhead.next
            head = head.next
        if lhead:
            head.next = lhead
        if rhead:
            head.next = rhead
        
        return dummy.next
    
    
    def get_mid(self, head):
        if not head or not head.next:
            return head
        slow = fast = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        return slow
        
