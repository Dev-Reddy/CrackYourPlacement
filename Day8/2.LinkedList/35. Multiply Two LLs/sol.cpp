class solution
{
public:
    long long multiplyTwoLists(Node *l1, Node *l2)
    {
        // code here
        long long num1 = 0;
        long long num2 = 0;
        while (l1 != nullptr)
        {
            num1 = (num1 * 10 + l1->data) % 1000000007;
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            num2 = (num2 * 10 + l2->data) % 1000000007;
            l2 = l2->next;
        }
        return (num1 * num2) % 1000000007;
    }
};