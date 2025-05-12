#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to detect cycle in a linked list
bool hasCycle(struct ListNode *head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return true;
        }
    }
    
    return false;
}

struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* createCyclicList(int values[], int size, int pos) {
    if (size == 0) return NULL;
    
    struct ListNode* head = newNode(values[0]);
    struct ListNode* current = head;
    struct ListNode* cycleNode = (pos == 0) ? head : NULL;
    
    for (int i = 1; i < size; i++) {
        current->next = newNode(values[i]);
        current = current->next;
        if (i == pos) {
            cycleNode = current;
        }
    }
    
    if (pos >= 0 && pos < size) {
        current->next = cycleNode;
    }
    
    return head;
}

int main() {
    // Test case 1: Cyclic list [3,2,0,-4] with cycle at position 1
    int values1[] = {3, 2, 0, -4};
    int pos1 = 1;
    struct ListNode* list1 = createCyclicList(values1, 4, pos1);
    printf("Test Case 1: %s\n", hasCycle(list1) ? "true" : "false");
    
    
    // Test case 2: Non-cyclic list [1,2,3,4]
    int values2[] = {1, 2, 3, 4};
    int pos2 = -1; // No cycle
    struct ListNode* list2 = createCyclicList(values2, 4, pos2);
    printf("Test Case 2: %s\n", hasCycle(list2) ? "true" : "false");
    
    // Free memory for non-cyclic list
    struct ListNode* temp;
    while (list2 != NULL) {
        temp = list2;
        list2 = list2->next;
        free(temp);
    }
    
    return 0;
}