#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head=NULL, *new=NULL;
int len;


void Begin(int a) 
{
    struct node *temp;
    new = (struct node*)malloc(sizeof(struct node));
    new->data = a;

    if (head == NULL) 
    {  
        head = new;
        new->next = head;
    } 
    else 
    {
        temp = head;
        while (temp->next != head) 
        { 
            temp = temp->next;
        }
        new->next = head;
        temp->next = new;
        head = new;
    }
}	
void End(int a) 
{
    struct node *temp;
    new = (struct node*)malloc(sizeof(struct node));
    new->data = a;

    if (head == NULL) 
    {
        head = new;
        new->next = head;
    } 
    else 
    {
        temp = head;
        while (temp->next != head) 
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = head; 
    }
}
int length() 
{
    struct node *temp = head;
    int count = 0;

    if (head == NULL) 
    {
        return 0;
    }

    while (temp->next != head) 
    {
    
        count++;
        temp = temp->next;
    }
    count++;

    return count;
}
void Display() 
{
    struct node *temp;
    if (head == NULL) 
    {
        printf("The List is Empty\n");
        return;
    }

    temp = head;
    printf("Circular Linked List: ");

    while (temp->next != head) 
    {  
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("%d --> (back to head)\n\n", temp->data); 

    len = length();
    printf("The Total Elements == %d\n", len);
}

void Middle(int a) 
{
    struct node *newNode, *temp;
    int loc, i = 1;
    len = length(); 

    if (len == 0) 
    {
        printf("The list is empty. Cannot insert in the middle.\n");
        return;
    }

    printf("Enter the location to be inserted: ");
    scanf("%d", &loc);

    if (loc > len || loc < 1) 
    {  
        printf("Invalid Location\n");
        return;
    }

    temp = head;
    while (i < loc)
    { 
        temp = temp->next;
        i++;
    }

    
    new = (struct node*)malloc(sizeof(struct node));
    new->data = a;

  
    new->next = temp->next;
    temp->next = new;

    printf("Node inserted successfully at position %d\n", loc);
}


void Search(int key) 
{
    struct node *temp = head;
    int pos = 1, found = 0;

    if (head == NULL) 
    {
        printf("The list is empty. Cannot search.\n");
        return;
    }

    while (temp->next != head) 
    {
        if (temp->data == key) 
        {
            printf("Element %d found at position %d\n", key, pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (temp->data == key && !found) 
    {		
        printf("Element %d found at position %d\n", key, pos);
        found = 1;
	}
}

void DBegin() 
{
    struct node *temp, *last;

    if (head == NULL)
    {  
        printf("The list is empty. Cannot delete.\n");
        return;
    }

    if (head->next == head)
    {  
        free(head);
        head = NULL;
        printf("The last node is deleted, and the list is now empty.\n");
        return;
    }

    temp = head;  

    last = head;
    while (last->next != head) 
    {
        last = last->next;
    }

    head = head->next;
    last->next = head;

    free(temp);
    printf("First node deleted successfully.\n");
}


void DMid() 
{
    struct node *temp, *nextnode;
    int loc, i = 1;
    len = length(); 

    if (len == 0) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }

    printf("Please enter the position to delete: ");
    scanf("%d", &loc);

    if (loc > len || loc < 1) {  
        printf("Invalid Location\n");
        return;
    }

    if (loc == 1) {
        DBegin(); 
        return;
    }

    temp = head;
    while (i < loc - 1) 
    { 
        temp = temp->next;
        i++;
    }

    nextnode = temp->next;
    temp->next = nextnode->next;

    free(nextnode);

    printf("Node at position %d deleted successfully.\n", loc);
}

void DEnd() 
{
    struct node *temp = head, *prev;

    if (head == NULL)
    {  
        printf("The list is empty, nothing to delete.\n");
        return;
    }

    if (head->next == head) 
    {  
        free(head);
        head = NULL;
        printf("Last node deleted, list is now empty.\n");
        return;
    }

    while (temp->next != head) 
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);

    printf("Last node deleted successfully.\n");
}

void main()
{
	int a;
	
	while(1)
	{
		int ch;
		printf("\n1.Insert Begining\n");
		printf("2. Insert Middle \n");
		printf("3. Insert End \n");
		printf("4. Display \n");
		printf("5. Search \n");
		printf("6. Delete Begining \n");
		printf("7. Delete Middle \n");
		printf("8. Delete End \n");
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element to be inserted \n");
				scanf("%d", &a);
				Begin(a);
				break;
			case 2:
				printf("Enter the element to be inserted \n");
				scanf("%d", &a);
				Middle(a);
				break;
			case 3:
				printf("Enter the element to be inserted \n");
				scanf("%d", &a);
				End(a);
				break;
			case 4: Display();
					break;
			case 5:   printf("Enter the element to search: \n");
                scanf("%d", &a);
                Search(a);
                break;
            case 6: DBegin();
				 break;
			case 7: DMid();
				break;
			case 8: DEnd();
				break;
            default:
                printf("Enter the choice Correctly\n");
                break;
		}
		
		
	}
	

}
