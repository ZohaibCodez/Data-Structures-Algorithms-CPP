#include "BST.h"

int main()
{
	BST<int> obj;
	obj.insert(5);
	obj.insert(3);
	obj.insert(7);	
	obj.insert(2);
	obj.insert(4);
	obj.insert(6);
	obj.insert(8);
	
	obj.inOrder();
	obj.preOrder();
	obj.postOrder();
    
 	obj.deleteMethod(2);;
 	
 	obj.inOrder();

	return 0;
}