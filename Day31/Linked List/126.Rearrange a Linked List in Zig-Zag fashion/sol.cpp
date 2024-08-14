#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void zigZagList(Node *head)
{
    bool flag = true;
    Node *current = head;
    while (current->next != NULL)
    {
        if (flag)
        {
            if (current->data > current->next->data)
                swap(current->data, current->next->data);
        }
        else
        {
            if (current->data < current->next->data)
                swap(current->data, current->next->data);
        }

        current = current->next;
        flag = !flag;
    }
}

void push(Node **head_ref, int new_data)
{
    struct Node *new_Node = new Node;
    new_Node->data = new_data;
    new_Node->next = (*head_ref);
    (*head_ref) = new_Node;
}

void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        printf("%d->", Node->data);
        Node = Node->next;
    }
    printf("NULL");
}

int main(void)
{
    struct Node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 6);
    push(&head, 8);
    push(&head, 7);
    push(&head, 3);
    push(&head, 4);

    printf("Given linked list \n");
    printList(head);

    zigZagList(head);

    printf("\nZig Zag Linked list \n");
    printList(head);

    return (0);
}
