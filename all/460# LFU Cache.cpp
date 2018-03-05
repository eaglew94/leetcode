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

