#ifndef BST_H
#define BST_H

#include "treeNode.hpp"
#include <iostream>
using namespace std;

class BST {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, Iphone iphone) {
        if (node == nullptr)
            return new TreeNode(iphone);

        if (iphone < node->data)
            node->left = insert(node->left, iphone);
        else if (iphone > node->data)
            node->right = insert(node->right, iphone);

        return node;
    }

    TreeNode* search(TreeNode* node, string serialNumber) {
        if (node == nullptr || node->data.serialNumber == serialNumber)
            return node;

        if (serialNumber < node->data.serialNumber)
            return search(node->left, serialNumber);

        return search(node->right, serialNumber);
    }

    TreeNode* remove(TreeNode* node, string serialNumber) {
        if (node == nullptr) return node;

        if (serialNumber < node->data.serialNumber)
            node->left = remove(node->left, serialNumber);
        else if (serialNumber > node->data.serialNumber)
            node->right = remove(node->right, serialNumber);
        else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data.serialNumber);
        }

        return node;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    void inorder(TreeNode* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->data.serialNumber << " - " << root->data.name << " - " << root->data.color << " - " << root->data.model << endl;
            inorder(root->right);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(Iphone iphone) {
        root = insert(root, iphone);
    }

    TreeNode* search(string serialNumber) {
        return search(root, serialNumber);
    }

    void remove(string serialNumber) {
        root = remove(root, serialNumber);
    }

    void printTree() {
        inorder(root);
    }
};

#endif // BST_H
