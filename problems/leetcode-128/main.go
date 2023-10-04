// https://leetcode.com/problems/longest-consecutive-sequence/description/

type Node struct {
	value int
	next  *Node
	prev  *Node
}

func longestConsecutive(nums []int) int {
	ans := 0
	m := make(map[int]*Node)

	for _, num := range nums {
		newNode := &Node{value: num}
        prev := m[num - 1]
		if prev != nil {
			newNode.prev = prev
			prev.next = newNode
		}
        next := m[num + 1]
		if next != nil {
			newNode.next = next
			next.prev = newNode
		}
		m[num] = newNode
	}

	seen := make(map[int]bool)
	currBest := 0
	for k, v := range m {
		if seen[k] {
			continue
		}
		seen[k] = true
		curr := v
		for curr != nil {
			currBest++
			seen[curr.value] = true
			curr = curr.next
		}
		curr = v.prev
		for curr != nil {
			currBest++
			seen[curr.value] = true
			curr = curr.prev
		}
		if currBest > ans {
			ans = currBest
		}
		currBest = 0

	}

	return ans
}