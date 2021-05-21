// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * reverseLinkedList(ListNode<int> *l) {
    if (!l->next) {
        return l;
    }
    ListNode<int> *prev = 0;
    ListNode<int> *curr = l;
    ListNode<int> *next = curr->next;
    
    while (curr) {
        curr->next = prev;
        prev = curr;
        curr = next;
        if (next) {
            next = next->next;
        }
    }
    return prev;
}

ListNode<int> * addTwoHugeNumbers(ListNode<int> * a, ListNode<int> * b) {
    // variables 
    ListNode<int> *revA;
    ListNode<int> *revB;
    ListNode<int> *revCurrA;
    ListNode<int> *revCurrB;
    ListNode<int> *res;
    ListNode<int> *next;
    int carry = 0;
    
    // edge cases 
    if (!a || (!a && !b)) {
        return b;
    } else if (!b) {
        return a;
    }
    // reverse both lists
    revA = reverseLinkedList(a);
    revB = reverseLinkedList(b);
    // create a new list by adding each element
    // add remaining elements from the list
    revCurrA = revA;
    revCurrB = revB;
    res = new ListNode<int>;
    while (revCurrA && revCurrB) {
        res->value = (revCurrA->value + revCurrB->value + carry) % 10000;
        carry = (revCurrA->value + revCurrB->value + carry) / 10000;
        next = new ListNode<int>;
        next->next = res;
        res = next;
        revCurrA = revCurrA->next;
        revCurrB = revCurrB->next;
    }
    
    while (revCurrA) {
        res->value = (revCurrA->value + carry) % 10000;
        carry = (revCurrA->value + carry) / 10000;
        next = new ListNode<int>;
        next->next = res;
        res = next;
        revCurrA = revCurrA->next;
    }
    
    while (revCurrB) {
        res->value = (revCurrB->value + carry) % 10000;
        carry = (revCurrB->value + carry) / 10000;
        next = new ListNode<int>;
        next->next = res;
        res = next;
        revCurrB = revCurrB->next;
    }
    
    if (carry) {
        res->value = carry;
        return res;
    }
    return res->next;
    
}
