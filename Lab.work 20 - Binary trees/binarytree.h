#ifndef BINARYTREE_H
#define BINARYTREE_H

#pragma once

#include <QFile>
#include <QGraphicsScene>
#include "nodeshape.h"

struct Node
{
    double data;
    Node
        *left,
        *right;
};

class BinaryTree
{
private:
    Node* root;
    int depth_tree(Node* leaf);

    void get_subtrees_sizes(const int size, int& left_size, int& right_size);
    void create_balanced_binary_tree(Node*& leaf, int size);

    void print_tree(Node*& leaf, QGraphicsScene *scene);
    void delete_tree(Node* leaf);

public:
    NodeShape *nodeshape;
    int depth_tree();

    void create_balanced_binary_tree();
    void create_balanced_binary_tree(int size);
    void print_tree(QGraphicsScene *scene);
    void load_tree_file(QString filename);

    double min_value();
    double min_value(Node* node);

    BinaryTree();
    ~BinaryTree();
};

#endif // BINARYTREE_H
