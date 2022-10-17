#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *removeDuplicates(Node *head)
{
    map<int, int> m;
    Node *cur = head;
    Node *pre;
    m[cur->data] = 1;
    pre = cur;
    cur = cur->next;
    while (cur != NULL)
    {
        if (m[cur->data])
        {
            pre->next = cur->next;
            cur = pre->next;
        }
        else
        {
            m[cur->data] = 1;
            pre = cur;
            cur = cur->next;
        }
    }
    return head;

}

int main()
{

    int n;
    cout << "Enter Number of Nodes in Linked list : ";
    cin >> n;
    struct Node *head = NULL;
    struct Node *temp = head;

    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        if (head == NULL)
            head = temp = new Node(data);
        else
        {
            temp->next = new Node(data);
            temp = temp->next;
        }
    }

    Node *result = removeDuplicates(head);
    cout << "Linked list after removing duplicates : ";
    print(result);
    cout << endl;

    return 0;
}
