#include "bst.h"


STACK * stackPush(STACK * st, BST * root)
{
	if (st->top == NULL)
	{
		st -> top = (stackNODE*)malloc(sizeof(stackNODE));
		st -> top -> root = root;
		st -> top -> next = NULL;
		st -> count = 1;
		return st;
	}
	else
	{
		stackNODE * temp = (stackNODE *) malloc(sizeof(stackNODE));
		temp -> next = st -> top;
		temp -> root = root;
		st -> top = temp;
		st -> count ++;
		return st;
	}
}

BST * stackGetTop(STACK * st)
{
	return st->top->root;
}

STACK * stackPop(STACK * st)
{
	if(st->top!=NULL)
	{
		stackNODE * tempSt = st -> top;
		st -> top = st -> top -> next;
		free(tempSt);
		st->count--;
		return st;	
	}
	else
	{
		st->count=0; // safety check
		return NULL;
	}
}

int isEmpty(STACK * st)
{
	return !(st->count); // BRANCH PREDICTION FAIL SAFE
}

STACK * printStack(STACK * st)
{
	if(st->top!=NULL)
	{
		stackNODE * mov = st->top;
		printf("- STACK -");
		while(mov != NULL)
		{
			printf("%d ", mov->root->val);
			mov = mov->next;
		}
	}

	printf("\n\n");

	return st;
}

int * readData(int * array, int N)
{
	int stemp;
	array = (int*) malloc(sizeof(int) * N);
	int i=0;
	for(i=0; i<N; i++)
	{
		stemp = scanf("%d", &array[i]);
	}
	return array;
}

BST * add(BST * root, int val)
{
	// iterative implementation
	BST * temp = (BST*)malloc(sizeof(BST));
	temp->val = val;
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = NULL;

	if(root==NULL)
	{
		root = temp;
		return root;
	}
	else
	{
		BST * current = root;

		while(1)
		{
			printf("WHILERUNNING");
			if(val <= current->val)
			{
				if(current->left==NULL)
				{
					current->left = temp;
					temp->parent = current;
					return root;
				}
				else
				{
					current = current->left;
					continue;
				}
			}
			else
			{
				if(current->right==NULL)
				{
					current->right = temp;
					temp->parent = current;
					return root;
				}
				else
				{
					current = current->right;
					continue;
				}
			}
		}
	}

	/*
	// recursive implementation

	if(root == NULL)
	{
		BST * temp = (BST*)malloc(sizeof(BST));
		temp->val = val;
		temp->left = NULL;
		temp->right = NULL;
		temp->parent = NULL;

		root = temp;
		return root;
	}
	else
	{
		if(val <= root->val)
		{
			if(root->left == NULL)
			{
				root->left = add(root->left, val);
				root->left->parent = root;
				return root;
			}
			else if(val > root->left->val)
			{
				
				root -> left -> right = add(root -> left -> right, val);
				root -> left -> right -> parent = root -> left;
				return root;
			}
			else
			{
				root->left = add(root->left, val);
				return root;
			}
		}

		else if(val > root->val)
		{
			if(root->right == NULL)
			{
				root->right = add(root->right, val);
				root->right->parent = root;
				return root;
			}
			else if(val < root->right->val)
			{
				root -> right -> left = add(root -> right -> left, val);
				root -> right -> left -> parent = root -> right;
				return root;
			}
			else
			{
				root->right = add(root->right, val);
				return root;
			}
		}
	}*/
}

BST * construct(BST * root, int * list, int size)
{
	int i=0;
	root = NULL;

	for(i=0; i<size; i++)
	{
		root = add(root, list[i]);
	}

	return root;
}

void inOrderTravRec(BST * root)
{
	if(root!=NULL)
	{
		inOrderTravRec(root->left);
		printf("%d ", root->val);
		inOrderTravRec(root->right);
	}
	else
	{
		lite
	}
}

void inOrderTravIter(BST * root)
{
	STACK * st = (STACK*)malloc(sizeof(STACK));
	st->top=NULL;
	st->count=0;

	printStack(st);

	while(!isEmpty(st))
	{
		root = stackGetTop(st);	stackPop(st);

		while(root->left!=NULL)
		{
			stackPush(st, root=root->left);
			printStack(st);
		}

		printf("%d ", root->val); // this is visiting the element

		if(root->right!=NULL)
		{
			stackPush(st, root->right);
			printStack(st);
		}
	}
}

void findKthSmallest(BST * root, int k)
{
	STACK * st = (STACK*)malloc(sizeof(STACK));
	st->top=NULL;
	st->count=0;
	BST * tempRoot = root;
	stackPush(st, tempRoot);

	int t = 0;

	while(!isEmpty(st))
	{
		tempRoot = stackGetTop(st);	stackPop(st);

		while(tempRoot->left!=NULL)
			stackPush(st, tempRoot=tempRoot->left);

		// printf("%d ", tempRoot->val);
		t++;

		if(t==k)
		{
			printf("%d \n", tempRoot->val);
			lite
		}

		if(tempRoot->right!=NULL)
			stackPush(st, tempRoot->right);
	}
}

void findBetweenKeys(BST * root, int k1, int k2)
{
	STACK * st = (STACK*)malloc(sizeof(STACK));
	st->top=NULL;
	st->count=0;
	BST * tempRoot = root;
	stackPush(st, tempRoot);

	while(!isEmpty(st))
	{
		tempRoot = stackGetTop(st);	stackPop(st);

		while(tempRoot->left!=NULL)
			stackPush(st, tempRoot=tempRoot->left);

		if(tempRoot->val >= k1 && tempRoot->val <= k2)
		{
			printf("%d ", tempRoot->val);
		}

		if(tempRoot->right!=NULL)
			stackPush(st, tempRoot->right);
	}

	printf("\n");
}