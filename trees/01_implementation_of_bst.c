#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* right;
	struct node* left;
};


struct node* new_node(int data){
	struct node* temp = (struct node*)malloc(sizeof(struct node*));
	temp -> data = data;
	temp -> left = NULL;
	temp -> right = NULL;
	return temp;
	
}
struct node* insert(struct node* node, int data){
	//if the tree is empty create a root node using new_node()
	if(node == NULL){
		return new_node(data);
	}
	if(data < node -> data){
		node -> left = insert(node -> left, data);
	}
	else if(data > node -> data){
		node -> right = insert(node -> right, data);
	}

	return node;
}
void print_tree(struct node* root){ //inorder traversal
	if(root == NULL) return;
	print_tree(root -> left);
	printf("IN %d \n", root->data);
	print_tree(root -> right);
	
}

void pre_order(struct node* root){
	if(root == NULL) return; 
	printf("PRE %d \n", root->data);
	pre_order(root->left);
	pre_order(root->right);
	
			
}

void post_order(struct node* root){
	if(root == NULL) return;
	post_order (root -> left);
	post_order (root -> right);
	printf("POST %d \n", root -> data);
}



int get_max(struct node* root){
	if(root->right == NULL){
		return root -> data;
	}
	return get_max(root -> right);
}

int get_min(struct node* root){
	if(root->left == NULL){
		return root -> data;
	}
	return get_min(root -> left);
}

int find_height(struct node* root){
	int left_subtree,right_subtree;
	if(root == NULL){return -1;}
	
	left_subtree = find_height(root -> left);
	right_subtree = find_height(root -> right);
		
	if(left_subtree >= right_subtree){return left_subtree + 1;}
	else {return right_subtree +1;}		
	
}


int is_bst_util(struct node* root, int min_val, int max_val){
	if(root == NULL){
		return 1;
	}
	if (root -> data < min_val 
			&& root -> data > max_val 
			&& is_bst_util(root -> left, min_val, root -> data 
			&& is_bst_util(root -> right, root -> data, max_val))){
		return 1;
	}
	else{
		return 0;
	}
}

int is_bst(struct node* root){
	return is_bst_util(root, get_min(root), get_max(root));
}

//deletion
struct node* delete(struct node* root, int data){
	if(root == NULL) return root;
	// if the data we are trying to remove is lesser than root it is in left subtree
	else if(data < root -> data) root -> left = delete(root -> left, data);
	// if the data we are trying to remove is greater than root it is in right subtree
	else if(data > root -> data) root -> right = delete(root -> right,data);

	else{
		// case1 : leaf node (no child).
		if(root -> left == NULL && root -> right == NULL ){
			free(root);
			root = NULL;
		}
		// case2 : target node has one child
		else if (root -> left == NULL){
			struct node* temp = root;
			root = root -> right;
			free(temp);
		}
		else if (root -> right == NULL){
			struct node * temp = root;
			root = root -> left;
			free(temp);
		}

		// case3 target node has 2 children
		else {
			struct node* temp = NULL;
			temp -> data = get_min(root -> right);
			root -> data = temp -> data;
			root -> right = delete(root -> right, temp -> data);
		}
	}
	return root;
}

int main(){
	struct node* root = NULL;
	root = insert(root, 50);
	insert(root, 30); 
	insert(root, 20); 
        insert(root, 40); 
        insert(root, 70); 
        insert(root, 60); 
        insert(root, 80);
       	insert(root, 100);

	printf("Max : %d \n", get_max(root));
	printf("Min : %d \n", get_min(root));
  	printf("Height : %d \n", find_height(root));

	delete(root, 100);
	delete(root, 40);

	print_tree(root);
	pre_order(root);
	post_order(root);

	if (is_bst(root) == 1){
		printf("tree is binary search tree. \n");
	}
	else{
		printf("tree is NOT binary search tree. \n");
	}

	


}
