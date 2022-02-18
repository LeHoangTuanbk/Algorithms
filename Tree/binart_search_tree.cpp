#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }    
};

Node* insert(Node *root, int value)
{
    if(!root)
    {
        return new Node(value);
    }
    if( value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else
    {
        root->left = insert(root->left, value);
    }
    return root;
}

bool search(Node *root, int value)
{
    if(root == nullptr) return false;
    if(root->data == value) return true;

    if(root->data > value)
    {
        return search(root->left, value);
    }
    else
    {
        return search(root->right,value);
    }
}


Node* min_value_node(Node* node)
{
    Node* current = node;
    while(current && current->left != nullptr)
    {
        current = current->left;
    }    

    return current;
}

Node* delete_node(Node* root, int value)
{
    if(root == nullptr) return root;

    if(value < root->data)
    {
        root->left = delete_node(root->left, value);
    }
    else if(value > root->data)
    {
        root->right = delete_node(root->right, value);
    }

    else 
    {
        if(root->left == nullptr && root->right == nullptr)
            return nullptr;
        
        else if(root->left == nullptr)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node *temp = min_value_node(root->right);
        root->data = temp->data;


        cout << temp->data << " test " << endl;
        root->right = delete_node(root->right, temp->data);
    }

    return root;
}


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


int main()
{
    Node *bst_root = new Node(1);

    bst_root = insert(bst_root, 3);

    bst_root = insert(bst_root,0);

    bst_root = insert(bst_root,2);

    bst_root = insert(bst_root,4);

    bst_root = insert(bst_root,5);

    preorder_traversal(bst_root);
    cout << endl;

    delete_node(bst_root, 3);

    preorder_traversal(bst_root);
    cout << endl;

    

    // cout << search(bst_root,-10);

    system("pause");
    return 0;
}