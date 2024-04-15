#ifndef GRAPHVIZ_H
#define GRAPHVIZ_H
#include <stdio.h>
#include "../TREE_EXP/Tree1/header/tree.h"
void Graphviz (Node* pNode, char* file);
void CreateGraph(Node* pNode, FILE* outfile);
#endif
