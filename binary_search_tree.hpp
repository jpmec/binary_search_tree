/// A simple binary search tree implementation.
/// For demonstration purposes only.
///
/// Written by Joshua Petitt
/// https://github.com/jpmec/binary_search_tree
/// MIT license


#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SERACH_TREE_HPP


#include <algorithm>
#include <stack>
#include <queue>




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


  /// Returns the height of the binary search tree.
  /// Returns -1 for empty tree (i.e. no root)
  int height(void) const
  {
    if (this->empty())
    {
      return -1;
    }

    return this->root->height();
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

        // This case helps to keep a balanced tree.
        else if (   (NULL == this->right)
                 && (NULL == this->left->left)
                 && (NULL == this->left->right)
                 && (value < this->left->value) )
        {
          Node* new_root = this->left;
          this->left = NULL;
          new_root->right = this;
          new_root->left = new Node(value);
          return new_root;
        }

        else
        {
          this->left = this->left->insert(value);
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

        // This case helps to keep a balanced tree.
        else if (   (NULL == this->left)
                 && (NULL == this->right->left)
                 && (NULL == this->right->right)
                 && (value > this->right->value) )
        {
          Node* new_root = this->right;
          this->right = NULL;
          new_root->left = this;
          new_root->right = new Node(value);
          return new_root;
        }

        else
        {
          this->right = this->right->insert(value);
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
          // TODO ADD AUTO-BALANCING HERE
          return this->left->insert_unique_node(*(this->right));
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


    /// Return height of node tree.
    /// Returns 0 if no children.
    int height(void)
    {
      int left_height = 0;
      if (NULL != this->left)
      {
        left_height = 1 + this->left->height();
      }

      int right_height = 0;
      if (NULL != this->right)
      {
        right_height = 1 + this->right->height();
      }

      return std::max(left_height, right_height);
    }


    protected:

    /// Protected default constructor.
    /// Do not call, should not be able to create a node without a given value.
    Node()
      : left(NULL), right(NULL), value(0)
    {
    }


    /// Insert unique node into the tree contained by this node.
    /// Node must be unique, otherwise bad things will happen.
    /// Returns root of resulting tree.
    Node* insert_unique_node(Node& other)
    {
      if (other.value < this->value)
      {
        if (NULL == this->left)
        {
          this->left = &other;
          return this;
        }

        else
        {
          this->left = this->left->insert_unique_node(other);
          return this;
        }
      }

      else // (other->value > this->value)
      {
        if (NULL == this->right)
        {
          this->right = &other;
          return this;
        }

        else
        {
          this->right = this->right->insert_unique_node(other);
          return this;
        }
      }
    }

  };


  public:

  class DepthFirstIterator
  {
    public:

    DepthFirstIterator(Node* root)
      : node(NULL)
    {
      if (NULL == root)
      {
        return;
      }

      node = root;
      node = push_left_nodes(node);
    }


    T operator*() const
    {
      if (NULL == node)
      {
        // TODO THROW EXCEPTION
        return 0;
      }

      return node->value;
    }


    DepthFirstIterator& operator++()
    {
      if (NULL == node)
      {
        return *this;
      }
      else if (NULL == node->right)
      {
        if (nodes.empty())
        {
          node = NULL;
        }
        else
        {
          node = nodes.top();
          nodes.pop();
        }
      }
      else
      {
        node = push_left_nodes(node->right);
      }

      return *this;
    }

    bool operator!=(const DepthFirstIterator& other) const
    {
      return (this->node != other.node);
    }


    protected:

    Node* push_left_nodes(Node* node)
    {
      while (NULL != node->left)
      {
        nodes.push(node);
        node = node->left;
      }

      return node;
    }


    Node* node;
    std::stack<Node*> nodes;
  };


  /// Return a DepthFirstIterator that has been set to the beginning of the tree.
  /// The beginning of the tree is the left-most node.
  DepthFirstIterator begin_depthfirst()
  {
    return DepthFirstIterator(this->root);
  }


  /// Return a DepthFirstIterator that represents the end of the tree.
  DepthFirstIterator end_depthfirst()
  {
    return DepthFirstIterator(NULL);
  }




  class BreadthFirstIterator
  {
    public:

    BreadthFirstIterator(Node* root)
      : node(NULL), queue_ptr(&queue0), next_queue_ptr(&queue1)
    {
      if (NULL == root)
      {
        return;
      }

      node = root;

      if (NULL != node->left)
      {
        next_queue_ptr->push(node->left);
      }

      if (NULL != node->right)
      {
        next_queue_ptr->push(node->right);
      }
    }


    T operator*() const
    {
      if (NULL == node)
      {
        // TODO THROW EXCEPTION
        return 0;
      }

      return node->value;
    }


    BreadthFirstIterator& operator++()
    {
      if (NULL == node)
      {
        return *this;
      }

      // if queue is empty, then swap the pointers
      if (queue_ptr->empty())
      {
        std::queue<Node*>* temp_ptr = queue_ptr;
        queue_ptr = next_queue_ptr;
        next_queue_ptr = temp_ptr;
      }

      // if queue is still empty, then we are done
      if (queue_ptr->empty())
      {
        node = NULL;
        return *this;
      }
      else
      {
        node = queue_ptr->front();
        queue_ptr->pop();

        if (NULL != node->left)
        {
          next_queue_ptr->push(node->left);
        }

        if (NULL != node->right)
        {
          next_queue_ptr->push(node->right);
        }

        return *this;
      }
    }

    bool operator!=(const BreadthFirstIterator& other) const
    {
      return (this->node != other.node);
    }


    protected:

    Node* node;

    std::queue<Node*>* queue_ptr;
    std::queue<Node*>* next_queue_ptr;

    std::queue<Node*> queue0;
    std::queue<Node*> queue1;
  };


  /// Return a DepthFirstIterator that has been set to the beginning of the tree.
  /// The beginning of the tree is the left-most node.
  BreadthFirstIterator begin_breadthfirst()
  {
    return BreadthFirstIterator(this->root);
  }


  /// Return a DepthFirstIterator that represents the end of the tree.
  BreadthFirstIterator end_breadthfirst()
  {
    return BreadthFirstIterator(NULL);
  }




  private:

  /// The root node, may be NULL.
  Node* root;

};




#endif//BINARY_SEARCH_TREE_HPP
