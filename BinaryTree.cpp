// BinaryTree.cpp - ���������� ������� ������ BinaryTree
#include "BinaryTree.h"
#include "TreeException.h"  // ��� ��������� ����������
#include <iostream> // ��� ������ � �������

using namespace std;

// ���������� ������ ���������� ������
void BinaryTree::BuildFromData(const vector<pair<int, string>>& Data) {
    // ������������ ������ ���� (��������, ����) �� ������� ������
    for (const auto& Item : Data) {
        int Value = Item.first;     // ��������� ��������
        const string& Path = Item.second;   // ��������� ����

        TreeNode* Current = _Root;  // �������� � �����

        // �������� �� ������� ������� ����
        for (char Direction : Path) {
            if (Direction == '0') { // �������� �����
                if (!Current->GetLeft()) {  // ���� ������ ������� ���
                    Current->SetLeft(new TreeNode(0));  // ������� � ��������� ��������� 0
                }
                Current = Current->GetLeft(); // ��������� �����
            }
            else if (Direction == '1') {    // �������� ������
                if (!Current->GetRight()) { // ���� ������� ������� ���
                    Current->SetRight(new TreeNode(0)); // ������� � ��������� ��������� 0
                }
                Current = Current->GetRight();  // ��������� ������
            }
            else {  // ������������ ������ � ����
                throw TreeException("�������� ������ � ����: " + string(1, Direction));
            }
        }

        // ���������, �� �������������� �� ������������ ��������
        if (Current->GetValue() != 0 && Current->GetValue() != Value) {
            throw TreeException("�������� ����� ��� �������� " + to_string(Value));
        }
        Current->SetValue(Value);   // ������������� �������� ��������
    }
}

// ���������� ������ ������ ������
void BinaryTree::Print() const {
    cout << "�������� ������ (�����):\n";
    _PrintTree(_Root, 0);   // �������� ����� � ����� � �������� ������
}