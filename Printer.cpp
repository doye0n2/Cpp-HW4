#include "Printer.h" // Printer Ŭ���� ������ �����ϴ� ���

// Printer Ŭ������ ������
Printer::Printer(string mo, string me, int a)
    : model(mo), manufacturer(me), availableCount(a), printedCount(0) {}  // ��, ������, ���� ���� �ʱ�ȭ

// ���� ���� ������� Ȯ���ϴ� �Լ�
bool Printer::isValidPrint(int pages) const {
    return availableCount >= pages;  // ���� ���� �Էµ� ������ �� �̻��� ��� true ��ȯ
}

// �μ��ϴ� �Լ�
void Printer::print(int pages) {
    if (isValidPrint(pages)) {  // ������ ����ϸ� �μ�
        printedCount += pages;  // �μ�� ������ �� ������Ʈ
        availableCount -= pages;  // ���� ���� �� ����
    }
    else {  // ������ �����ϸ� ���� �޽��� ���
        cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
    }
}

// �������� ���¸� ����ϴ� �Լ�
void Printer::showPrinter() const {
    cout << model << ", " << manufacturer << ", ���� ���� " << availableCount << "��";  // ������ ������ ���� ���� ���
}

// InkJetPrinter Ŭ������ ������
InkJetPrinter::InkJetPrinter(string mo, string me, int a, int i)
    : Printer(mo, me, a), availableInk(i) {}  // ��ũ�� �����ʹ� �θ� Ŭ������ �����ڸ� ȣ���ϰ� ��ũ ���� �ʱ�ȭ

// ��ũ�� ������� Ȯ���ϴ� �Լ�
bool InkJetPrinter::isValidInkJetPrint(int pages) const {
    return availableInk >= pages;  // ��ũ ���� �Էµ� ������ �� �̻��� ��� true ��ȯ
}

// ��ũ�� �����ͷ� �μ��ϴ� �Լ�
void InkJetPrinter::printInkJet(int pages) {
    if (isValidPrint(pages)) {  // ������ ����ϸ�
        if (isValidInkJetPrint(pages)) {  // ��ũ�� ����ϸ�
            print(pages);  // �θ� Ŭ������ print() ȣ���Ͽ� �μ�
            availableInk -= pages;  // �μ� �� ��ũ ����
            cout << "����Ʈ�Ͽ����ϴ�" << endl;  // ���� �޽��� ���
        }
        else {  // ��ũ ���� �� ���� �޽��� ���
            cout << "��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
        }
    }
    else {  // ���� ���� �� ���� �޽��� ���
        cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
    }
}

// ��ũ�� �������� ���¸� ����ϴ� �Լ�
void InkJetPrinter::showInkJetPrinter() const {
    showPrinter();  // �θ� Ŭ������ showPrinter() ȣ���Ͽ� ���� ������ ���
    cout << ", ���� ��ũ " << availableInk << endl;  // ��ũ ���� ���
}

// LaserPrinter Ŭ������ ������
LaserPrinter::LaserPrinter(string mo, string me, int a, int t)
    : Printer(mo, me, a), availableToner(t) {}  // ������ �����ʹ� �θ� Ŭ������ �����ڸ� ȣ���ϰ� ��� ���� �ʱ�ȭ

// ��ʰ� ������� Ȯ���ϴ� �Լ�
bool LaserPrinter::isValidLaserPrint(int pages) const {
    return availableToner >= pages;  // ��� ���� �Էµ� ������ �� �̻��� ��� true ��ȯ
}

// ������ �����ͷ� �μ��ϴ� �Լ�
void LaserPrinter::printLaser(int pages) {
    if (isValidPrint(pages)) {  // ������ ����ϸ�
        if (isValidLaserPrint(pages)) {  // ��ʰ� ����ϸ�
            print(pages);  // �θ� Ŭ������ print() ȣ���Ͽ� �μ�
            availableToner -= pages;  // �μ� �� ��� ����
            cout << "����Ʈ�Ͽ����ϴ�" << endl;  // ���� �޽��� ���
        }
        else {  // ��� ���� �� ���� �޽��� ���
            cout << "��ʰ� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
        }
    }
    else {  // ���� ���� �� ���� �޽��� ���
        cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
    }
}

// ������ �������� ���¸� ����ϴ� �Լ�
void LaserPrinter::showLaserPrinter() const {
    showPrinter();  // �θ� Ŭ������ showPrinter() ȣ���Ͽ� ���� ������ ���
    cout << ", ���� ��� " << availableToner << endl;  // ��� ���� ���
}
