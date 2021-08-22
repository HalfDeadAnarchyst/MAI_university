#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

typedef struct Node Node;
struct Node {
    int value;
    Node *left;
    Node *right;
};
typedef struct Tree {
    Node *root;
    int count;
}Tree;

Tree *Create() {
    Tree *tree = (Tree*)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->count = 0;
    return tree;
}

void Insert(Tree *t) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    scanf("%d", &newNode->value);
    newNode->left = newNode->right = NULL;
    if (t->root == NULL) {
        t->root = newNode;
        t->count++;
    }
    else {
        Node *n = t->root;
        while (n!= NULL) {
            if (n->value < newNode->value)
                if (n->right != NULL)
                    n = n->right;
                else {
                    n->right = newNode;
                    t->count++;
                    break;
                }
            else
                if (n->value > newNode->value)
                    if (n->left != NULL)
                        n = n->left;
                    else {
                        n->left = newNode;
                        t->count++;
                        break;
                }
            if (n->value == newNode->value) break; 
        }
    }

}
void apply(Node *node, int d) {

    while (d != 0) {
        printf(" ");
        d--;
    }
    printf("%d\n", node->value);
}

void walk(Node *node, int depth) {
    if (node != NULL) {
        apply(node, depth);
        walk(node->left, depth + 1);
        walk(node->right, depth + 1);
    }
}

int Task(Node *node, int depth) {
    int result = 0;
    if (node != NULL) {
		if (node->value == depth) result += 1;
        Task(node->left, depth + 1);
        Task(node->right, depth + 1);
    }
	return result;
}

void Delete(Tree *t) {
    bool flag = 0;
    bool dir = 0;
    int del_val = 0;
    Node *k = t->root;
    scanf("%d", &del_val);
    if (t->root == NULL) printf("Tree is empty");
    else {
        Node *n = t->root;
        while (n != NULL) {
            if (n->value < del_val)
            {
                k = n;
                n = n->right;
                dir = 1;
            }
            else if (n->value > del_val)
            {
                k = n;
                n = n->left;
                dir = 0;
            }
            else if (n->value == del_val) { 
                if(del_val == t->root->value) flag = 1;
                if (n->left == NULL && n->right == NULL) { //у удаляемого узла нет детей
                    free(n);
                    n = NULL;
                    if(dir)
                        k->right = NULL;
                    else k->left = NULL;
                }
                else if (n->left != NULL && n->right != NULL) {
                    Node *savedNode;//в savedNode запоминаем элемент, который хотим удалить
                    savedNode = n;
                    k = n;
                    n = n->right;
                    dir = 1;
                    while (n->left != NULL) {
                        k = n;
                        n = n->left;
                        dir = 0;
                    }
                    savedNode->value = n->value;
                    free(n);
                    n = NULL;
                    if(!dir)
                        k->left = NULL;
                        else k->right = NULL;
                    
                }
                else if (n->left != NULL && n->right == NULL) {//есть только левое поддерево
                    Node *savedNode;
                    savedNode = n;
                    n = n->left;
                    while (n->right != NULL) {
                        k = n;
                        n = n->right;
                        dir = 1;
                    }
                    
                    savedNode->value = n->value;
                    free(n);
                    n = NULL;
                    if (flag){
                    k->left = NULL;
                    break;
                    }
                else if(dir)
                    k->right = NULL;
                    else k->left = NULL;
                }
                else if (n->right != NULL && n->left == NULL) {//есть только правое поддерево
                    Node *savedNode;
                    savedNode = n;
                    k = n;
                    n = n->right;
                    while (n->left != NULL) {
                        k = n;
                        n = n->left;
                        dir = 0;
                    }
                    savedNode->value = n->value;
                    free(n);
                    n = NULL;
                    if (flag){
                    k->right = NULL;
                    break;
                    }
                else if(!dir)
                    k->left = NULL;
                    else k->right = NULL;
                }
 
            }
        }
    }
}
/*
//For Delete func, recursive too.
Node* minimum(Node *n) {
	if (n->left == NULL)
		return n;
	return minimum(n->left);
}
 
//Delete func is searching and deleting node at all rules
void Delete(Node* DeleteNode, int value) { //It is recursive, be careful;
	if (DeleteNode == NULL) {
		printf("No such element\n");
		return;
	}
	if (value < DeleteNode->data) {
		Delete(DeleteNode->left, value);
	}
	else if (value > DeleteNode->data) {//Here i rly need commentaries. I'll add them later
		Delete(DeleteNode->right, value);
	}
	else if ((DeleteNode->left != NULL) && (DeleteNode->right != NULL)) {
		//Node* DDNode=(Node*)malloc(sizeof(Node));
		Node* ddNode = DeleteNode;
		DeleteNode = minimum(DeleteNode->right);//}?
		ddNode->data = DeleteNode->data;
		free(DeleteNode);
		printf("Succesfull. ");
		//Delete(DeleteNode->right, DeleteNode->right->data);
	}
	else if (DeleteNode->left != NULL) {
		DeleteNode = DeleteNode->left;
	}
	else {
		DeleteNode = DeleteNode->right;
	}//if left right null
}*/
int main(){
    setlocale(LC_ALL,"Russian");
    char ch = 'a';
	Tree* tree = Create();
    int var;
		printf("Ввод:\n1 - добавить элемент\n2 - удалить элемент\n3 - визуализация дерева\n4 - результат задания\n5 - показать это сообщение\n");
	while (ch != '0'){
		
		ch = getchar();
		if (ch == '0') break;
		if (ch == '1') Insert(tree);
		if (ch == '2'){
           // scanf("%d", &var);
             Delete(tree);
        }
		if (ch == '3'){
		    printf("Дерево: \n");
		walk(tree->root, 0);
		}
		if (ch == '4'){
			if (Task(tree->root, 0)==){
				printf("Результат: %d \n", Task(tree->root, 0));
			}
			else{
				printf("Результат: %d \n", Task(tree->root, 0)-1);
			}
		}
		if (ch == '5') printf("Информация \n");
	}
    return 0;
}
