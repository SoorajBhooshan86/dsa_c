
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
  int value;
  struct Node *next;
} Node;

typedef struct List {
  Node *something;
  int len;
} List;

void init(List *l) {

  l->something = NULL;
  l->len = 0;
}

void push(List *l, int val) {

  Node *newNode = (Node *)malloc(sizeof(Node));
  Node *temp = (Node *)malloc(sizeof(Node));

  if (l->len == 0) {

    newNode->value = val;
    newNode->next = NULL;

    l->something = newNode;
  } else {

    temp = l->something;

    while (temp->next != NULL) {
      temp = temp->next;
    }

    newNode->value = val;
    newNode->next = NULL;
    temp->next = newNode;
  }

  l->len++;
}

void pustAt(List *l, int val, int index) {

  if (index > l->len || index < 0) {
    printf("Index out of bound \n");
    exit(0);
  }

  Node *newNode = (Node *)malloc(sizeof(Node));
  Node *temp = (Node *)malloc(sizeof(Node));
  temp = l->something;
  int count = 0;

  newNode->value = val;
  newNode->next = NULL;

  if (count == index) {

    l->something = newNode;
    l->something->next = temp;
    l->len++;
    return;
  }

  Node *tt = (Node *)malloc(sizeof(Node));

  while (temp->next != NULL) {
    count++;

    if (count == index) {

      tt = temp->next;
      temp->next = newNode;
      newNode->next = tt;
      l->len++;
      return;
    }

    temp = temp->next;
  }
}

void pop(List *l) {

  if (l->len == 0) {
    printf("\nList is empty\n");
    exit(0);
  }

  Node *t = (Node *)malloc(sizeof(Node));
  Node *tt = (Node *)malloc(sizeof(Node));

  t = l->something;

  while (t->next != NULL) {

    if (t->next != NULL) {
      tt = t;
    }
    t = t->next;
  }

  tt->next = NULL;
  l->len--;
}

void popAt(List *l, int index) {

  if (index > l->len || index < 0) {
    printf("Index out of bound \n");
    exit(0);
  }

  Node *t = (Node *)malloc(sizeof(Node));
  Node *tt = (Node *)malloc(sizeof(Node));
  int count = 0;

  t = l->something;

  if (count == index) {

    l->something = l->something->next;
    l->len--;
    return;
  }

  while (t->next != NULL) {

    if (count + 1 == index) {
      tt = t->next;
      t->next = tt->next;
      break;
    }
    count++;
    t = t->next;
  }

  l->len--;
}

void printList(List *l) {

  Node *temp = l->something;

  printf("\n---------------------------------\n");
  printf("\nLength of list : %d\n", l->len);
  printf("Values : ");

  while (temp != NULL) {
    printf("%d\t", temp->value);
    temp = temp->next;
  }
}

void replaceAt(List *l, int val, int index) {

  if (index > l->len || index < 0) {
    printf("Index out of bound \n");
    exit(0);
  }

  Node *temp = (Node *)malloc(sizeof(Node));
  temp = l->something;
  int count = 0;

  while (temp != NULL) {

    if (count == index) {
      temp->value = val;
      return;
    }

    count++;
    temp = temp->next;
  }
}

int main(int argc, char *argv[]) {

  List l;

  init(&l);
  push(&l, 10);
  push(&l, 20);
  push(&l, 30);
  push(&l, 40);
  push(&l, 50);
  printList(&l);

  pop(&l);
  pop(&l);
  pop(&l);
  printList(&l);

  pustAt(&l, 100, 0);
  pustAt(&l, 200, 1);
  pustAt(&l, 500, 1);
  printList(&l);

  popAt(&l, 0);
  printList(&l);

  popAt(&l, 2);
  printList(&l);

  replaceAt(&l, 1000, 0);
  replaceAt(&l, 2000, 1);
  replaceAt(&l, 3000, 2);
  printList(&l);

  pop(&l);
  pop(&l);
  pop(&l);
  pop(&l);
}
