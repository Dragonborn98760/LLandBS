// main.cpp

#include "test_linked_list.h" 
#include "test_binary_search_tree.h" 
#include "test_doubly_linked_list.h" 

int main(int argc, char **argv) 
{
	// FOR PASS
	test_linked_list();
    test_binary_search_tree();

	// FOR PASS WITH DISTINCTION
    test_doubly_linked_list(); 

   return 0;
}
