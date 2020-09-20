# include <iostream>
#include <list>

using namespace std;



//typedef struct ListNode *Ptr;
using List = struct ListNode*;
using Pos = List ;

ListNode* reverse(ListNode* head);
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k);

// 创建空链表
struct ListNode{
	int val;
	ListNode *next;
	explicit ListNode(int x): val(x), next(nullptr){}
};

int main(){


	int num;
	cin >> num;
	ListNode* head = new ListNode(num);
	ListNode* p = head;


	// 尾插法构建链表
	while (cin >> num)
	{
		if (num == -1)
			break;
		auto newNode = new ListNode(num);
		p->next = newNode;
		p = p->next;
	}

//	ListNode* reverse_head = reverse(head);

	ListNode* Kth = FindKthToTail(head, 2);

	cout << Kth->val<<endl;

	// 遍历链表
	auto m = head;
	while (m){
		cout << m->val << endl;
		m = m->next;
	}

	return 0;
}

ListNode* insertNode(ListNode* head, int data){
	ListNode* newNode = new ListNode(data);
	ListNode* p = head;
	if (p == nullptr){
		head = newNode;
	}
	else {
		while (p->next != nullptr)
			p = p->next;
		p->next = newNode;
	}
	return head;
}

ListNode* deleteNode(ListNode* head, int data){
	ListNode *p = head;
	if (head == nullptr)
		return head;
	else
	{
		while(p->next != nullptr && p->next->val != data)
			p = p->next;
	}
	if (p->next == nullptr)
		return head;
	else
	{
		ListNode* deleteNode = p->next;
		p->next = deleteNode->next;
		delete deleteNode;
		return head;
	}
}


ListNode* reverse(ListNode* head)
{
	ListNode* pPre = nullptr;
	ListNode* p = head;
	ListNode* pReverseHead = nullptr;
	while (p != nullptr)
	{
		ListNode* pNext = p->next;
		if (pNext == nullptr)
		{
			pReverseHead = p;
		}
		p->next = pPre;
		pPre = p;
		p = pNext;
	}
	return pReverseHead;
}

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k){
	if (pListHead == nullptr || k == 0){
		return nullptr;
	}

	ListNode *AheadPtr = pListHead;
	for(int i = 0; i < k-1; i++){
		AheadPtr = AheadPtr->next;
	}
	ListNode *BeforeK = pListHead;

	while (AheadPtr->next != nullptr)
	{
		AheadPtr = AheadPtr->next;
		BeforeK = BeforeK->next;
	}
	return BeforeK;
}

ListNode *MeetNode(ListNode* pHead){
	ListNode *pNode = pHead;

	ListNode* slowNode = pNode->next;
	ListNode* fastNode = slowNode->next;
	while (slowNode != nullptr && fastNode != nullptr){
		if (fastNode == slowNode)
			return fastNode;
		slowNode = slowNode->next;
		fastNode = fastNode->next->next;
	}
	return nullptr;
}

int Count(ListNode* pMeet){
	int count = 0;
	ListNode* pNode = pMeet;
	while (pNode->next != pMeet){
		++count;
		pNode = pNode->next;
	}
	++count;
	return count;
}

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	ListNode* meetNode = MeetNode(pHead);
	int count = Count(meetNode);
	ListNode* aheadNode = pHead;
	ListNode* beforeNode = pHead;
	for (int i = 0 ; i < count; i++)
	{
		aheadNode = aheadNode->next;
	}
	while (aheadNode != beforeNode)
	{
		aheadNode = aheadNode->next;
		beforeNode = beforeNode->next;
	}

	ListNode* result = aheadNode;
	return result;

}