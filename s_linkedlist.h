#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef S_LINKEDLIST_H_
#define S_LINKEDLIST_H_

// Alias for struct and enum.
typedef struct single_linked_list slinkedlist;
typedef enum boolean boolean;

// Generic structure of the single linked list.
struct single_linked_list
{
	void *node_data;
	slinkedlist *node_ptr;
};

// Create enum of boolean.
enum boolean
{
	false,	// false will be 0
	true
};

// List of function which can be used to manage the single linked list.
boolean sPush(slinkedlist**, void* const);
boolean sAppend(slinkedlist**, void* const);
void* sPop(slinkedlist**);
boolean sDelete(slinkedlist**, const unsigned);
void sDeleteAll(slinkedlist**);
void* sGetNodeData(slinkedlist*, const unsigned);
void sDisplayAll(slinkedlist*, void(*stringify_func)(void*));
int sFind(slinkedlist*, void*, int(*compare_func)(void*, void*));
void sSort(slinkedlist**, int(*compare_func)(void*, void*));
slinkedlist* sReverse(slinkedlist*);
slinkedlist* sGetSubList(slinkedlist*, unsigned, unsigned);
void sClone(slinkedlist*, slinkedlist**);

// Special functions which will used for allocation of heap memory, so that the
// at the time of exit all the allocated memory can be freed safly.
void* sMalloc(unsigned);
void sReleaseHeapMemories(void);

// Commonly used variables.
extern const unsigned LINKEDLIST_SIZE;
extern slinkedlist *s_heap_tracker___;

#endif // S_LINKEDLIST_H_