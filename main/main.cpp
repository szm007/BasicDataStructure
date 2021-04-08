#include <iostream>
#include <vector>
#include "../BinaryTree/BST.cpp"
#include "../Algorithm/SortFunc.cpp"
using namespace std;

int main()
{
	BST<int> bst({ 2,3,4,5 });
	bst.insert(67);
	bst.del(3);
	bst.print();
}