#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node * next;
};

struct node * tail = NULL;

void insertAtPosition(int position , int data){
	struct node * link = (struct node *) malloc(sizeof(struct node));
	link->data = data;
	if(position==1){
		struct node * temp = tail->next;
		link->next = temp;
		tail->next = link;
		return;
	}else if(position == length()+1){
		link->next = tail->next;
		tail->next = link;
		tail = link;
	}else if(position <= length()){
		struct node * temp = tail->next;
		struct node * temp2 = NULL;
		while(position>2){
			temp = temp->next;
			position--;
		}
		temp2 = temp->next;
		temp->next = link;
		link->next = temp2;
	}else{
		printf("\ninvalid positon");
	}
	
}

void deletePosition(int position){
	struct node *temp = tail->next;
	struct node *temp2 = NULL;
	if(position==1){
		tail->next = temp->next;
		free(temp);
	}else if(position == length()){
		while(temp->next != tail){
			temp = temp->next ;
		}
		temp->next = tail->next;
		free(tail);
		tail = temp ;
	}else if(position<length()){
		while(position>2){
			position--;
			temp = temp->next;
		}
		temp2 = temp->next;
		temp->next = temp2->next;
		free(temp2);
	}else{
		printf("\ninvalid position");
	}
}

int length(){
	int count = 0;
	if(tail == NULL){
		return count;
	}
	struct node * temp = tail->next;
	while(temp!=tail){
		count++;
		temp = temp->next;
	}
	return ++count;
}

void insertFirst(int data){
	struct node * link = (struct node *) malloc(sizeof(struct node));
	link->data = data;
	if(tail==NULL){
		link->next = link;
		tail = link;
	}else{
		link->next = tail->next;
		tail->next = link;
	}
}

void deleteFirst(){

	if(tail==NULL){
		printf("\nlist is empty");
	}
	else if(tail==tail->next){
		free(tail);
		tail=NULL;
	}else{
		struct node * temp = tail->next;
		tail->next = temp->next;
		free(temp);
		temp=NULL;
	}
	return;
}

void insertLast(int data){
	struct node * link = (struct node *) malloc(sizeof(struct node));
	link->data = data;
	if(tail == NULL){
		link->next = link;
	}else{
		link->next = tail->next;
		tail->next = link;
	}
	tail = link;
}

void deleteLast(){
	if(tail==NULL){
		printf("\nlist is empty");
	}else if(tail->next == tail){
		free(tail);
		tail=NULL;
	}else{
		struct node * temp = tail->next;
		while(temp->next!=tail){
			temp=temp->next;
		}
		temp->next = tail->next;
		free(tail);
		tail=temp;
	}
}

void display(){
	if(tail==NULL){
		printf("\nlist is empty");
		return;
	}
	printf("\n");
	struct node * temp = tail->next;
	do{
		printf("%d ",temp->data);
		temp = temp->next;
	}while(temp!=tail->next);
}

int main(){
	insertFirst(12);
	insertFirst(54);
	insertLast(55);
	deletePosition(30);
//	printf("\n%d",length());
//	deleteFirst();
//	insertFirst(132);
//	insertFirst(544);
//	deleteFirst();deleteFirst();
//	printf("\n%d",length());
//	deleteLast();
	display();
}
