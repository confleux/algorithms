struct Node {
  string key;
  string value;
  struct Node* next;
  struct Node* prev;
};
 
int calcHash(string& x) {
  int sum = 0;
  for (char c : x) {
    sum = (sum + (int)c) * 3 % ARR_SIZE;
  }
  return sum % ARR_SIZE;
}
 
string exists(string& x, vector<Node*>& arr) {
  int hash = calcHash(x);
 
  if (arr[hash] == nullptr) {
    return EMPTY_STR;
  } else {
    Node* node = arr[hash];
    while (true) {
      if (node->key == x) {
        return node->value;
      }
      if (node->next == nullptr) {
        return EMPTY_STR;
      } else {
        node = node->next;
      }
    }
  }
}
 
void put(string& x, string& y, vector<Node*>& arr) {
  int hash = calcHash(x);
  if (exists(x, arr) == EMPTY_STR) {
    if (arr[hash] == nullptr) {
      Node* newnode = new Node;
      newnode->next = nullptr;
      newnode->prev = nullptr;
      newnode->key = x;
      newnode->value = y;
 
      arr[hash] = newnode;
    } else {
      Node* node = arr[hash];
      while (node->next != nullptr) {
        node = node->next;
      }
      Node* newnode = new Node;
 
      newnode->next = nullptr;
      newnode->prev = node;
      newnode->key = x;
      newnode->value = y;
 
      node->next = newnode;
      newnode->prev = node;
    }
  } else {
    Node* node = arr[hash];
    while (true) {
      if (node->key == x) {
        node->value = y;
        break;
      }
      if (node->next == nullptr) {
        break;
      } else {
        node = node->next;
      }
    }
  }
}
 
void remove(string& x, vector<Node*>& arr) {
  if (exists(x, arr) != EMPTY_STR) {
    int hash = calcHash(x);
    if (arr[hash]->next == nullptr) {
      arr[hash] = nullptr;
      delete arr[hash];
    } else {
      Node* node = arr[hash];
      while (true) {
        if (node->key == x) {
          if (node->prev == nullptr) {
            node->next->prev = nullptr;
            arr[hash] = node->next;
            break;
          }
          if (node->next == nullptr) {
            node->prev->next = nullptr;
            break;
          }
          node->prev->next = node->next;
          node->next->prev = node->prev;
          break;
        } else {
          if (node->next != nullptr) {
            node = node->next;
          } else {
            break;
          }
        }
      }
    }
  }
}
