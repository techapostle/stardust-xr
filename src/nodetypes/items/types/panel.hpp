#pragma once

#include <string>
#include <vector>

#include "../item.hpp"

class Surface;

namespace StardustXRServer {

class PanelItem : public Item {
public:
	PanelItem(Client *client, Surface *surface, sk::pose_t pose);
	~PanelItem();

	void update();

	void serializeData(flexbuffers::Builder &fbb);
	Alias *makeAlias(Client *client);
	std::vector<uint8_t> applySurfaceMaterial(Client *callingClient, flexbuffers::Reference data, bool returnValue);

	std::vector<uint8_t> setPointerActive(Client *callingClient, flexbuffers::Reference data, bool returnValue);
	std::vector<uint8_t> setPointerPosition(Client *callingClient, flexbuffers::Reference data, bool returnValue);
	std::vector<uint8_t> setPointerButtonPressed(Client *callingClient, flexbuffers::Reference data, bool returnValue);
	std::vector<uint8_t> scrollPointerAxis(Client *callingClient, flexbuffers::Reference data, bool returnValue);

	std::vector<uint8_t> touchDown(Client *callingClient, flexbuffers::Reference data, bool returnValue);
	std::vector<uint8_t> touchMove(Client *callingClient, flexbuffers::Reference data, bool returnValue);
	std::vector<uint8_t> touchUp(Client *callingClient, flexbuffers::Reference data, bool returnValue);

	std::vector<uint8_t> resize(Client *callingClient, flexbuffers::Reference data, bool returnValue);
	std::vector<uint8_t> close(Client *callingClient, flexbuffers::Reference data, bool returnValue);

	static TypeInfo itemTypeInfo;
	Surface *surface;
};

}
