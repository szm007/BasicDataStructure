#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include "BST.h"

// init a bst from a list
template<typename T> BST<T>::BST (std::vector<T> vt) {
	if (vt.empty())
		return;
	auto it = vt.begin();
	while (it != vt.end()) {
		insert(*it);
		it++;
	}
}
// insert a node into bst
template<typename T> void BST<T>::insert(T target) {
	//insert the 1st node
	if (root == nullptr) {
		root = new Node(target);
		head = &root;
		return;
	}
	Node* cur = root,*pre=nullptr;
	while (cur != nullptr && cur->val != target) {
		pre = cur;
		if (cur->val > target)
			cur = cur->l;
		else
			cur = cur->r;
	}
	if (cur != nullptr) {
		std::cout << "Existed" << std::endl;
		return;
	}
	cur = new Node(target);
	if (pre->val > target)
		pre->l = cur;
	else
		pre->r = cur;
}
template<typename T> void BST<T>::del(T target) {
	Node* cur = root, * pre = nullptr;
	while (cur != nullptr && cur->val != target) {
		pre = cur;
		if (cur->val > target)
			cur = cur->l;
		else
			cur = cur->r;
	}
	if (cur == nullptr) {
		std::cout << "Not found "<< target << std::endl;
		return;
	}
	// delete leaf node
	if (cur->l == nullptr && cur->r == nullptr) {
		if (pre == nullptr) {
			head = nullptr;
			root = nullptr;
		}
		else {
			if (pre->val > cur->val)
				pre->l = nullptr;
			else
				pre->r = nullptr;
		}
		delete(cur);
	}
	// delete a node with left child
	else if (cur->l != nullptr && cur->r == nullptr) {
		if (pre == nullptr) {
			root = cur->l;
			head = &root;
		}
		else {
			if (pre->val > cur->val)
				pre->l = cur->l;
			else
				pre->r = cur->l;
		}
		delete(cur);
	}
	// delete a node with right child
	else if (cur->r != nullptr && cur->l == nullptr) {
		if (pre == nullptr) {
			root = cur->r;
			head = &root;
		}
		else {
			if (pre->val > cur->val)
				pre->l = cur->r;
			else
				pre->r = cur->r;
		}
		delete(cur);
	}
	// delete a nodde with two children
	else {
		Node* tmp = new Node(minimum(cur->r));
		del(tmp->val);
		tmp->l = cur->l;
		if(cur->r!=tmp)
			tmp->r = cur->r;
		if (pre == nullptr) {
			root = tmp;
			head = &root;
		}
		else {
			if (pre->val > cur->val)
				pre->l = tmp;
			else
				pre->r = tmp;
		}
		delete(cur);
	}
	

}
// find the most left child of top
template<typename T> typename BST<T>::Node* BST<T>::minimum(Node* top) {
	Node *cur = top;
	while (cur->l != nullptr)
		cur = cur->l;
	return cur;
}
// find the most right child of top
template<typename T> typename BST<T>::Node* BST<T>::maximum(Node* top) {
	Node* cur = top;
	while (cur->r != nullptr)
		cur = cur->r;
	return cur;
}
// print  bst order by asc
template<typename T> void BST<T>::print() {
	if (root == nullptr)
		return;
	std::stack<Node*> st;
	std::set<Node*> visited;
	st.push(root);
	visited.insert(root);
	while (!st.empty()) {
		Node *cur = st.top();
		if (cur->l != nullptr && visited.find(cur->l) == visited.end()) {
			st.push(cur->l);
			visited.insert(cur->l);
		}
		else {
			std::cout << cur->val << ' ';
			st.pop();
			if (cur->r != nullptr && visited.find(cur->r) == visited.end()) {
				st.push(cur->r);
				visited.insert(cur->r);
			}
		}
	}
}
// find if target in bst or not
template<typename T> bool BST<T>::search(T target) {
	Node *cur = root;
	while (cur != nullptr && cur->val != target) {
		if (cur->val > target)
			cur = cur->l;
		else
			cur = cur->r;
	}
	return cur != nullptr;
}