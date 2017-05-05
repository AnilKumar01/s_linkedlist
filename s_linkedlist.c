#include "s_linkedlist.h"

///////////////////////////////////////////////////////////////////////////////
// Determine the size of linked list.
const unsigned LINKEDLIST_SIZE = sizeof(slinkedlist);

///////////////////////////////////////////////////////////////////////////////
// INSERTION OPERATIONS
// Implementation of the push function.
boolean sPush(slinkedlist **ref_ptr, void* const node_data)
{
	// Allocate memory for the new node.
	slinkedlist *new_node = (slinkedlist*)sMalloc(LINKEDLIST_SIZE);
	if(new_node == NULL)
			return false;
	new_node->node_data = node_data;
	new_node->node_ptr = NULL;

	// Attach the new node to the ref_ptr of th linked list.
	if((*ref_ptr) == NULL)
		(*ref_ptr) = new_node;
	else
	{
		new_node->node_ptr = (*ref_ptr);
		(*ref_ptr) = new_node;
	}
	return true;
}

// Implementation of the append function.
boolean sAppend(slinkedlist **ref_ptr, void* const node_data)
{
	// Allocate memory for the new node.
	slinkedlist *new_node = (slinkedlist*)sMalloc(LINKEDLIST_SIZE);
	if(new_node == NULL)
		return false;
	new_node->node_data =  node_data;
	new_node->node_ptr = NULL;

	// Attach the new node to the ref_ptr of th linked list.
	if((*ref_ptr) == NULL)
		(*ref_ptr) = new_node;
	else
	{
		slinkedlist *append_ptr = (*ref_ptr);
		while(append_ptr->node_ptr != NULL)
			append_ptr = append_ptr->node_ptr;
		
		append_ptr->node_ptr = new_node;
	}
	return true;
}

///////////////////////////////////////////////////////////////////////////////
// DELETE OPERATIONS
// Implementation of the pop function.
void* sPop(slinkedlist **ref_ptr)
{
	if((*ref_ptr) != NULL)
	{
		slinkedlist *delete_node = (*ref_ptr);
		void* node_data = (*ref_ptr)->node_data;
		(*ref_ptr) = (*ref_ptr)->node_ptr;
		free(delete_node);
		return node_data;
	}
}

// Implementation of the delete function.
boolean sDelete(slinkedlist **ref_ptr, const unsigned node_index)
{
	unsigned index = 0;
	slinkedlist *delete_ptr = (*ref_ptr);
	if(node_index == index)
	{
		if(delete_ptr != NULL)
		{
			(*ref_ptr) = delete_ptr->node_ptr;
			free(delete_ptr->node_data);
			free(delete_ptr);
			return true;
		}
	}
	else
	{
		index++;
		while(index < node_index)
		{
			if(delete_ptr->node_ptr == NULL)
				break;
			delete_ptr = (delete_ptr->node_ptr);
			index++;
		}
		if(index == node_index && delete_ptr != NULL)
		{
			slinkedlist *delete_node = (delete_ptr->node_ptr);
			delete_ptr->node_ptr = (delete_ptr->node_ptr)->node_ptr;
			free(delete_node->node_data);
			free(delete_node);
			return true;
		}
	}
	return false;
}

// Implementation of delete all function.
void sDeleteAll(slinkedlist **ref_ptr)
{
	while((*ref_ptr) != NULL)
	{
		slinkedlist *delete_node = (*ref_ptr);
		(*ref_ptr) = (*ref_ptr)->node_ptr;
		free(delete_node->node_data);
		free(delete_node);
	}
}

///////////////////////////////////////////////////////////////////////////////
// VIEW OPERATIONS
// Implementation of the get node data function.
void* sGetNodeData(slinkedlist *ref_ptr, const unsigned node_index)
{
	unsigned index = 0;
	slinkedlist *itrate_ptr = ref_ptr;
	while(index < node_index)
	{
		if(itrate_ptr->node_ptr == NULL)
			break;
		itrate_ptr = itrate_ptr->node_ptr;
		index++;
	}
	if(index == node_index && itrate_ptr != NULL)
	{
		return itrate_ptr->node_data;
	}
}

