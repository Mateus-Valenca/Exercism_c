#include "binary_search_tree.h"

node_t *create_node(int value)
{
    node_t *n = malloc(sizeof(node_t));
    if (!n) return NULL;

    n->data = value;
    n->left = NULL;
    n->right = NULL;

    return n;
}
node_t *insert(node_t *root, int value)
{
    if (root == NULL)
        return create_node(value);

    if (value <= root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}
int count_nodes(node_t *root)
{
    if (!root) return 0;
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}
node_t *build_tree(int *tree_data, size_t tree_data_len)
{
    node_t *root = NULL;
    for (size_t i = 0; i < tree_data_len; i++) {
        root = insert(root, tree_data[i]);
    }

    return root;
}
void free_tree(node_t *tree)
{
    if (!tree) return;

    free_tree(tree->left);
    free_tree(tree->right);

    free(tree);
}
void inorder(node_t *root, int *arr, int *index)
{
    if(!root) return;
    inorder(root->left,arr,index);//Go find the leaf on the left side
    arr[*index] = root->data;
    (*index)++;

    inorder(root->right,arr,index);//Go find the leaf on the right side
    
}

int *sorted_data(node_t *tree)
{
    int size = count_nodes(tree);

    int *arr = malloc(size * sizeof(int));
    if (!arr) return NULL;

    int index = 0;
    inorder(tree, arr, &index);

    return arr;
}
