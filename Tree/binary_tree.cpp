#include <bits/stdc++.h>

using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

};

void preorder_traversal(Node *root) 
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " "; 
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal(Node *root)
{
    if(root == nullptr) return;
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}


void postorder_traversal(Node *root)
{
    if(root == nullptr) return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->data << " ";
}

void inorder_traversal_iterative(Node *root)
{
    stack<Node *> s;
    Node *cur = root;

    while( cur != nullptr || s.empty() == 0)
    {
        while( cur != nullptr)
        {
            s.push(cur);
            cur = cur->left;
        }

        cur = s.top();
        s.pop();

        cout << cur->data << " ";

        cur = cur->right;
    }
}

void post_traversal_iterative(Node *root)
{
    stack<Node*> s;
    Node *cur = root;

    while( cur != nullptr || s.empty() == 0)
    {
        while( cur != nullptr)
        {
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();

        cout << cur->data << " ";

        cur = cur->right;

    }
}

void BFS(Node *root)
{
    if(root == nullptr) return;

    queue<Node*> q;

    q.push(root);

    while( q.empty() == false)
    {
        Node *temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if(temp->left != nullptr) 
        {
            q.push(temp->left);
        }

        if(temp->right != nullptr)
        {
            q.push(temp->right);
        }
    }
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    /*
            1
           /  \
         2       3
        /  \  
       4    5
    */
    cout << "Preorder traversal of the tree: "; preorder_traversal(root); cout << endl;
    cout << "Inorder traversal of the tree: "; inorder_traversal(root); cout << endl;
    cout << "Postorder traversal of the tree: "; postorder_traversal(root); cout << endl;

    cout << "Inorder traversal of the tree iterative: "; inorder_traversal_iterative(root); cout << endl;

    cout << "BFS: "; BFS(root); cout << endl;
    system("pause");
    return 0;

}