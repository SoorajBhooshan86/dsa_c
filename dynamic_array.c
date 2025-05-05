
// DSA Dynamic Array

#include <stdio.h>
#include <stdlib.h>
struct Darray {

  int *arr;
  int len;
  int size;
};

void init(struct Darray *array, int size) {
  array->len = 0;
  array->size = 0;
  array->arr = (int *)malloc(size * sizeof(int));
}

void append(struct Darray *array, int value) {

  if (array->arr == NULL) {
    printf("Array initilization failed or not done\n");
    exit(1);
  }

  if (array->len == array->size) {

    array->size += 2;

    int *newarr = (int *)malloc(array->len * sizeof(int));

    if (newarr == NULL) {
      printf("Memmory allocation failed for copy array");
      exit(1);
    }

    for (int i = 0; i < array->len; i++) {
      newarr[i] = array->arr[i];
    }

    array->arr = (int *)malloc(array->size * sizeof(int));

    for (int i = 0; i < array->len; i++) {
      array->arr[i] = newarr[i];
    }

    free(newarr);
  }
  array->arr[array->len] = value;
  array->len++;
}

void pop(struct Darray *array) {

  if (array->arr == NULL) {
    printf("Array initilization failed or not done\n");
    exit(1);
  }

  if (array->len < 0)
    return;

  array->len--;
}

void print(struct Darray *array) {

  if (array->arr == NULL) {
    printf("Array initilization failed or not done\n");
    exit(1);
  }

  for (int i = 0; i < array->len; i++) {
    printf("%d\t", array->arr[i]);
  }
  printf("\n");
}

void removeAt(struct Darray *array, int index) {

  if (array->arr == NULL) {
    printf("Array initilization failed or not done\n");
    exit(1);
  }

  if (index < 0 || index > array->len) {
    printf("Invalid Index");
    exit(1);
  }

  for (int i = 0; i < array->len; i++) {

    if (i >= index) {

      array->arr[i] = array->arr[i + 1];
    }
  }
  array->len--;
}

void swapAt(struct Darray *array, int index, int value) {

  if (array->arr == NULL) {
    printf("Array initilization failed or not done\n");
    exit(1);
  }

  if (index < 0 || index > array->len) {
    printf("Invalid Index");
    exit(1);
  }

  array->arr[index] = value;
}

int at(struct Darray *array, int index) {

  if (array->arr == NULL) {
    printf("Array initilization failed or not done\n");
    exit(1);
  }

  if (index < 0 || index > array->len) {
    printf("Invalid Index");
    exit(1);
  }

  return array->arr[index];
}

int main(int argc, char *argv[]) {

  struct Darray array;

  init(&array, 4);

  append(&array, 10);
  append(&array, 20);
  append(&array, 30);
  append(&array, 40);
  append(&array, 50);

  print(&array);

  printf("\nElement at 2 is %d \n", at(&array, 2));

  printf("Swaping element %d with -1 \n\n", at(&array, 2));

  swapAt(&array, 2, -1);

  print(&array);
  printf("\nPoping element \n");
  pop(&array);
  print(&array);
  printf("\nRemoving element at 2\n");
  removeAt(&array, 2);
  print(&array);

  return 0;
}
