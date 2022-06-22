#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

typedef struct {
    int val;
    struct list_head list;
} ListNode;

ListNode *genListNode(int val)
{
    ListNode *node = malloc(sizeof(ListNode));
    if (!node)
        return NULL;
    node->val = val;
    INIT_LIST_HEAD(&node->list);
    return node;
}

void printList(struct list_head *head)
{
    ListNode *node;
    list_for_each_entry(node, head, list) {
        printf("%d ",node->val);
    }
    printf("\n");
}

void freeList(struct list_head *head)
{
    ListNode *del, *next;
    list_for_each_entry_safe (del, next, head, list) {
        list_del(&del->list);
        free(del);
    }
}