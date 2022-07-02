#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node * prev;
	struct node * next;
};

struct node * head = NULL;
struct node * current = NULL;

void addFirst(int data){
	struct node * link = (struct node *) malloc(sizeof(struct node));
	link->data = data;
	if(head==NULL){
		link->prev = NULL;
		link->next = NULL;
		head = link;
	}else{
		link->prev = current;
		link->next = NULL;
		current->next = link;
	}
	current = link;
}

void deleteLast(){
	struct node * temp = current->prev;
	if(head!=current){
		printf("hello1\n");
		free(current);
		temp->next = NULL;
		current = temp ;	
	}else{
		current=NULL;
		printf("hello\n");
		free(head);
		head=NULL;
	}
	
}

void display(){
	struct node * temp = head ;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
}

int main(){
	addFirst(12),
	addFirst(43);
	deleteLast();
	addFirst(345);
	deleteLast();
	display();
}
