#include<iostream>
#include <list>

 //Definition for singly-linked list.
 struct ListNode
 {
     int val;
     ListNode *next;

     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
     if(l1 == nullptr)
     {
         return l2;
     }
     else if(l2 == nullptr)
     {
         return l1;
     }

     // Create a new empty head node
     ListNode* newHead = new ListNode;

     // Check first nodes against each other
     if (l1->val <= l2->val)
     {
         // If l1 is less than l2 then set the newHead value to be that of l1
         newHead->val = l1->val;

         // Advance to next node is l1 list
         l1 = l1->next;
     }
     else
     {
         // If l1 is less than l2 then set the newHead value to be that of l1
         newHead->val = l2->val;

         // Advance to next node is l2 list
         l2 = l2->next;
     }

     // Create a new tail node, set it to also point to the new head node
     ListNode* newTail = newHead;

     // Loop over existing nodes until we hit a nullptr in one of the lists
     while (l1 != nullptr && l2 != nullptr)
     {
         ListNode* temp = new ListNode;

         if (l1->val <= l2->val)
         {
             // Save location of l1
             temp = l1;

             // Advance l1 to next node
             l1 = l1->next;
         }
         else
         {
             // Save location of l2
             temp = l2;

             // Advance l2 to next node
             l2 = l2->next;
         }

         // Set the next node is the new list to be that which was saved
         newTail->next = temp;

         // Update the tail position to relfect correctly pointing at the tail node
         newTail = temp;
     }

     // Once we get to here, one of the list has reached nullptr
     if (l1 == nullptr)
     {
         // Append l2 node
         newTail->next = l2;
         newTail = l2;
     }
     else if (l2 == nullptr)
     {
         // Otherwise append l1 node
         newTail->next = l1;
         newTail = l1;
     }

     return newHead;
}

ListNode* altMergeTwoLists(ListNode* l1, ListNode* l2)
{
    if (l1 == nullptr)
    {
        return l2;
    }
    else if (l2 == nullptr)
    {
        return l1;
    }

    std::list<ListNode*> newList1;
    std::list<ListNode*> newList2;

    // ListNode* newHead1 = new ListNode;
    // ListNode* newHead2 = new ListNode;

    while (l1 != nullptr)
    {
        newList1.push_back(l1);
        l1 = l1->next;
    }

    while (l2 != nullptr)
    {
        newList2.push_back(l2);
        l2 = l2->next;
    }

    // Merge/Splice into 1 list
    newList1.splice(newList1.end(), newList2);

    return newList1.front();
}

int main()
{
    ListNode* firstHead = new ListNode(1);
    std::list<ListNode*> list1;
    list1.push_back(firstHead);
    firstHead->next = new ListNode(3);
    firstHead = firstHead->next;
    firstHead->next = new ListNode(5);
    firstHead = list1.front();

    ListNode* secondHead = new ListNode(2);
    std::list<ListNode*> list2;
    list2.push_back(secondHead);
    secondHead->next = new ListNode(5);
    secondHead = secondHead->next;
    secondHead->next = new ListNode(9);
    secondHead = list2.front();

    //ListNode* mergedLists = altMergeTwoLists(firstHead, secondHead);
    ListNode* mergedLists = mergeTwoLists(firstHead, secondHead);

    while (mergedLists != nullptr)
    {
        std::cout << "[ " << mergedLists->val << " ], ";
        mergedLists = mergedLists->next;
    }

    return 0;
}