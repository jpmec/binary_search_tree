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
    assert(0 == int_tree2.size());
    assert(0 == int_tree1.compare(int_tree2));
  }

  { // test one element tree
    BinarySearchTree<int> int_tree1;
    int_tree1.insert(0);

    BinarySearchTree<int> int_tree2(int_tree1);

    assert(!int_tree2.empty());
    assert(1 == int_tree2.size());
    assert(1 == int_tree2.count(0));
    assert(0 == int_tree1.compare(int_tree2));
  }

  { // test two element tree with unique elements
    BinarySearchTree<int> int_tree1;
    int_tree1.insert(0);
    int_tree1.insert(1);

    BinarySearchTree<int> int_tree2(int_tree1);

    assert(!int_tree2.empty());
    assert(2 == int_tree2.size());
    assert(1 == int_tree2.count(0));
    assert(0 == int_tree1.compare(int_tree2));
  }

  { // test two element tree with identical elements
    BinarySearchTree<int> int_tree1;
    int_tree1.insert(0);
    int_tree1.insert(0);

    BinarySearchTree<int> int_tree2(int_tree1);

    assert(!int_tree2.empty());
    assert(1 == int_tree2.size());
    assert(1 == int_tree2.count(0));
    assert(0 == int_tree1.compare(int_tree2));
  }
}




void test_destructor(void)
{
  // Instantiate and let it be destructed when out of scope.
  BinarySearchTree<int> int_tree;
}




void test_assignment(void)
{
  { // test empty tree
    BinarySearchTree<int> int_tree1;
    BinarySearchTree<int> int_tree2;

    int_tree2 = int_tree1;

    assert(int_tree2.empty());
    assert(0 == int_tree2.size());
    assert(0 == int_tree1.compare(int_tree2));
  }

  { // test one element tree
    BinarySearchTree<int> int_tree1;
    int_tree1.insert(0);

    BinarySearchTree<int> int_tree2;

    int_tree2 = int_tree1;

    assert(!int_tree2.empty());
    assert(1 == int_tree2.size());
    assert(1 == int_tree2.count(0));
    assert(0 == int_tree1.compare(int_tree2));
  }

  { // test two element tree with unique elements
    BinarySearchTree<int> int_tree1;
    int_tree1.insert(0);
    int_tree1.insert(1);

    BinarySearchTree<int> int_tree2;

    int_tree2 = int_tree1;

    assert(!int_tree2.empty());
    assert(2 == int_tree2.size());
    assert(1 == int_tree2.count(0));
    assert(0 == int_tree1.compare(int_tree2));
  }

  { // test two element tree with identical elements
    BinarySearchTree<int> int_tree1;
    int_tree1.insert(0);
    int_tree1.insert(0);

    BinarySearchTree<int> int_tree2;

    int_tree2 = int_tree1;

    assert(!int_tree2.empty());
    assert(1 == int_tree2.size());
    assert(1 == int_tree2.count(0));
    assert(0 == int_tree1.compare(int_tree2));
  }
}




void test_empty(void)
{
  { // test empty tree
    BinarySearchTree<int> int_tree;

    assert(int_tree.empty());
  }

  { // test one element tree
    BinarySearchTree<int> int_tree;
    int_tree.insert(0);

    assert(!int_tree.empty());
  }
}




void test_clear(void)
{
  { // test empty tree
    BinarySearchTree<int> int_tree;

    int_tree.clear();

    assert(int_tree.empty());
  }

  { // test one element tree
    BinarySearchTree<int> int_tree;
    int_tree.insert(0);

    int_tree.clear();

    assert(int_tree.empty());
  }

  { // test two element tree
    BinarySearchTree<int> int_tree;
    int_tree.insert(0);
    int_tree.insert(1);

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

  { // test one element tree with same values
    BinarySearchTree<int> int_tree1;
    int_tree1.insert(0);

    BinarySearchTree<int> int_tree2;
    int_tree2.insert(0);

    assert(0 == int_tree1.compare(int_tree2));
  }

  { // test one element tree with 1 < 2
    BinarySearchTree<int> int_tree1;
    int_tree1.insert(0);

    BinarySearchTree<int> int_tree2;
    int_tree2.insert(1);

    assert(1 == int_tree1.compare(int_tree2));
  }

  { // test one element tree with 1 > 2
    BinarySearchTree<int> int_tree1;
    int_tree1.insert(1);

    BinarySearchTree<int> int_tree2;
    int_tree2.insert(0);

    assert(-1 == int_tree1.compare(int_tree2));
  }
}




void test_insert(void)
{
  { // test insert a single element
    BinarySearchTree<int> int_tree;

    int_tree.insert(0);

    assert(!int_tree.empty());
    assert(1 == int_tree.size());
    assert(1 == int_tree.count(0));
  }

  { // test insert two elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(0);
    int_tree.insert(1);

    assert(!int_tree.empty());
    assert(2 == int_tree.size());
    assert(1 == int_tree.count(0));
  }

  { // test insert two elements with identical values
    BinarySearchTree<int> int_tree;

    int_tree.insert(0);
    int_tree.insert(0);

    assert(!int_tree.empty());
    assert(1 == int_tree.size());
    assert(1 == int_tree.count(0));
  }
}




void test_erase(void)
{
  { // test empty tree
    BinarySearchTree<int> int_tree;

    int_tree.erase(0);

    assert(int_tree.empty());
  }

  { // test one element tree
    BinarySearchTree<int> int_tree;
    int_tree.insert(0);

    int_tree.erase(0);

    assert(int_tree.empty());
  }

  { // test two element tree with unique values
    BinarySearchTree<int> int_tree;
    int_tree.insert(0);
    int_tree.insert(1);

    int_tree.erase(0);

    assert(!int_tree.empty());
    assert(1 == int_tree.size());
    assert(0 == int_tree.count(0));
    assert(1 == int_tree.count(1));
  }

  { // test two element tree with unique values
    BinarySearchTree<int> int_tree;
    int_tree.insert(0);
    int_tree.insert(1);

    int_tree.erase(1);

    assert(!int_tree.empty());
    assert(1 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(0 == int_tree.count(1));
  }
}




void test_size(void)
{
  { // test empty tree
    BinarySearchTree<int> int_tree;

    assert(0 == int_tree.size());
  }

  { // test tree with one element
    BinarySearchTree<int> int_tree;
    int_tree.insert(0);

    assert(1 == int_tree.size());
  }

  { // test tree with two unique elements
    BinarySearchTree<int> int_tree;
    int_tree.insert(0);
    int_tree.insert(1);

    assert(2 == int_tree.size());
  }

  { // test tree with two identical elements
    BinarySearchTree<int> int_tree;
    int_tree.insert(0);
    int_tree.insert(0);

    assert(1 == int_tree.size());
  }
}




void test_count(void)
{
  { // test empty tree
    BinarySearchTree<int> int_tree;

    assert(0 == int_tree.count(0));
  }

  { // test one element tree
    BinarySearchTree<int> int_tree;
    int_tree.insert(0);

    assert(1 == int_tree.count(0));
  }

  { // test two element tree with unique values
    BinarySearchTree<int> int_tree;
    int_tree.insert(0);
    int_tree.insert(1);

    assert(1 == int_tree.count(0));
  }

  { // test two element tree with identical values
    BinarySearchTree<int> int_tree;
    int_tree.insert(0);
    int_tree.insert(0);

    assert(1 == int_tree.count(0));
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
