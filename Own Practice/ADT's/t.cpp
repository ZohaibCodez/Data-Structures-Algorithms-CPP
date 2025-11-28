#include <iostream>
using namespace std;

template<class T>
class Node {
public:
    T data;
    Node<T>* left;
    Node<T>* right;
    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

template<class T>
class BST {
private:
    Node<T>* root;

    void inOrderHelper(Node<T>* p);
    void preOrderHelper(Node<T>* p);
    void postOrderHelper(Node<T>* p);

    Node<T>* findMin(Node<T>* node);
    Node<T>* findMax(Node<T>* node);

    Node<T>* deleteNode(Node<T>* root, T node);

    int heightHelper(Node<T>* node);
    int countNodesHelper(Node<T>* node);
    int countLeafHelper(Node<T>* node);
    int countInternalHelper(Node<T>* node);

    void clearHelper(Node<T>* node);
    void mirrorHelper(Node<T>* node);

public:
    BST() : root(nullptr) {}

    void insert(T node);
    bool search(T node);

    void inOrder();
    void preOrder();
    void postOrder();

    void deleteMethod(T p);

    // Newly added functions
    T getMin();
    T getMax();
    int height();
    int countNodes();
    int countLeafNodes();
    int countInternalNodes();
    bool isEmpty();
    void clear();
    void mirror();
    T sumOfNodes();
    bool searchRecursive(T key);
    T findSuccessor(T key);
    T findPredecessor(T key);
    void rangeSearch(T low, T high);
    T sumHelper(Node<T>* node);
    void rangeSearchHelper(Node<T>* node, T low, T high);
    bool searchRecHelper(Node<T>* node, T key);
    
};

// -------------------------------------------------------------

template<class T>
void BST<T>::insert(T node) {
    Node<T>* newNode = new Node<T>(node);

    if (root == nullptr) {
        root = newNode;
        return;
    }

    Node<T>* current = root;
    Node<T>* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (node < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (node < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
}

// -------------------------------------------------------------

template<class T>
Node<T>* BST<T>::findMin(Node<T>* node) {
    while (node->left != nullptr)
        node = node->left;
    return node;
}

template<class T>
Node<T>* BST<T>::findMax(Node<T>* node) {
    while (node->right != nullptr)
        node = node->right;
    return node;
}

// -------------------------------------------------------------

template<class T>
Node<T>* BST<T>::deleteNode(Node<T>* root, T node) {
    if (root == nullptr)
        return root;

    if (node < root->data)
        root->left = deleteNode(root->left, node);
    else if (node > root->data)
        root->right = deleteNode(root->right, node);
    else {
        // case: one child or no child
        if (root->left == nullptr) {
            Node<T>* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node<T>* temp = root->left;
            delete root;
            return temp;
        }

        // case: two children
        Node<T>* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

template<class T>
void BST<T>::deleteMethod(T node) {
    root = deleteNode(root, node);
}

// -------------------------------------------------------------

template<class T>
bool BST<T>::search(T node) {
    Node<T>* current = root;

    while (current != nullptr) {
        if (current->data == node)
            return true;
        else if (node < current->data)
            current = current->left;
        else
            current = current->right;
    }
    return false;
}

// -------------------------------------------------------------

template<class T>
void BST<T>::inOrderHelper(Node<T>* p) {
    if (p != nullptr) {
        inOrderHelper(p->left);
        cout << p->data << " ";
        inOrderHelper(p->right);
    }
}

template<class T>
void BST<T>::inOrder() {
    inOrderHelper(root);
    cout << endl;
}

template<class T>
void BST<T>::preOrderHelper(Node<T>* p) {
    if (p != nullptr) {
        cout << p->data << " ";
        preOrderHelper(p->left);
        preOrderHelper(p->right);
    }
}

template<class T>
void BST<T>::preOrder() {
    preOrderHelper(root);
    cout << endl;
}

template<class T>
void BST<T>::postOrderHelper(Node<T>* p) {
    if (p != nullptr) {
        postOrderHelper(p->left);
        postOrderHelper(p->right);
        cout << p->data << " ";
    }
}

template<class T>
void BST<T>::postOrder() {
    postOrderHelper(root);
    cout << endl;
}

// -------------------------------------------------------------
// NEW FUNCTIONS BELOW
// -------------------------------------------------------------

template<class T>
T BST<T>::getMin() {
    if (root == nullptr) throw runtime_error("Tree is empty");
    return findMin(root)->data;
}

template<class T>
T BST<T>::getMax() {
    if (root == nullptr) throw runtime_error("Tree is empty");
    return findMax(root)->data;
}

// --------------------------- Height ---------------------------

template<class T>
int BST<T>::heightHelper(Node<T>* node) {
    if (node == nullptr) return -1;
    int leftH = heightHelper(node->left);
    int rightH = heightHelper(node->right);
    return 1 + max(leftH, rightH);
}

template<class T>
int BST<T>::height() {
    return heightHelper(root);
}

// ------------------------ Count Nodes -------------------------

template<class T>
int BST<T>::countNodesHelper(Node<T>* node) {
    if (node == nullptr) return 0;
    return 1 + countNodesHelper(node->left) + countNodesHelper(node->right);
}

template<class T>
int BST<T>::countNodes() {
    return countNodesHelper(root);
}

// ------------------------ Leaf Nodes --------------------------

template<class T>
int BST<T>::countLeafHelper(Node<T>* node) {
    if (node == nullptr) return 0;
    if (node->left == nullptr && node->right == nullptr) return 1;
    return countLeafHelper(node->left) + countLeafHelper(node->right);
}

template<class T>
int BST<T>::countLeafNodes() {
    return countLeafHelper(root);
}

// ------------------------ Internal Nodes ----------------------

template<class T>
int BST<T>::countInternalHelper(Node<T>* node) {
    if (node == nullptr || (node->left == nullptr && node->right == nullptr))
        return 0;
    return 1 + countInternalHelper(node->left) + countInternalHelper(node->right);
}

template<class T>
int BST<T>::countInternalNodes() {
    return countInternalHelper(root);
}

// ------------------------ Empty check -------------------------

template<class T>
bool BST<T>::isEmpty() {
    return root == nullptr;
}

// ------------------------ Clear Tree --------------------------

template<class T>
void BST<T>::clearHelper(Node<T>* node) {
    if (node == nullptr) return;
    clearHelper(node->left);
    clearHelper(node->right);
    delete node;
}

template<class T>
void BST<T>::clear() {
    clearHelper(root);
    root = nullptr;
}

// ----------------------- Mirror Tree --------------------------

template<class T>
void BST<T>::mirrorHelper(Node<T>* node) {
    if (node == nullptr) return;

    swap(node->left, node->right);

    mirrorHelper(node->left);
    mirrorHelper(node->right);
}

template<class T>
void BST<T>::mirror() {
    mirrorHelper(root);
}

// -------------------------------------------------------------

template<class T>
T BST<T>::sumHelper(Node<T>* node) {
    if (node == nullptr) return 0;
    return node->data + sumHelper(node->left) + sumHelper(node->right);
}

template<class T>
T BST<T>::sumOfNodes() {
    return sumHelper(root);
}


template<class T>
bool BST<T>::searchRecursive(T key) {
    return searchRecHelper(root, key);
}

template<class T>
bool BST<T>::searchRecHelper(Node<T>* node, T key) {
    if (node == nullptr) return false;
    if (node->data == key) return true;

    if (key < node->data)
        return searchRecHelper(node->left, key);
    else
        return searchRecHelper(node->right, key);
}
template<class T>
T BST<T>::findSuccessor(T key) {
    Node<T>* current = root;
    Node<T>* succ = nullptr;

    while (current != nullptr) {
        if (key < current->data) {
            succ = current;
            current = current->left;
        } else {
            current = current->right;
        }
    }
    if (succ == nullptr) throw runtime_error("No successor");
    return succ->data;
}
template<class T>
T BST<T>::findPredecessor(T key) {
    Node<T>* current = root;
    Node<T>* pred = nullptr;

    while (current != nullptr) {
        if (key > current->data) {
            pred = current;
            current = current->right;
        } else {
            current = current->left;
        }
    }
    if (pred == nullptr) throw runtime_error("No predecessor");
    return pred->data;
}
template<class T>
void BST<T>::rangeSearch(T low, T high) {
    rangeSearchHelper(root, low, high);
    cout << endl;
}

template<class T>
void BST<T>::rangeSearchHelper(Node<T>* node, T low, T high) {
    if (node == nullptr) return;

    if (low < node->data)
        rangeSearchHelper(node->left, low, high);

    if (low <= node->data && node->data <= high)
        cout << node->data << " ";

    if (high > node->data)
        rangeSearchHelper(node->right, low, high);
}


int main() {
    BST<int> obj;

    obj.insert(5);
    obj.insert(3);
    obj.insert(7);
    obj.insert(2);
    obj.insert(4);
    obj.insert(6);
    obj.insert(8);

    cout << "Inorder: ";
    obj.inOrder();

    cout << "Min: " << obj.getMin() << endl;
    cout << "Max: " << obj.getMax() << endl;

    cout << "Nodes: " << obj.countNodes() << endl;
    cout << "Leaves: " << obj.countLeafNodes() << endl;
    cout << "Internal: " << obj.countInternalNodes() << endl;

    cout << "Height: " << obj.height() << endl;

    cout << "Mirrored inorder: ";
    obj.mirror();
    obj.inOrder();

    return 0;
}
