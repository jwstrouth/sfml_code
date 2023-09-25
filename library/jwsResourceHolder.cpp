#ifndef JWSRESOURCEHOLDER_CPP
#define JWSRESOURCEHOLDER_CPP

#include "jwsResourceHolder.h"

template <typename Resource, typename Identifier>
jwsResourceHolder<Resource, Identifier>::jwsResourceHolder()
{
    //ctor
}

template <typename Resource, typename Identifier>
jwsResourceHolder<Resource, Identifier>::~jwsResourceHolder()
{
    //dtor
}

template <typename Resource, typename Identifier>
void jwsResourceHolder<Resource, Identifier>::Load(Identifier id, const std::string& filename)
{
	// Create and load resource
	std::unique_ptr<Resource> resource(new Resource());
	if (!resource->loadFromFile(filename))
		throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);

	// If loading successful, insert resource to map
	InsertResource(id, std::move(resource));
}

template <typename Resource, typename Identifier>
template <typename Parameter>
void jwsResourceHolder<Resource, Identifier>::Load(Identifier id, const std::string& filename, const Parameter& secondParam)
{
	// Create and load resource
	std::unique_ptr<Resource> resource(new Resource());
	if (!resource->loadFromFile(filename, secondParam))
		throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);

	// If loading successful, insert resource to map
	InsertResource(id, std::move(resource));
}

template <typename Resource, typename Identifier>
Resource& jwsResourceHolder<Resource, Identifier>::Get(Identifier id)
{
	auto found = mResourceMap.find(id);
	assert(found != mResourceMap.end());

	return *found->second;
}

template <typename Resource, typename Identifier>
const Resource& jwsResourceHolder<Resource, Identifier>::Get(Identifier id) const
{
	auto found = mResourceMap.find(id);
	assert(found != mResourceMap.end());

	return *found->second;
}

template <typename Resource, typename Identifier>
void jwsResourceHolder<Resource, Identifier>::InsertResource(Identifier id, std::unique_ptr<Resource> resource)
{
	// Insert and check success
	auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
	assert(inserted.second);
}

#endif // JWSRESOURCEHOLDER_CPP
