struct Node {
  string key;
  string value;
 
  struct Node* next;
  struct Node* prev;
 
  struct Node* nextinlist;
  struct Node* previnlist;
};
 
Node* curnode;
 
int calcHash(string& x) {
  int sum = 0;
  for (char c : x) {
    sum = (sum + (int)c) * 17 % ARR_SIZE;
  }
  return sum;
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
    Node* newnode = new Node;
 
    if (arr[hash] == nullptr) {
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
 
      newnode->next = nullptr;
      newnode->prev = node;
      newnode->key = x;
      newnode->value = y;
 
      node->next = newnode;
      newnode->prev = node;
    }
 
    if (curnode == nullptr) {
      newnode->nextinlist = nullptr;
      newnode->previnlist = nullptr;
    } else {
      curnode->nextinlist = newnode;
      newnode->previnlist = curnode;
      newnode->nextinlist = nullptr;
    }
 
    curnode = newnode;
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
    Node* node = arr[hash];
 
    if (node->next == nullptr) {
      if (arr[hash]->previnlist != nullptr && arr[hash]->nextinlist != nullptr) {
        arr[hash]->nextinlist->previnlist = arr[hash]->previnlist;
        arr[hash]->previnlist->nextinlist = arr[hash]->nextinlist;
      } else if (arr[hash]->previnlist == nullptr && arr[hash]->nextinlist != nullptr) {
        arr[hash]->nextinlist->previnlist = nullptr;
      } else if (arr[hash]->nextinlist == nullptr && arr[hash]->previnlist != nullptr) {
        arr[hash]->previnlist->nextinlist = nullptr;
      }
 
      if (arr[hash] == curnode) {
        curnode = curnode->previnlist;
      }
 
      arr[hash] = nullptr;
    } else {
      while (true) {
        if (node->key == x) {
 
          if (node->previnlist != nullptr && node->nextinlist != nullptr) {
            node->nextinlist->previnlist = node->previnlist;
            node->previnlist->nextinlist = node->nextinlist;
          } else if (node->previnlist == nullptr && node->nextinlist != nullptr) {
            node->nextinlist->previnlist = nullptr;
          } else if (node->nextinlist == nullptr && node->previnlist != nullptr) {
            node->previnlist->nextinlist = nullptr;
          }
 
          if (node == curnode) {
            curnode = curnode->prev;
          }
 
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
 
string prev(string& x, vector<Node*>& arr) {
  int hash = calcHash(x);
  if(exists(x, arr) != EMPTY_STR) {
    Node* node = arr[hash];
    while (true) {
      if (node->key == x) {
        if (node->previnlist == nullptr) {
          return EMPTY_STR;
        } else {
          return node->previnlist->value;
        }
      }
      if (node->next == nullptr) {
        return EMPTY_STR;
      } else {
        node = node->next;
      }
    }
  } else {
    return EMPTY_STR;
  }
}
 
string next(string& x, vector<Node*> arr) {
  int hash = calcHash(x);
  if(exists(x, arr) != EMPTY_STR) {
    Node* node = arr[hash];
    while (true) {
      if (node->key == x) {
        if (node->nextinlist == nullptr) {
          return EMPTY_STR;
        } else {
          return node->nextinlist->value;
        }
      }
      if (node->next == nullptr) {
        return EMPTY_STR;
      } else {
        node = node->next;
      }
    }
  } else {
    return EMPTY_STR;
  }
}
