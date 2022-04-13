struct Node {
  int value;
  Node* next;
};

struct Queue {
  Node* head  = NULL;
  Node* tail = NULL;
  int size = 0;

  void push (int value) {
    Node* element = tail;

    tail = new Node;
    tail->value = value;
    tail->next = NULL;

    if (size == 0) {
      head = tail;
    } else {
      element->next = tail;
    }

    ++size;
  }

  int pop () {
    Node* element = head;
    int value = element->value;

    head = head->next;

    --size;
    return value;
  }
};
