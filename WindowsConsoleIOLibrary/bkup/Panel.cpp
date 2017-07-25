#include "Panel.h"



Panel::Panel()
{
}

void Panel::addComponent(UIComponent * component) {
	if (component)
		this->components.push_back(component);
}

void Panel::removeAll() {
	while (components.size() > 0) {
		delete components.back();
		components.pop_back();
	}
}

void Panel::draw() {
	for (vector<UIComponent *>::iterator it = components.begin(); it != components.end(); ++it) {
		(*it)->draw();
	}
}


Panel::~Panel() {
	this->removeAll();
}