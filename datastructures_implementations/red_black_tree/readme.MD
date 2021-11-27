<h2 align = "center"> Notes </h2>

---

<h3> Insertion </h3>

If push_blackness fails, consider all the possibilities

* First scenario - Node and its parent are both right children
  
        25 (black) --> Grandparent
         |
         -- 50 (red) --> Parent
            |
             -- 75 (red) --> Child

 Here, inserted node is right child, and it's parent is also right child.
 <b> rotate_left </b> is needed here - node with value 75 takes place of it's parent.

  <b> Pseudocode </b>

     Grandparent->right = Parent->left 
     Parent->left = Grandparent
     if(Grandparent->parent){
         Parent->parent = Grandparent->parent;
          Grandparent->parent->value > Grandparent->value
              ? Grandparent->left = Parent;
              : Grandparent->right = Parent;
     } else { 
        root = Parent
     }

     Grandparent->parent = Parent
     Parent->left ? Parent->left->parent == Grandparent

  <b> C++ </b>

```c++
    void rotate_left(Node *node) {
    auto parent = node->parent;

    parent->color = 'r';
    parent->right = node->left;
    node->left = parent;

    if (parent->parent) {
      node->parent = parent->parent;

      if (node->parent->value > parent->value)
        parent->parent->left = node;
      else
        parent->parent->right = node;

    } else {
      node->color = 'b';
      node->parent = nullptr;
      root = node;
    }

    parent->parent = node;
    if (node->left) node->left->parent = parent;
   }
```

#

<h3 align="center"> Visualization </h3>

#

![rotate left visualization](rotate_left.png)
