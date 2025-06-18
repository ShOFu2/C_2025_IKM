// BinaryTree.h - заголовочный файл класса бинарного дерева
#include "TreeNode.h"   // Для работы с узлами
#include "TreeException.h" // Для обработки исключений
#include <vector>       // Для хранения входных данных
#include <iostream>      // Для вывода в консоль
#include <string>       // Для работы со строками

using namespace std;

class BinaryTree {
private:
    TreeNode* _Root;    // Указатель на корневой узел дерева

    // Рекурсивная функция для полной очистки дерева
    // Принимает: текущий узел для обработки
    void _Clear(TreeNode* Node) {
        if (Node) { // Если узел существует
            _Clear(Node->GetLeft());    // Рекурсивно очищаем левое поддерево
            _Clear(Node->GetRight());   // Рекурсивно очищаем правое поддерево
            delete Node;                // Удаляем текущий узел
        }
    }

    // Рекурсивная функция для глубокого копирования дерева
    // Принимает: узел для копирования
    // Возвращает: указатель на копию узла
    TreeNode* _Copy(TreeNode* Node) {
        if (!Node) {    // Базовый случай рекурсии
            return nullptr;
        }

        // Создаем новый узел с тем же значением
        TreeNode* NewNode = new TreeNode(Node->GetValue());

        // Рекурсивно копируем поддеревья
        NewNode->SetLeft(_Copy(Node->GetLeft()));
        NewNode->SetRight(_Copy(Node->GetRight()));

        return NewNode;
    }

    // Рекурсивная функция для вывода дерева
    // Принимает: текущий узел и уровень вложенности
    void _PrintTree(TreeNode* Node, int Level) const {
        if (!Node) {    // Базовый случай рекурсии
            return;
        }

        // Сначала правое поддерево (будет выше при выводе)
        _PrintTree(Node->GetRight(), Level + 1);

        // Вывод отступов и элементов для упрощения понимания дерева
        for (int i = 0; i < Level; i++) {
            if (i == Level - 1) {
                cout << "|-> ";
            }
            else {
                cout << "|   ";
            }
        }

        // Вывод значения узла
        cout << Node->GetValue();
        cout << endl;

        // Затем левое поддерево (будет ниже при выводе)
        _PrintTree(Node->GetLeft(), Level + 1);
    }

public:
    // Конструктор по умолчанию создает дерево с корнем = 0
    BinaryTree() : _Root(new TreeNode(0)) {}

    // Конструктор копирования (правило трех)
    BinaryTree(const BinaryTree& Other) {
        _Root = _Copy(Other._Root);  // Глубокое копирование
    }

    // Деструктор (правило трех)
    ~BinaryTree() {
        _Clear(_Root);  // Рекурсивное удаление всех узлов
    }

    // Оператор присваивания (правило трех)
    BinaryTree& operator=(const BinaryTree& Other) {
        if (this != &Other) {  // Защита от самоприсваивания
            _Clear(_Root);     // Очищаем текущее дерево
            _Root = _Copy(Other._Root); // Копируем новое дерево
        }
        return *this;
    }

    // Основной метод построения дерева из данных
    // Принимает: вектор пар (значение, путь)
    void BuildFromData(const vector<pair<int, string>>& Data);

    // Метод для вывода дерева в удобном формате
    void Print() const;
};