// Implementation of the display all function.
void sDisplayAll(slinkedlist *ref_ptr, void(*stringify_func)(void*))
{
	while(ref_ptr != NULL)
	{
		void *tmp_node_data = ref_ptr->node_data;
		stringify_func(tmp_node_data);	
		ref_ptr = ref_ptr->node_ptr;
	}
}

///////////////////////////////////////////////////////////////////////////////
// SEARCH OPERATIONS
// Implemenation of find function.
int sFind(slinkedlist *ref_ptr, void *key, int(*compare_func)(void*, void*))
{
	int index = 0;
	while(ref_ptr != NULL)
	{
		void *tmp_node_data = ref_ptr->node_data;
		if(compare_func(key, tmp_node_data) == 0)
			return index;

		index++;
		ref_ptr = ref_ptr->node_ptr;
	}
	return -1;
}

///////////////////////////////////////////////////////////////////////////////
// SORT OPERATIONS
// Implementation of sort function.
void sSort(slinkedlist **ref_ptr, int(*compare_func)(void*, void*))
{
	slinkedlist *itrate_ptr_0 = (*ref_ptr);

	while(itrate_ptr_0->node_ptr != NULL)
	{
		slinkedlist *itrate_ptr_1 = itrate_ptr_0->node_ptr;
		while(itrate_ptr_1 != NULL)
		{
			if(compare_func(itrate_ptr_0->node_data, itrate_ptr_1->node_data) > 0)
			{
				void *tmp_node_data = itrate_ptr_0->node_data;
				itrate_ptr_0->node_data = itrate_ptr_1->node_data;
				itrate_ptr_1->node_data = tmp_node_data;
			}
			itrate_ptr_1 = itrate_ptr_1->node_ptr;
		}
		itrate_ptr_0 = itrate_ptr_0->node_ptr;
	}
}

///////////////////////////////////////////////////////////////////////////////
// REVERSE AND COPY OPERATIONS
// Implementation of reverse function.
slinkedlist* sReverse(slinkedlist *ref_ptr)
{
	slinkedlist *rev_list = NULL;
	while(ref_ptr != NULL)
	{
		sPush(&rev_list, ref_ptr->node_data);
		ref_ptr = ref_ptr->node_ptr;
	}
	return rev_list;
}

// Implementation of copy function.
slinkedlist* sGetSubList(slinkedlist *ref_ptr, unsigned from_ni, unsigned non)
{
	slinkedlist *cpy_list = NULL;
	unsigned index = 0;
	while(ref_ptr != NULL)
	{
		if(index++ >= from_ni && non-- > 0)
		{
			sAppend(&cpy_list, ref_ptr->node_data);
		}
		ref_ptr = ref_ptr->node_ptr;
	}
	return cpy_list;
}

// Implementation of clone function.
void sClone(slinkedlist *from_ref_ptr, slinkedlist **to_ref_ptr)
{
	while(from_ref_ptr != NULL)
	{
		sAppend(&(*to_ref_ptr), from_ref_ptr->node_data);
		from_ref_ptr = from_ref_ptr->node_ptr;
	}
}

///////////////////////////////////////////////////////////////////////////////
// MEMORY MANAGEMENT OPERATIONS
// A garbage list which will keep track of all memory allocated through the
// sMalloc function.
slinkedlist *s_heap_tracker___ = NULL;

// Implementation of memory allocation function.
void* sMalloc(unsigned nob)
{
	// Allocate memory for the request.
	void *heap_mem_ptr___ = malloc(nob);
	// Create new node for garbage list.
	slinkedlist *new___ = (slinkedlist*)malloc(LINKEDLIST_SIZE);
	new___->node_data = heap_mem_ptr___;
	new___->node_ptr = NULL;
	// Add the reference of the memory in the garbage list for tracking of 
	// all allocated memories.
	if(s_heap_tracker___ == NULL)
		s_heap_tracker___ = new___;
	else
	{
		new___->node_ptr = s_heap_tracker___;
		s_heap_tracker___ = new___;
	}
	// Return the allocated memory reference.
	return heap_mem_ptr___;
}

// Implementation of release heap memory function.
void sReleaseHeapMemories(void)
{
	sDeleteAll(&s_heap_tracker___);
}