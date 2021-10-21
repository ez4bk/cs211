#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct bstNode {
    int val;
    struct bstNode* l_child;
    struct bstNode* r_child;
}bstNode;

bstNode* insert (bstNode* root, int key);
void printTreeR (bstNode* root);

int main(int argc, char* argv[])
{
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }

    struct bstNode* root = NULL;

    char buff[256];
    while ( fscanf(fp, "%s", buff)!=EOF ) {
        root = insert(root, atoi(buff));
    }
    printTreeR(root);

    fclose(fp);
    return 0;
}

bstNode* insert (bstNode* root, int key){
    // If the BSTNode doesn't yet exist
    if (root==NULL) {
        root = malloc(sizeof(bstNode));
        root->l_child = NULL;
        root->r_child = NULL;
        root->val = key;
    }

    // If the BSTNode already exists, then insert key in correct subtree
    if (key<root->val){
        root->l_child = insert(root->l_child, key);
    }else if (key==root->val){
        //Nothing happened
    }else { // key>root->key
        root->r_child = insert(root->r_child, key);
    }
    return root;
}

void printTreeR (bstNode* root){
    if (root == NULL) return;
    printTreeR(root->r_child);
    printf("%d ", root->val);
    free(root);
    printTreeR(root->l_child);
    return;
}