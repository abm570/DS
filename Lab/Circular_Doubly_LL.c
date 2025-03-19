#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL, *tail = NULL, *new=NULL;

int length();
void Begin(int a);
void End(int a);
void Middle(int a);
void Search(int key);
void DBegin();
void DMid();
void DEnd();
void Display();


int length() 
{
    struct node *temp = head;
    int count = 0;

    if (head == NULL) 
        return 0;

    while (temp != tail)
    { 
        count++;
        temp = temp->next;
    }
    count++;

    return count;
}

void Begin(int a) 
{
    new = (struct node*)malloc(sizeof(struct node));
    new->data = a;

    if (head == NULL)
    { 
		new->next = new;
        new->prev = new;
        head = tail = new;
       
    } else {
        new->next = head;
        new->prev = tail;

        tail->next = new;
        head->prev = new;

        head = new;
    }
}

void End(int a) 
{
    new = (struct node*)malloc(sizeof(struct node));
    new->data = a;

    if (head == NULL) {
        new->next = new;
        new->prev = new;
        head = tail = new;
    } 
    else 
    {
        new->next = head;
        new->prev = tail;

        tail->next = new;
        head->prev = new;

        tail = new;
    }
}

void Middle(int a) 
{
    struct node *temp;
    int loc, i = 1, len;

    len = length();
    if (len == 0) 
    {
        printf("The list is Empty\n");
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
    while (i < loc) {
        temp = temp->next;
        i++;
    }

    new = (struct node*)malloc(sizeof(struct node));
    new->data = a;

    new->next = temp->next;
    new->prev = temp;

    temp->next->prev = new;
    temp->next = new;
}

void Search(int key) 
{
    struct node *temp = head;
    int pos = 1, found = 0;

    if (head == NULL) {
        printf("The list is empty. Cannot search.\n");
        return;
    }

    while (temp != tail) { 
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (temp->data == key) {
        printf("Element %d found at position %d\n", key, pos);
        found = 1;
    }

    if (!found) {
        printf("Element %d not found in the list.\n", key);
    }
}

void DBegin() 
{
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }

    struct node *temp = head;

    if (head == tail) 
    {
        free(head);
        head = tail = NULL;
    } 
    else 
    {
        head = head->next;
        tail->next = head;
        head->prev = tail;
        free(temp);
    }
}

void DMid() 
{
    struct node *temp;
    int loc, i = 1, len;

    len = length();
    if (len == 0) {
        printf("The list is empty\n");
        return;
    }

    printf("Enter the position to delete: ");
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
    while (i < loc) {
        temp = temp->next;
        i++;
    }

    if (temp == tail) {
        DEnd();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
}

void DEnd() {
    if (head == NULL) {
        printf("The list is empty, nothing to delete.\n");
        return;
    }

    if (head == tail) {
        free(head);
        head = tail = NULL;
        printf("Last node deleted, list is now empty.\n");
        return;
    }

    struct node *temp = tail;

    tail = tail->prev;
    tail->next = head;
    head->prev = tail;

    free(temp);

    printf("Last node deleted successfully.\n");
}

void Display() {
    struct node *temp;
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }

    temp = head;
    while (temp != tail) { 
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("%d <-> (Head)\n", temp->data);

    printf("Total Elements: %d\n", length());
}

int main() {
    int a, ch;

    while (1) {
        printf("\n1. Insert Beginning\n");
        printf("2. Insert Middle\n");
        printf("3. Insert End\n");
        printf("4. Display\n");
        printf("5. Search\n");
        printf("6. Delete Beginning\n");
        printf("7. Delete Middle\n");
        printf("8. Delete End\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &a);
                Begin(a);
                break;
            case 2:
                printf("Enter the element to be inserted: ");
                scanf("%d", &a);
                Middle(a);
                break;
            case 3:
                printf("Enter the element to be inserted: ");
                scanf("%d", &a);
                End(a);
                break;
            case 4:
                Display();
                break;
            case 5:
                printf("Enter the element to search: ");
                scanf("%d", &a);
                Search(a);
                break;
            case 6:
                DBegin();
                break;
            case 7:
                DMid();
                break;
            case 8:
                DEnd();
                break;
            case 9:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Enter a valid choice!\n");
        }
    }
}
