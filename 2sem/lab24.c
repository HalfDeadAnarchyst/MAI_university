#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//Stack part#########################################################################################################################################
typedef struct stack Stack;
typedef struct elem Elem;

struct stack {
    Elem* head;
    int size;
};

struct elem {
    char symbol;
    Elem* next;
};

//Functions for stack: Create, IsEmpty, top, push, pop
//Functions for stack - ready;

Stack *Create() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->size = 0;
    s->head = NULL;
    return s;
}

void push(Stack *S, char head) {
    Elem* el = (Elem*)malloc(sizeof(Elem));
    el->next = NULL;
    el->symbol = head;
    if (S->head == NULL) {
        S->head = el;
        S->size++;
    }
    else {
        el->next = S->head;
        S->head = el;
        S->size++;
    }
}

char pop(Stack *s) {
    if (s->head == NULL) {
        return -1;
    }
    Elem *el = s->head;
    s->head = s->head->next;
    s->size--;
    char symbol = el->symbol;
    free(el);
    return (symbol);
}

char top(Stack *s) {
    if (s->head == NULL) {
        //printf("Stack is empty \n");
    }
    else {
        //printf("%c\n", s->head->symbol);
    }
    return (s->head->symbol);
}

int IsEmpty(Stack *s) {
    if (s->head == NULL) {
        return 1;
    }
    else return 0;
}

int priority(char symbol) {
    switch (symbol) {
    case '^':
        return 4;
    break;
    case '*':
        return 3;
    break;
    case '/':
        return 3;
    break;
    case '+':
        return 2;
    break;
    case '-':
        return 2;
    break;
    case ')':
        return 1;
    break;
    case '(':
        return 0;
    break;
    default:
        return -1;
        printf("In func priority - exception\n");
    break;
    }
}

//Tree part##############################################################################################################################################
typedef struct tree Tree;
typedef struct node Node;
typedef struct ForTask Task;
//typedef struct LastNode Last;

struct node {
//    Node* head;
    Node* left;
    Node* right;
    char data;
};

struct tree {
    Node* root;
};

/*struct LastNode{
    Node* last;
};*/

//Functions todo:
//Insert -
//Visualisation	+
//Createtree; +
//Freetree?
Node* nodeCreate()
{
    Node* n = (Node*)malloc(sizeof(Node));
    n->left = NULL;
    n->right = NULL;
    return n;
}
Tree* CreateTree(){
    Tree *T = (Tree*)malloc(sizeof(Tree));
    T->root = nodeCreate();
    return T;
}

/*Last* CreateLast(){
    Last *L = (Last*)malloc(sizeof(Last));
    L->last = NULL;
    return L;
}*/



void Insert(Node *n, Stack *s)
    {
    if (IsEmpty(s))
        {
        n = NULL;
        return;
        }
        if ((top(s)=='-')||(top(s)=='+')||(top(s)=='*')||(top(s)=='/')||(top(s)=='^')) // если верхушка стека - оператор
        {
        n->data = top(s);
        pop(s);
        n->left = nodeCreate();
        n->right = nodeCreate();
        Insert(n->left, s);
        Insert(n->right, s);
        }
    else
    if (((1) && (1)) || ((0) && (1))) //(((top(s) >= 'a') && (top(s) <= 'z')) || ((top(s) >= '0') && (top(s) <= '9'))) // если верхушка стека - число
        {
        n->data = top(s);
        pop(s);
        }
}

/*void Insert(char symbol, Tree* t, Last* L){
    if (t->root==NULL) {
        Node* Node1=(Node*)malloc(sizeof(Node));
        Node1->head=NULL;
        Node1->right=NULL;
        Node1->left=NULL;
        Node1->data=symbol;
        t->root=Node1;
        L->last=Node1;
    }
    else if (L->last->right==NULL){
        Node* Node1=(Node*)malloc(sizeof(Node));
        Node1->head=L->last;
        Node1->right=NULL;
        Node1->left=NULL;
        Node1->data=symbol;
        if ((symbol=='-')||(symbol=='+')||(symbol=='*')||(symbol=='/')||(symbol=='^')){
            L->last->right=Node1;
        }
    }
    else if (L->last->left==NULL){
        Node* Node1=(Node*)malloc(sizeof(Node));
        Node1->head=L->last;
        Node1->right=NULL;
        Node1->left=NULL;
        Node1->data=symbol;
        if ((symbol=='-')||(symbol=='+')||(symbol=='*')||(symbol=='/')||(symbol=='^')){
            L->last->right=Node1;
        }
    }
    else{
            if(L->last=t->root){
                return;
            }
            else {
                L->last=L->last->head;
                Insert(symbol, t, L);
            }
        }
    return;
}*/

