#include "binarytree.h"

static Leaf_T leaf_init(int value);
static Leaf_T *leaf_new(int value);
static Leaf_T leaf_copy(const Leaf_T* leaf);

static Leaf_T leaf_init(int value) {
    Leaf_T leaf;
    leaf.value = value;
    leaf.right = NULL;
    leaf.left = NULL;
    return leaf;
}

static Leaf_T *leaf_new(int value) {
    Leaf_T *leaf = (Leaf_T*) malloc(sizeof(Leaf_T));

    if (leaf == NULL)
        return NULL;

    leaf->value = value;
    leaf->right = NULL;
    leaf->left = NULL;
    return leaf;
}

static Leaf_T leaf_copy(const Leaf_T* leaf) {
    if (leaf == NULL) {
        log_error("trying to copy a null value.");

        // just return a "null leaf"
        Leaf_T invalid = {0};
        return invalid;
    }

    return *leaf;
}

BinaryTree binarytree_init(void) {
    BinaryTree btree = {
        .root = NULL,
        .height = 0,
        .size = 0,
    };
    return btree;
}

BinaryTree *binarytree_new(void) {
    BinaryTree *btree = (BinaryTree*) malloc(sizeof(BinaryTree));

    if (btree == NULL)
        return NULL;

    *btree = binarytree_init();
    return btree;
}

void binarytree_insert(int value) {}
