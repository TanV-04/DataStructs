#include <iostream>
using namespace std;

struct node
{
  int data;
  node *left, *right;

  // constructor
  node(int val)
  {
    data = val;
    left = NULL;
    right = NULL;
  }
};

node *insert(node *root, int val)
{
  if (root == NULL)
  {
    return new node(val);
  }
  else if (val > root->data)
  {
    root->right = insert(root->right, val);
  }
  else
  {
    root->left = insert(root->left, val);
  }
  return root;
}

void inorder(node *root)
{
  if (root == NULL)
  {
    return;
  }
  inorder(root->left);
  cout << " " << root->data;
  inorder(root->right);
}

void preorder(node *root)
{
  if (root == NULL)
  {
    return;
  }
  cout << " " << root->data;
  preorder(root->left);
  preorder(root->right);
}

void postorder(node *root)
{
  if (root == NULL)
  {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout << " " << root->data;
}

node *search(node *root, int data1)
{
  if (root == NULL)
  {
    return NULL;
  }
  if (root->data == data1)
  {
    return root;
  }
  else if (data1 > root->data)
  {
    return search(root->right, data1);
  }
  else
  {
    return search(root->left, data1);
  }
}

node *inorderSuccessor(node *root, int data1)
{
  node *curr = root;
  while (curr && curr->left != NULL)
  {
    curr = curr->left;
  }
  return curr;
}

node *deleteNode(node *root, int data1)
{
  if (data1 > root->data)
  {
    root->right = deleteNode(root, data1);
  }
  else if (data1 < root->data)
  {
    root->left = deleteNode(root, data1);
  }
  else
  {
    if (root->left == NULL)
    {
      node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      node *temp = root->left;
      free(root);
      return temp;
    }
    else
    {
      node *temp = inorderSuccessor(root->right, data1);
      root->data = temp->data;                           // swap
      root->right = deleteNode(root->right, temp->data); // call the delete function
    }
    return root;
  }
}

int main()
{
  struct node *root = NULL;
  int key, x;

  // default input

  // root = insert(root, 5);
  // root = insert(root, 1);
  // root = insert(root, 10);
  // root = insert(root, 2);
  // root = insert(root, 4);

  // user input
  do
  {
    cout << "enter a value: ";
    cin >> x;
    if (x != 0)
    {
      root = insert(root, x);
    }
  } while (x != 0);

  cout << "inorder traversal: " << endl;
  inorder(root);

  cout << endl;

  cout << "preorder traversal: " << endl;
  preorder(root);

  cout << endl;

  cout << "postorder traversal: " << endl;
  postorder(root);

  cout << endl;

  cout << "enter number to search: ";
  cin >> key;
  if (search(root, key) == NULL)
  {
    cout << "not found" << endl;
  }
  else
  {
    cout << "found!" << endl;
  }

  // delete a node

  // inorder(root);
  // int data_del;
  // cout<<endl;
  // cout << "enter data to delete: ";
  // cin >> data_del;
  // root = deleteNode(root, data_del);
  // cout << "the updated list: " << endl;
  // inorder(root);

  return 0;
  cout << endl;
  cout << "tree is created\n";
}