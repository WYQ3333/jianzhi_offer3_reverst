#include<iostream>
#include<vector>

using namespace std;

struct ListNode {     
	int val;      
	struct ListNode *next;
    ListNode(int x)
		:val(x), 
		next(NULL) {
	}
};

class Solution {
public:
	Solution()
		:_head(nullptr){
	}
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> arrayList;
		int i = 0;
		ListNode *pcur = _head;
		ListNode *pre = _head;
		while (pcur!= nullptr){
			pcur = pcur->next;
			pre->next = head->next;
			head = pre;
			pre = pcur;
			arrayList[i++] = pre->val;
		}
		return arrayList;
	}
	ListNode* BuyNewNode(int val){
		ListNode *NewNode = (ListNode*)new int(val);
		if (nullptr != NewNode){
			return nullptr;
		}
		NewNode->next = nullptr;
		NewNode->val = val;
		return NewNode;
	}
	void CreateLinklist(int val){
		ListNode *head = nullptr;
		ListNode *NewNode = BuyNewNode(val);
		if (NewNode == nullptr){
			return;
		}
		NewNode->next = head;
		head->next = NewNode;
	}
	~Solution(){
		ListNode* pcur = _head;
		ListNode* pre = _head;
		while (pcur != nullptr){
			pcur = pcur->next;
			delete pre;
			pre = pcur;
		}
	}
public:
	ListNode* _head;
};


int main(){
	Solution s;
	s.CreateLinklist(1);
	s.CreateLinklist(2);
	s.CreateLinklist(3);
	s.CreateLinklist(4);
	s.CreateLinklist(5);
	system("pause");
	return 0;
}