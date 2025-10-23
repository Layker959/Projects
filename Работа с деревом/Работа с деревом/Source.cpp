//1
#include <iostream>
#include <queue>
using namespace std;

struct Node //Структура узлов
{
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

int main() 
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Дерево создано
    return 0;
}
//2
int countNodes(Node* root) //Функция подсчитывает количество узлов в дереве
{
    if (root == nullptr) 
    {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}
//3
Node* searchValue(Node* root, int value) //Выполняет поиск значения в дереве, начиная с корня
{
    if (root == nullptr || root->data == value) 
    {
        return root;
    }

    Node* leftSearch = searchValue(root->left, value);
    Node* rightSearch = searchValue(root->right, value);

    return leftSearch ? leftSearch : rightSearch;
}
//4
void DFS(Node* root) //Обходит дерево в глубину, начиная с корня
{
    if (root == nullptr) 
    {
        return;
    }

    cout << root->data << " ";
    DFS(root->left);
    DFS(root->right);
}
//5
//#include <queue>

void BFS(Node* root) //Реализует обход дерева в ширину с использованием очереди
{
    if (root == nullptr) 
    {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) 
    {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left) 
        {
            q.push(current->left);
        }
        if (current->right) 
        {
            q.push(current->right);
        }
    }
}
//6
void deleteTree(Node* root) //Удаляет все узлы дерева, освобождая выделенную память для каждого узла
{
    if (root == nullptr) 
    {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}
//7
bool isMirror(Node* leftSubtree, Node* rightSubtree) //Сравнивает левую и правую части дерева относительно центра
{
    if (leftSubtree == nullptr && rightSubtree == nullptr) 
    {
        return true;
    }

    if (leftSubtree == nullptr || rightSubtree == nullptr) 
    {
        return false;
    }

    return (leftSubtree->data == rightSubtree->data) &&
        isMirror(leftSubtree->left, rightSubtree->right) &&
        isMirror(leftSubtree->right, rightSubtree->left);
}

bool isSymmetric(Node* root) //Проверяет, является ли дерево симметричным
{
    if (root == nullptr) 
    {
        return true;
    }

    return isMirror(root->left, root->right);
}
