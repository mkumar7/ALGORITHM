#include "bst.h"
#include <stdio.h>
#include <stdlib.h>
#define SET 1
#define RESET 0
int index;

Tree *newTree()
{
    Tree * t = malloc(sizeof(Tree));
    t->root=NULL;
    t->insert = insert;
    t->sort = sort;
    t->search = search;
    t->clone = clone;
    t->compare = compare;
    t->removeData = tree;
    t->delete = delete;
    return t;
}
Node *newNode(Data d,Node *parent)
{
    Node * n = malloc(sizeof(Node));
    n->data = d;
    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;
    return n;
}
Data * insert(struct Tree *bst,Data temp)
{
    while(bst->root == NULL)
    {
        bst->root = malloc(sizeof(Node));
       
        bst->root->data = temp;
        bst->root->parent = bst->root;
        bst->root->left = NULL;
        bst->root->right = NULL;
        return &(bst->root->data);
    }
     Data * store = insertNode(bst->root,temp);
        return store;
    
}
Data * insertNode(Node *n, Data d)
{
    while(n->data.value == d.value)
    {
        return NULL;
    }
    if(n->data.value > d.value)
	{
		if(n->left == NULL)
		{
			n->left = malloc(sizeof(Node));
	
			n->left->parent = n;
			n->left->left = NULL;
			n->left->right = NULL;
			n->left->data = d;
			return &n->left->data;
		}
		
		else insertNode(n->left,d);
    }

     else if(n->data.value < d.value)
      {
		if (n->right == NULL)
		{
			n->right = malloc(sizeof(Node));
			n->right-> parent = n, 
			n->right->data = d;
		
			n->right->left = NULL;
			n->right->right = NULL;
	
			return &(n->right->data);
		}
		else insertNode(n->right,d);

	}
	

}


int sortNode(Node *n,Data *d,int temp)
{
  while(n == NULL)
  {
    return temp;
  }
  
    temp = sortNode(n->left,d,temp);
    d[temp] = n->data;
    temp++;
    temp = sortNode(n->right,d,temp);
    return temp;
}
void sort(struct Tree *bst, Data * array)
{
     if(bst->root != NULL)
     sortNode(bst->root,array,0);
    
}

Node *searchNode(Node * node, Data data)
{
    while(node == NULL)
    {
        return NULL;
    }
        if(node->data.value == data.value)
        {
            return &node->data;
        }
        if(node->data.value < data.value)
        {
            searchNode(node->right,data);
        }
        else if(node->data.value > data.value)
        {
            searchNode(node->left,data);
        }
        
        
}
Data * search(struct Tree *bst,Data data)
{
    while(bst->root == NULL)
    {
        return NULL;
    }
     
     return searchNode(bst->root,data);
  
}
Tree *OrderTree(Node *node,Tree * d)
{
    while(node==NULL)
    {
    	return;
    }

        insert(d, node->data);
        OrderTree(node->left, d);
        OrderTree(node->right, d);
 }
Tree * clone(Tree *bst)
{
    while(bst->root == NULL)
    {
    	return NULL;
    }
        Tree * d = newTree();
        OrderTree(bst->root, d);
        return d;
    
}



int Ordercompare(Node * d1,Node * d2)
{
    while(d1==NULL && d2==NULL)
    {
        return 1;
    }
    if(d1!=NULL && d2!=NULL)
    {
        return(
               (d1->data.value == d2->data.value) &&
               (Ordercompare(d1->left,d2->left)) &&
                (Ordercompare(d1->right,d2->right))
        );
    }
    return 0;
}
int compare(Tree* temp1, Tree* temp2)
{
    while(temp1 == NULL || temp2 == NULL)

    {
        return 0;
    }
     if(temp2 == NULL && temp2 == NULL)
    {
        return 1;
    }
     Ordercompare(temp1->root,temp2->root);
   }

void delete(Tree * d)
{
	if(d->root!=NULL) 
	{
		deleteTree(d->root);
	}
	free(d);
}
void deleteTree(Node * n)
{
	if(n!=NULL){
		deleteTree(n->left);
		deleteTree(n->right);
		removeLeaf(n);
	}
}

Node * delSearch(Tree * tree, Data data)
{
	while(tree->root==NULL) 
	{
		return NULL;
	} 
	
		return deleteNode(tree->root,data);
	
}
Node * deleteNode(Node * node, Data data)
{
	while(node==NULL) 
	{
		return NULL;
	}
	  

		if(node->data.value == data.value) 
		{
			return node;
		}
		if(node->data.value < data.value) 
		{
			deleteNode(node->right,data);
		}
		else if(node->data.value > data.value) 
		{
			deleteNode(node->left,data);
		}
		
}

void tree(Tree * bst, Data value)
{
	Node * delete = delSearch(bst, value);
	if(delete!=NULL)
	{
		if(delete->left==NULL && delete->right==NULL)
		{
			if(delete==bst->root) 
			{
				free(bst->root);
				bst->root=NULL;
			} 
			else 
			{
				removeLeaf(delete);
			}
		}
		else if(delete->left==NULL || delete->right==NULL) 
		{
			if(delete==bst->root) 
			{
				if(delete->left==NULL)
				{
					bst->root=delete->right;
					delete->right=NULL;
				}
				
				free(delete);
				delete=NULL;
			} 
			else 
			{
				shortCircuit(delete);
			}
		}
		else 
		{
			promotion(delete);
		}
	}
}
void removeLeaf(Node * n)
{
	while(n->parent==NULL)
	{
		free(n);
	
	} 
	 if(n == n->parent->left)
		{
			n->parent->left=NULL;
			n->parent = NULL;
		}
		else
		 {
			n->parent->right=NULL;
			n->parent = NULL;
		}
		free(n);
		
	
}
void shortCircuit(Node *n)
{

	while(n->parent==NULL) 
	{
		if(n->left != NULL)
		{
			n->right=NULL;
		}
		else
		{
			(n->right==NULL);
		
			n->left=NULL;
		}
		free(n);
		
	}
	
	    if(n == n->parent->left)
		{
			if(n->left != NULL) 
			{
				n->parent->left = n->left;
				n->left->parent = n->parent;
			}
			else{
				(n->left == NULL);
			
				n->parent->left = n->right;
				n->right->parent = n->parent;
			}
		}
		else 
		 {
			if(n->left != NULL) 
			{
				n->parent->right = n->left;
				n->left->parent = n->parent;
			}
			else 
			{
				n->parent->right = n->right;
				n->right->parent = n->parent;
			}
		}
		free(n);
	
	
}
void promotion(Node * n)
{
	Node *rightMin  = Rightmin(n);
	n->data.value =rightMin->data.value;

	if(rightMin->right==NULL && rightMin->left == NULL)
	 {
		removeLeaf(rightMin);
	}
	else 
	{
		shortCircuit(rightMin);
	}
}
Node * Leftmin(Node * n)
{
	n = n->left;
	while(n->right !=NULL)
	{
       n = n->left;
	}
	return n;
}
Node * Rightmin(Node * n)
{
	n = n->right;
	while(n->left !=NULL)
	{
		n = n->left;
	}
	return n;
}

void postorder(Tree * d)
{
	if(d->root!=NULL)
		Traversal(d->root);
}
void Traversal(Node* n)
{
	if(n != NULL) 
	{
		Traversal(n->left);
		Traversal(n->right);
	}
}
