#include "Printer.h" // Printer 클래스 선언을 포함하는 헤더

int main() {
    // InkJetPrinter 객체를 생성하고 초기화: 모델명 "Officejet V40", 제조사 "HP", 용지 5장, 잉크 10
    InkJetPrinter ink("Officejet V40", "HP", 5, 10);

    // LaserPrinter 객체를 생성하고 초기화: 모델명 "SCX-6x45", 제조사 "삼성전자", 용지 3장, 토너 20
    LaserPrinter laser("SCX-6x45", "삼성전자", 3, 20);

    // 현재 작동 중인 프린터 상태 출력
    cout << "현재 작동중인 2대의 프린터는 아래와 같다" << endl;

    // InkJetPrinter 상태 출력
    cout << "잉크젯 : ";
    ink.showInkJetPrinter();

    // LaserPrinter 상태 출력
    cout << "레이저 : ";
    laser.showLaserPrinter();

    // 사용자로부터 입력 받을 변수 선언
    int printer, paper;
    char ch;

    // 무한 루프 시작: 사용자가 프로그램을 종료할 때까지 계속 반복
    while (true) {
        // 사용자에게 프린터 선택과 매수(인쇄할 페이지 수)를 입력받음
        cout << endl << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
        cin >> printer >> paper;

        // 입력된 프린터 번호에 따라 해당 프린터의 인쇄 메서드 호출
        switch (printer) {
        case 1:
            ink.printInkJet(paper);  // 잉크젯 프린터로 인쇄
            break;
        case 2:
            laser.printLaser(paper); // 레이저 프린터로 인쇄
            break;
        default:
            cout << "잘못된 입력입니다." << endl;  // 1 또는 2 이외의 값 입력 시 오류 메시지 출력
            break;
        }

        // 인쇄 후 각 프린터의 상태 출력 (남은 용지, 잉크/토너 상태)
        ink.showInkJetPrinter();
        laser.showLaserPrinter();

        // 계속 프린트할지 여부 확인
        cout << "게속 프린트 하시겠습니까(y/n)>>";
        cin >> ch;

        // 사용자가 'n'을 입력하면 루프 종료 (프로그램 종료)
        if (ch == 'n') break;
    }

    return 0; // 프로그램 종료
}
