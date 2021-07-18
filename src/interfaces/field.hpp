#pragma once

#include "../nodetypes/node.hpp"

namespace StardustXRServer {

class FieldInterface : public Node {
public:
	FieldInterface(Client *client);
	virtual ~FieldInterface() {}

	std::vector<uint8_t> createBoxField(flexbuffers::Reference data, bool returnValue);
	std::vector<uint8_t> createSphereField(flexbuffers::Reference data, bool returnValue);
};

} // namespace StardustXRServer