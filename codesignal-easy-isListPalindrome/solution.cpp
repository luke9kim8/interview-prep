// Singly-linked lists are already defined with this interface:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
bool isListPalindrome(ListNode<int> * l) {
    if (!l || !l->next) {
        return true;
    }
    // declare variables
    int length = 0;
    int mid = 0;
    int count = 0;
    ListNode<int> *prev;
    ListNode<int> *curr;
    ListNode<int> *next;
    ListNode<int> *firstHalf;
    ListNode<int> *secondHalf;
    
    // find midpoint
    curr = l;
    while (curr) {
        length += 1;
        curr = curr->next;
    }
    mid = length / 2;
    // reverse first half
    curr = l;
    prev = 0;
    next = l->next;
    while (count < mid) {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next->next;
        count += 1;
    } 
    // prev is the start of the first half
    // call is the start of the second half
    firstHalf = prev;
    secondHalf = curr;
    
    // compare with second half to see 
    // if l is palindrome
    if (length % 2 == 1) {
        firstHalf = firstHalf->next;
    }
    
    while (firstHalf && secondHalf) {
        if (firstHalf->value != secondHalf->value)
            return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return true;
    
    
}

