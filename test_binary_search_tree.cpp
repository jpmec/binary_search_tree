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

  { // test two element tree with unique elements
    BinarySearchTree<int> int_tree1;
    int_tree1.insert(1);
    int_tree1.insert(0);

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

  { // test two element tree with unique elements
    BinarySearchTree<int> int_tree1;
    int_tree1.insert(1);
    int_tree1.insert(0);

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



  { // test three element tree with unique elements
    BinarySearchTree<int> int_tree1;
    int_tree1.insert(0);
    int_tree1.insert(1);
    int_tree1.insert(2);

    BinarySearchTree<int> int_tree2;

    int_tree2 = int_tree1;

    assert(!int_tree2.empty());
    assert(3 == int_tree2.size());
    assert(1 == int_tree2.count(0));
    assert(1 == int_tree2.count(1));
    assert(1 == int_tree2.count(2));
    assert(0 == int_tree1.compare(int_tree2));
  }

  { // test three element tree with unique elements
    BinarySearchTree<int> int_tree1;
    int_tree1.insert(0);
    int_tree1.insert(2);
    int_tree1.insert(1);

    BinarySearchTree<int> int_tree2;

    int_tree2 = int_tree1;

    assert(!int_tree2.empty());
    assert(3 == int_tree2.size());
    assert(1 == int_tree2.count(0));
    assert(1 == int_tree2.count(1));
    assert(1 == int_tree2.count(2));
    assert(0 == int_tree1.compare(int_tree2));
  }

  { // test three element tree with unique elements
    BinarySearchTree<int> int_tree1;
    int_tree1.insert(1);
    int_tree1.insert(0);
    int_tree1.insert(2);

    BinarySearchTree<int> int_tree2;

    int_tree2 = int_tree1;

    assert(!int_tree2.empty());
    assert(3 == int_tree2.size());
    assert(1 == int_tree2.count(0));
    assert(1 == int_tree2.count(1));
    assert(1 == int_tree2.count(2));
    assert(0 == int_tree1.compare(int_tree2));
  }

  { // test three element tree with unique elements
    BinarySearchTree<int> int_tree1;
    int_tree1.insert(1);
    int_tree1.insert(2);
    int_tree1.insert(0);

    BinarySearchTree<int> int_tree2;

    int_tree2 = int_tree1;

    assert(!int_tree2.empty());
    assert(3 == int_tree2.size());
    assert(1 == int_tree2.count(0));
    assert(1 == int_tree2.count(1));
    assert(1 == int_tree2.count(2));
    assert(0 == int_tree1.compare(int_tree2));
  }

  { // test three element tree with unique elements
    BinarySearchTree<int> int_tree1;
    int_tree1.insert(2);
    int_tree1.insert(0);
    int_tree1.insert(1);

    BinarySearchTree<int> int_tree2;

    int_tree2 = int_tree1;

    assert(!int_tree2.empty());
    assert(3 == int_tree2.size());
    assert(1 == int_tree2.count(0));
    assert(1 == int_tree2.count(1));
    assert(1 == int_tree2.count(2));
    assert(0 == int_tree1.compare(int_tree2));
  }

  { // test three element tree with unique elements
    BinarySearchTree<int> int_tree1;
    int_tree1.insert(2);
    int_tree1.insert(1);
    int_tree1.insert(0);

    BinarySearchTree<int> int_tree2;

    int_tree2 = int_tree1;

    assert(!int_tree2.empty());
    assert(3 == int_tree2.size());
    assert(1 == int_tree2.count(0));
    assert(1 == int_tree2.count(1));
    assert(1 == int_tree2.count(2));
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

  { // test two element tree
    BinarySearchTree<int> int_tree;
    int_tree.insert(1);
    int_tree.insert(0);

    int_tree.clear();

    assert(int_tree.empty());
  }

  { // test three element tree
    BinarySearchTree<int> int_tree;
    int_tree.insert(0);
    int_tree.insert(1);
    int_tree.insert(2);

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
    assert(1 == int_tree.count(1));
  }

  { // test insert two elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(1);
    int_tree.insert(0);

    assert(!int_tree.empty());
    assert(2 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
  }

  { // test insert two elements with identical values
    BinarySearchTree<int> int_tree;

    int_tree.insert(0);
    int_tree.insert(0);

    assert(!int_tree.empty());
    assert(1 == int_tree.size());
    assert(1 == int_tree.count(0));
  }

  { // test insert three elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(0);
    int_tree.insert(1);
    int_tree.insert(2);

    assert(!int_tree.empty());
    assert(3 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
  }

  { // test insert three elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(0);
    int_tree.insert(2);
    int_tree.insert(1);

    assert(!int_tree.empty());
    assert(3 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
  }

  { // test insert three elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(1);
    int_tree.insert(0);
    int_tree.insert(2);

    assert(!int_tree.empty());
    assert(3 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
  }

  { // test insert three elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(1);
    int_tree.insert(2);
    int_tree.insert(0);

    assert(!int_tree.empty());
    assert(3 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
  }

  { // test insert three elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(2);
    int_tree.insert(0);
    int_tree.insert(1);

    assert(!int_tree.empty());
    assert(3 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
  }

  { // test insert three elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(2);
    int_tree.insert(1);
    int_tree.insert(0);

    assert(!int_tree.empty());
    assert(3 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
  }

  { // test insert four elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(0);
    int_tree.insert(1);
    int_tree.insert(2);
    int_tree.insert(3);

    assert(!int_tree.empty());
    assert(4 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
    assert(1 == int_tree.count(3));
  }

  { // test insert four elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(0);
    int_tree.insert(1);
    int_tree.insert(3);
    int_tree.insert(2);

    assert(!int_tree.empty());
    assert(4 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
    assert(1 == int_tree.count(3));
  }

  { // test insert four elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(0);
    int_tree.insert(2);
    int_tree.insert(1);
    int_tree.insert(3);

    assert(!int_tree.empty());
    assert(4 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
    assert(1 == int_tree.count(3));
  }

  { // test insert four elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(0);
    int_tree.insert(2);
    int_tree.insert(3);
    int_tree.insert(1);

    assert(!int_tree.empty());
    assert(4 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
    assert(1 == int_tree.count(3));
  }

  { // test insert four elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(0);
    int_tree.insert(3);
    int_tree.insert(1);
    int_tree.insert(2);

    assert(!int_tree.empty());
    assert(4 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
    assert(1 == int_tree.count(3));
  }

  { // test insert four elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(0);
    int_tree.insert(3);
    int_tree.insert(2);
    int_tree.insert(1);

    assert(!int_tree.empty());
    assert(4 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
    assert(1 == int_tree.count(3));
  }

  { // test insert four elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(1);
    int_tree.insert(0);
    int_tree.insert(2);
    int_tree.insert(3);

    assert(!int_tree.empty());
    assert(4 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
    assert(1 == int_tree.count(3));
  }

  { // test insert four elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(1);
    int_tree.insert(0);
    int_tree.insert(3);
    int_tree.insert(2);

    assert(!int_tree.empty());
    assert(4 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
    assert(1 == int_tree.count(3));
  }

  { // test insert four elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(1);
    int_tree.insert(2);
    int_tree.insert(0);
    int_tree.insert(3);

    assert(!int_tree.empty());
    assert(4 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
    assert(1 == int_tree.count(3));
  }

  { // test insert four elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(1);
    int_tree.insert(2);
    int_tree.insert(3);
    int_tree.insert(0);

    assert(!int_tree.empty());
    assert(4 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
    assert(1 == int_tree.count(3));
  }

  { // test insert four elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(1);
    int_tree.insert(3);
    int_tree.insert(0);
    int_tree.insert(2);

    assert(!int_tree.empty());
    assert(4 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
    assert(1 == int_tree.count(3));
  }

  { // test insert four elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(1);
    int_tree.insert(3);
    int_tree.insert(2);
    int_tree.insert(0);

    assert(!int_tree.empty());
    assert(4 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
    assert(1 == int_tree.count(3));
  }

  { // test insert four elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(2);
    int_tree.insert(0);
    int_tree.insert(1);
    int_tree.insert(3);

    assert(!int_tree.empty());
    assert(4 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
    assert(1 == int_tree.count(3));
  }

  { // test insert four elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(2);
    int_tree.insert(0);
    int_tree.insert(3);
    int_tree.insert(1);

    assert(!int_tree.empty());
    assert(4 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
    assert(1 == int_tree.count(3));
  }

  { // test insert four elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(2);
    int_tree.insert(1);
    int_tree.insert(0);
    int_tree.insert(3);

    assert(!int_tree.empty());
    assert(4 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
    assert(1 == int_tree.count(3));
  }

  { // test insert four elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(2);
    int_tree.insert(1);
    int_tree.insert(3);
    int_tree.insert(0);

    assert(!int_tree.empty());
    assert(4 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
    assert(1 == int_tree.count(3));
  }

  { // test insert four elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(2);
    int_tree.insert(3);
    int_tree.insert(0);
    int_tree.insert(1);

    assert(!int_tree.empty());
    assert(4 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
    assert(1 == int_tree.count(3));
  }

  { // test insert four elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(2);
    int_tree.insert(3);
    int_tree.insert(1);
    int_tree.insert(0);

    assert(!int_tree.empty());
    assert(4 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
    assert(1 == int_tree.count(3));
  }

  { // test insert four elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(3);
    int_tree.insert(0);
    int_tree.insert(1);
    int_tree.insert(2);

    assert(!int_tree.empty());
    assert(4 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
    assert(1 == int_tree.count(3));
  }

  { // test insert four elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(3);
    int_tree.insert(0);
    int_tree.insert(2);
    int_tree.insert(1);

    assert(!int_tree.empty());
    assert(4 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
    assert(1 == int_tree.count(3));
  }

  { // test insert four elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(3);
    int_tree.insert(1);
    int_tree.insert(0);
    int_tree.insert(2);

    assert(!int_tree.empty());
    assert(4 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
    assert(1 == int_tree.count(3));
  }

  { // test insert four elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(3);
    int_tree.insert(1);
    int_tree.insert(2);
    int_tree.insert(0);

    assert(!int_tree.empty());
    assert(4 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
    assert(1 == int_tree.count(3));
  }

  { // test insert four elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(3);
    int_tree.insert(2);
    int_tree.insert(0);
    int_tree.insert(1);

    assert(!int_tree.empty());
    assert(4 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
    assert(1 == int_tree.count(3));
  }

  { // test insert four elements with unique values
    BinarySearchTree<int> int_tree;

    int_tree.insert(3);
    int_tree.insert(2);
    int_tree.insert(1);
    int_tree.insert(0);

    assert(!int_tree.empty());
    assert(4 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
    assert(1 == int_tree.count(3));
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

  { // test two element tree with unique values
    BinarySearchTree<int> int_tree;
    int_tree.insert(1);
    int_tree.insert(0);

    int_tree.erase(0);

    assert(!int_tree.empty());
    assert(1 == int_tree.size());
    assert(0 == int_tree.count(0));
    assert(1 == int_tree.count(1));
  }

  { // test two element tree with unique values
    BinarySearchTree<int> int_tree;
    int_tree.insert(1);
    int_tree.insert(0);

    int_tree.erase(1);

    assert(!int_tree.empty());
    assert(1 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(0 == int_tree.count(1));
  }

  { // test three element tree with unique values
    BinarySearchTree<int> int_tree;
    int_tree.insert(0);
    int_tree.insert(1);
    int_tree.insert(2);

    int_tree.erase(0);

    assert(!int_tree.empty());
    assert(2 == int_tree.size());
    assert(0 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
  }

  { // test three element tree with unique values
    BinarySearchTree<int> int_tree;
    int_tree.insert(0);
    int_tree.insert(1);
    int_tree.insert(2);

    int_tree.erase(1);

    assert(!int_tree.empty());
    assert(2 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(0 == int_tree.count(1));
    assert(1 == int_tree.count(2));
  }

  { // test three element tree with unique values
    BinarySearchTree<int> int_tree;
    int_tree.insert(0);
    int_tree.insert(1);
    int_tree.insert(2);

    int_tree.erase(2);

    assert(!int_tree.empty());
    assert(2 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(0 == int_tree.count(2));
  }

  { // test three element tree with unique values
    BinarySearchTree<int> int_tree;
    int_tree.insert(0);
    int_tree.insert(2);
    int_tree.insert(1);

    int_tree.erase(0);

    assert(!int_tree.empty());
    assert(2 == int_tree.size());
    assert(0 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
  }

  { // test three element tree with unique values
    BinarySearchTree<int> int_tree;
    int_tree.insert(0);
    int_tree.insert(2);
    int_tree.insert(1);

    int_tree.erase(1);

    assert(!int_tree.empty());
    assert(2 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(0 == int_tree.count(1));
    assert(1 == int_tree.count(2));
  }

  { // test three element tree with unique values
    BinarySearchTree<int> int_tree;
    int_tree.insert(0);
    int_tree.insert(2);
    int_tree.insert(1);

    int_tree.erase(2);

    assert(!int_tree.empty());
    assert(2 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(0 == int_tree.count(2));
  }

  { // test three element tree with unique values
    BinarySearchTree<int> int_tree;
    int_tree.insert(1);
    int_tree.insert(0);
    int_tree.insert(2);

    int_tree.erase(0);

    assert(!int_tree.empty());
    assert(2 == int_tree.size());
    assert(0 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
  }

  { // test three element tree with unique values
    BinarySearchTree<int> int_tree;
    int_tree.insert(1);
    int_tree.insert(0);
    int_tree.insert(2);

    int_tree.erase(1);

    assert(!int_tree.empty());
    assert(2 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(0 == int_tree.count(1));
    assert(1 == int_tree.count(2));
  }

  { // test three element tree with unique values
    BinarySearchTree<int> int_tree;
    int_tree.insert(1);
    int_tree.insert(0);
    int_tree.insert(2);

    int_tree.erase(2);

    assert(!int_tree.empty());
    assert(2 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(0 == int_tree.count(2));
  }

  { // test three element tree with unique values
    BinarySearchTree<int> int_tree;
    int_tree.insert(1);
    int_tree.insert(2);
    int_tree.insert(0);

    int_tree.erase(0);

    assert(!int_tree.empty());
    assert(2 == int_tree.size());
    assert(0 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
  }

  { // test three element tree with unique values
    BinarySearchTree<int> int_tree;
    int_tree.insert(1);
    int_tree.insert(2);
    int_tree.insert(0);

    int_tree.erase(1);

    assert(!int_tree.empty());
    assert(2 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(0 == int_tree.count(1));
    assert(1 == int_tree.count(2));
  }

  { // test three element tree with unique values
    BinarySearchTree<int> int_tree;
    int_tree.insert(1);
    int_tree.insert(2);
    int_tree.insert(0);

    int_tree.erase(2);

    assert(!int_tree.empty());
    assert(2 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(0 == int_tree.count(2));
  }

  { // test three element tree with unique values
    BinarySearchTree<int> int_tree;
    int_tree.insert(2);
    int_tree.insert(0);
    int_tree.insert(1);

    int_tree.erase(0);

    assert(!int_tree.empty());
    assert(2 == int_tree.size());
    assert(0 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
  }

  { // test three element tree with unique values
    BinarySearchTree<int> int_tree;
    int_tree.insert(2);
    int_tree.insert(0);
    int_tree.insert(1);

    int_tree.erase(1);

    assert(!int_tree.empty());
    assert(2 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(0 == int_tree.count(1));
    assert(1 == int_tree.count(2));
  }

  { // test three element tree with unique values
    BinarySearchTree<int> int_tree;
    int_tree.insert(2);
    int_tree.insert(0);
    int_tree.insert(1);

    int_tree.erase(2);

    assert(!int_tree.empty());
    assert(2 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(0 == int_tree.count(2));
  }

  { // test three element tree with unique values
    BinarySearchTree<int> int_tree;
    int_tree.insert(2);
    int_tree.insert(1);
    int_tree.insert(0);

    int_tree.erase(0);

    assert(!int_tree.empty());
    assert(2 == int_tree.size());
    assert(0 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(1 == int_tree.count(2));
  }

  { // test three element tree with unique values
    BinarySearchTree<int> int_tree;
    int_tree.insert(2);
    int_tree.insert(1);
    int_tree.insert(0);

    int_tree.erase(1);

    assert(!int_tree.empty());
    assert(2 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(0 == int_tree.count(1));
    assert(1 == int_tree.count(2));
  }

  { // test three element tree with unique values
    BinarySearchTree<int> int_tree;
    int_tree.insert(2);
    int_tree.insert(1);
    int_tree.insert(0);

    int_tree.erase(2);

    assert(!int_tree.empty());
    assert(2 == int_tree.size());
    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
    assert(0 == int_tree.count(2));
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

  { // test tree with two unique elements
    BinarySearchTree<int> int_tree;
    int_tree.insert(1);
    int_tree.insert(0);

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
    assert(1 == int_tree.count(1));
  }

  { // test two element tree with unique values
    BinarySearchTree<int> int_tree;
    int_tree.insert(1);
    int_tree.insert(0);

    assert(1 == int_tree.count(0));
    assert(1 == int_tree.count(1));
  }

  { // test two element tree with identical values
    BinarySearchTree<int> int_tree;
    int_tree.insert(0);
    int_tree.insert(0);

    assert(1 == int_tree.count(0));
  }
}



void test_height(void)
{
  { // test empty tree
    BinarySearchTree<int> int_tree;

    assert(-1 == int_tree.height());
  }

  { // test one element tree
    BinarySearchTree<int> int_tree;
    int_tree.insert(0);

    assert(0 == int_tree.height());
  }

  { // test two element tree
    BinarySearchTree<int> int_tree;
    int_tree.insert(0);
    int_tree.insert(1);

    assert(1 == int_tree.height());
  }

  { // test two element tree
    BinarySearchTree<int> int_tree;
    int_tree.insert(1);
    int_tree.insert(0);

    assert(1 == int_tree.height());
  }

  { // test four element tree
    BinarySearchTree<int> int_tree;
    int_tree.insert(0);
    int_tree.insert(1);
    int_tree.insert(2);
    int_tree.insert(3);

    assert(2 == int_tree.height());
  }


  { // test full seven element tree
    BinarySearchTree<int> int_tree;
    int_tree.insert(3);
    int_tree.insert(1);
    int_tree.insert(5);
    int_tree.insert(0);
    int_tree.insert(2);
    int_tree.insert(4);
    int_tree.insert(6);

    assert(2 == int_tree.height());
  }

  { // test eight element tree
    BinarySearchTree<int> int_tree;
    int_tree.insert(3);
    int_tree.insert(1);
    int_tree.insert(5);
    int_tree.insert(0);
    int_tree.insert(2);
    int_tree.insert(4);
    int_tree.insert(6);
    int_tree.insert(7);

    assert(3 == int_tree.height());
  }
}




void test_begin_depthfirst(void)
{
  // setup balanced tree
  const int values[] = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};

  BinarySearchTree<int> int_tree;

  for (int i = 0; i < 15; ++i)
  {
    int_tree.insert(values[i]);
  }


  BinarySearchTree<int>::DepthFirstIterator iter = int_tree.begin_depthfirst();
  const BinarySearchTree<int>::DepthFirstIterator end = int_tree.end_depthfirst();
  int expected = 1;
  for (; iter != end; ++expected, ++iter)
  {
    int value = *iter;

    if (expected != value)
    {
      cout << "expected: " << expected << " value: " << value << endl;
    }

    assert(expected == value);
  }
}



void test_begin_breadthfirst(void)
{
  // setup balanced tree
  const int values[] = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};

  BinarySearchTree<int> int_tree;

  for (int i = 0; i < 15; ++i)
  {
    int_tree.insert(values[i]);
  }

  BinarySearchTree<int>::BreadthFirstIterator iter = int_tree.begin_breadthfirst();
  const BinarySearchTree<int>::BreadthFirstIterator end = int_tree.end_breadthfirst();
  int i = 0;
  for (; (iter != end) && (i < 16); ++i, ++iter)
  {
    int value = *iter;
    int expected = values[i];

    if (expected != value)
    {
      cout << "expected: " << expected << " value: " << value << endl;
    }

    assert(expected == value);
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
  test_height();

  test_begin_depthfirst();
  test_begin_breadthfirst();

  cout << __FILE__ << " PASSED"<< endl;
}
