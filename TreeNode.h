// TreeNode.h - заголовочный файл класса узла дерева
#ifndef TREENODE_H
#define TREENODE_H

// Класс представляет узел бинарного дерева
class TreeNode {
private:
    int _Value;         // Хранимое значение узла
    TreeNode* _Left;    // Указатель на левого потомка (nullptr если отсутствует)
    TreeNode* _Right;   // Указатель на правого потомка (nullptr если отсутствует)

public:
    // Конструктор создает узел с заданным значением
    // По умолчанию потомки инициализируются nullptr
    explicit TreeNode(int Val) : _Value(Val), _Left(nullptr), _Right(nullptr) {}
    
    // === Геттеры и сеттеры ===
    // Получение значения узла
    int GetValue() const {
        return _Value;
    }
    // Установка нового значения
    void SetValue(int Val) {
        _Value = Val;
    }

    // Получение левого потомка
    TreeNode* GetLeft() const { 
        return _Left;
    }
    // Установка левого потомка
    void SetLeft(TreeNode* Node) {
        _Left = Node;
    }

    // Получение правого потомка
    TreeNode* GetRight() const {
        return _Right;
    }
    // Установка правого потомка
    void SetRight(TreeNode* Node) {
        _Right = Node;
    }
};

#endif