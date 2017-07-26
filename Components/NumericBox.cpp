#include "NumericBox.h"

NumericBox::NumericBox(int _val, int _min, int _max, short x_pos, short y_pos,
	BorderType border, Color tColor, Color bColor, UIComponent * parent)
	: UIComponent(x_pos, y_pos, 14, 2, border, tColor, bColor, parent), incrementor(*this), decrementor(*this) {

	if (_val >= _min && _val <= _max) {
		maximum = _max;
		minimum = _min;
		value = _val;
		decBtn = new Button(&decrementor, "-", x_pos, y_pos, 1,2, border, tColor, bColor);
		incBtn = new Button(&incrementor, "+", x_pos+13, y_pos, 1, 2, border, tColor, bColor);
	}
	else {
		throw IOConsoleException("Numeric Box: value exceeds limits");
	}
}

void NumericBox::drawValue() const {
	auto ctrl = CCTRL;
	// clear background
	COORD c = { position.X + 3, position.Y + 1 };
	short text_len = static_cast<short>(std::to_string(getValue()).length());
	//SetConsoleCursorPosition(h, c);
	ctrl.setPosition(c);
	for (short i = 0; i < width - 4; i++) {
		std::cout << " ";
	}

	// print centered text
	c = { position.X + static_cast<short>(width / 2) - text_len / 2, position.Y + 1 };
	ctrl.setPosition(c);
	std::cout << getValue();
}

void NumericBox::draw() {
	decBtn->draw();
	incBtn->draw();
	UIComponent::draw();
	auto ctrl = CCTRL;
	ctrl.setPosition({ position.X + 2, position.Y});
	std::cout << "\xC2";
	ctrl.setPosition({ position.X + 13, position.Y });
	std::cout << "\xC2";
	ctrl.setPosition({ position.X + 2, position.Y +2});
	std::cout << "\xC1";
	ctrl.setPosition({ position.X + 13, position.Y + 2 });
	std::cout << "\xC1";
	drawValue();
}

void NumericBox::setValue(int _val) {
	if (_val < getMin()) value = getMin();
	else if (_val > getMax()) value = getMax();
	else value = _val;
	drawValue();
}

void NumericBox::setMin(int _min) {
	if (getValue() >= _min) {
		minimum = _min;
	}
	else {
		throw IOConsoleException("Numeric Box: value exceeds limits");
	}
}

void NumericBox::setMax(int _max) {
	if (getValue() <= _max) {
		maximum = _max;
	}
	else {
		throw IOConsoleException("Numeric Box: value exceeds limits");
	}
}

NumericBox::~NumericBox() {
	if (incBtn) delete incBtn;
	if (decBtn) delete decBtn;
}

void NumericBox::IncrementAction::action() {
	parent.setValue(parent.getValue() + 1);
}

void NumericBox::DecrementAction::action() {
	parent.setValue(parent.getValue() - 1);
}