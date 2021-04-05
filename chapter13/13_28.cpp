#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

class TreeNode
{
public:
    TreeNode()
        : value(std::string()), count(new int(1)), left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode &rhs)
        : value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right) { ++*count; }
    TreeNode &operator=(const TreeNode &rhs);
    ~TreeNode()
    {
        --*count;
        if (*count == 0)
        {
            delete count;
            delete left;
            delete right;
        }
    }

private:
    std::string value;
    int *count;
    TreeNode *left;
    TreeNode *right;
};

TreeNode &TreeNode::operator=(const TreeNode &rhs)
{
    ++*rhs.count;
    --*count;
    if (*count)
    {
        delete count;
        delete left;
        delete right;
    }
    count = rhs.count;
    left = rhs.left;
    right = rhs.right;
}

class BinStrTree
{
public:
    BinStrTree() : root(new TreeNode()) {}
    BinStrTree(const BinStrTree &bst) : root(new TreeNode(*bst.root)) {}
    BinStrTree &operator=(const BinStrTree &bst);
    ~BinStrTree() { delete root; }

private:
    TreeNode *root;
};

BinStrTree &BinStrTree::operator=(const BinStrTree &bst)
{
    TreeNode *new_root = new TreeNode(*bst.root);
    delete root;
    root = new_root;
    return *this;
}

int main()
{

    return 0;
}