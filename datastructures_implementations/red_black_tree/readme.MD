<h2 align = "center"> Notes </h2>

---

<h3> Insertion </h3>

If push_blackness fails, consider all the possibilities

* <b>First scenario </b> - Node and its parent are both right children
  
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

#

* <b>Second scenario</b> - Node and its parent are both left children
  
                75      (black) --> Grandparent
                |
           50 --         (red) --> Parent
           |
      25 --              (red) --> Child

Everything is pretty similar here, only the direction changes.

<b> Pseudocode </b>

     Grandparent->left = Parent->right
     Parent->right = Grandparent
     if(Grandparent->parent){
          Parent->parent = Grandparent->parent;
          Grandparent->parent->value > Grandparent->value
              ? Grandparent->left = Parent;
              : Grandparent->right = Parent;
     } else { 
        root = Parent
     }

     Grandparent->parent = Parent
     Parent->right ? Parent->right->parent == Grandparent

  <b> C++ </b>

```c++
    void rotate_right(Node *node) {
        auto parent = node->parent;

        parent->color = 'r';
        parent->left = node->right;
        node->right = parent;

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
        if (node->right) node->right->parent = parent;
    }
```

<h3> I believe visualization is not needed for this. </h3>
