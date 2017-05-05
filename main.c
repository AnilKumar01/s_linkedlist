#include <stdio.h>
#include <stdlib.h>
#include "s_linkedlist.h"

typedef struct node_value node_value;

struct node_value
{
	int data;
};

void print_node_value(void* nv)
{
	node_value *node_val = nv;
	printf("data: %d\n", node_val->data);
}

int compare_node_value(void* nv1, void* nv2)
{
	node_value *node_val1 = nv1;
	node_value *node_val2 = nv2;
	if(node_val1->data < node_val2->data)
		return -1;
	else if(node_val1->data > node_val2->data)
		return 1;
	else
		return 0;
}

int main(void)
{
	slinkedlist *head = NULL;
	int opt;
	node_value *nv;

	while(1)
	{
		printf("==============================\n");
		printf("Linked List Demo\n");
		printf("------------------------------\n");
		printf("push data------------------->1\n");
		printf("display all data------------>2\n");
		printf("delete data----------------->3\n");
		printf("append data----------------->4\n");
		printf("pop head-------------------->5\n");
		printf("get node value-------------->6\n");
		printf("node exists?---------------->7\n");
		printf("sort the list--------------->8\n");
		printf("reverse the list------------>9\n");
		printf("copy list------------------>10\n");
		printf("clone list----------------->11\n");
		printf("quit------------------------>0\n");
		printf("choose an option...");
		scanf("%d", &opt);
		printf("==============================\n");
		switch(opt)
		{
			case 1:
				printf("Linked List Demo->push data\n");
				printf("------------------------------\n");
				printf("enter data: ");	
				nv = (node_value*)sMalloc(sizeof(node_value));			
				scanf("%d", &(nv->data));
				sPush(&head, nv);
				break;
			case 2:
				printf("Linked List Demo->display all\n");
				printf("------------------------------\n");
				sDisplayAll(head, &print_node_value);
				break;
			case 3:
				printf("Linked List Demo->delete data\n");
				printf("------------------------------\n");
				printf("enter node number to delete: ");
				int node_num;
				scanf("%d", &node_num);
				if(sDelete(&head, node_num) == true)
					printf("node deleted successfully...\n");
				sDisplayAll(head, &print_node_value);
				break;
			case 4:
				printf("Linked List Demo->append data\n");
				printf("------------------------------\n");
				printf("enter data: ");
				nv = (node_value*)sMalloc(sizeof(node_value));
				scanf("%d", &(nv->data));
				sAppend(&head, nv);
				break;
			case 5:
				printf("Linked List Demo->popp head\n");
				printf("------------------------------\n");
				nv = sPop(&head);
				printf("head poped [%d]\n", nv->data);
				break;
			case 6:
				printf("Linked List Demo->get node value\n");
				printf("------------------------------\n");
				printf("enter node number: ");
				scanf("%d", &node_num);
				print_node_value(sGetNodeData(head, node_num));
				break;
			case 7:
				printf("Linked List Demo->Node exists?\n");
				printf("------------------------------\n");
				printf("enter data: ");
				nv = (node_value*)sMalloc(sizeof(node_value));
				scanf("%d", &(nv->data));
				printf("is data in the list? %d\n", sFind(head, nv, &compare_node_value));
				break;
			case 8:
				printf("Linked List Demo->Sort The List\n");
				printf("------------------------------\n");
				sSort(&head, &compare_node_value);
				sDisplayAll(head, &print_node_value);
				break;
			case 9:
				printf("Linked List Demo->Reverse The List\n");
				printf("------------------------------\n");
				sDisplayAll(sReverse(head), &print_node_value);
				break;
			case 10:
				printf("Linked List Demo->Copy List\n");
				printf("------------------------------\n");
				sDisplayAll(sGetSubList(head, 3, 3), &print_node_value);
				break;
			case 11:
				printf("Linked List Demo->Clone List\n");
				printf("------------------------------\n");
				slinkedlist *cloneList = NULL;
				sClone(head, &cloneList);
				sDisplayAll(cloneList, &print_node_value);
				break;
			case 0:
				sReleaseHeapMemories();
				exit(0);
				break;
			default:
				printf("error: invalid option.\n");
		}
	}

	return 0;
}