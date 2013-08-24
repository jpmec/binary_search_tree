/// A simple binary search tree implementation.
/// For demonstration purposes only.
///
/// Written by Joshua Petitt
/// https://github.com/jpmec/binary_search_tree
/// MIT license


#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SERACH_TREE_HPP




template <typename T>
class BinarySearchTree
{
public:

  /// Default constructor.
  BinarySearchTree()
  {
  }


  /// Copy constructor.
  BinarySearchTree(const BinarySearchTree& other)
  {
  }


  /// Virtual destructor.
  virtual ~BinarySearchTree()
  {
    clear();
  }


  /// Assignment, copy elements to this from other.
  BinarySearchTree& operator=(const BinarySearchTree& other)
  {
    return *this;
  }


  /// Clear all the elements.
  void clear()
  {
  }

  /// Compare this to other tree.
  /// Returns 0 if trees are same size and contain the same values.
  /// Returns < 0 if value encountered in other tree is lower than this tree.
  /// Retruns > 0 if value encountered in other tree is greater than this tree.
  int compare(const BinarySearchTree& other) const
  {
    return 0;
  }


  /// Insert a value into the tree.
  BinarySearchTree& insert(T value)
  {
    return *this;
  }


  /// Erase value from the tree.
  BinarySearchTree& erase(T value)
  {
    return *this;
  }


  /// Return number of elements in tree.
  size_t size(void) const
  {
    return 0;
  }


  /// Returns number of elements that are equivalent to T.
  size_t count(const T& value) const
  {
    return 0;
  }

};




#endif//BINARY_SEARCH_TREE_HPP
