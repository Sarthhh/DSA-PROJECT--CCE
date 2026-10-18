#include <iostream>
using namespace std;

struct Node {
    int id;
    Node *left, *right;
    bool lt, rt;
};

Node* create(int id) {
    Node* n = new Node;
    n->id = id;
    n->left = n->right = NULL;
    n->lt = n->rt = true;
    return n;
}

Node* insert(Node* root, int id) {
    if (root == NULL)
        return create(id);

    Node* p = root;

    while (true) {
        if (id < p->id) {
            if (!p->lt)
                p = p->left;
            else {
                Node* n = create(id);
                n->left = p->left;
                n->right = p;
                p->left = n;
                p->lt = false;
                break;
            }
        }
        else if (id > p->id) {
            if (!p->rt)
                p = p->right;
            else {
                Node* n = create(id);
                n->right = p->right;
                n->left = p;
                p->right = n;
                p->rt = false;
                break;
            }
        }
        else {
            cout << "Duplicate Employee ID!\n";
            break;
        }
    }

    return root;
}

Node* leftMost(Node* p) {
    if (p == NULL)
        return NULL;

    while (!p->lt)
        p = p->left;

    return p;
}

Node* rightMost(Node* p) {
    if (p == NULL)
        return NULL;

    while (!p->rt)
        p = p->right;

    return p;
}

Node* successor(Node* p) {
    if (p->rt)
        return p->right;

    return leftMost(p->right);
}

Node* predecessor(Node* p) {
    if (p->lt)
        return p->left;

    return rightMost(p->left);
}

Node* search(Node* root, int id) {
    Node* p = root;

    while (p != NULL) {
        if (id == p->id)
            return p;

        if (id < p->id) {
            if (p->lt)
                return NULL;
            p = p->left;
        }
        else {
            if (p->rt)
                return NULL;
            p = p->right;
        }
    }

    return NULL;
}

void inorder(Node* root) {
    Node* p = leftMost(root);

    while (p != NULL) {
        cout << p->id << " ";
        p = successor(p);
    }
}

void preorder(Node* p) {
    if (p == NULL)
        return;

    cout << p->id << " ";

    if (!p->lt)
        preorder(p->left);

    if (!p->rt)
        preorder(p->right);
}

int main() {
    Node* root = NULL;
    int choice, id;

    do {
        cout << "\n\n--- Employee ID Directory ---";
        cout << "\n1. Insert Employee ID";
        cout << "\n2. Inorder Traversal";
        cout << "\n3. Find Predecessor and Successor";
        cout << "\n4. Preorder Traversal";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Employee ID: ";
            cin >> id;
            root = insert(root, id);
            break;

        case 2:
            cout << "Inorder Traversal: ";
            inorder(root);
            break;

        case 3: {
            cout << "Enter Employee ID: ";
            cin >> id;

            Node* p = search(root, id);

            if (p == NULL) {
                cout << "Employee ID not found!";
            }
            else {
                Node* pred = predecessor(p);
                Node* succ = successor(p);

                if (pred)
                    cout << "Predecessor: " << pred->id << endl;
                else
                    cout << "No Predecessor (First Employee)\n";

                if (succ)
                    cout << "Successor: " << succ->id << endl;
                else
                    cout << "No Successor (Last Employee)\n";
            }
            break;
        }

        case 4:
            cout << "Preorder Traversal: ";
            preorder(root);
            break;

        case 5:
            cout << "Program Ended.";
            break;

        default:
            cout << "Invalid Choice!";
        }

    } while (choice != 5);

    return 0;
}
