#pragma once
#include "UIComponent.h"
#include <vector>
#include <string>
using namespace std;


class RadioBox : public UIComponent {

	vector<string> options;
	int selected_index;

public:

	RadioBox(string* options, int len, short pos_x, short pos_y, short width, BorderType border = Double, Color tColor = White, Color bColor = Black, UIComponent* parent = NULL);

	void draw();
	void mouseClicked(MOUSE_EVENT_RECORD);

	bool slectedItem(int index);
	bool clearSelection();
	bool canGetFocus() { return true; }
	const string getCheckedString() const;
};
