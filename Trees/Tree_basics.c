#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct TreeNode
{
  int data;

  struct TreeNode *left;
  struct TreeNode *right;
}tree_node;

tree_node *create_node(int );
tree_node *insert_node(tree_node *, int);
bool search_data(tree_node *, int);

//======================> Main Function.
int main(void)
{
  tree_node *root = NULL;

  root = insert_node(root, 10);
  root = insert_node(root, 15);

  int test = 10;

  if(search_data(root, test))
    printf("\nFound %d\n", test);
  else
    printf("\n Not found %d\n", test);

  return 0;
}
// ======================> Declared Function.
bool malloc_handler(void *ptr)
{
  if(ptr == NULL)
  {
    printf("\n Error malloc. \n");
    return false;
  }

  else
    return true;
}

tree_node *create_node(int data)
{
  // Allocate new node.
  tree_node *new_node = (tree_node *) malloc(sizeof(tree_node));

  if(malloc_handler(new_node))
  {
    new_node->left  = NULL;
    new_node->right = NULL;
    new_node->data  = data;
  }

  return new_node;
}

tree_node *insert_node(tree_node *root, int data)
{
  // Check if the root isn't == NULL (tree is empty)
  if(!(root))
  {
    root = create_node(data);
  }
  //
  else if((root))
  {
    // If the new input data is smaller than the current node data.
    // Then it will be inserted in the left half of the tree.
    if(data <= root->data)
    {
      root->left = insert_node(root->left, data);
    }
    else
    {
      root->right = insert_node(root->right, data);
    }
  }

  else
    return NULL;

  return root;
}

bool search_data(tree_node *root, int data)
{
  if(!(root))
    return false;

  else if(root->data == data)
    return true;

  else if(data <= root->data)
  {
    return search_data(root->left, data);
  }

  else if(data >= root->data)
  {
    return search_data(root->right, data);
  }

  else
    return false;
}
