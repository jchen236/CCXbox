// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <Windows.h>
#include <Xinput.h>
#include "XBoxController.h"


int main() {
	XBoxController xc(0.05f, 0.05f);
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
