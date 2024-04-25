#pragma once

template <typename T>
class DoublyLinkedList {
private:
	struct Node
	{
		T data;
		Node* prev;
		Node* next;
		Node(const T& data = T(), Node* prev = nullptr, Node* next = nullptr) : data(data), prev(prev), next(next) {}
	};
	Node sentinel;
	int count;
public:
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList<T>& other);
	DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& other);
	~DoublyLinkedList();
	bool empty() const;
	int size() const;
	class Const_Iterator {
		friend class DoublyLinkedList;
		const Node* current;
		Const_Iterator(const Node* current = nullptr) : current(current) {}
	public:
		Const_Iterator& operator++() {
			current = current->next;
			return *this;
		}
		Const_Iterator operator++(int) {
			Const_Iterator curr(*this);
			++(*this);
			return  curr;
		}
		Const_Iterator& operator--() {
			current = current->prev;
			return *this;
		}
		Const_Iterator operator--(int) {
			Const_Iterator curr(*this);
			--(*this);
			return  curr;
		}
		bool operator==(const Const_Iterator& other) const {
			return current == other.current;
		}
		bool operator!=(const Const_Iterator& other) const {
			return !(*this == other);
		}
		const T& operator*() const {
			return current->data;
		}
		const T* operator->() const {
			return &current->data;
		}
	};
	Const_Iterator cbegin() const {
		return Const_Iterator(sentinel.next);
	}
	Const_Iterator cend() const {
		return Const_Iterator(&sentinel);
	}
	class Iterator {
		friend class DoublyLinkedList;
		Node* current;
		Iterator(Node* current = nullptr) : current(current) {}
	public:
		Iterator& operator++() {
			current = current->next;
			return *this;
		}
		Iterator operator++(int) {
			Iterator curr(*this);
			++(*this);
			return  curr;
		}
		Iterator& operator--() {
			current = current->prev;
			return *this;
		}
		Iterator operator--(int) {
			Iterator curr(*this);
			--(*this);
			return  curr;
		}
		bool operator==(const Iterator& other) const {
			return current == other.current;
		}
		bool operator!=(const Iterator& other) const {
			return !(*this == other);
		}
		T& operator*() {
			return current->data;
		}
		T* operator->() {
			return &current->data;
		}
		T& operator*() const {
			return current->data;
		}
		T* operator->() const {
			return &current->data;
		}
	};
	Iterator begin() {
		return Iterator(sentinel.next);
	}
	Iterator end() {
		return Iterator(&sentinel);
	}
	

	void insert(Iterator it, const T& element);
	void push_back(const T& element);
	void push_front(const T& element);

	
	Iterator erase(Iterator it)
	{
		it.current->next->prev = it.current->prev;
		it.current->prev->next = it.current->next;
		Iterator result(it.current->next);
		delete it.current;
		--count;
		return result;
	}
	void pop_back();
	void pop_front();
private:
	void copy(const DoublyLinkedList<T>& other);
	void free();
};

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList()
{
	sentinel.next = &sentinel;
	sentinel.prev = &sentinel;
	count = 0;
}

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& other) : DoublyLinkedList()
{
	copy(other);
}

template<typename T>
inline DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other)
{
	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}

template<typename T>
inline DoublyLinkedList<T>::~DoublyLinkedList()
{
	free();
}

template<typename T>
inline bool DoublyLinkedList<T>::empty() const
{
	return size() == 0;
}

template<typename T>
inline int DoublyLinkedList<T>::size() const
{
	return count;
}

template<typename T>
inline void DoublyLinkedList<T>::insert(Iterator it, const T& element)
{
	Node* newNode = new Node(element, it.current->prev, it.current);
	newNode->prev->next = newNode;
	newNode->next->prev = newNode;
	++count;
}

template<typename T>
inline void DoublyLinkedList<T>::push_back(const T& element)
{
	insert(end(), element);
}

template<typename T>
inline void DoublyLinkedList<T>::push_front(const T& element)
{
	insert(begin(), element);
}

template<typename T>
inline void DoublyLinkedList<T>::pop_back()
{
	erase(sentinel.prev);
}

template<typename T>
inline void DoublyLinkedList<T>::pop_front()
{
	erase(begin());
}

template<typename T>
inline void DoublyLinkedList<T>::copy(const DoublyLinkedList<T>& other)
{
	for (Const_Iterator it = other.cbegin(); it != other.cend(); it++)
	{
		push_back(*it);
	}
}

template<typename T>
inline void DoublyLinkedList<T>::free()
{
	while (!empty()) {
		pop_back();
	}
}
