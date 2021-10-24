struct Node {
    int value;
    struct Node *next;
};

struct Stack {
  Node *head= NULL;
  int size = 0;

  void push (int value) {
    Node* newHead = new Node;
    newHead->value = value;
    newHead->next = this->head;
    this->head = newHead;
    this->size = this->size + 1;
  }

  int pop () {
    if (this->head == NULL) {
      printf("Error: stack is empty\n");
      exit(1);
    }
    int value = this->head->value;
    this->head = this->head->next;
    this->size = this->size - 1;
    return value;
  }

  bool isEmpty () {
    if (this->size == 0) {
      return true;
    } else {
      return false;
    }
  }
};
