#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node
{
int data;
struct node *next;
};

void print_list(struct node *head)
{

while(head)
{
cout << head->data <<" ";
head = head->next;
}

cout << endl;
}

void insert_front(struct node **head, int data)
{
struct node * new_node = NULL;

new_node = (struct node *)malloc(sizeof(struct node));

if (new_node == NULL)
{
cout <<"\nUnable to allocate memory\n";
}

new_node->data = data;
new_node->next = *head;

*head = new_node;
}

void create_loop(struct node *head)
{
struct node *temp = head;

while(temp->next)
temp = temp->next;

temp->next = head->next;
}

void print_loop(struct node *head)
{
int n = 25;

while(n--)
{
cout << head->data <<" ";
head = head->next;
}

cout << endl;
}

void detect_loop(struct node *head)
{
struct node *slow = head;
struct node *fast = head;

while(slow && fast->next && fast->next->next)
{
if ((slow == fast->next) || (slow == fast->next->next ))
{
cout <<"\nLinked list has a loop\n";
return;
}

slow = slow->next;
fast = fast->next->next;
}

cout <<"\nLinked list does not have any loop\n";
}

void remove_loop(struct node *head, struct node *loop_node)
{
struct node *near = head;
struct node *far = head;
struct node *ptr = loop_node;
struct node *prev = NULL;

while(ptr->next != loop_node)
{
ptr = ptr->next;
far = far->next;
}

prev = far;
far = far->next;

while(near != far)
{
prev = far;
far = far->next;
near = near->next;
}

prev->next = NULL;
}

void detect_and_remove_loop(struct node *head)
{
struct node *slow = head;
struct node *fast = head;

while(slow && fast->next && fast->next->next)
{
if ((slow == fast->next) || (slow == fast->next->next ))
{
cout <<"\nLinked list has a loop\n";
remove_loop(head, slow);
return;
}

slow = slow->next;
fast = fast->next->next;
}

cout <<"\nLinked list does not have any loop\n";
}

int main()
{
int n, i, data;
struct node * head = NULL;

cout <<"\nEnter number of elements :";
cin >> n;
cout <<"\nEnter the elements :" ;
for (i = 0; i < n; i++)
{
cin >> data;
insert_front(&head, data);
}

cout <<"\nThe Linked List is : ";
print_list(head);
detect_loop(head);

cout <<"\nCreating loop…\n";
create_loop(head);
cout <<"\nPrinting list with loop\n";
print_loop(head);
cout <<"\nRemoving loop…\n";
detect_and_remove_loop(head);

cout <<"\nList after removing loop:\n";
print_list(head);
}

/*
INPUT:

Enter number of elements :5

Enter the elements :50 40 12 10 9


OUTPUT:

The Linked List is : 9 10 12 40 50 

Linked list does not have any loop

Creating loop…

Printing list with loop
9 10 12 40 50 10 12 40 50 10 12 40 50 10 12 40 50 10 12 40 50 10 12 40 50 

Removing loop…

Linked list has a loop

List after removing loop:
9 10 12 40 50 

*/
