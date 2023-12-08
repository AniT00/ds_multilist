#include "deque.h"

#include <iostream>
#include <string>
#include <numeric>

enum Option
{
  NONE,
  PUSH_FRONT,
  PUSH_BACK,
  POP_FRONT,
  POP_BACK,
  FRONT,
  BACK,
  SWAP,
  CHECK_EMPTY,
  GET_SIZE,
  ROTATE,
  CONTAINS,
  CLEAR,
  QUIT
};

void
push_front(deque<int>& deque);

void
push_back(deque<int>& deque);

void
front(deque<int>& deque);

void
back(deque<int>& deque);

void
check_empty(deque<int>& deque);

void
get_size(deque<int>& deque);

void
contains(deque<int>& deque);

int
main()
{
  deque<int> deque;
  deque.push_back(10);
  deque.push_back(32);
  deque.push_back(12);
  deque.push_back(33);
  deque.push_back(1);
  deque.push_back(4);
  deque.push_back(19);

  bool quit = false;
  std::string inp;
  while (!quit) {
    deque.print();
    std::cout << " 1. Push front\n"
              << " 2. Push back\n"
              << " 3. Pop front\n"
              << " 4. Pop back\n"
              << " 5. Front\n"
              << " 6. Back\n"
              << " 7. Swap\n"
              << " 8. Check if empty\n"
              << " 9. Get size\n"
              << "10. Rotate\n"
              << "11. Check if contains\n"
              << "12. Clear\n"
              << "13. Quit\n";
    std::cin >> inp;
    int option = std::stoi(inp);
    switch (option) {
      case PUSH_FRONT:
        push_front(deque);
        break;
      case PUSH_BACK:
        push_back(deque);
        break;
      case POP_FRONT:
        deque.pop_front();
        break;
      case POP_BACK:
        deque.pop_back();
        break;
      case FRONT:
        front(deque);
        break;
      case BACK:
        back(deque);
        break;
      case SWAP:
        deque.swap();
        break;
      case CHECK_EMPTY:
        check_empty(deque);
        break;
      case GET_SIZE:
        get_size(deque);
        break;
      case ROTATE:
        deque.rotate();
        break;
      case CONTAINS:
        contains(deque);
        break;
      case CLEAR:
        deque.clear();
        break;
      case QUIT:
        quit = true;
        break;
      default:
        break;
    }
    system("cls");
  }
  return 0;
}

void
push_front(deque<int>& deque)
{
  int v;
  std::cout << "Enter value: ";
  std::cin >> v;
  deque.push_front(v);
}

void
push_back(deque<int>& deque)
{
  int v;
  std::cout << "Enter value: ";
  std::cin >> v;
  deque.push_back(v);
}

void
front(deque<int>& deque)
{
  std::cout << deque.front() << '\n';
  std::cin.ignore(std::numeric_limits<std::streamsize>::max());
  std::cin.get();
}

void
back(deque<int>& deque)
{
  std::cout << deque.back() << '\n';
  std::cin.ignore(std::numeric_limits<std::streamsize>::max());
  std::cin.get();
}

void
check_empty(deque<int>& deque)
{
  if (deque.empty()) {
    std::cout << "Deque is empty." << '\n';

  } else {
    std::cout << "Deque is not empty." << '\n';
  }
  std::cin.ignore(std::numeric_limits<std::streamsize>::max());
  std::cin.get();
}

void
get_size(deque<int>& deque)
{
  std::cout << "Size: " <<  deque.size() << '\n';
  std::cin.ignore(std::numeric_limits<std::streamsize>::max());
  std::cin.get();
}

void
contains(deque<int>& deque)
{
  int v;
  std::cout << "Enter value: ";
  std::cin >> v;
  if (deque.contains(v)) {
    std::cout << "Deque is empty." << '\n';

  } else {
    std::cout << "Deque is not empty." << '\n';
  }
  std::cin.ignore(std::numeric_limits<std::streamsize>::max());
  std::cin.get();
}
