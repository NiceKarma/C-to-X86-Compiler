#include "compiler.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * TreeNode data type constructor
 * Parameters: none
 * Returns a pointer to the new node created
 */
TreeNode *createNode() {
        TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));

        // Initialize members
        new_node->value = 0;
        new_node->child = NULL;
        new_node->sibling = NULL;

        return new_node;
}

/*
 * Function to create the a child for a parent node
 * Description: If the parent->child pointer is NULL, then it fill in that
 * pointer as the first child. If the pointer is not null, then the it will
 * fill the first sibling pointer that is not NULL.
 * Parameters: parent - the parent node for the new child
 * Returns a pointer to the new child/sibling.
 */
TreeNode *addChild(TreeNode *parent) {
        TreeNode *child = createNode();

        if (parent->child == NULL) {
                parent->child = child;
                return child;
        }

        TreeNode *current_child = parent->child;
        while (current_child->sibling != NULL) {
                current_child = current_child->sibling;
        }
        current_child->sibling = child;
        return child;
}

/*
 * accessChild function to easily access children
 * Description: function to easily access children without having the do a
 * bunch of ->'s.
 * Parameters: parent - the parent node that you want to access the child of
 * child_num - which child you want to access. starts at 0.
 * Returns the child that you want to access. Returns NULL if parent is NULL or
 * there arent that many children.
 */
TreeNode *accessChild(TreeNode *parent, int child_num) {
        // Return NULL before it dereferences a NULL ptr
        if (parent == NULL) {
                printf("In accessChild, parent parameter is NULL!\n");
                return NULL;
        }

        // Just return the parent's child if referencing the first child
        if (child_num == 0) {
                return parent->child;
        }

        // Recursive loop to index to the correct sibling
        TreeNode *current_child = parent->child;
        for (int i = 1; i < child_num; i++) {
                // Return NULL before it dereferences a NULL ptr
                if (current_child == NULL) {
                        printf("In accessChild, not that many children!\n");
                        return NULL;
                }
                current_child = current_child->sibling;
        }
        return current_child->sibling;
}
