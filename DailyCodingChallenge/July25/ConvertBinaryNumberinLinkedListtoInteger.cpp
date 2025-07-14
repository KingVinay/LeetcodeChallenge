#include<bits/stdc++.h>
using namespace std;

int getDecimalValue(ListNode* head) {
    int ans = 0;

    for (; head; head = head->next)
        ans = ans * 2 + head->val;

    return ans;
}

int main()
{
    // Example usage
    ListNode* head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);

    int result = getDecimalValue(head);
    cout << "Decimal value of the binary number in linked list: " << result << endl;

    return 0;
}