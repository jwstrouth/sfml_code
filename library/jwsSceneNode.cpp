#include "jwsSceneNode.h"

#if 0
#include <Foreach.hpp> // more review is needed to understand
#endif // 0

#include <algorithm>
#include <cassert>

jwsSceneNode::jwsSceneNode()
{
    //ctor
}

jwsSceneNode::~jwsSceneNode()
{
    //dtor
}

void jwsSceneNode::AttachChild(Ptr child)
{
    child->m_parent = this;
	m_children.push_back(std::move(child));
}

jwsSceneNode::Ptr jwsSceneNode::DetachChild(const jwsSceneNode &node)
{
    auto found = std::find_if(m_children.begin(), m_children.end(), [&] (Ptr& p) { return p.get() == &node; });
    assert(found != m_children.end());

    Ptr result = std::move(*found);
    result->m_parent = nullptr;
	m_children.erase(found);
    return result;
}

void jwsSceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// Apply transform of current node
	states.transform *= getTransform();

	// Draw node and children with changed transform
	DrawCurrent(target, states);
	DrawChildren(target, states);
}

void jwsSceneNode::DrawCurrent(sf::RenderTarget&, sf::RenderStates) const
{
	// Do nothing by default
}

void jwsSceneNode::DrawChildren(sf::RenderTarget& target, sf::RenderStates states) const
{
    static bool firstTime = false;
#if 0
	FOREACH(const Ptr& child, m_children)
	{
		child->draw(target, states);
    }
#endif // 0

    for (auto itr = m_children.begin();itr != m_children.end(); ++itr)
    {
        (*itr)->draw(target, states);

        if(firstTime == false)
        {
            std::cout << "Draw child\n";
            firstTime = true;
        }
    }

    if(firstTime == false)
    {
        std::cout << "jwsSceneNode::DrawChildren\n";
        firstTime = true;
    }
}

void jwsSceneNode::Update(sf::Time dt)
{
    UpdateCurrent(dt);
    UpdateChildren(dt);
}

void jwsSceneNode::UpdateCurrent(sf::Time dt)
{

}

void jwsSceneNode::UpdateChildren(sf::Time dt)
{
    for (auto itr = m_children.begin();itr != m_children.end(); ++itr)
    {
        (*itr)->Update(dt);
    }
}

sf::Vector2f jwsSceneNode::GetWorldPosition() const
{
    return GetWorldTransform() * sf::Vector2f();
}

sf::Transform jwsSceneNode::GetWorldTransform() const
{
    sf::Transform transform = sf::Transform::Identity;

	for (const jwsSceneNode* node = this; node != nullptr; node = node->m_parent)
	{
		transform = node->getTransform() * transform;
    }

	return transform;
}

