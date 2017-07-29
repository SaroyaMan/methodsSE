#pragma once
#include "UIComponent.h"
#include <vector>
#include <string>
using namespace std;


class RadioBox : public UIComponent {

	vector<string> options;
	short selected_index;
	short hovered_index;

public:

	RadioBox(string* options, int len, short pos_x, short pos_y, short width, BorderType border = Solid, Color tColor = White, Color bColor = Black, UIComponent* parent = NULL);

	void draw();
	void invertNeeded(int i);
	void mouseClicked(MOUSE_EVENT_RECORD);
	void keyPressed(KEY_EVENT_RECORD);

	bool isTraversable() override { return true; }
	bool isAtEnd() override { return options.size() - 1 == hovered_index; }
	void onFocus() override;
	void onBlur()  override;

	bool selectedItem(int index);
	bool clearSelection();
	bool canGetFocus() { return true; }
	const string getCheckedString() const;
};
