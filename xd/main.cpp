struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head) {
  auto rv = head;
  if (head == nullptr) return head;
  auto curr = head->next;
  auto nx = curr;
  if (nx == nullptr) return head;
  // while(nx->next != nullptr){
  nx = nx->next;
  curr->next = rv;
  // rv = curr;
  // curr = nx;
  // }

  return head;
}


