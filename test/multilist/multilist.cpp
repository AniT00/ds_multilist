#include "deque.h"
#include "multilist.h"
#include <iostream>
#include <string>
#include <vector>

enum Option
{
  NONE,
  INSERT,
  REMOVE_LEVEL,
  REMOVE_BRANCH,
  CLEAR,
  QUIT
};

void
insert(multilist<int>& list)
{
  int v, elem;
  char child;
  std::cout << "Enter value: ";
  std::cin >> v;
  if (list.size() == 0) {
    list.insert(v);
    return;
	}
  std::cout << "Enter element after which to insert: ";
  std::cin >> elem;
  std::cout << "Is it child? [Y/n]: ";
  std::cin >> child;
  list.insert(v, elem, child == 'y' || child == 'Y');
}

void
remove_branch(multilist<int>& list)
{
  int v;
  std::cout << "Enter value: ";
  std::cin >> v;
  list.remove_branch(v);
}

void
remove_level(multilist<int>& list)
{
  int v;
  std::cout << "Enter level: ";
  std::cin >> v;
  list.remove_level(v);
}

int
main()
{
  multilist<int> list;
  list.insert(2);
  list.insert(3, 2, true);
  list.insert(4, 3, true);
  list.insert(5, 3, true);
  list.insert(6, 4, true);
  list.insert(8, 3);
  list.insert(7, 3);
  list.insert(10, 3);

  bool quit = false;
  std::string inp;
  while (!quit) {
    std::cout << list << '\n';
    std::cout
			<< "1. Insert\n" 
			<< "2. Remove level\n" 
			<< "3. Remove branch\n" 
			<< "4. Clear\n" 
			<< "5. Quit\n";
    std::cin >> inp;
    int option = std::stoi(inp);
    switch (option) {
      case INSERT:
        insert(list);
        break;
      case REMOVE_LEVEL:
        remove_level(list);
        break;
      case REMOVE_BRANCH:
        remove_branch(list);
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