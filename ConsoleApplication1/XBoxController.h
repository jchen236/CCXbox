#pragma once
#include <Windows.h>
#include <Xinput.h>
#include <iostream>

using namespace std;

#ifndef XBOXCONTROLLER_H
#define XBOXCONTROLLER_H

class XBoxController
{
public:	

	float leftStickX;
	float leftStickY;
	float rightStickX;
	float rightStickY;

	// Constructors and Destructors
	XBoxController();
	XBoxController(float, float);
	~XBoxController();

	//Accessor Functions
	float getDeadzoneX() const;
	float getDeadzoneY() const;
	XINPUT_GAMEPAD *getState();
	bool CheckConnection();
	bool Refresh();

	//Mutator Functions
	void setDeadzoneX(float);
	void setDeadzoneY(float);
	void setMaxVoltage(float);

private:
	int controllerId;
	XINPUT_STATE state;
	float deadzoneX;
	float deadzoneY;
	float maxVoltage;



};

#endif