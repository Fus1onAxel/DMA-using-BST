#ifndef TREENODE_H
#define TREENODE_H

#include "iphone.hpp"

struct TreeNode {
    Iphone data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(Iphone val) : data(val), left(nullptr), right(nullptr) {}
};

#endif // TREENODE_H
