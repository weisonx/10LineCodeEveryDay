
struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
};

int findLastButK(ListNode *head, int k)
{
    int n = 0;
    struct ListNode *node;

    node = head;
    while(node)
    {
        n++;
        node = node->m_pNext;
    }

    int end = n - k + 1;
    node = head;
    while(end > 0)
    {
        node = node->m_pNext;
        end--;
    }

    return node->m_nValue;
}

int findLastButK_double_pointer(ListNode *head, int k)
{
    struct ListNode *node1, *node2;

    int i = 0;
    node1 = head;
    while(i < k - 1)
    {
        node1 = node1->m_pNext;
    }

    node2 = head;
    while(node1)
    {
        node1 = node1->m_pNext;
        node2 = node2->m_pNext;
    }

    return node2->m_nValue;
}