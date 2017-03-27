#include "Test.h"


int main(int argc, char** argv)
{
    char** my_list;
    StringListInit(&my_list,5);
    std::cout << StringListSize(my_list) << '\n';
    std::cout << StringListCapacity(my_list) << '\n';
    PrintList(my_list);
    StringListAdd(&my_list,"Roma");
    StringListAdd(&my_list,"Greb");
    std::cout << '\n';
    std::cout << StringListSize(my_list) << '\n';
    std::cout << StringListCapacity(my_list) << '\n';
    PrintList(my_list);
    std::cout << '\n';
    StringListAdd(&my_list,"is");
    StringListAdd(&my_list,"is");
    StringListAdd(&my_list,"a");
    StringListAdd(&my_list,"beginner");
    StringListAdd(&my_list,"in programming");
    std::cout << StringListSize(my_list) << '\n';
    std::cout << StringListCapacity(my_list) << '\n';
    PrintList(my_list);
    std::cout << '\n';
    std::cout << StringListIndexOf(my_list,"Roma") << '\n';
    RemoveDuplicatesString(&my_list);
    PrintList(my_list);
    std::cout << '\n';
    ListSort(my_list);
    PrintList(my_list);
    std::cout << '\n';
    RemoveString(&my_list,"Greb");
    std::cout << '\n';
    PrintList(my_list);
    std::cout << '\n';
//    StringListDestroy(&my_list);
   return 0;
}
