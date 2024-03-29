#include<bits/stdc++.h>

using namespace std;   

struct Node {
	int data;
	Node* left;
	Node* right;
	int cnt;

	Node(int data) {
		this->data = data;
		left = nullptr;
		right = nullptr;
		cnt = 1;
	} 
};

Node* getMin(Node* root) {
	while (root->left != nullptr) {
		root = root->left;
	}
	return root;
}

Node* add(Node* root, int data) {
	if (root == nullptr) {
		return new Node(data);
	} else if (root->data > data) {
		if (root->left == nullptr) {
			root->left = new Node(data);
		} else {
			root->left = add(root->left, data);
		}
	} else if (root->data < data) {
		if (root->right == nullptr) {
			root->right = new Node(data);
		} else {
			root->right = add(root->right, data);
		}
	}
	else if(root -> data == data){
		root -> cnt++;
	}
	return root;
}

Node* deleteNode(Node* root, int data) {
	if (root == NULL) {
		return NULL;
	} else if (root->data > data) {
		root->left = deleteNode(root->left, data);
		return root;
	} else if (root->data < data) {
		root->right = deleteNode(root->right, data);
		return root;
	} else {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		} else if (root->right == NULL) {
			Node* temp = root->left;
			delete root;
			return temp;
		} else if (root->left == NULL) {
			Node* temp = root->right;
			delete root;
			return temp;
		} else {
			Node* temp = getMin(root->right);
			root->data = temp->data;
			root -> cnt = temp -> cnt;
			root->right = deleteNode(root->right, temp->data);
			return root;
		}
	}
}

Node* find(Node* root, int x) {
	if (root == NULL) {
		return nullptr;
	} else if (root->data == x) {
		return root;
	} else if (root->data < x) {
		return find(root->right, x);
	} else {
		return find(root->left, x);
	}
}

int main(){
	Node * root = nullptr;
	int n; cin >> n;
	for(int i= 0; i < n; i++){
		string query; int num;
		cin >> query >> num;
		if(query == "insert"){
			root = add(root, num);
		}
		else if(query == "delete"){
			Node * need = find(root, num);
			if(need != nullptr && need -> cnt == 1) root = deleteNode(root, num);
			else if(need != nullptr) find(root, num) -> cnt--;
		}
		else if(query == "cnt"){
			Node * need = find(root, num);
			if(need == nullptr) cout << 0 << endl;
			else cout << need -> cnt << endl;
		}
	} 
}