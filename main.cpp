// main.cpp
#include "Printer.h"  // Printer.h 헤더 파일을 포함하여 Printer 클래스와 그 파생 클래스를 사용할 수 있도록 함
#include <iostream>    // 표준 입출력 기능을 사용하기 위해 iostream 라이브러리 포함

using namespace std;   // std 네임스페이스를 사용하여 표준 라이브러리 함수와 객체들을 쉽게 사용

int main() {  // 프로그램 실행의 시작점인 main 함수 정의
    // InkjetPrinter와 LaserPrinter 객체 생성, 각각 잉크젯과 레이저 프린터를 나타냄
    InkjetPrinter inkjet("Officejet V40", "HP", 5, 10);  // 잉크젯 프린터 객체 생성, 5장 종이, 10 잉크
    LaserPrinter laser("SCX-6x45", "삼성전자", 3, 20);  // 레이저 프린터 객체 생성, 3장 종이, 20 토너

    // 현재 작동 중인 프린터 상태 출력
    cout << "현재 작동중인 2대의 프린터는 아래와 같다" << endl;

    // 잉크젯 프린터 상태 출력
    cout << "잉크젯 : ";
    inkjet.showStatus();  // inkjet 객체의 상태를 출력하는 showStatus 함수 호출

    // 레이저 프린터 상태 출력
    cout << "레이저 : ";
    laser.showStatus();  // laser 객체의 상태를 출력하는 showStatus 함수 호출

    int printerType, pages;  // 프린터 선택과 인쇄할 페이지 수를 저장할 변수 선언
    char continuePrinting;   // 계속 인쇄할지 여부를 묻는 변수

    do {  // do-while 루프 시작, 사용자가 'y' 또는 'Y'를 입력할 때까지 반복
        // 프린터 타입과 인쇄할 페이지 수를 입력받음
        cout << "\n프린터 (1: 잉크젯, 2: 레이저)와 매수 입력>> ";
        cin >> printerType >> pages;  // 프린터 타입과 페이지 수 입력 받기

        if (printerType == 1) {  // 잉크젯 프린터 선택 시
            inkjet.print(pages);  // 잉크젯 프린터로 인쇄, 인쇄가 가능하면 자원 차감
        }
        else if (printerType == 2) {  // 레이저 프린터 선택 시
            laser.print(pages);  // 레이저 프린터로 인쇄, 인쇄가 가능하면 자원 차감
        }
        else {  // 잘못된 프린터 타입 입력 시
            cout << "잘못된 프린터 선택입니다.\n";  // 오류 메시지 출력
        }

        // 두 프린터의 상태를 출력
        inkjet.showStatus();  // 잉크젯 프린터 상태 출력
        laser.showStatus();   // 레이저 프린터 상태 출력

        // 계속 프린트할지 여부 묻기
        cout << "계속 프린트 하시겠습니까(y/n)? ";
        cin >> continuePrinting;  // 사용자로부터 계속할지 여부 입력 받기
        cout << "\n";  // 출력 포맷을 위해 개행 추가
    } while (continuePrinting == 'y' || continuePrinting == 'Y');  // 'y' 또는 'Y'를 입력하면 계속 반복

    return 0;  // 프로그램 종료
}
