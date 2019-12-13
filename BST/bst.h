#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

typedef struct Data{
    int value;
}Data;

typedef struct Node
{
    struct Data data;
    struct Node *left, * right, * parent;
    
}Node;

typedef struct Tree{
    struct Node *root;
    struct Data * (*insert)(struct Tree *bst,Data value);
    struct Data * (*search)(struct Tree *bst,Data value);
    void (*sort)(struct Tree *bst, Data *array);
    struct Tree * (*clone)(struct Tree*);
    int (*compare)(struct Tree*, struct Tree*);
    void (*removeData)(struct Tree *bst, Data value);
    void (*delete)(struct Tree * bst);
}Tree;

Tree * newTree();
Node * newNode(Data d,Node *parent);

Data * insertNode(Node *n,Data d);
Data * insert(struct Tree *bst,Data value);

void sort(struct Tree *bst, Data *test);


Data * search(struct Tree *bst,Data value);


Tree * clone(struct Tree *bst);


int compare(struct Tree*, struct Tree*);

void delete(struct Tree * tree);


Node * deleteNode(Node * node, Data data);

void tree(struct Tree * tree, Data data);
void removeLeaf(Node * node);
void shortCircuit(Node *node);
void promotion(Node * node);
Node * Leftmin(Node * node);
Node * Rightmin(Node * node);
void postorder(struct Tree * tree);
void Traversal(Node* node);

#endif // BST_H_INCLUDED
