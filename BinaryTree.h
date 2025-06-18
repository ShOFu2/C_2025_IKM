// BinaryTree.h - ������������ ���� ������ ��������� ������
#include "TreeNode.h"   // ��� ������ � ������
#include "TreeException.h" // ��� ��������� ����������
#include <vector>       // ��� �������� ������� ������
#include <iostream>      // ��� ������ � �������
#include <string>       // ��� ������ �� ��������

using namespace std;

class BinaryTree {
private:
    TreeNode* _Root;    // ��������� �� �������� ���� ������

    // ����������� ������� ��� ������ ������� ������
    // ���������: ������� ���� ��� ���������
    void _Clear(TreeNode* Node) {
        if (Node) { // ���� ���� ����������
            _Clear(Node->GetLeft());    // ���������� ������� ����� ���������
            _Clear(Node->GetRight());   // ���������� ������� ������ ���������
            delete Node;                // ������� ������� ����
        }
    }

    // ����������� ������� ��� ��������� ����������� ������
    // ���������: ���� ��� �����������
    // ����������: ��������� �� ����� ����
    TreeNode* _Copy(TreeNode* Node) {
        if (!Node) {    // ������� ������ ��������
            return nullptr;
        }

        // ������� ����� ���� � ��� �� ���������
        TreeNode* NewNode = new TreeNode(Node->GetValue());

        // ���������� �������� ����������
        NewNode->SetLeft(_Copy(Node->GetLeft()));
        NewNode->SetRight(_Copy(Node->GetRight()));

        return NewNode;
    }

    // ����������� ������� ��� ������ ������
    // ���������: ������� ���� � ������� �����������
    void _PrintTree(TreeNode* Node, int Level) const {
        if (!Node) {    // ������� ������ ��������
            return;
        }

        // ������� ������ ��������� (����� ���� ��� ������)
        _PrintTree(Node->GetRight(), Level + 1);

        // ����� �������� � ��������� ��� ��������� ��������� ������
        for (int i = 0; i < Level; i++) {
            if (i == Level - 1) {
                cout << "|-> ";
            }
            else {
                cout << "|   ";
            }
        }

        // ����� �������� ����
        cout << Node->GetValue();
        cout << endl;

        // ����� ����� ��������� (����� ���� ��� ������)
        _PrintTree(Node->GetLeft(), Level + 1);
    }

public:
    // ����������� �� ��������� ������� ������ � ������ = 0
    BinaryTree() : _Root(new TreeNode(0)) {}

    // ����������� ����������� (������� ����)
    BinaryTree(const BinaryTree& Other) {
        _Root = _Copy(Other._Root);  // �������� �����������
    }

    // ���������� (������� ����)
    ~BinaryTree() {
        _Clear(_Root);  // ����������� �������� ���� �����
    }

    // �������� ������������ (������� ����)
    BinaryTree& operator=(const BinaryTree& Other) {
        if (this != &Other) {  // ������ �� ����������������
            _Clear(_Root);     // ������� ������� ������
            _Root = _Copy(Other._Root); // �������� ����� ������
        }
        return *this;
    }

    // �������� ����� ���������� ������ �� ������
    // ���������: ������ ��� (��������, ����)
    void BuildFromData(const vector<pair<int, string>>& Data);

    // ����� ��� ������ ������ � ������� �������
    void Print() const;
};