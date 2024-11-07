#include "Printer.h" // Printer Ŭ���� ������ �����ϴ� ���

int main() {
    // InkJetPrinter ��ü�� �����ϰ� �ʱ�ȭ: �𵨸� "Officejet V40", ������ "HP", ���� 5��, ��ũ 10
    InkJetPrinter ink("Officejet V40", "HP", 5, 10);

    // LaserPrinter ��ü�� �����ϰ� �ʱ�ȭ: �𵨸� "SCX-6x45", ������ "�Ｚ����", ���� 3��, ��� 20
    LaserPrinter laser("SCX-6x45", "�Ｚ����", 3, 20);

    // ���� �۵� ���� ������ ���� ���
    cout << "���� �۵����� 2���� �����ʹ� �Ʒ��� ����" << endl;

    // InkJetPrinter ���� ���
    cout << "��ũ�� : ";
    ink.showInkJetPrinter();

    // LaserPrinter ���� ���
    cout << "������ : ";
    laser.showLaserPrinter();

    // ����ڷκ��� �Է� ���� ���� ����
    int printer, paper;
    char ch;

    // ���� ���� ����: ����ڰ� ���α׷��� ������ ������ ��� �ݺ�
    while (true) {
        // ����ڿ��� ������ ���ð� �ż�(�μ��� ������ ��)�� �Է¹���
        cout << endl << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
        cin >> printer >> paper;

        // �Էµ� ������ ��ȣ�� ���� �ش� �������� �μ� �޼��� ȣ��
        switch (printer) {
        case 1:
            ink.printInkJet(paper);  // ��ũ�� �����ͷ� �μ�
            break;
        case 2:
            laser.printLaser(paper); // ������ �����ͷ� �μ�
            break;
        default:
            cout << "�߸��� �Է��Դϴ�." << endl;  // 1 �Ǵ� 2 �̿��� �� �Է� �� ���� �޽��� ���
            break;
        }

        // �μ� �� �� �������� ���� ��� (���� ����, ��ũ/��� ����)
        ink.showInkJetPrinter();
        laser.showLaserPrinter();

        // ��� ����Ʈ���� ���� Ȯ��
        cout << "�Լ� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
        cin >> ch;

        // ����ڰ� 'n'�� �Է��ϸ� ���� ���� (���α׷� ����)
        if (ch == 'n') break;
    }

    return 0; // ���α׷� ����
}
