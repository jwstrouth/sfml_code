#ifndef JWSRESOURCEHOLDER_H
#define JWSRESOURCEHOLDER_H

#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>

template <typename Resource, typename Identifier>
class jwsResourceHolder
{
    public:
        jwsResourceHolder();
        virtual ~jwsResourceHolder();

        void Load(Identifier id, const std::string& filename);

        template <typename Parameter>
		void Load(Identifier id, const std::string& filename, const Parameter& secondParam);

		Resource& Get(Identifier id);
		const Resource& Get(Identifier id) const;

    protected:

    private:
        void InsertResource(Identifier id, std::unique_ptr<Resource> resource);

    private:
        std::map<Identifier, std::unique_ptr<Resource>>	mResourceMap;
};

#include <jwsResourceHolder.cpp>

#endif // JWSRESOURCEHOLDER_H
