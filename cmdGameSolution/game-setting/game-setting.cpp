#include "ScreenBuffer.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "CmdUtil.h"

#include "cmdUI/TextObject.h"
#include "cmdUI/SliderObject.h"
#include "cmdUI/EditObject.h"
#include "cmdUI/ButtonObject.h"
#include "cmdUI/CheckBoxObject.h"

using namespace CmdUI;

extern INPUTVALUE g_Input;
extern TIMEMANAGER g_Time;

bool isGameRunning = false;

TEXT* scoreTextLabel;
SLIDER* aSlider;
BUTTON* counterButton;
EDIT* nameTextBox;
CHECKBOX* fixCheckBox;

int counter = 0;
bool is_fixed = false;

void Start()
{
	ScreenInit();
	InputInit();
	TimeInit();

	scoreTextLabel = CreateText(0, 0, L"Slider: 50 | Counter: 0 | Name: Enter your name.", 0x000f);
	aSlider = CreateSlider(0, 3, 30, L"TEST", 0, 100, 50, 0x000f, 0x0007);
	counterButton = CreateButton(0, 5, 7, 3, L"Count", 0x000f, 0x0007);
	nameTextBox = CreateEdit(0, 10, 15, 20, L"Enter your name.", false, 0x000f, 0x0007, 0x0007);
	fixCheckBox = CreateCheckBox(0, 12, L"fix everything", false, 0x000f, 0x0007);

	isGameRunning = true;
}

void Update()
{
	InputUpdate();
	TimeUpdate();
	
	UpdateSlider(aSlider, &g_Input);
	UpdateButton(counterButton, &g_Input);
	UpdateEdit(nameTextBox, &g_Input);
	UpdateCheckBox(fixCheckBox, &g_Input);
}

void Render()
{
	ScreenClear();

	DrawTextControl(scoreTextLabel);
	DrawSlider(aSlider);
	DrawButton(counterButton);
	DrawEdit(nameTextBox);
	DrawCheckBox(fixCheckBox);
}

void Release()
{
	ReleaseText(scoreTextLabel);
	ReleaseSlider(aSlider);
	ReleaseButton(counterButton);
	ReleaseEdit(nameTextBox);
	ReleaseCheckBox(fixCheckBox);
}

int main()
{
	Start();

	while (isGameRunning)
	{
		Update();

		Render();

		ScreenFlipping();

		WaitForNextFrame();
	}

	Release();

	return 0;
}