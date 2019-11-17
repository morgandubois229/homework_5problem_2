#pragma once

#include "Tree.h"
#include "TreeNode.h"
#include <vector>
#include "LinkedStack.h"

template<class T>
class BinaryTree :  public Tree<T> {
private:
    TreeNode<T>* root;

    int height(TreeNode<T>* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + std::max(height(root->left), height(root->right));
    }

public:
    BinaryTree() : root(nullptr) {};

    BinaryTree(std::vector<T> &array) {
        // not implemented yet
    }

    BinaryTree(TreeNode<T>* root) : root(root) {
    }

    bool contains(T val) override {
        // not implemented yet
        return false;
    }

    std::vector<T> traverseInOrder() override {
        // homework, to be done iteratively
    }

    std::vector<T> traversePreOrder() override {
        // don't bother
    }

    std::vector<T> traversePostOrder() override {
        // homework, to be done iteratively
    }

    virtual ~BinaryTree() {
        removeSubtree(root);
    }

    void removeSubtree(TreeNode<T>* aNode) {
        if (aNode->getLeft() == nullptr && aNode->getRight() == nullptr) {
            delete aNode;
            return;
        }
        else if (aNode->getRight() == nullptr) {
            removeSubtree(aNode->getLeft());
            delete aNode;
            return;
        }
        else if (aNode->getLeft() == nullptr) {
            removeSubtree(aNode->getRight());
            delete aNode;
            return;
        }
        else {
            removeSubtree(aNode->getLeft());
            removeSubtree(aNode->getRight());
            delete aNode;
            return;
        }
    }

    T LCA(T node1, T node2) {
        // homework
    }

    bool add(const T &) override {
        // not implemented yet
    }

    bool remove(const T &) override {
        // not implemented yet
    }

    int height() override {
        return height(root);
    }

};
