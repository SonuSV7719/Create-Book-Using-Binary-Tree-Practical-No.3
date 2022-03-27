#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    string data;
    Node* left;
    Node* right;
    Node(string _data);
};

Node::Node(string _data)
{
    data = _data;
    left = NULL;
    right = NULL;
}

class BinaryTree
{
    public:
    Node* insert_value(Node* root, string data, string topic);
    void display(Node* root);
    
};

Node* BinaryTree::insert_value(Node *root, string data, string direction)
{
    if (root == NULL)
    {
        return new Node(data);
    }
    else if(direction.compare("Left-Chapter") == 0 || direction.compare("left-chapter")==0)
    {
        root->left = insert_value(root->left, data, direction);
    }
    else if(direction.compare("Right-Chapter") == 0 || direction.compare("right-chapter")==0)
    {
        root->right = insert_value(root->right, data, direction);
    }
    else if(direction.compare("right-section") == 0 || direction.compare("Right-section")==0)
    {
        root->right = insert_value(root->right, data, direction);
    }
    else if(direction.compare("Left-section") == 0 || direction.compare("left-section")==0)
    {
        root->left = insert_value(root->left, data, direction);
    }
    else if(direction.compare("right-sub-section") == 0 || direction.compare("Right-sub-section")==0)
    {
        root->right = insert_value(root->right, data, direction);
    }
    else if(direction.compare("Left-sub-section") == 0 || direction.compare("left-sub-section")==0)
    {
        root->left = insert_value(root->left, data, direction);
    }
    

    return root;
}

void BinaryTree::display(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<"-> ";
    display(root->left);
    display(root->right);
}

int main()
{
    Node* root = new Node("Operating System");
    BinaryTree tree;
    tree.insert_value(root, "Introduction to OS", "left-chapter");
    tree.insert_value(root, "What is OS", "left-section");
    tree.insert_value(root, "Input Devices", "Right-section");
    tree.insert_value(root, "Interface between hardware and software", "Left-sub-section");
    tree.insert_value(root, "Mouse, keyboard, etc.", "Right-sub-section");

    tree.insert_value(root, "Memory Management", "right-chapter");
    tree.insert_value(root, "Page replacement Algorithm", "left-section");
    tree.insert_value(root, "Deadlock", "Right-section");
    tree.insert_value(root, "FIFO, LRU, etc.", "Left-sub-section");
    tree.insert_value(root, "What is deadlock", "Right-sub-section");

    tree.display(root);
    cout<<endl<<endl<<endl;
    Node* root1 = new Node("Operating System");
    cout<<setw(59) <<root1->data<<setw(59)<<endl;
    Node* left_Topic = new Node("Introduction to OS");
    root1->left = left_Topic;
    cout<<setw(47)<<"/"<<setw(8)<<"\\"<<endl;
    cout<<setw(46)<<"/"<<setw(10)<<"\\"<<endl;
    cout<<setw(45)<<"/"<<setw(12)<<"\\"<<endl;
    Node* right_Topic = new Node("Memory Management");
    root1->right = right_Topic;
    cout<<setw(49)<<left_Topic->data;
    cout<<setw(23)<<right_Topic->data<<endl;

    cout<<setw(37)<<"/"<<setw(8)<<"\\"<<endl;
    cout<<setw(36)<<"/"<<setw(10)<<"\\"<<endl;
    cout<<setw(35)<<"/"<<setw(12)<<"\\"<<endl;
    Node* right_section = new Node("What is OS");
    left_Topic->right = right_section;
    Node* left_section = new Node("Input Devices");
    left_Topic->left = left_section;
    cout<<setw(36)<<left_section->data;
    cout<<setw(17)<<right_section->data<<endl;

    
    cout<<endl<<endl<<"Similarly for others";

    
    
    return 0;
}