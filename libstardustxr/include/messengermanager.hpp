#ifndef MESSENGERMANAGER_H
#define MESSENGERMANAGER_H

#include <Godot.hpp>
#include <Node.hpp>
#include <Variant.hpp>
#include <stardustxr/scenegraph.hpp>
#include <stardustxr/server/messengermanager.hpp>
#include <unistd.h>

namespace godot {

class MessengerManager : public Node, public StardustXR::Scenegraph {
  GODOT_CLASS(MessengerManager, Node);

public:
  static void _register_methods();

  MessengerManager();
  ~MessengerManager();

  void _init();

  void sendSignal(std::string path, std::string method,
                  flexbuffers::Reference data);
  std::vector<uint8_t> executeMethod(std::string path,
                                             std::string method,
                                             flexbuffers::Reference args);

  private:
	StardustXR::MessengerManager messengerManager;
    const Variant flexbufferToVariant(flexbuffers::Reference buffer);
};

} // namespace godot

#endif