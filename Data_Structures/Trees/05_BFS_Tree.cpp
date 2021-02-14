// Breadth First Search or Level Order Traversal

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void BFS(Node* root) {
    // Algorithm: The Level Order Traversal can be implemented efficiently using a Queue.
    // 1) Create an empty queue q.
    // 2) Push the root node of tree to q. That is, q.push(root).
    // 3) Loop while the queue is not empty:
    //     a) Pop the top node from queue and print the node.
    //     b) Enqueue node's children (first left then right children) to q
    //     c) Repeat the process until queue is not empty.

    if (root == NULL) 
        return;

    queue<Node *> q;
    q.push(root);
    Node* curr;

    while (!q.empty()) {
        curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left) {
            q.push(curr->left);
        }
        if (curr->right) {
            q.push(curr->right);
        }
    }
}

int main() {
    // Create the following Binary Tree
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5
    
    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5);

    BFS(root);

    return 0;
}