/*void visualisation(Node *cur, int depth) {
    int i;
    if (cur != NULL) {
        visualisation(cur->right, depth+1);
        for(i = 0; i < depth; ++i)
        printf(" ");
        printf("c\n", cur->data);
        visualisation(cur->left, depth+1);
    }
    else if (cur == NULL && depth == 0)
    printf("Empty\n");
}*/


void visualisation(Node *root, int n) {
    if (root->left != NULL) {
        n++;
        visualisation(root->left, n);
    }
    for (int i = 0; i <= n; i++)
        printf("    ");
    printf("%c \n", root->data);
    if (root->right != NULL) {
        n++;
        visualisation(root->right, n);
    }
}

struct ForTask{
    Node* First;
    Node* Second;
    Node* Char;
};

Task* CreateTask(){
    Task *T=(Task*)malloc(sizeof(Task));
    T->First=NULL;
    T->Second=NULL;
    return T;
}

void MyTask(Node* cur){
    //Checking that node is * and have - and char at sides.
    if ((cur->data=='*')&&((cur->left->data=='-')&&(((cur->right->data>= 'a')&&(cur->right->data<= 'z'))||((cur->right->data>= '0')&&(cur->right->data)<= '9')))||((cur->right->data=='-')&&(((cur->left->data>= 'a')&&(cur->left->data<= 'z'))||((cur->left->data>= '0')&&(cur->left->data)<= '9'))))
	{
        Task *T=CreateTask(); //Taking info
        if (cur->left->data=='-')
        {
            T->First=cur->left->left;
            T->Second=cur->left->right;
            T->Char=cur->right;
        }
        if (cur->right->data=='-')
        {
            T->First=cur->right->left;
            T->Second=cur->right->right;
            T->Char=cur->left;
        }
        //Changing paths
        cur->data='-';
        cur->left->data='*';
        cur->right->data='*';
        cur->left->left=T->Char;
        cur->left->right=T->First;
        cur->right->left=T->Char;
        cur->right->right=T->Second;
        free(T);
    }//Calling for left'n'right brunchees
    if(cur->right!=NULL){
        MyTask(cur->right);
    }
    if(cur->left!=NULL){
        MyTask(cur->left);
    }
}

int main() {
    char string[80];
    int i = 0;
    scanf("%s", string);
    Stack *res = Create();
    Stack *temp = Create();
    while ((string[i] != '\0')) {//КОНЕЦ СТРОКИ/ФАЙЛА. Вспомни.
        //printf("%c", string[i]);
        if ((string[i] >= 'a'&&string[i] <= 'z') || (string[i] >= '0'&&string[i] <= '9')) {
            push(res, string[i]);
        }
        else if (string[i] == ')') {
            while (top(temp) != '(') {
                push(res, pop(temp));
            }
            pop(temp);
        }
        else if ((string[i] == '*') || (string[i] == '/') || (string[i] == '+') || (string[i] == '-') || (string[i] == '^') || (string[i] == '(')) {
            if (IsEmpty(temp) == 1) {
                push(temp, string[i]);
            }
            else {
                if (priority(top(temp)) > priority(string[i])) {
                    push(res, pop(temp));
                }
                push(temp, string[i]);
            }
        }
        i++;
    }
    //printf("\n###########################\n");
    while (!IsEmpty(temp)) {
        push(res, pop(temp));
    }
  /*if (i>4){
        pop(res);
    }*/
    free(temp);
    /*while (!IsEmpty(res)) {
        top(res);
        pop(res);
    }*/
    //printf("Stack is ready\n");
    //Результрующий стек получен
    //Делаем дерево

    Tree* t = CreateTree();
    //Last* L = CreateLast();
    while (!IsEmpty(res)) {
        Insert(t->root, res);
    }
    free(res);
    printf("    ");
    visualisation(t->root, 0);
    printf("/n####################/n");
    MyTask(t->root);
    visualisation(t->root, 0);
}
