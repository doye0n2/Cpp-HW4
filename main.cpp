// main.cpp
#include "Printer.h"  // Printer.h ��� ������ �����Ͽ� Printer Ŭ������ �� �Ļ� Ŭ������ ����� �� �ֵ��� ��
#include <iostream>    // ǥ�� ����� ����� ����ϱ� ���� iostream ���̺귯�� ����

using namespace std;   // std ���ӽ����̽��� ����Ͽ� ǥ�� ���̺귯�� �Լ��� ��ü���� ���� ���

int main() {  // ���α׷� ������ �������� main �Լ� ����
    // InkjetPrinter�� LaserPrinter ��ü ����, ���� ��ũ���� ������ �����͸� ��Ÿ��
    InkjetPrinter inkjet("Officejet V40", "HP", 5, 10);  // ��ũ�� ������ ��ü ����, 5�� ����, 10 ��ũ
    LaserPrinter laser("SCX-6x45", "�Ｚ����", 3, 20);  // ������ ������ ��ü ����, 3�� ����, 20 ���

    // ���� �۵� ���� ������ ���� ���
    cout << "���� �۵����� 2���� �����ʹ� �Ʒ��� ����" << endl;

    // ��ũ�� ������ ���� ���
    cout << "��ũ�� : ";
    inkjet.showStatus();  // inkjet ��ü�� ���¸� ����ϴ� showStatus �Լ� ȣ��

    // ������ ������ ���� ���
    cout << "������ : ";
    laser.showStatus();  // laser ��ü�� ���¸� ����ϴ� showStatus �Լ� ȣ��

    int printerType, pages;  // ������ ���ð� �μ��� ������ ���� ������ ���� ����
    char continuePrinting;   // ��� �μ����� ���θ� ���� ����

    do {  // do-while ���� ����, ����ڰ� 'y' �Ǵ� 'Y'�� �Է��� ������ �ݺ�
        // ������ Ÿ�԰� �μ��� ������ ���� �Է¹���
        cout << "\n������ (1: ��ũ��, 2: ������)�� �ż� �Է�>> ";
        cin >> printerType >> pages;  // ������ Ÿ�԰� ������ �� �Է� �ޱ�

        if (printerType == 1) {  // ��ũ�� ������ ���� ��
            inkjet.print(pages);  // ��ũ�� �����ͷ� �μ�, �μⰡ �����ϸ� �ڿ� ����
        }
        else if (printerType == 2) {  // ������ ������ ���� ��
            laser.print(pages);  // ������ �����ͷ� �μ�, �μⰡ �����ϸ� �ڿ� ����
        }
        else {  // �߸��� ������ Ÿ�� �Է� ��
            cout << "�߸��� ������ �����Դϴ�.\n";  // ���� �޽��� ���
        }

        // �� �������� ���¸� ���
        inkjet.showStatus();  // ��ũ�� ������ ���� ���
        laser.showStatus();   // ������ ������ ���� ���

        // ��� ����Ʈ���� ���� ����
        cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)? ";
        cin >> continuePrinting;  // ����ڷκ��� ������� ���� �Է� �ޱ�
        cout << "\n";  // ��� ������ ���� ���� �߰�
    } while (continuePrinting == 'y' || continuePrinting == 'Y');  // 'y' �Ǵ� 'Y'�� �Է��ϸ� ��� �ݺ�

    return 0;  // ���α׷� ����
}
