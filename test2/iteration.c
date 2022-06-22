#include "node.h"

struct list_head *deleteDuplicates(struct list_head *head);

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
    head = deleteDuplicates(head);
    printf("Output: ");
    printList(head);

    freeList(head);
    free(head);
    fclose(f);
    return 0;
}

struct list_head *deleteDuplicates(struct list_head *head)
{
    if (!head)
        return NULL;

    if (list_empty(head) || list_is_singular(head))
        return head;

    bool is_dup = false;
    ListNode *node, *next;
    list_for_each_entry_safe (node, next, head, list) {
        if (node->val == next->val) {
            // delete the duplicated node
            list_del(&node->list);
            free(node);
            is_dup = true;
        } else {
            if (is_dup) {
                // delete the last duplicated node
                list_del(&node->list);
                free(node);
                is_dup = false;
            }
        }
    }

    return head;
}
