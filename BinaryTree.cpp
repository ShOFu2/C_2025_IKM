// BinaryTree.cpp - реализация методов класса BinaryTree
#include "BinaryTree.h"
#include "TreeException.h"  // Для обработки исключений
#include <iostream> // Для вывода в консоль

using namespace std;

// Реализация метода построения дерева
void BinaryTree::BuildFromData(const vector<pair<int, string>>& Data) {
    // Обрабатываем каждую пару (значение, путь) из входных данных
    for (const auto& Item : Data) {
        int Value = Item.first;     // Извлекаем значение
        const string& Path = Item.second;   // Извлекаем путь

        TreeNode* Current = _Root;  // Начинаем с корня

        // Проходим по каждому символу пути
        for (char Direction : Path) {
            if (Direction == '0') { // Движение влево
                if (!Current->GetLeft()) {  // Если левого потомка нет
                    Current->SetLeft(new TreeNode(0));  // Создаем с временным значением 0
                }
                Current = Current->GetLeft(); // Переходим влево
            }
            else if (Direction == '1') {    // Движение вправо
                if (!Current->GetRight()) { // Если правого потомка нет
                    Current->SetRight(new TreeNode(0)); // Создаем с временным значением 0
                }
                Current = Current->GetRight();  // Переходим вправо
            }
            else {  // Недопустимый символ в пути
                throw TreeException("Неверный символ в пути: " + string(1, Direction));
            }
        }

        // Проверяем, не перезаписываем ли существующее значение
        if (Current->GetValue() != 0 && Current->GetValue() != Value) {
            throw TreeException("Конфликт путей для значения " + to_string(Value));
        }
        Current->SetValue(Value);   // Устанавливаем конечное значение
    }
}

// Реализация метода вывода дерева
void BinaryTree::Print() const {
    cout << "Бинарное дерево (боком):\n";
    _PrintTree(_Root, 0);   // Начинаем вывод с корня и нулевого уровня
}