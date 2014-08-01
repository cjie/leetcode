
/*
Rotate List

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL || head->next==NULL || k==0)
        {
            return head;
        }

        ListNode* pTail = head;
        int listLength = 1;
        while (pTail->next)
        {
            pTail = pTail->next;
            listLength += 1;
        }
        k = k % listLength;
        int bk = listLength - k;
        
        pTail->next = head;

        for (int i = 0; i < bk; ++i)
        {
            pTail = pTail->next;
        }
        head = pTail->next;
        pTail->next = NULL;
        
        return head;
    }
};

void check_test_case(std::vector<int>& iv, int k)
{
    ListNode* pList = createList(iv);
    printList(pList);
    Solution s;
    printList( s.rotateRight(pList, k) );
    cout<<endl;
}

#define TEST_CASE(ID,NUMS,K) { \
int n##ID[]= NUMS;\
int k##ID = K;\
std::vector<int> iv(n##ID, n##ID + static_cast<int>(sizeof(n##ID)/sizeof(int)));\
cout<<"[Test Case #"<<#ID<<"] (K="<<K<<")"<<endl;\
check_test_case(iv, k##ID);\
}

#define LIST_1 {1}
#define LIST_2 {1,2}
#define LIST_3 {1,2,3}
#define LIST_5 {1,2,3,4,5}
#define LIST_10 {1,2,3,4,5,6,7,8,9,10}

int main()
{
    TEST_CASE(1, LIST_1, 0);
    TEST_CASE(2, LIST_1, 1);
    TEST_CASE(3, LIST_1, 2);
    TEST_CASE(4, LIST_2, 0);
    TEST_CASE(5, LIST_2, 1);
    TEST_CASE(6, LIST_2, 2);
    TEST_CASE(7, LIST_2, 3);
    TEST_CASE(8, LIST_5, 0);
    TEST_CASE(9, LIST_5, 1);
    TEST_CASE(10, LIST_5, 2);
    TEST_CASE(11, LIST_5, 4);
    TEST_CASE(12, LIST_5, 5);
    TEST_CASE(13, LIST_5, 6);
    TEST_CASE(14, LIST_10, 3);

    return 0;
}