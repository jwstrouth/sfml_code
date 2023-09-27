#ifndef JWSSCENENODE_H
#define JWSSCENENODE_H

#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include <vector>
#include <memory>
#include <iostream>

class jwsSceneNode: public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
    public:
        typedef std::unique_ptr<jwsSceneNode> Ptr;

    public:
        jwsSceneNode();
        virtual ~jwsSceneNode();

        void            AttachChild(Ptr child);
		Ptr             DetachChild(const jwsSceneNode& node);
		void	        Update(sf::Time dt);
		sf::Vector2f	GetWorldPosition() const;
		sf::Transform	GetWorldTransform() const;

    protected:

    private:
        virtual void    draw(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void	DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
		void			DrawChildren(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void	UpdateCurrent(sf::Time dt);
		void			UpdateChildren(sf::Time dt);

    private:
        std::vector<Ptr>    m_children;
		jwsSceneNode*       m_parent;
};

#endif // JWSSCENENODE_H
