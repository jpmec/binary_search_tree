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
    this->root->operator=(*(other.root));

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
    if (this->empty())
    {
      if (other.empty())
      {
        return 0;
      }
      else
      {
        return 1;
      }
    }

    else if (other.empty())
    {
      return -1;
    }

    else
    {
      return this->root->compare(*(other.root));
    }
  }


  /// Insert a value into the tree.
  BinarySearchTree& insert(const T& value)
  {
    if (NULL == this->root)
    {
      this->root = new Node(value);
      return *this;
    }

    this->root = this->root->insert(value);

    return *this;
  }


  /// Erase value from the tree.
  BinarySearchTree& erase(const T& value)
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
  /// Note: this binary search tree is not allowed to have duplicate values,
  /// so count will return either 0 or 1.
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
  /// Most methods of this class are implemented as recursive functions.
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


    /// Insert value into the tree contained by this node.
    /// Returns root of resulting tree.
    Node* insert(const T& value)
    {
      if (value < this->value)
      {
        if (NULL == this->left)
        {
          this->left = new Node(value);
          return this;
        }
        else
        {
          // TODO IMPLEMENT THIS CASE
          return this;
        }
      }

      else if (value > this->value)
      {
        if (NULL == this->right)
        {
          this->right = new Node(value);
          return this;
        }
        else
        {
          // TODO IMPLEMENT THIS CASE
          return this;
        }
      }

      else
      {
        // value already exists, nothing to do.
        return this;
      }
    }


    /// Erase the value from the tree contained by this node.
    /// Returns root node of resulting tree.
    Node* erase(const T& value)
    {
      if (value < this->value)
      {
        this->left = this->left->erase(value);
        return this;
      }
      else if (value > this->value)
      {
        this->right = this->right->erase(value);
        return this;
      }
      else
      {
        if ((NULL == this->left) && (NULL != this->right))
        {
          Node* new_root = this->right;
          delete (this);
          return new_root;
        }

        else if ((NULL != this->left) && (NULL == this->right))
        {
          Node* new_root = this->left;
          delete (this);
          return new_root;
        }

        else if ((NULL != this->left) && (NULL != this->right))
        {
          // TODO IMPLEMENT THIS CASE
          return this;
        }

        else // child nodes both NULL
        {
          delete (this);
          return NULL;
        }
      }
    }


    /// Assignment operator.
    /// Copy other values into this tree.
    Node& operator=(const Node& other)
    {
      this->clear();
      this->value = other.value;

      if (NULL != other.left)
      {
        this->left = new Node(other.left->value);
        this->left->operator=(*other.left);
      }

      if (NULL != other.right)
      {
        this->right = new Node(other.right->value);
        this->right->operator=(*other.right);
      }

      return *this;
    }


    /// Compare this tree to other tree.
    int compare(const Node& other)
    {
      if (other.value < this->value)
      {
        return -1;
      }
      else if (other.value > this->value)
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }


    protected:

    /// Protected default constructor.
    /// Do not call, should not be able to create a node without a given value.
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
