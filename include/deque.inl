#include "deque.h"

template<typename T>
deque<T>::Node::Node(const T& data, Node* next, Node* prev)
{
  this->data = data;
  this->next = next;
  this->prev = prev;
}

template<typename T>
void
deque<T>::push_back(const T& v)
{
  m_size++;
  if (tail == nullptr) {
    head = tail = new Node(v);
    return;
  }
  tail->next = new Node(v, nullptr, tail);
  tail = tail->next;
}

template<typename T>
void
deque<T>::pop_back()
{
  if (common_pop()) {
    return;
  }
  tail = tail->prev;
  delete tail->next;
  tail->next = nullptr;
  m_size--;
}

template<typename T>
const T&
deque<T>::back() const
{
  return tail->data;
}

template<typename T>
void
deque<T>::push_front(const T& v)
{
  m_size++;
  if (head == nullptr) {
    head = tail = new Node(v);
    return;
  }
  head = new Node(v, head, nullptr);
}

template<typename T>
void
deque<T>::pop_front()
{
  if (common_pop()) {
    return;
  }

  head = head->next;
  delete head->prev;
  m_size--;
}

template<typename T>
const T&
deque<T>::front() const
{
  return head->data;
}

template<typename T>
void
deque<T>::swap()
{
  if (empty()) {
    return;
  }
  std::swap(head->data, tail->data);
}

template<typename T>
bool
deque<T>::empty() const
{
  return m_size == 0;
}

template<typename T>
size_t
deque<T>::size() const
{
  return m_size;
}

template<typename T>
void
deque<T>::rotate()
{
  Node* prev_b;
  Node* b = head;
  Node* e = tail;
  while (b != e) {
    std::swap(b->data, e->data);
    b = b->next;
    if (b == e) {
      break;
    }
    e = e->prev;
    if (b == e) {
      break;
    }
  }
}

template<typename T>
bool
deque<T>::contains(const T& v) const
{
  Node* c = head;
  while (c != nullptr) {
    if (c->data == v) {
      return true;
    }
    c = c->next;
  }
  return false;
}

template<typename T>
void
deque<T>::clear()
{
  Node* c = head;
  while (c != nullptr) {
    Node* tmp = c->next;
    delete c;
    c = tmp;
  }
  head = tail = nullptr;
  m_size = 0;
}

template<typename T>
void
deque<T>::print()
{
  Node* c = head;
  while (c != nullptr) {
    std::cout << c->data << ' ';
    c = c->next;
  }
  std::cout << '\n';
}

template<typename T>
bool
deque<T>::common_pop()
{
  if (m_size == 0) {
    throw std::logic_error("Attemt to remove from empty deque.");
  }
  if (m_size == 1) {
    delete head;
    head = tail = nullptr;
    return true;
  }
  return false;
}