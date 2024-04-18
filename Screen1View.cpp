#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{
	gauge1modifier = 25;
	EngTempmodifier = 1;
}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::handleTickEvent()
{
	int gauge1minValue;
	int gauge1maxValue;
	gauge1.getRange(gauge1minValue, gauge1maxValue);
/*
	if (gauge1.getValue()== gauge1minValue || gauge1.getValue()== gauge1maxValue)
	{
		gauge1modifier *= -1;
	}
*/
	gauge1.updateValue(gauge1.getValue() + gauge1modifier, 0);

	if (gauge1.getValue() >= gauge1maxValue*0.8)
	{
		upShiftArrow_Warning.setVisible(true);
		upShiftArrow_Warning.invalidate();
	} else {
		upShiftArrow_Warning.setVisible(false);
		upShiftArrow_Warning.invalidate();
	}

	Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", gauge1.getValue() / 20);
	textArea1.invalidate();

	Unicode::snprintf(RPM_TextBuffer, RPM_TEXT_SIZE, "%d", gauge1.getValue());
	RPM_Text.invalidate();

}
