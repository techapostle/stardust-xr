#pragma once

#include <functional>
#include <string>
#include "../nodetypes/graphical/drawablenode.hpp"

namespace StardustXRServer {

class Node;

typedef std::function<bool (std::string, Node *)> PropagateFunction;

// Define lambda functions for update and draw functions to be propagated
static PropagateFunction ScenegraphUpdateFunction = [](std::string, Node *node) {
	if(node)
		node->update();
	return node;
};
static PropagateFunction ScenegraphDrawFunction = [](std::string, Node *node) {
	if(DrawableNode *drawNode = dynamic_cast<DrawableNode *>(node))
		drawNode->draw();
	return true;
};

}