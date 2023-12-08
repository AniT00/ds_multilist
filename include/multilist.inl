#include "multilist.h"

Node(const T& data, Node* next = nullptr)
{
  this->data = data;
  this->next = next;
  this->child = nullptr;
}
}
;

public:
size_t
size()
{
  return m_size;
}

size_t
levelSize(size_t level)
{
  return m_level_sizes[level];
}

void
insert(const T& v)
{
  if (m_head == nullptr) {
    m_head = new Node(v);
    m_size++;
    return;
  }
  Node* c = m_head;
  while (c->next != nullptr) {
    c = c->next;
  }
  c->next = new Node(v);
  m_size++;
}

void
insert(const T& v, const T& after_elem, bool is_child = false)
{
  Node* elem = find(after_elem);
  if (elem == nullptr) {
    throw std::exception("No such element");
  }
  if (is_child) {
    push_child(elem, v);
  } else {
    elem->next = new Node(v, elem->next);
  }
  m_size++;
}

void
remove_level(int level)
{
  remove_level(level, m_head);
}

/* void remove_branch(const T& root)
 {
   Node* found_elem = find(root);
   if (found_elem == nullptr) {
     throw std::exception("No such element");
   }
   Node* n = found_elem->next;
   clear(found_elem);
 }*/

void
remove_branch(const T& elem)
{
  Node* found_elem = find(elem);
  if (found_elem == nullptr) {
    throw std::exception("No such element");
  }
  clear(found_elem->child);
  found_elem->child = nullptr;
}

void
clear()
{
  clear(m_head);
  m_head = nullptr;
}

friend std::ostream&
operator<<(std::ostream& os, const Multilist<T>& list)
{
  list.print(os, 0);
  return os;
}

private:
Node* m_head = nullptr;
size_t m_size = 0;
std::vector<size_t> m_level_sizes;

void
remove_level(int level, Node* n)
{
  Node* cur = n;
  if (level == 0) {
    clear(m_head);
    m_head = nullptr;
  } else if (level > 1) {
    while (cur != nullptr) {
      if (cur->child != nullptr) {

        remove_level(level - 1, cur->child);
      }
      cur = cur->next;
    }
  } else {
    clear(n->child);
    n->child = nullptr;
  }
}

Node*
find(const T& v, Node* root = nullptr, bool get_first = false)
{
  if (root == nullptr) {
    root = m_head;
  }
  Node* c = root;
  while (c != nullptr) {
    if (c->data == v) {
      return get_first ? root : c;
    }
    Node* child_found = nullptr;
    if (c->child != nullptr && (child_found = find(v, c->child))) {
      return child_found;
    }
    c = c->next;
  }
  return nullptr;
}

Node*
find_branch_of(const T& v, Node* root = nullptr)
{
  find(v, root, true;)
}

void
push_child(Node* node, const T& v)
{

  if (node->child == nullptr) {
    node->child = new Node(v);
    return;
  }
  Node* c = node->child;
  while (c->next != nullptr) {
    c = c->next;
  }
  c->next = new Node(v);
}

void
print(std::ostream& os, size_t level, Node* n = nullptr) const
{
  Node* c = n == nullptr ? m_head : n;
  while (c != nullptr) {
    os << std::string(level * 2, ' ') << c->data << '\n';
    if (c->child != nullptr) {
      print(os, level + 1, c->child);
    }
    c = c->next;
  }
}

template<typename T>
void
Multilist<T>::clear(Node* n = nullptr)
{
  if (n == nullptr) {
    return;
  }
  Node* c = n;
  while (c != nullptr) {
    if (c->child != nullptr) {
      clear(n->child);
    }
    Node* next = c->next;
    delete c;
    c = next;
    m_size--;
  }
}