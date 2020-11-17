#include<iostream>
using namespace std;

class Node{
	public:
		Node *prev;
		int data;
		Node *next;
	
}*first=NULL;

void create(int a[],int n){
	Node *t,*last;
	int i;
	first = new Node();
	first->data=a[0];
	first->prev=first->next=NULL;
	last=first;
	
	for(i=1;i<n;i++){
		t=new Node();
		t->data=a[i];
		t->next=NULL;
		t->prev=last;
		last->next=t;
		last=t;
		
	}
}

void display(Node *p){
	while(p){
		cout<<p->data<<" ";
		p=p->next;
		
	}
	cout<<"\n";
}

int Length(Node *p){
	int l=0;
	while(p){
		l++;
		p=p->next;
	}
	return l;
	
}

void insert(Node *p,int index,int x){
	Node *t;
	int i;
	if(index<0 || index>Length(p))
		return;
	if(index==0){
		t=new Node();
		t->data=x;
		t->next=first;
		t->prev=NULL;
		first->prev=t;
		first=t;
	}
	
	else{
		for(i=1;i<index-1;i++)
			p=p->next;
		t=new Node();
		t->data=x;
		t->next=p->next;
		t->prev=p;
		if(p->next)p->next->prev=t;
		p->next=t; 
	}
}

int Delete(Node *p,int index){
	Node *q;
	int x=-1,i;
	
	if(index<1 || index>Length(p))
		return -1;
	if(index==1){
		first=first->next;
	if(first)first->prev=NULL;
	
	x=p->data;
	delete p;
	
	}
	
	else{
		for(i=0;i<index-1;i++)
			p=p->next;
		
		p->prev->next=p->next;
		if(p->next)
			p->next->prev=p->prev;
			
		x=p->data;
		delete p;
	}
	return x;
}

void reverse(Node *p){
	Node *temp;
	while(p!=NULL){
		temp=p->next;
		p->next=p->prev;
		p->prev=temp;
		p=p->prev;
		
		if(p!=NULL && p->next==NULL)
			first=p;
	}
}
int main(){
	int a[]={2,4,8,18,28};
	create(a,5);
	insert(first,4,21);
	Delete(first,4);
	Delete(first,1);
	reverse(first);
	display(first);
	cout<<"Length:"<<Length(first);
	return 0;
}
