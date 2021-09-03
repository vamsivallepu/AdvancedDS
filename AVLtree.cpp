#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *left;
    Node *right;
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class AVL {
   public:
    Node *root;
    AVL() { root = NULL; }
    int height(Node *root) {
        if (root == NULL) {
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        return max(lh, rh) + 1;
    }
    Node *ll(Node *root) {
        Node *temp = root->left;
        root->left = NULL;
        if (temp->right == NULL)
            temp->right = root;
        else {
            root->left = temp->right;
            temp->right = root;
        }
        return temp;
    }
    Node *lr(Node *root) {
        root->left = rr(root->left);
        return ll(root);
    }
    Node *rr(Node *root) {
        Node *temp = root->right;
        root->right = NULL;
        if (temp->left == NULL)
            temp->left = root;
        else {
            root->right = temp->left;
            temp->left = root;
        }
        return temp;
    }
    Node *rl(Node *root) {
        root->right = ll(root->right);
        return rr(root);
    }
    Node *findmin(Node *root) {
        if (root == NULL) return NULL;
        if (root->left == NULL)
            return root;
        else
            return findmin(root->left);
    }
    Node *insert(Node *root, int e) {
        if (root == NULL) {
            root = new Node(e);
        } else if (root->data > e) {
            root->left = insert(root->left, e);
            if (height(root->left) - height(root->right) == 2 ||
                height(root->left) - height(root->right) == -2) {
                if (e < root->left->data)
                    root = ll(root);
                else
                    root = lr(root);
            }
        } else {
            root->right = insert(root->right, e);
            if (height(root->left) - height(root->right) == 2 ||
                height(root->left) - height(root->right) == -2) {
                if (e > root->right->data)
                    root = rr(root);
                else
                    root = rl(root);
            }
        }
        return root;
    }
    int search(Node *root, int ele) {
        if (root == NULL)
            return 0;
        else if (ele < root->data)
            return search(root->left, ele);
        else if (ele > root->data)
            return search(root->right, ele);
        else
            return 1;
    }

    Node *del(Node *root, int e) {
        Node *temp;
        if (root == NULL)
            return root;
        else if (e < root->data) {
            root->left = del(root->left, e);
            if (height(root->right) - height(root->left) == 2) {
                if (root->right->right)
                    root = rr(root);
                else
                    root = rl(root);
            }
        } else if (e > root->data) {
            root->right = del(root->right, e);
            if (height(root->left) - height(root->right) == 2) {
                if (root->left->left)
                    root = ll(root);
                else
                    root = lr(root);
            }
        } else {
            if (root->left == NULL && root->right == NULL) {
                free(root);
                return NULL;
            } else if (root->left != NULL && root->right != NULL) {
                temp = findmin(root->right);
                root->data = temp->data;
                root->right = del(root->right, temp->data);
            } else if (root->left == NULL) {
                root->data = root->right->data;
                free(root->right);
                root->right = NULL;
            } else {
                root->data = root->left->data;
                free(root->left);
                root->left = NULL;
            }
        }
        return root;
    }
    void printtree(Node *t, int level) {
        if (t) {
            printtree(t->right, level + 1);
            for (int i = 0; i < level; i++) cout << "\t";
            cout << t->data << endl;
            printtree(t->left, level + 1);
        }
    }
};

int main() {
    AVL at;
    at.root = at.insert(at.root, 9);
    at.root = at.insert(at.root, 7);
    at.root = at.insert(at.root, 3);
    at.root = at.insert(at.root, 4);
    at.root = at.insert(at.root, 5);
    at.root = at.insert(at.root, 6);
    at.printtree(at.root, 1);
    at.del(at.root, 3);
    cout << "\n";
    at.printtree(at.root, 1);
    return 0;
}