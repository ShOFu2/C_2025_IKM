// TreeNode.h - ������������ ���� ������ ���� ������
#ifndef TREENODE_H
#define TREENODE_H

// ����� ������������ ���� ��������� ������
class TreeNode {
private:
    int _Value;         // �������� �������� ����
    TreeNode* _Left;    // ��������� �� ������ ������� (nullptr ���� �����������)
    TreeNode* _Right;   // ��������� �� ������� ������� (nullptr ���� �����������)

public:
    // ����������� ������� ���� � �������� ���������
    // �� ��������� ������� ���������������� nullptr
    explicit TreeNode(int Val) : _Value(Val), _Left(nullptr), _Right(nullptr) {}
    
    // === ������� � ������� ===
    // ��������� �������� ����
    int GetValue() const {
        return _Value;
    }
    // ��������� ������ ��������
    void SetValue(int Val) {
        _Value = Val;
    }

    // ��������� ������ �������
    TreeNode* GetLeft() const { 
        return _Left;
    }
    // ��������� ������ �������
    void SetLeft(TreeNode* Node) {
        _Left = Node;
    }

    // ��������� ������� �������
    TreeNode* GetRight() const {
        return _Right;
    }
    // ��������� ������� �������
    void SetRight(TreeNode* Node) {
        _Right = Node;
    }
};

#endif