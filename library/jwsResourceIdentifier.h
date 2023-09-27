#ifndef BOOK_RESOURCEIDENTIFIERS_H
#define BOOK_RESOURCEIDENTIFIERS_H

// Forward declaration of SFML classes
namespace sf
{
	class Texture;
}

namespace Textures
{
	enum ID
	{
		Eagle,
		Raptor,
		Desert,
	};
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class jwsResourceHolder;

typedef jwsResourceHolder<sf::Texture, Textures::ID> TextureHolder;

#endif // BOOK_RESOURCEIDENTIFIERS_H
