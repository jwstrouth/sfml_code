#ifndef JWSSPRITENODE_H
#define JWSSPRITENODE_H

#include <SFML/Graphics/Sprite.hpp>

#include <jwsSceneNode.h>

class jwsSpriteNode: public jwsSceneNode
{
    public:
        jwsSpriteNode(const sf::Texture& texture);
        jwsSpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect);
        virtual ~jwsSpriteNode();

    protected:

    private:
        virtual void    DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        sf::Sprite  m_sprite;
};

#endif // JWSSPRITENODE_H
