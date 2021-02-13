#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    // para constructor
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder_recursive(Node* root) {
    if (root == NULL) {
        return;
    }

    // inorder traversal -- left_child -> parent_node -> right_child
    inorder_recursive(root->left);
    cout << root->data << " ";
    inorder_recursive(root->right);
}

void preorder_recursive(Node* root) {
    if (root == NULL) {
        return;
    }

    // preorder traversal -- parent_node -> left_child -> right_child
    cout << root->data << " ";
    preorder_recursive(root->left);
    preorder_recursive(root->right);
}

void postorder_recursive(Node* root) {
    if (root == NULL) {
        return;
    }

    // postorder traversal -- left_child -> right_child -> parent_node
    postorder_recursive(root->left);
    postorder_recursive(root->right);
    cout << root->data << " ";
}

// next 3 functions represent samething
// but coding it without recursion

void inorder_iterative(Node* root) {
    // for better understanding, watch the below video
    // https://www.youtube.com/watch?v=5y_j0OqD7v8

    // Algorithm:
    // 1) Create an empty stack
    // 2) Initialize current node to root
    // 3) Push current node to stack & set (curr = curr->left) until curr is NULL
    // 4) If curr is NULL & stack is not empty :-
    //         a) pop top of stack & print it
    //         b) set curr = popped_node->right
    //         c) goto step - 3
    // 5) If (curr == NULL && stack is empty) then we are done

    stack<Node *> stk;
    Node* curr = root;

    while (curr != NULL || !stk.empty()) {
        while (curr != NULL) {
            stk.push(curr);
            curr = curr->left;
        }
        curr = stk.top();
        stk.pop();
        cout << curr->data << " ";

        curr = curr->right;
    }
}

void preorder_iterative(Node* root) {
    // for better understanding, watch the below video
    // https://www.youtube.com/watch?v=K2ybI-GEHSY


    // to solve iteratively, stack is required !!
    stack<Node *> stk;

    // Algorithm :
    // push the root in stack
    // while (stack not empty)
    //      1) pop & store top node from stack
    //      2) print it
    //      3) push right (check if it exists or not)
    //      4) push left (check if it exists or not)
    
    stk.push(root);
    Node* curr = NULL;
    while (!stk.empty()) {
        curr = stk.top();
        cout << curr->data << " ";
        stk.pop();
        if (curr->right != NULL)
            stk.push(curr->right);
        if (curr->left != NULL)
            stk.push(curr->left);
    }

}

void postorder_iterative(Node* root) {
    // 1. Push root to first stack.
    // 2. Loop while first stack is not empty
    //      1. Pop a node from first stack and push it to second stack
    //      2. Push left and right children of the popped node to first stack
    // 3. Print contents of second stack

    stack<Node *> s1;
    stack<Node *> s2;
    Node* curr;

    s1.push(root);
    while (!s1.empty()) {
        curr = s1.top();
        s2.push(curr);
        s1.pop();
        if (curr->left)
            s1.push(curr->left);
        if (curr->right)
            s1.push(curr->right);
    }
    while (!s2.empty()) {
        curr = s2.top();
        cout << curr->data << " ";
        s2.pop();
    }
}

int main() {
    // Construct the Tree
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

    cout << endl << "Inorder traversal recursively : ";
    inorder_recursive(root);
    cout << endl << "Inorder traversal iteratively : ";
    inorder_iterative(root);

    cout << endl << "\nPreorder traversal recursively : ";
    preorder_recursive(root);
    cout << endl << "Preorder traversal iteratively : ";
    preorder_iterative(root);

    cout << endl << "\nPostorder traversal recursively : ";
    postorder_recursive(root);
    cout << endl << "Postorder traversal iteratively : ";
    postorder_iterative(root);

    return 0;

}