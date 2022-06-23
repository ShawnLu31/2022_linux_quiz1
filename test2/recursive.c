#include "node.h"

void deleteDuplicates(struct list_head *head, struct list_head *l);

int main(int argc, char *argv[]){
    struct list_head *head = malloc(sizeof(struct list_head));
    if (!head) {
        printf("Error NO MEMORY\n");
        exit(1);
    }
    INIT_LIST_HEAD(head);

    FILE *f = fopen(argv[1], "r");
    int n = 0;
    while(fscanf(f, "%d", &n) != EOF) {
        ListNode *node = genListNode(n);
        if (!node) {
            printf("Error NO MEMORY\n");
            exit(1);
        }
        list_add_tail(&node->list, head);
    }

    printf("Input: ");
    printList(head);
    deleteDuplicates(head, head->next);
    printf("Output: ");
    printList(head);

    freeList(head);
    free(head);
    fclose(f);
    return 0;
}

void deleteDuplicates(struct list_head *head, struct list_head *l)
{
    if (!head)
        return;
    if (list_empty(head) || list_is_singular(head))
        return;

    if (l == head)
        return;

    if (l->next != head && list_entry(l, ListNode, list)->val == list_entry(l->next, ListNode, list)->val) {
        while (l->next != head && list_entry(l, ListNode, list)->val == list_entry(l->next, ListNode, list)->val) {
            l = l->next;
            list_del(l->prev);
        }
        l = l->next;
        list_del(l->prev);
        deleteDuplicates(head, l);
        return;
    }


    deleteDuplicates(head, l->next);
    return;
}