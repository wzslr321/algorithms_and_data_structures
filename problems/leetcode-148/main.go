// https://leetcode.com/problems/sort-list/description/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func merge(l1 *ListNode, l2 *ListNode) *ListNode {
	head := &ListNode{}
	curr := head

	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			curr.Next = l1
			l1 = l1.Next
		} else {
			curr.Next = l2
			l2 = l2.Next
		}
		curr = curr.Next
	}

	if l1 != nil {
		curr.Next = l1
	} else {
		curr.Next = l2
	}

	return head.Next
}

func sortList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	tmp, slow, fast := head, head, head
	for fast != nil && fast.Next != nil {
		tmp, slow, fast = slow, slow.Next, fast.Next.Next
	}
	tmp.Next = nil
	rest := slow

	head = sortList(head)
	rest = sortList(rest)

	return merge(head, rest)
}