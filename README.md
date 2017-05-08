# s_linkedlist
### s_linkedlist is a generic implementaion of single linked list in c language, that means using this, you can create any type of list.

### For example, you can make a list of students, contacts, animals, etc.
### s_linkedlist provides various type of operations which can be used for the manipulation of a list. These operations are listed as follows:

- sPush: It will add a node at the head position of the linked list. This function takes two arguments, i) a reference pointer to the linked list, and ii) value of the node data. And it will return true on success, otherwise false.

	format: 

		boolean sPush(slinkedlist **ref_ptr, void* const node_data)

	example:

		slinkedlist *my_slinkedlist = NULL;
		int my_data = 20;
		sPush(&my_slinkedlist, &my_data);

- sAppend: It will append the list i.e. add a node at the end of the list.  This function takes two arguments, i) a reference pointer to the linked list, and ii) value of the node data. And it will return true on success, otherwise false.

	format:

		boolean sAppend(slinkedlist **ref_ptr, void* const node_data)

	eample:

		slinkedlist *my_slinkedlist = NULL;
		int my_data = 20;
		sPush(&my_slinkedlist, &my_data);

- sPop: It will remove a node from the head end. It takes linked list reference as an argument and return popped node data.

	format:

		void* sPop(slinkedlist **ref_ptr)

	example:
	
		int *my_data;
		my_data = sPop(&my_slinkedlist);

- sDelete: Function will delete/remove a node whose index (starting from 0) is specified. This function takes two arguments, i) a reference pointer to the linked list, and ii) node index number which has to remove. And it will return true on success, otherwise false.
	
	format:
		
		boolean sDelete(slinkedlist **ref_ptr, const unsigned node_index)
	
	example:
		
		if(sDelete(&my_slinkedlist, 2) == true)
			printf("record deleted!!");
		else
			printf("operation faled!!");

- sDeleteAll: It will delete all node from the linked list whose reference is given as an argument. 
	
	format:
		
		void sDeleteAll(slinkedlist **ref_ptr)
	
	example:
		
		sDeleteAll(&my_slinkedlist);

- sGetNodeData: It will return a node from the linked list. This function takes two arguments, i) a pointer to the linked list, and ii) node index number.
	
	format:
		
		void* sGetNodeData(slinkedlist *ref_ptr, const unsigned node_index)
	
	example:
		
		int *my_data;
		my_data = sGetNodeData(my_slinkedlist, 5);	

- sDisplayAll: It will print all the node data of the linked list. This function takes two arguments, i) a pointer to the linked list, and ii) a reference to a function which can represent the data in string/readable format. 
	
	format:
		
		void sDisplayAll(slinkedlist *ref_ptr, void(*stringify_func)(void*))
	
	example:
		
		sDisplayAll(my_slinkedlist, &printMyData);

- sFind: Used for search a node in the linked list. This function takes three arguments, i) a pointer to the linked list, ii) a pointer to the key which has to search, and iii) a reference pointer to a function which can compare the data for equality. And it will return the index number if the key is in the list, otherwise -1 will returned.
	
	format:
		
		int sFind(slinkedlist *ref_ptr, void *key, int(*compare_func)(void*, void*))
	
	example:
		
		int key = 20;
		sFind(my_slinkedlist, key, &compare_node_value);

- sSort: It will sort the given linked list. This function takes two arguments, i) a reference to the linked list, and ii) a reference pointer to a function which can compare the data for equality.
	
	format:
		
		void sSort(slinkedlist **ref_ptr, int(*compare_func)(void*, void*))
	
	example:
		
		sSort(&my_slinkedlist, &compare_node_value);

- sReverse: It will return a linked list which is reverse of the given list provided in the argument.
	
	format:
		
		slinkedlist* sReverse(slinkedlist *ref_ptr)
	
	example:
		
		slinkelist *my_reverselist = NULL;
		my_reverselist = sReverse(my_slinkedlist);

- sGetSubList: It will return the sub list from the given list. This function takes three arguments, i) a pointer to the linked list, ii) index from which sublist need to extract, and iii) number of nodes need to extract.
	
	format:
		
		slinkedlist* sGetSubList(slinkedlist *ref_ptr, unsigned from_ni, unsigned non)
	
	example:
		
		slinkedlist *my_sublist = NULL;
		my_sublist = sGetSubList(my_slinkedlist, 3, 3);

- sClone: It will make a clone of the given list. This function takes two arguments, i) a pointer to the linked list, and ii) reference pointer to the clone list.
	
	format:
		
		void sClone(slinkedlist *from_ref_ptr, slinkedlist **to_ref_ptr)
	
	example:
		
		slinkedlist *my_clonelist = NULL;
		sClone(my_slinkedlist, &my_clonelist);


### Appart from the above functionalities, s_linkedlist also provides some special function which can be use for memory managements. These are as follows:

- sMalloc: This function can be use for the memory allocation. It takes amount of memory (i.e. number of bytes) as an argument which need to allocate in the heap and return the reference of the allocated memory. Any memory which is allocated using the sMalloc, the reference of the memory is stored in the 's_heap_tracker___' list, so that at the end of the application memory can be freed easily.
	
	format:
		
		void* sMalloc(unsigned nob)
	
	example: 
		
		char *p;
		p = (char*)sMalloc(sizeof(char)*10);

- sReleaseHeapMemories: This function whill release all the memory allocated through sMalloc. It is recommanded that this function should called at the end of the program.
	
	format:
		
		void sReleaseHeapMemories(void)
	
	example:
		
		sReleaseHeapMemories();
