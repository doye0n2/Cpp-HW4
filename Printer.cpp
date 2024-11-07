#include "Printer.h" // Printer 클래스 선언을 포함하는 헤더

// Printer 클래스의 생성자
Printer::Printer(string mo, string me, int a)
    : model(mo), manufacturer(me), availableCount(a), printedCount(0) {}  // 모델, 제조사, 용지 수를 초기화

// 용지 수가 충분한지 확인하는 함수
bool Printer::isValidPrint(int pages) const {
    return availableCount >= pages;  // 용지 수가 입력된 페이지 수 이상인 경우 true 반환
}

// 인쇄하는 함수
void Printer::print(int pages) {
    if (isValidPrint(pages)) {  // 용지가 충분하면 인쇄
        printedCount += pages;  // 인쇄된 페이지 수 업데이트
        availableCount -= pages;  // 남은 용지 수 차감
    }
    else {  // 용지가 부족하면 오류 메시지 출력
        cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
    }
}

// 프린터의 상태를 출력하는 함수
void Printer::showPrinter() const {
    cout << model << ", " << manufacturer << ", 남은 종이 " << availableCount << "장";  // 프린터 정보와 남은 용지 출력
}

// InkJetPrinter 클래스의 생성자
InkJetPrinter::InkJetPrinter(string mo, string me, int a, int i)
    : Printer(mo, me, a), availableInk(i) {}  // 잉크젯 프린터는 부모 클래스의 생성자를 호출하고 잉크 수를 초기화

// 잉크가 충분한지 확인하는 함수
bool InkJetPrinter::isValidInkJetPrint(int pages) const {
    return availableInk >= pages;  // 잉크 수가 입력된 페이지 수 이상인 경우 true 반환
}

// 잉크젯 프린터로 인쇄하는 함수
void InkJetPrinter::printInkJet(int pages) {
    if (isValidPrint(pages)) {  // 용지가 충분하면
        if (isValidInkJetPrint(pages)) {  // 잉크가 충분하면
            print(pages);  // 부모 클래스의 print() 호출하여 인쇄
            availableInk -= pages;  // 인쇄 후 잉크 차감
            cout << "프린트하였습니다" << endl;  // 성공 메시지 출력
        }
        else {  // 잉크 부족 시 오류 메시지 출력
            cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
        }
    }
    else {  // 용지 부족 시 오류 메시지 출력
        cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
    }
}

// 잉크젯 프린터의 상태를 출력하는 함수
void InkJetPrinter::showInkJetPrinter() const {
    showPrinter();  // 부모 클래스의 showPrinter() 호출하여 공통 정보를 출력
    cout << ", 남은 잉크 " << availableInk << endl;  // 잉크 상태 출력
}

// LaserPrinter 클래스의 생성자
LaserPrinter::LaserPrinter(string mo, string me, int a, int t)
    : Printer(mo, me, a), availableToner(t) {}  // 레이저 프린터는 부모 클래스의 생성자를 호출하고 토너 수를 초기화

// 토너가 충분한지 확인하는 함수
bool LaserPrinter::isValidLaserPrint(int pages) const {
    return availableToner >= pages;  // 토너 수가 입력된 페이지 수 이상인 경우 true 반환
}

// 레이저 프린터로 인쇄하는 함수
void LaserPrinter::printLaser(int pages) {
    if (isValidPrint(pages)) {  // 용지가 충분하면
        if (isValidLaserPrint(pages)) {  // 토너가 충분하면
            print(pages);  // 부모 클래스의 print() 호출하여 인쇄
            availableToner -= pages;  // 인쇄 후 토너 차감
            cout << "프린트하였습니다" << endl;  // 성공 메시지 출력
        }
        else {  // 토너 부족 시 오류 메시지 출력
            cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
        }
    }
    else {  // 용지 부족 시 오류 메시지 출력
        cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
    }
}

// 레이저 프린터의 상태를 출력하는 함수
void LaserPrinter::showLaserPrinter() const {
    showPrinter();  // 부모 클래스의 showPrinter() 호출하여 공통 정보를 출력
    cout << ", 남은 토너 " << availableToner << endl;  // 토너 상태 출력
}
