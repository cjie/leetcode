/*
Remove Duplicates from Sorted List II

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createList(std::vector<int>& iv)
{
    if (iv.size()==0) {return NULL;}
    ListNode* pListHead = new ListNode(iv[0]);
    if (pListHead == NULL) {return NULL;}
    ListNode* pCurNode = pListHead;
    
    for (int i = 1; i < static_cast<int>(iv.size()); ++i)
    {
        ListNode* pNewNode = new ListNode(iv[i]);
        pCurNode->next = pNewNode;
        pCurNode = pNewNode;
    }
    return pListHead;
}

void printList(ListNode* pListHead)
{
    cout<<"[LIST] ";
    while (pListHead)
    {
        cout<<pListHead->val<<"->";
        pListHead = pListHead->next;
    }
    cout<<"NULL"<<endl;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head==NULL || head->next==NULL)
            return head;

        ListNode *pDummyHead = new ListNode(0);
        pDummyHead->next = head;

        ListNode *pNewHead = head;
        ListNode *p = head;
        ListNode *pLast = pDummyHead;
        
        bool bFoundHead = false;
        while (p->next)
        {
            int nLastValue = p->val;
            ListNode *pSub = p->next;
            if (p->val != pSub->val)
            {
                if (bFoundHead==false)
                {
                    bFoundHead=true;
                    pNewHead = p;
                }
                pLast = p;
                p = p->next;
                continue;
            }
            while (pSub && (pSub->val == nLastValue))
            {
                ListNode *pToDelete = pSub;
                pSub = pSub->next;
                delete pToDelete;
            }
            ListNode *pToDelete = p;
            p = pSub;
            delete pToDelete;
            pLast->next = pSub;
            if (p==NULL)
                break;
        }
        if (bFoundHead==false)
        {
            pNewHead = p;
        }
        delete pDummyHead;
        return pNewHead;
    }
};


void check_test_case(std::vector<int>& iv)
{
    ListNode* pList = createList(iv);
    printList(pList);
    Solution s;
    printList( s.deleteDuplicates(pList) );
    cout<<endl;
}

#define TEST_CASE(ID,NUMS) { \
int n##ID[]= NUMS;\
std::vector<int> iv(n##ID, n##ID + static_cast<int>(sizeof(n##ID)/sizeof(int)));\
cout<<"[Test Case #"<<#ID<<"]"<<endl;\
check_test_case(iv);\
}

#define LIST_1 {1}
#define LIST_2 {1,1}
#define LIST_3 {1,2}
#define LIST_4 {1,1,2}
#define LIST_5 {1,1,2,2}
#define LIST_6 {1,1,2,2,3}
#define LIST_7 {1,1,2,3,3}
#define LIST_8 {1,1,2,3,3,4,4}
#define LIST_9 {1,1,2,3,3,4,5,6,6}
#define LIST_10 {1,1,2,2,3,3,4,5,5,6,6,6,6}
#define LIST_11 {1,1,2,2,3,3,4,5,5,6,6,6,6,7}

int main()
{
    TEST_CASE(1, LIST_1);
    TEST_CASE(2, LIST_2);
    TEST_CASE(3, LIST_3);
    TEST_CASE(4, LIST_4);
    TEST_CASE(5, LIST_5);
    TEST_CASE(6, LIST_6);
    TEST_CASE(7, LIST_7);
    TEST_CASE(8, LIST_8);
    TEST_CASE(9, LIST_9);
    TEST_CASE(10, LIST_10);
    TEST_CASE(11, LIST_11);
            
    return 0;
}