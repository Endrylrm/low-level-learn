#pragma once
#include <stdio.h>

typedef struct Leaf {
  int value;
  struct Leaf *left;
  struct Leaf *right;
} Leaf_T;

typedef struct {
  size_t size;
  size_t height;
  Leaf_T *root;
} BinaryTree;

BinaryTree binarytree_init(void);
BinaryTree *binarytree_new(void);
void binarytree_insert(int value);