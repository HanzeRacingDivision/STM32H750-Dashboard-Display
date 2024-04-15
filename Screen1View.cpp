#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{
	gauge1modifier = 1;
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

	if (gauge1.getValue()== gauge1minValue || gauge1.getValue()== gauge1maxValue)
	{
		gauge1modifier *= -1;
	}

	gauge1.updateValue(gauge1.getValue() + gauge1modifier, 0);

	if (gauge1.getValue() >= 60)
	{
		upShiftArrow_Warning.setVisible(1);
		//upShiftArrow_Warning.invalidate();
	} else {
		upShiftArrow_Warning.setVisible(0);
	}


	int EngTempMinValue;
	int EngTempMaxValue;
	EngTemp_Thermom.getRange(EngTempMinValue, EngTempMaxValue);

	if (EngTemp_Thermom.getValue()== EngTempMinValue || EngTemp_Thermom.getValue()== EngTempMaxValue)
	{
		EngTempmodifier *= -1;
	}

	EngTemp_Thermom.updateValue(EngTemp_Thermom.getValue() + EngTempmodifier, 0);

	if (EngTemp_Thermom.getValue() >= 80)
	{
		EngTemp_Warning.setVisible(1);
	} else {
		EngTemp_Warning.setVisible(0);
	}

	Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%d", EngTemp_Thermom.getValue());
	textArea1.invalidate();

}
