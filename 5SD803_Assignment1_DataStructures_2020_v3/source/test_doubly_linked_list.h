// test_doubly_linked_list.h

#ifndef TEST_DOUBLY_LINKED_LIST_H_INCLUDED
#define TEST_DOUBLY_LINKED_LIST_H_INCLUDED

#include "unit_test.hpp"
#include "doubly_linked_list.h"

void test_doubly_linked_list() 
{
   doubly_linked_list list;

   TEST_BEGIN(doubly_linked_list::size);
   TEST_CASE(list.size() == 0);
   TEST_END();


   TEST_BEGIN(doubly_linked_list::push_front);
   list.push_front(2);     // 2
   TEST_CASE(list.size() == 1);
   TEST_CASE(list.at(0) == 2);
   TEST_CASE(list.front() == 2);

   list.push_front(1);     // 1, 2
   TEST_CASE(list.size() == 2);
   TEST_CASE(list.at(0) == 1);
   TEST_CASE(list.front() == 1);
   TEST_CASE(list.at(1) == 2);
   TEST_CASE(list.back() == 2);
   TEST_END();


   TEST_BEGIN(doubly_linked_list::push_back);
   list.push_back(3);      // 1, 2, 3
   TEST_CASE(list.size() == 3);
   TEST_CASE(list.at(2) == 3);
   TEST_CASE(list.front() == 1);
   TEST_CASE(list.back() == 3);

   list.push_back(5);      // 1, 2, 3, 5
   TEST_CASE(list.size() == 4);
   TEST_CASE(list.at(2) == 3);
   TEST_CASE(list.at(3) == 5);
   TEST_CASE(list.front() == 1);
   TEST_CASE(list.back() == 5);
   TEST_END();


   TEST_BEGIN(doubly_linked_list::insert);
   list.insert(4, 3);      // 1, 2, 3, 4, 5
   TEST_CASE(list.size() == 5);
   TEST_CASE(list.at(2) == 3);
   TEST_CASE(list.at(3) == 4);
   TEST_CASE(list.at(4) == 5);
   TEST_CASE(list.front() == 1);
   TEST_CASE(list.back() == 5);
   list.insert(0, 0); // 0, 1, 2, 3, 4, 5
   TEST_CASE(list.size() == 6);
   TEST_CASE(list.at(0) == 0);
   TEST_CASE(list.at(3) == 3);
   TEST_CASE(list.at(5) == 5);
   TEST_CASE(list.front() == 0);
   TEST_CASE(list.back() == 5);
   list.insert(6, 6); // 0, 1, 2, 3, 4, 5, 6
   TEST_CASE(list.size() == 7);
   TEST_CASE(list.at(0) == 0);
   TEST_CASE(list.at(3) == 3);
   TEST_CASE(list.at(6) == 6);
   TEST_CASE(list.front() == 0);
   TEST_CASE(list.back() == 6);
   TEST_END();


   TEST_BEGIN(doubly_linked_list::remove);
   list.remove(6);         // 0, 1, 2, 3, 4, 5
   TEST_CASE(list.size() == 6);
   TEST_CASE(list.front() == 0);
   TEST_CASE(list.at(0) == 0);
   TEST_CASE(list.at(2) == 2);
   TEST_CASE(list.at(5) == 5);
   TEST_CASE(list.back() == 5);
   list.remove(0);         // 1, 2, 3, 4, 5
   TEST_CASE(list.size() == 5);
   TEST_CASE(list.front() == 1);
   TEST_CASE(list.at(1) == 2);
   TEST_CASE(list.at(2) == 3);
   TEST_CASE(list.at(4) == 5);
   TEST_CASE(list.back() == 5);
   list.remove(1);         // 1, 3, 4, 5
   TEST_CASE(list.size() == 4);
   TEST_CASE(list.front() == 1);
   TEST_CASE(list.at(1) == 3);
   TEST_CASE(list.at(2) == 4);
   TEST_CASE(list.back() == 5);
   TEST_END();


   TEST_BEGIN(doubly_linked_list::pop_front);
   list.pop_front();       // 3, 4, 5
   TEST_CASE(list.size() == 3);
   TEST_CASE(list.front() == 3);
   TEST_CASE(list.back() == 5);
   TEST_END();


   TEST_BEGIN(doubly_linked_list::pop_back);
   list.pop_back();       // 3, 4
   TEST_CASE(list.size() == 2);
   TEST_CASE(list.front() == 3);
   TEST_CASE(list.back() == 4);
   TEST_END();


   TEST_BEGIN(doubly_linked_list::clear);
   list.clear(); // empty
   TEST_CASE(list.size() == 0);
   list.clear();
   TEST_CASE(list.size() == 0);
   list.pop_back();
   TEST_CASE(list.size() == 0);
   list.pop_front();
   TEST_CASE(list.size() == 0);
   TEST_CASE(list.at(-2) == -1);
   TEST_CASE(list.at(45) == -1);
   list.remove(-1);
   TEST_CASE(list.size() == 0);
   list.remove(10);
   TEST_CASE(list.size() == 0);
   list.insert(100, -1);
   TEST_CASE(list.size() == 0);
   list.insert(100, 100);
   TEST_CASE(list.size() == 0);
   list.insert(1, 0); // 1
   TEST_CASE(list.size() == 1);
   TEST_CASE(list.front() == 1);
   TEST_CASE(list.back() == 1);
   TEST_CASE(list.at(0) == 1);
   list.remove(0); // empty
   TEST_CASE(list.size() == 0);
   TEST_CASE(list.front() == -1);
   TEST_CASE(list.back() == -1);
   TEST_CASE(list.at(0) == -1);
   TEST_END();

   TEST_BEGIN("Traversal");
   list.clear();
   list.push_back(1);  // 1
   list.push_back(2);  // 1, 2
   list.push_back(3);  // 1, 2, 3
   list.push_back(4);  // 1, 2, 3, 4
   list.push_back(5);  // 1, 2, 3, 4, 5
   {
	   int arr[] = { 1,2,3,4,5 };
	   TEST_CASE(traverse(arr, 5, list) == 1);
   }
   {
	   int arr[] = { 5,4,3,2,1 };
	   TEST_CASE(traverseReversed(arr, 5, list) == 1);
   }
   list.pop_front(); // 2, 3, 4, 5
   list.pop_back(); // 2, 3, 4
   {
	   int arr[] = { 2,3,4 };
	   TEST_CASE(traverse(arr, 3, list) == 1);
   }
   {
	   int arr[] = { 4,3,2 };
	   TEST_CASE(traverseReversed(arr, 3, list) == 1);
   }
   list.insert(1, 1); // 2, 1, 3, 4
   list.insert(5, 3); // 2, 1, 3, 5, 4
   {
	   int arr[] = { 2, 1, 3, 5, 4 };
	   TEST_CASE(traverse(arr, 3, list) == 1);
   }
   {
	   int arr[] = { 4, 5, 3, 1, 2 };
	   TEST_CASE(traverseReversed(arr, 3, list) == 1);
   }
   list.remove(2); // 2, 1, 5, 4
   {
	   int arr[] = { 2, 1, 5, 4 };
	   TEST_CASE(traverse(arr, 3, list) == 1);
   }
   {
	   int arr[] = { 4, 5, 1, 2 };
	   TEST_CASE(traverseReversed(arr, 3, list) == 1);
   }
   list.push_front(3); // 3, 2, 1, 5, 4
   list.push_front(6); // 6, 3, 2, 1, 5, 4
   {
	   int arr[] = { 6, 3, 2, 1, 5, 4 };
	   TEST_CASE(traverse(arr, 3, list) == 1);
   }
   {
	   int arr[] = { 4, 5, 1, 2, 3, 6 };
	   TEST_CASE(traverseReversed(arr, 3, list) == 1);
   }
}

bool traverse(const int arr[], const unsigned int size, const doubly_linked_list& list)
{
	doubly_linked_list::node* current = list.head_;
	for (unsigned int i = 0; i < size;i++)
	{
		if (current == nullptr)
			return false;
		if (current->value_ == arr[i])
		{
			current = current->next_;
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool traverseReversed(const int arr[], const unsigned int size, const doubly_linked_list& list)
{
	doubly_linked_list::node* current = list.tail_;
	for (unsigned int i = 0; i < size; i++)
	{
		if (current == nullptr)
			return false;
		if (current->value_ == arr[i])
		{
			current = current->previous_;
		}
		else
		{
			return false;
		}
	}
	return true;
}
#endif // !TEST_DOUBLY_LINKED_LIST_H_INCLUDED
