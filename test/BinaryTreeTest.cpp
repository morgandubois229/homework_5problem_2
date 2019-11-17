#include "BinaryTree.h"
#include "gtest/gtest.h"
#include "vector"

TEST(tree, demo) {
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(5));

    BinaryTree<int> tree(root);

    ASSERT_EQ(tree.height(),3);
}

TEST(tree, inOrderTraversal) {
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(5));
    BinaryTree<int> tree(root);

    std::vector<int> returnedVector = tree.traverseInOrder();

    std::vector<int> key = {2, 1, 7, 3, 5, 5};

    ASSERT_TRUE(key==returnedVector);

}

TEST(tree, postOrderTraversal) {
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(5));
    BinaryTree<int> tree(root);

    std::vector<int> returnedVector = tree.traversePostOrder();

    std::vector<int> key = {2, 7, 1, 5, 5, 3};

    ASSERT_TRUE(key==returnedVector);

}

TEST(tree, lowestCommonAncestor) {
    TreeNode<int>* root = new TreeNode<int>(4);
    root->setLeft(new TreeNode<int>(8));
    root->setRight(new TreeNode<int>(6));

    root->getLeft()->setLeft(new TreeNode<int>(7));
    root->getLeft()->setRight(new TreeNode<int>(3));

    root->getRight()->setLeft(new TreeNode<int>(2));
    root->getRight()->setRight(new TreeNode<int>(9));

    BinaryTree<int> tree(root);

    ASSERT_EQ(tree.LCA(8, 6), 4);

}