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
		vector<int> arrayList(10);
		int i = 0;
		ListNode *pcur = head;
		ListNode *pre = head;
		head = nullptr;
		while (pcur!= nullptr){
			pcur = pcur->next;
			pre->next = head;
			head = pre;
			pre = pcur;
		}
		pcur = head;
		_head = head;
		while (pcur != nullptr){
			arrayList[i++] = pcur->val;
			pcur = pcur->next;
		}
		return arrayList;
	}
	ListNode* BuyNewNode(int val){
		ListNode *NewNode = (ListNode*)new int(val);
		if (nullptr == NewNode){
			return nullptr;
		}
		NewNode->next = nullptr;
		NewNode->val = val;
		return NewNode;
	}
	void CreateLinklist(int val){
		ListNode *NewNode = BuyNewNode(val);
		if (NewNode == nullptr){
			return;
		}
		NewNode->next = _head;
		_head= NewNode;
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

class Solution2 {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> value;
		if (head != NULL)
		{
			value.insert(value.begin(), head->val);
			while (head->next != NULL)
			{
				value.insert(value.begin(), head->next->val);
				head = head->next;
			}

		}
		return value;
	}
};

int main(){
	Solution s;
	s.CreateLinklist(1);
	s.CreateLinklist(2);
	s.CreateLinklist(3);
	s.CreateLinklist(4);
	s.CreateLinklist(5);
	vector<int> arrayLists=s.printListFromTailToHead(s._head);
	int i = 0;
	for (i = 0; i < arrayLists.size(); ++i){
		cout << arrayLists[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}