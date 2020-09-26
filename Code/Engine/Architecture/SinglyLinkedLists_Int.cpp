#include "Engine/Architecture/SinglyLinkedLists_Int.hpp"

//-----------------------------------------------------------------------------------------------
SLL_Int_Node::SLL_Int_Node() {}


//-----------------------------------------------------------------------------------------------
SLL_Int_Node::SLL_Int_Node(const int value, SLL_Int_Node* ptr): m_info(value), m_next(ptr) {}


//-----------------------------------------------------------------------------------------------
SinglyLinkedList_Int::SinglyLinkedList_Int() {}


//-----------------------------------------------------------------------------------------------
SinglyLinkedList_Int::~SinglyLinkedList_Int()
{
	Clear();
}


//-----------------------------------------------------------------------------------------------
bool SinglyLinkedList_Int::IsEmpty() const
{
	return m_head == nullptr;
}


//-----------------------------------------------------------------------------------------------
bool SinglyLinkedList_Int::IsInList(const int value) const
{
	SLL_Int_Node* temp = nullptr;
	
	for (temp = m_head; temp != nullptr && temp->m_info != value; temp = temp->m_next);

	return temp != nullptr;
}


//-----------------------------------------------------------------------------------------------
void SinglyLinkedList_Int::AddToHead(const int value)
{
	m_head = new SLL_Int_Node(value, m_head);
	
	if (m_tail == nullptr)
	{
		m_tail = m_head;
	}
}


//-----------------------------------------------------------------------------------------------
void SinglyLinkedList_Int::AddToTail(const int value)
{
	if (m_tail != nullptr) 
	{
		m_tail->m_next = new SLL_Int_Node(value);
		m_tail = m_tail->m_next;
	}
	else
	{
		m_tail = new SLL_Int_Node(value);
		m_head = m_tail;
	}
}


//-----------------------------------------------------------------------------------------------
void SinglyLinkedList_Int::Clear()
{
	while (!IsEmpty())
	{
		DeleteFromHead();
	}
}


//-----------------------------------------------------------------------------------------------
int SinglyLinkedList_Int::DeleteFromHead()
{
	const int value = m_head->m_info;
	SLL_Int_Node* temp_head = m_head;
	
	if (m_head == m_tail)
	{
		m_head = nullptr;
		m_tail = nullptr;
	}
	else
	{
		m_head = m_head->m_next;
	}
	
	delete temp_head;
	return value;
}


//-----------------------------------------------------------------------------------------------
int SinglyLinkedList_Int::DeleteFromTail()
{
	const int value = m_tail->m_info;

	if (m_head == m_tail)
	{
		delete m_head;
		m_head = nullptr;
		m_tail = nullptr;
	}
	else 
	{ 
		SLL_Int_Node* temp_node = nullptr; 
		for (temp_node = m_head; temp_node->m_next != m_tail; temp_node = temp_node->m_next);
		
		delete m_tail;
		m_tail = temp_node;
		m_tail->m_next = nullptr;
	}

	return value;
}