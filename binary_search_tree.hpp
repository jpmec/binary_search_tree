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
    : root(NULL)
  {
  }


  /// Copy constructor.
  BinarySearchTree(const BinarySearchTree& other)
    : root(NULL)
  {
    *this = other;
  }


  /// Virtual destructor.
  virtual ~BinarySearchTree()
  {
    clear();
  }


  /// Assignment, copy elements to this from other.
  BinarySearchTree& operator=(const BinarySearchTree& other)
  {
    this->clear();

    if (other.empty())
    {
      return *this;
    }

    this->root = new Node(other.root->value);

    return *this;
  }


  /// Returns true if the tree is empty.
  bool empty(void) const
  {
    return (NULL == this->root);
  }


  /// Clear all the elements.
  BinarySearchTree& clear(void)
  {
    if (NULL == this->root)
    {
      return *this;
    }

    this->root->clear();
    delete(this->root);
    this->root = NULL;

    return *this;
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
    if (NULL == this->root)
    {
      this->root = new Node(value);
      return *this;
    }

    return *this;
  }


  /// Erase value from the tree.
  BinarySearchTree& erase(T value)
  {
    if (this->empty())
    {
      return *this;
    }

    this->root = this->root->erase(value);

    return *this;
  }


  /// Return number of elements in tree.
  size_t size(void) const
  {
    if (this->empty())
    {
      return 0;
    }

    return this->root->size();
  }


  /// Returns number of elements that are equivalent to T.
  size_t count(const T& value) const
  {
    if (this->empty())
    {
      return 0;
    }

    return this->root->count(value);
  }


  protected:

  /// Binary search tree node type.
  /// Contains left and right pointers, and its value.
  struct Node
  {
    struct Node* left;
    struct Node* right;
    T value;

    /// Constructor, must pass value for node.
    Node(const T& v)
      : left(NULL), right(NULL), value(v)
    {
    }

    /// Constructor, must pass value, left and right pointers.
    Node(const T& v, Node* l, Node* r)
      : left(l), right(r), value(v)
    {
    }

    /// Get the size of the tree contained by this node.
    size_t size(void) const
    {
      size_t count = 1;

      if (NULL != this->left)
      {
        count += this->left->size();
      }

      if (NULL != this->right)
      {
        count += this->right->size();
      }

      return count;
    }


    /// Count the number of nodes with equivalent values contained by this node.
    size_t count(const T& value) const
    {
      size_t count = 0;

      if (this->value == value)
      {
        count += 1;
      }

      if (NULL != this->left)
      {
        count += this->left->count(value);
      }

      if (NULL != this->right)
      {
        count += this->right->count(value);
      }

      return count;
    }


    /// Delete the child elements of this.
    void clear(void)
    {
      if (NULL != this->left)
      {
        this->left->clear();
        delete(this->left);
        this->left = NULL;
      }

      if (NULL != this->right)
      {
        this->right->clear();
        delete(this->right);
        this->right = NULL;
      }
    }

    /// Erase the value from the tree contained by this node.
    /// Returns root node of resulting tree.
    Node* erase(const T& value)
    {
      if (this->value == value)
      {
        if (NULL != this->right)
        {
          // TODO IMPLEMENT THIS CASE
        }

        else if (NULL != this->left)
        {
          // TODO IMPLEMENT THIS CASE
        }

        delete (this);
        return NULL;
      }
      else
      {
        // TODO IMPLEMENT THIS CASE
        return this;
      }
    }

    protected:

    /// Protected default constructor.
    /// Do not call.
    Node()
      : left(NULL), right(NULL), value(0)
    {
    }
  };

private:

  /// The root node, may be NULL.
  Node* root;

};




#endif//BINARY_SEARCH_TREE_HPP
