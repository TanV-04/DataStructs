#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

struct node
{
  int data;
  node *left, *right;

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
  else
  {
    if (val < root->data)
    {
      root->left = insert(root->left, val);
    }
    else
    {
      root->right = insert(root->right, val);
    }
  }
  return root;
}

void max_stack(node *root)
{
  if (root == NULL)
  {
    return;
  }
  else
  {
    queue<node *> store;
    store.push(root);
    store.push(NULL);

    while (!store.empty())
    {
      // Initialize max_el for each level
      int max_el = INT32_MIN;

      // Get the number of nodes at the current level
      int level = store.size();

      // Iterate through nodes at the current level
      for (int i = 0; i < level; i++)
      {
        node *temp = store.front();
        store.pop();

        if (temp != NULL)
        {
          max_el = max(max_el, temp->data);

          if (temp->left)
          {
            store.push(temp->left);
          }
          if (temp->right)
          {
            store.push(temp->right);
          }
        }
      }

      cout << " " << max_el;
    }
  }
}


int main()
{
  struct node *root = NULL;
  int x;
  do
  {
    cout << "enter elements (0 to exit): ";
    cin >> x;
    if (x != 0)
    {
      root = insert(root, x);
    }
  } while (x != 0);

  max_stack(root);
  cout << endl;
}