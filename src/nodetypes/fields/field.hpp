#ifndef STARDUSTXRSERVER_FIELD_HPP
#define STARDUSTXRSERVER_FIELD_HPP

#include "../spatialnode.hpp"

namespace StardustXRServer {

class Field : public SpatialNode {
public:
	Field();
	virtual ~Field();

	float normalRadius = 0.0000001f;

	virtual float localDistance(const vec3 point);
	virtual const vec3 localClosestPoint(const vec3 point);
	virtual const vec3 localNormal(const vec3 point);
	virtual const vec3 localNormal(const vec3 point, const float radius);

	virtual float distance(const vec3 point);
	virtual const vec3 closestPoint(const vec3 point);
	virtual const vec3 normal(const vec3 point);
	virtual const vec3 normal(const vec3 point, const float radius);
};

} // namespace StardustXRServer

#endif // STARDUSTXRSERVER_FIELD_HPP