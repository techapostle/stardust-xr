#pragma once

#include "node.hpp"
#include <vector>

namespace StardustXRServer {

class Alias : public Node {
public:
	Alias(Client *client, Node *original, std::vector<std::string> methods);

protected:
	Node *original;
};

} // namespace StardustXRServer