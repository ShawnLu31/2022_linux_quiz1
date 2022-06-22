#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct ListNode {
    int val;
    struct list_head list;
};

struct ListNode *genListNode(int val)
{
    struct ListNode *node = malloc(sizeof(struct ListNode));
    if (!node)
        return NULL;
    node->val = val;
    INIT_LIST_HEAD(&node->list);
    return node;
}

void printList(struct list_head *head)
{
    struct ListNode *node;
    list_for_each_entry(node, head, list) {
        printf("%d ",node->val);
    }
    printf("\n");
}