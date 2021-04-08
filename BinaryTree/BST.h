#include <vector>
template<typename T> class BST {
public:
	BST() {};
	BST(std::vector<T>);
	void insert(T);
	void del(T);
	bool search(T);
	void print();
private:

	struct Node {
		T val;
		Node* r, * l;
		Node(T v) :val(v), r(nullptr), l(nullptr) {}
		Node(Node* tmp) :val(tmp->val), r(tmp->r), l(tmp->l) {}
	};
	Node** head = nullptr;
	Node* root = nullptr;
	Node* minimum(Node*);
	Node* maximum(Node*);
};