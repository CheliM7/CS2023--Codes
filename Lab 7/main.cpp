#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Defining inorder traversal
void traverseInOrder(struct node *root) {
    if (root){
        traverseInOrder(root->left);
        cout<< (root->key) << " ";
        traverseInOrder(root->right);
    }
}


//creating a node
node* createNode(int key){
    node * newNode = new node();
    newNode->key=key;
    newNode->left= nullptr;
    newNode->right=nullptr;
    return newNode;
}


// Inserting a node
struct node *insertNode(struct node *node, int key) {
  //Case 1: Empty Tree- create a new node
  if (node == NULL){
    return createNode(key);
  }

  //Case 2: Non-empty tree- Traverse the tree
  //two cases of value comparison
  if (key < node->key) {
    node->left = insertNode(node->left, key);
  }

  else if (key > node->key) {
    node->right = insertNode(node->right, key);
  }

  return node;
}


// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  //Case 1: Empty Tree
  if (root == NULL) {
    return root;
  }

  //Case 2: Non-Empty Tree- Traverse the tree
  if (key < root->key) {
    root->left = deleteNode(root->left, key);
  }

  else if (key > root->key) {
    root->right = deleteNode(root->right, key);
  }

  //Case 3: When it is the ROOT that is being deleted
  else
    {// Sub-Case 1: Node has no children
    if (root->left == NULL && root->right == NULL) {
      delete root;
      root = NULL;
    }

    // Sub-Case 2: Node has one child
    else if (root->left == NULL) {
      struct node *temp = root;
      root = root->right;
      delete temp;

    } else if (root->right == NULL) {
      struct node *temp = root;
      root = root->left;
      delete temp;
    }
    // Sub-Case 3: Node has two children
    else {
      struct node *temp = root->right;
      while (temp->left != NULL) {
        temp = temp->left;
      }
      root->key = temp->key;
      //following Inorder
      root->right = deleteNode(root->right, temp->key);
    }
    }
    return root;
}


// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }

  traverseInOrder(root);
}
