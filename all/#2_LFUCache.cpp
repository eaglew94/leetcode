#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
#include <iterator>
using namespace std;


class Node {
public:
	int key;
	int value;
	int frequency;
	Node * left;
	Node * right;
	Node(int _key, int _value,int _frequency) {
		frequency = 0;
		left = nullptr;
		right = nullptr;
		value = _value;
		key = _key;

	}
	~Node()
	{
		left = nullptr;
		right = nullptr;
	}
	Node(){
		frequency = 0;
		left = nullptr;
		right = nullptr;
		value = 0;
	}




};

class FreqList
{
public:

	Node* head;
	Node* tail;
	int size;

	FreqList()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;

	}
	FreqList(Node* _head, Node* _tail,int _size)
	{
		size = _size;
		head = _head;
		tail = _tail;

	}
	~FreqList()
	{
		head = nullptr;
		tail = nullptr;
	}
};



class LFUCache {
public:
	unordered_map<int, Node> nodeMap;
	unordered_map<int, FreqList> freqMap;
	int capacity;
	int minFreq;
	LFUCache(int _capacity) {
		capacity = _capacity;
		minFreq = 0;
	}
	void removeNodeFromFreqMap(Node* pNode, FreqList * pList)
	{
		int frequency = pNode->frequency;
		/*FreqList * pList = &freqMap[frequency];*/
		
		if (pList->size == 1)
		{
			freqMap.erase(frequency);
			if (minFreq == frequency) //上面的步骤处理后，可能最小频率已经删除了数据，所以需要判断
				minFreq++;
		}
		else
		{
			if (pList->head == pNode)
			{
				pList->head = pList->head->right;
			}
			else if (pList->tail == pNode)
			{
				pList->tail = pList->tail->left;
			}
			else
			{
				pNode->left->right = pNode->right;
				pNode->right->left = pNode->left;
			}

			pList->size--;
		}
	}
	void addNodeToFreqMap(Node* pNode, int frequency)
	{
		unordered_map<int, FreqList>::iterator itFreq = freqMap.find(frequency);
		if (itFreq == freqMap.end())
		{
			//freqList不存在
			freqMap[frequency] = FreqList(pNode, pNode,1);
			pNode->frequency = frequency;

		}
		else
		{
			//freqList存在
			FreqList * pList = &freqMap[frequency];
			pNode->right = pList->head;
			pList->head->left = pNode;
			pNode->left = nullptr;
			pList->head = pNode;
			pNode->frequency = frequency;
			pList->size++;


		}
	}
	int get(int key) {
		//判断是否存在
		unordered_map<int, Node>::iterator itNode = nodeMap.find(key);
		if (itNode==nodeMap.end())
		//if (nodeMap.count(key)==0)
		{
			//不在nodeMap中
			return -1;
		}
		else
		{
			//存在，则要使其在freqmap的变换位置
			Node* pNode = &nodeMap[key];
			removeNodeFromFreqMap(pNode, &freqMap[pNode->frequency]); //首先要从原来的地方删除
			addNodeToFreqMap(pNode, pNode->frequency + 1);

			return pNode->value;
		}




	}

	void put(int key, int value) {
		if (capacity == 0) return;
		if (get(key) != -1)
		{
			nodeMap[key].value = value;
			return;
		}
		//删除
		if (nodeMap.size() >= capacity)
		{
			FreqList * pList = &freqMap[minFreq];
			Node * pTail = pList->tail;
			int min_key = pTail->key;
			removeNodeFromFreqMap(pTail, pList);
			nodeMap.erase(min_key);
		}
		addNodeToFreqMap(&(nodeMap[key] = Node(key, value, 0)), 0);
		minFreq = 0;
	}



};
void main()
{
	LFUCache cache = LFUCache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;
	cache.put(3, 3);
	cout << cache.get(2) << endl;
	cout << cache.get(3) << endl;
	cache.put(4, 4);
	cache.put(4, 4);
	cache.put(4, 4);
	cout << cache.get(3) << endl;
	cout << cache.get(4) << endl;
	cache.put(4, 6);
	cache.put(5, 5);
	cout << cache.get(5) << endl;
	cout << cache.get(4) << endl;
	cout << cache.get(2) << endl;
	cout << cache.get(3) << endl;
	cache.put(4, 4);
	cache.put(4, 4);
	cache.put(4, 4);
	cout << cache.get(3) << endl;
	cout << cache.get(4) << endl;
	cache.put(4, 6);
	cache.put(5, 5);
	cout << cache.get(5) << endl;
	cout << cache.get(4) << endl;

	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;
	cache.put(3, 3);
	cout << cache.get(2) << endl;
	cout << cache.get(3) << endl;
	cache.put(4, 4);
	cache.put(4, 4);
	cache.put(4, 4);
	cout << cache.get(3) << endl;
	cout << cache.get(4) << endl;
	cache.put(4, 6);
	cache.put(5, 5);
	cout << cache.get(5) << endl;
	cout << cache.get(4) << endl;
	cout << cache.get(2) << endl;
	cout << cache.get(3) << endl;
	cache.put(4, 4);
	cache.put(4, 4);
	cache.put(4, 4);
	cout << cache.get(3) << endl;
	cout << cache.get(4) << endl;
	cache.put(4, 6);
	cache.put(5, 5);
	cout << cache.get(5) << endl;
	cout << cache.get(4) << endl;
	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;
	cache.put(3, 3);
	cout << cache.get(2) << endl;
	cout << cache.get(3) << endl;
	cache.put(4, 4);
	cache.put(4, 4);
	cache.put(4, 4);
	cout << cache.get(3) << endl;
	cout << cache.get(4) << endl;
	cache.put(4, 6);
	cache.put(5, 5);
	cout << cache.get(5) << endl;
	cout << cache.get(4) << endl;
	cout << cache.get(2) << endl;
	cout << cache.get(3) << endl;
	cache.put(4, 4);
	cache.put(4, 4);
	cache.put(4, 4);
	cout << cache.get(3) << endl;
	cout << cache.get(4) << endl;
	cache.put(4, 6);
	cache.put(5, 5);
	cout << cache.get(5) << endl;
	cout << cache.get(4) << endl;

	printf("aha");
}