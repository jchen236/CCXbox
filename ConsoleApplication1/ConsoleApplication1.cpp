// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include <Windows.h>
#include "stdafx.h"
#include <Xinput.h>
#include "XBoxController.cpp"
#include "XBoxController.h"


int main() {
	XBoxController xc(0.05, 0.05);
	bool wasConnected = true;

	while (true) {
		Sleep(100);

		if (!xc.Refresh()) {
			if (wasConnected) {
				wasConnected = false;
				cout << "Connect a controller please";
			}
		}
		else
			if (!wasConnected) {
				wasConnected = true;
				cout << "Controller is connected" << endl;
			}
		cout << "Left thumb stick: (" << xc.leftStickX << ", " << xc.leftStickY <<
			")    Right thumb stick : (" << xc.rightStickX << ", " << xc.rightStickY << ")" <<
			endl;
	}
}
