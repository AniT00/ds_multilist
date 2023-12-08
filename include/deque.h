#pragma once
#include <stdexcept>

#include <iostream>

template<typename T>
class Deque
{
private:
  struct Node
  {
    int data;
    Node* next;
    Node* prev;

    Node(const T& data, Node* next = nullptr, Node* prev = nullptr);
  };

public:
  void push_back(const T& v);

  void pop_back();

  const T& back() const;

  void push_front(const T& v);

  void pop_front();

  const T& front() const;

  void swap();

  bool empty() const;

  size_t size() const;

  void rotate();

  bool contains(const T& v) const;

	void clear();

	#ifndef NDEBUG
        void print();
	#endif

private:
        bool common_pop();

  Node* head = nullptr;
  Node* tail = nullptr;
  size_t m_size = 0;
};

#include "deque.inl"