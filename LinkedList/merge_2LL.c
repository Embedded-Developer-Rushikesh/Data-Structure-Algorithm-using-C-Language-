#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode head;
    struct ListNode* ans=&head;
    head.next=NULL;
    while(list1!=NULL && list2!=NULL)
    {
        if(list1->val<list2->val)
        {
            ans->next=list1;
            list1=list1->next;
            ans=ans->next;
        }else{
            ans->next=list2;
            list2=list2->next;
            ans=ans->next;
        }
    }
    if(list1!=NULL)
    {
        ans->next=list1;
    }
    if(list2!=NULL)
    {
        ans->next=list2;
    }
    return head.next;
}
void printList(struct ListNode* head)
{
    while(head!=NULL)
    {
        printf("%d->",head->val);
        head=head->next;
    }
    printf("NULL");
    printf("\n");
}

struct ListNode*  newNode(int val)
{
    struct ListNode* Node=(struct ListNode*)malloc(sizeof(struct ListNode));
    Node->val=val;
    Node->next=NULL;
    return Node;
}
int main() {
    struct ListNode* list1 = newNode(1);
    list1->next = newNode(2);
    list1->next->next = newNode(4);
    
    struct ListNode* list2 = newNode(1);
    list2->next = newNode(3);
    list2->next->next = newNode(4);
    
    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);
    
    struct ListNode* merged = mergeTwoLists(list1, list2);
    printf("Merged list: ");
    printList(merged);
  
    while (merged != NULL) {
        struct ListNode* temp = merged;
        merged = merged->next;
        free(temp);
    }
    
    return 0;
}