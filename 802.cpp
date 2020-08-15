#include <iostream>
#include <string>
using namespace std;
struct node{
	int data;
	node *prev = nullptr, *next = nullptr;
};
void PushFront(node *&head, int x, node *se[]);
void PushBack(node *&head, int x, node *se[]);
void Clear(node *&head, node *se[]);
void printList(node *head[], int n);
void cat(node *head[], int a, int b, node *se[][2]);
int main(){
	int n, m;
	cin >> n >> m;
	string str;
	node *nodes[n];
	node *se[n][2] = {nullptr};
	for(int i = 0; i < n; i++){
		nodes[i] = nullptr;
	}
	for(int i = 0; i < m; i++){
		cin >> str;
		int  a = 0, b = 0, x = 0;
		if(str == "PushFront"){
			cin >> a >> x;
			a--;
			PushFront(nodes[a], x, se[a]);
		}	
		else if(str == "PushBack"){
			cin >> a >> x;
			a--;
			PushBack(nodes[a], x, se[a]);
		}
		else if(str == "Clear"){
			cin >> a;
			a--;
			Clear(nodes[a], se[a]);
		}
		else if(str == "Concatenate"){
			cin >> a >> b;
			a--;
			b--;
			cat(nodes, a, b, se);
		}
	}
	printList(nodes, n);
	return 0;
}

void PushFront(node *&head, int x, node *se[]){
	if(head != nullptr){
		node *tmp = new node;
		tmp->data = x;
		tmp->next = head;
		head = tmp;
		se[0] = tmp;
	}
	else{
		head = new node;
		head->next = nullptr;
		head->prev = nullptr;
		head->data = x;
		se[0] = head;
		se[1] = head;
	}
}
void PushBack(node *&head, int x, node *se[]){
	if(head != nullptr){
		node *test = se[1];

		node *cur = new node;
		cur->data = x;
		cur->prev = test;
		cur->next = nullptr;
		test->next = cur;
		se[1] = cur;
	}
	else{
		head = new node;
		head->data = x;
		head->prev = nullptr;
		head->next = nullptr;
		se[1] = head;
		se[0] = head;
	}
}

void Clear(node *&head, node *se[]){
	while(1){
		if(head == nullptr){
			break;
		}
		node *pointer = head->next;
		delete head;
		head = pointer;
	}
	se[0] = nullptr;
	se[1] = nullptr;
}
void printList(node *head[], int n){
	for(int i = 0; i < n; i++){
		int num = i + 1;
		cout << num << ": ";
		int counter = 0;
		node *tmp = head[i];
		if(tmp != nullptr){
			for(tmp = head[i]; tmp->next != nullptr; tmp = tmp->next){
				cout << tmp->data << " ";
			}
			cout << tmp->data << endl;
		}
		else{
			cout << "Empty\n";
		}
	}
}


void cat(node *head[], int a, int b, node* se[][2]){
	node *tmpA = head[a];
	node *tmpB = head[b];
	if(tmpB != nullptr){
		tmpB = se[b][1];
		if(tmpA != nullptr){
			se[b][1]->next = head[a];
			se[b][1] = se[a][1];
			head[a] = nullptr;
		}
	}
	else{
		if(tmpA != nullptr){
			head[b] = head[a];
			se[b][0] = head[a];
			se[b][1] = se[a][1];
			head[a] = nullptr;
		}
	}
	Clear(head[a], se[a]);
}
