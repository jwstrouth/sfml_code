#include "jwsSpriteNode.h"

#include <SFML/Graphics/RenderTarget.hpp>

jwsSpriteNode::jwsSpriteNode(const sf::Texture& texture):
m_sprite(texture)
{
    //ctor
}

jwsSpriteNode::jwsSpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect):
m_sprite(texture, textureRect)
{

}

jwsSpriteNode::~jwsSpriteNode()
{
    //dtor
}

void jwsSpriteNode::DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}
