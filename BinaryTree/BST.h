#include <vector>
class BST {
public:
	BST() {};
	BST(std::vector<int>);
	void insert(int);
	void del(int);
	bool search(int);
	void print();
private:

	struct Node {
		int val;
		Node* r, * l;
		Node(int v) :val(v), r(nullptr), l(nullptr) {}
		Node(Node* tmp) :val(tmp->val), r(tmp->r), l(tmp->l) {}
	};
	Node** head = nullptr;
	Node* root = nullptr;
	Node* mostLeft(Node*);
	Node* mostRight(Node*);
};