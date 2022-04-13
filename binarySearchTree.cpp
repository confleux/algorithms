typedef struct Node {
  int key;
  struct Node* left;
  struct Node* right;
 
  Node() {
    left = nullptr;
    right = nullptr;
  }
};
 
Node* insert(Node* x, int y) {
  if (x == nullptr) {
    Node* returnValue = new Node;
    returnValue->key = y;
    return returnValue;
  } else if (x->key > y) {
    x->left = insert(x->left, y);
  } else if (x->key < y) {
    x->right = insert(x->right, y);
  }
 
  return x;
}
 
Node* minimum(Node* x) {
  if (x->left == nullptr) {
    return x;
  }
  return minimum(x->left);
}
 
Node* maximum(Node* x) {
  if (x->right == nullptr) {
    return x;
  }
  return maximum(x->right);
}
 
Node* search(Node* x, int y) {
  if (x == nullptr || y == x->key) {
    return x;
  }
  if (y < x->key) {
    return search(x->left, y);
  } else {
    return search(x->right, y);
  }
}
 
Node* next(Node* root, int x) {
  Node* current = root;
  Node* successor = nullptr;
  while (current != nullptr) {
    if (current->key > x) {
      successor = current;
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return successor;
}
 
Node* prev(Node* root, int x) {
  Node* current = root;
  Node* successor = nullptr;
  while (current != nullptr) {
    if (current->key < x) {
      successor = current;
      current = current->right;
    } else {
      current = current->left;
    }
  }
  return successor;
}
 
Node* remove(Node* root, int x) {
  if (root == nullptr) {
    return root;
  }
 
  if (root->key > x) {
    root->left = remove(root->left, x);
  } else if (root->key < x) {
    root->right = remove(root->right, x);
  } else {
    if (root->left == nullptr && root->right == nullptr) {
      return nullptr;
    } else if (root->left == NULL) {
      Node* returnValue = root->right;
      delete root;
      return returnValue;
    } else if (root->right == nullptr) {
      Node* returnValue = root->left;
      delete root;
      return returnValue;
    }
 
    Node* tmp = minimum(root->right);
    root->key = tmp->key;
    root->right = remove(root->right, tmp->key);
  }
 
  return root;
}
