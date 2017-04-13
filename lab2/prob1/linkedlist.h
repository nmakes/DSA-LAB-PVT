/* linkedlist.h */

// structure definitions
// structure of a linked list node. It contains an element
struct NODE
{
	int element;
	struct NODE * next;
};

typedef struct NODE node;

/* structure of a linked list / head. It stores the count of number of elements
in the list and also a pointer link to the first node of the list. */

struct LINKEDLIST
{
	int count;
	node * first;
};
// function declarations

typedef struct LINKEDLIST linkedList;
typedef linkedList* list;

void insertInFront(list head, int ele);
void insertAtEnd(list head, int ele);
void deleteFromFront(list head);
void deleteAtEnd(list head);
void traverse(list head);