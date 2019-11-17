#pragma once

#include "Tree.h"
#include "TreeNode.h"
#include <vector>
#include "LinkedStack.h"
#include "iostream"

template<class T>
class BinaryTree : public Tree<T> {
private:
    TreeNode<T> *root;

    int height(TreeNode<T> *root) {
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

    BinaryTree(TreeNode<T> *root) : root(root) {
    }

    bool contains(T val) override {
        // not implemented yet
        return false;
    }

    std::vector<T> traverseInOrder() override {
        // homework, to be done iteratively

        std::vector<T> aVector;
        LinkedStack<TreeNode<T> *> theStack;
        TreeNode<T> *curr = root;

        while (curr != NULL || theStack.isEmpty() == false) {

            while (curr != NULL) {

                theStack.push(curr);
                curr = curr->left;
            }


            curr = theStack.peek();
            theStack.pop();
            T test = curr->val;
            aVector.push_back(curr->val);

            curr = curr->right;

        }


        return aVector;
    }

    std::vector<T> traversePreOrder() override {
        // don't bother
    }

    std::vector<T> traversePostOrder() override {
        // homework, to be done iteratively
        std::vector<T> aVector;

        LinkedStack<TreeNode<T> *> stack1, stack2;

        stack1.push(root);
        TreeNode<T>* node;


        while (!stack1.isEmpty()) {

            node = stack1.peek();
            stack1.pop();
            stack2.push(node);

            if (node->left)
                stack1.push(node->left);
            if (node->right)
                stack1.push(node->right);
        }


        while (!stack2.isEmpty()) {
            node = stack2.peek();
            stack2.pop();
            aVector.push_back(node->val);
        }
        return aVector;
    }

    virtual ~BinaryTree() {
        removeSubtree(root);
    }

    void removeSubtree(TreeNode<T> *aNode) {
        if (aNode->getLeft() == nullptr && aNode->getRight() == nullptr) {
            delete aNode;
            return;
        } else if (aNode->getRight() == nullptr) {
            removeSubtree(aNode->getLeft());
            delete aNode;
            return;
        } else if (aNode->getLeft() == nullptr) {
            removeSubtree(aNode->getRight());
            delete aNode;
            return;
        } else {
            removeSubtree(aNode->getLeft());
            removeSubtree(aNode->getRight());
            delete aNode;
            return;
        }
    }

    T LCA(T node1, T node2) {
        // homework
        if (node1 == node2) {
            return node1;
        }

        std::vector<T> path1;
        std::vector<T> path2;

        findPath(node1, root, path1);
        findPath(node2, root, path2);

        if (path1[0] == node1 && path2[0] == node2) {
            return node1;
        }

        int limiter;

        if (path1.size() > path2.size()) {
            limiter = path2.size();
        } else {
            limiter = path1.size();
        }

        for (int i = 1; i < limiter; i++) {

            if (path1[i] != path2[i]) {
                return path1[i - 1];

            }

        }
        if (path1[limiter - 1] == path2[limiter - 1]) {
            return path1[limiter-1];
        }
    }

    bool findPath(T value1, TreeNode<T>* current, std::vector<T>& path) {

        if (current == nullptr) {
            return false;
        }

        path.push_back(current->val);

        if (current->val == value1) {
            return true;
        }

        if (findPath(value1, current->getLeft(), path) || findPath(value1, current->getRight(), path)) {
            return true;
        }

        path.pop_back();
        return false;
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
