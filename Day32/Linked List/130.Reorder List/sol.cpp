// Upvote and Comment
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        // base case : linkedlist is empty
        if (!head)
            return;

        // finding the middle with the help of two pointer approach
        ListNode *tmp = head, *half = head, *prev = NULL;
        while (tmp->next && tmp->next->next)
        {
            tmp = tmp->next->next;
            half = half->next;
        }

        // adding one bit in case of lists with even length
        if (tmp->next)
            half = half->next;

        // Now reverse the second half
        while (half)
        {
            tmp = half->next;
            half->next = prev;
            prev = half;
            half = tmp;
        }
        half = prev;

        // After reversing the second half, let's merge both the halfes
        while (head && half)
        {
            tmp = head->next;
            prev = half->next;
            head->next = half;
            half->next = tmp;
            head = tmp;
            half = prev;
        }

        // Base case : closing when we had even length arrays
        if (head && head->next)
            head->next->next = NULL;
    }
};