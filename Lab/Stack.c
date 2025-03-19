#include<stdio.h>
#include<stdlib.h>
int top=-1, n;

void push(int a[], int e)
{
	if(top==n-1)
	{
		printf("Stack is Full \n");
	}
	else
	{
		top++;
		a[top] = e;
		printf("******************************************************\n");
		printf("\nElement %d is Pushed \n", e);
		printf("******************************************************\n");
	}
}

void pop(int a[])
{
	if(top==-1)
	{
		printf("******************************************************\n");
		printf("Stack is Under Flow \n");
		printf("******************************************************\n");
	}
	else
	{
		printf("******************************************************\n");
		printf("Element %d is poped \n", a[top--]);
		printf("******************************************************\n");
	}
}

void peek(int a[])
{
	if(top==-1)
	{
		printf("******************************************************\n");
		printf("Stack is Under Flow \n");
		printf("******************************************************\n");
	}
	else
	{
		printf("******************************************************\n");
		printf("The Top Most Element is %d\n", a[top]);
		printf("******************************************************\n");
	}
	
}

void display(int a[])
{
	if(top==-1)
	{
		printf("Stack is Emplty \n");
	}
	else
	{
		printf("Elements of Stack are \n");
		printf("******************************************************\n");
		for(int i=top;i>-1;i--)
		{
			printf("%d \n",a[i]);
		}
	}
}

void main()
{
	printf("Enter the size of the Array \n");
	scanf("%d", &n);
	int a[n],  e;
	while(1)
	{
		int ch;
		printf("\n\n1->Insert element \t2->Delete element \n3->Peek \t\t4->Display \n5->Exit\n");
		printf("\nEnter choice:\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the element to be pushed \n");
			scanf("%d", &e);
			push(a, e);
			break; 
			case 2: pop(a);
			break;
			case 3: peek(a);
			break;
			case 4: display(a);
			break;
			case 5: printf("Exiting...\n");
				exit(0);
			break;
			default: printf("Enter the choice Correctly");
		}
		
	}
	

}
