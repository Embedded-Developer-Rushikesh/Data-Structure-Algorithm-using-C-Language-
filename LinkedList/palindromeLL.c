#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* ReverseLL(struct ListNode* head) {
    struct ListNode* temp = head;
    struct ListNode* prev = NULL;
    struct ListNode* next = NULL;
    while (temp != NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev; 
}

bool isPalindrome(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* ReverseNode = ReverseLL(slow);
    while (head != NULL && ReverseNode != NULL) {
        if (head->val != ReverseNode->val) {
            return false;
        }
        head = head->next;
        ReverseNode = ReverseNode->next;
    }
    return true;
}

struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(2);
    head->next->next->next = newNode(1);
    bool result = isPalindrome(head);
    printf("Output: %s\n", result ? "true" : "false");
    freeList(head);

    return 0;
}