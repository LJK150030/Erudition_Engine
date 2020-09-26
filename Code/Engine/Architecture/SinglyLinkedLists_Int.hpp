#pragma once

//-----------------------------------------------------------------------------------------------
struct SLL_Int_Node
{
public:
	int m_info = -1;
	SLL_Int_Node* m_next = nullptr;
	
public:
	SLL_Int_Node();
	explicit SLL_Int_Node(const int value, SLL_Int_Node* ptr = nullptr);
};


//-----------------------------------------------------------------------------------------------
class SinglyLinkedList_Int
{
public:
	SinglyLinkedList_Int();
	~SinglyLinkedList_Int();
	
	bool IsEmpty() const;
	bool IsInList(int value) const;
	
	void AddToHead(int value);
	void AddToTail(int value);
	void Clear();
	int DeleteFromHead();
	int DeleteFromTail();
	

private:
	SLL_Int_Node* m_head = nullptr;
	SLL_Int_Node* m_tail = nullptr;
}; 