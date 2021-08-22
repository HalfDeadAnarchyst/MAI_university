#include <stdio.h>
#include <stdlib.h>
typedef struct node Node;
typedef struct tree Tree;
 
 
struct node {
	float data;
	Node *left;
	Node *right;
};
 
struct tree {
	Node *root;
};
 
void CreateTree(Tree **T) {
	*T = (Tree*)malloc(sizeof(Tree));
	(*T)->root = NULL;
}
 
void Insert(Node **srcNode, float value) {
	if (*srcNode == NULL) {
		Node* NewNode=(Node*)malloc(sizeof(Node));
		NewNode->data=value;
		NewNode->left=NewNode->right=NULL;
		*srcNode = NewNode;
		printf("Succesfull. ");
		return;
	}
	else if (value<(*srcNode)->data) {
		Insert(&(*srcNode)->left, value);
	}
	else if (value>(*srcNode)->data) {
		Insert(&(*srcNode)->right, value);
	}
	else if (value==(*srcNode)->data) {
	printf("This element already exist\n");
	return;
	}
}
 
//It's non-recursive, maybe i need this
/*void Insert (Node *NewNode, Tree *Tree){
	NewNode=(Node*)malloc(sizeof(Node));
	NewNode->left=NewNode->right=NULL;
	scanf("%f", &NewNode->data);
	if (Tree->root==NULL){
		Tree->root=NewNode;
	}
	else{
		Node *TimeNode = Tree->root;
		while (TimeNode!=NULL) {
			if (TimeNode->data > NewNode->data) //Situiation1
				if (TimeNode->right!=NULL)
					TimeNode=TimeNode->right;
				else {
					TimeNode->right=NewNode;
					break;
				}
			else //Situation2
			if (TimeNode->data < NewNode->data)
				if (TimeNode->left!=NULL)
					TimeNode=TimeNode->left;
				else {
					TimeNode->left=NewNode
					break;
				}
			else if (TimeNode->data == NewNode->data){
				break;//SItuatuion3printf("Please enter a new command \n");
			}
		}
	free(TimeNode);
	}
}*/
 
void apply(Node *node, int d) {
	while (d!=0) {
		printf(" ");
		d--;
	}
}

void walk (Node *node, int depth) {
	if (node != NULL) {
		apply(node, depth);
		walk(node->left, depth+1);
		walk(node->right, depth+1);
	}
}

//For Delete func, recursive too.
Node* minimum(Node *n) {
	if (n->left == NULL)
		return n;
	return minimum(n->left);
}
 
//Delete func is searching and deleting node at all rules
void Delete(Node* DeleteNode, float value) { //It is recursive, be careful;
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
}

int Specialtask(Node* CurrentNode, int brunches){
	if (brunches==0) {
		if ((CurrentNode->left)&&(CurrentNode->right)==NULL) {
			return 1;
		}
		else if (CurrentNode->left!=NULL) {
			brunches=1;
			if (Specialtask(CurrentNode->left, brunches)==1) {
				return 1;}
			else {return 0;}
		}
		else if (CurrentNode->right!=NULL) {
			brunches=1;
			if (Specialtask(CurrentNode->right, brunches)==1) {
				return 1;}
			else {return 0;}
		}
		else {
			brunches=2;
			if((Specialtask(CurrentNode->left, brunches)==1)&&(Specialtask(CurrentNode->right, brunches)==1)) {
				return 1;}
			else {return 0;}
		}
	}
//1 brunch
	else if (brunches==1) {
		if ((CurrentNode->left)&&(CurrentNode->right)==NULL) {
			return 1;
		}
		else if (CurrentNode->left!=NULL) {
			if(Specialtask(CurrentNode->left, brunches)==1){
				return 1;}
			else {return 0;}
		}
		else if (CurrentNode->right!=NULL) {
			if(Specialtask(CurrentNode->right, brunches)==1){
				return 1;}
			else {return 0;}
		}
		else {
			return 0;
		}
	}
//2 brunches
	else {
		if ((CurrentNode->left)&&(CurrentNode->right)==NULL) {
			return 1;
		}
		else if (CurrentNode->left!=NULL) {
			return 0;
		}
		else if (CurrentNode->right!=NULL) {
			return 0;
		}
		else {
			if ((Specialtask(CurrentNode->left, brunches)==1)&&(Specialtask(CurrentNode->right, brunches)==1)){
				return 1;}
			else {return 0;}
		}
	}
return 2;
}

//Availible functions CreateTree, Insert, Delete, Walk (minimum, apply). Struct tree and node
int main() {
	Tree* Treeee;
	CreateTree(&Treeee);
	int i;
	float value;
	printf("Press 1 to add element, press 2 to delete element, \n");
	printf("Press 3 to show tree, press 4 for special task, \n press 5 to show this message again, press 0 to exit\n");
	while(i!=0){
		printf("Please enter a new command \n");
		scanf("%d", &i);
		switch(i) {
		case 1:
			printf("Please enter an element \n");
			scanf("%f", &value);
			Insert(&Treeee->root, value);
		break;
		case 2:
			printf("Please enter an element \n");
			scanf("%f", &value);
			Delete(Treeee->root, value);
		break;
		case 3:
			walk(Treeee->root, 0);
		break;
		case 4:
			printf("This is not a working function yet. Please contact the developers \n");
			if (Specialtask(Treeee->root, 0)==0) {
				printf("Tree width grow isn't monotonic\n");
			}
			else if (Specialtask(Treeee->root, 1)==0){
				printf("Tree width grow is monotonic\n");
			}
			else printf("exception\n");
		break;
		case 5:
			printf("Press 1 to add element, press 2 to delete element, \n");
			printf("Press 3 to show tree, press 4 for special task, \n press 5 to show this message again, press 0 to exit\n");
		break;
		case 0:
			return 0;
		break;
		default:
			printf("Here is no such menu, please enter another number\n");
		break;
		}
	}
}
  


























