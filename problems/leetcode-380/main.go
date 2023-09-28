// https://leetcode.com/problems/insert-delete-getrandom-o1/description/

type RandomizedSet struct {
	indexes map[int]int
	values  []int
}

func Constructor() RandomizedSet {
	set := RandomizedSet{
		indexes: make(map[int]int),
		values:  make([]int, 0),
	}

	return set
}

func (this *RandomizedSet) Insert(val int) bool {
	_, ok := this.indexes[val]
	if ok {
		return false
	}
	n := len(this.values)
	this.indexes[val] = n
	this.values = append(this.values, val)

	return true
}

func (this *RandomizedSet) Remove(val int) bool {
	v, ok := this.indexes[val]
	if ok {
		n := len(this.values)
		tmp := this.values[n-1]
		this.values[n-1] = this.values[v]
		this.values[v] = tmp
		this.indexes[tmp] = v
		delete(this.indexes, val)
		this.values = this.values[:n-1]
		return true
	}

	return false
}

func (this *RandomizedSet) GetRandom() int {
	n := len(this.values)
	i := rand.Intn(n)

	return this.values[i]
}