#include <iostream>
#include <cassert>

#include "binary_search_tree.hpp"


using namespace std;




void test_default_constructor(void)
{
  BinarySearchTree<int> int_tree;

  assert(int_tree.empty());
}




void test_copy_constructor(void)
{
  { // test empty tree
    BinarySearchTree<int> int_tree1;

    BinarySearchTree<int> int_tree2(int_tree1);

    assert(int_tree2.empty());
    assert(0 == int_tree1.compare(int_tree2));
  }
}




void test_destructor(void)
{
  /// Instantiate and let it be destructed when out of scope.
  BinarySearchTree<int> int_tree;
}




void test_assignment(void)
{
  { // test empty tree
    BinarySearchTree<int> int_tree1;
    BinarySearchTree<int> int_tree2;

    int_tree2 = int_tree1;

    assert(int_tree2.empty());
    assert(0 == int_tree1.compare(int_tree2));
  }
}




void test_empty(void)
{
  { // test empty tree
    BinarySearchTree<int> int_tree;

    assert(int_tree.empty());
  }
}




void test_clear(void)
{
  { // test empty tree
    BinarySearchTree<int> int_tree;

    int_tree.clear();

    assert(int_tree.empty());
  }
}




void test_compare(void)
{
  { // test empty tree
    BinarySearchTree<int> int_tree1;
    BinarySearchTree<int> int_tree2;

    assert(0 == int_tree1.compare(int_tree2));
  }
}




void test_insert(void)
{
  assert(0);
}




void test_erase(void)
{
  assert(0);
}




void test_size(void)
{
  { // test empty tree
    BinarySearchTree<int> int_tree;

    assert(0 == int_tree.size());
  }
}




void test_count(void)
{
  { // test empty tree
    BinarySearchTree<int> int_tree;

    assert(0 == int_tree.count(0));
  }
}




int main(int argc, char* argv[])
{
  test_default_constructor();
  test_copy_constructor();
  test_destructor();
  test_assignment();
  test_empty();
  test_clear();
  test_compare();
  test_insert();
  test_erase();
  test_size();
  test_count();

  cout << __FILE__ << " PASSED"<< endl;
}
