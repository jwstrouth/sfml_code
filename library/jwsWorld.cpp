#include "jwsWorld.h"

jwsWorld::jwsWorld(sf::RenderWindow &window):
m_window(window),
m_worldView(window.getDefaultView()),
m_textures(),
m_sceneGraph(),
m_sceneLayers(),
m_worldBounds(0.f, 0.f, m_worldView.getSize().x, 2000.f),
m_scrollSpeed(-50.f),
m_spawnPosition(m_worldView.getSize().x / 2.f, m_worldBounds.height - m_worldView.getSize().y / 2.f),
m_aircraft(nullptr)
{
    LoadTextures();
    BuildScene();

    // Prepare the view
	m_worldView.setCenter(m_spawnPosition);
	std::cout << "Spawn Position: x: " << m_spawnPosition.x << ", y: " << m_spawnPosition.y << std::endl;
	std::cout << "World Bound: x: " << m_worldBounds.left << ", y: " << m_worldBounds.top << ", w: " << m_worldBounds.width << ", h: " << m_worldBounds.height << std::endl;
	std::cout << "World View: x: " << m_worldView.getSize().x << ", y: " << m_worldView.getSize().y << std::endl;
}

jwsWorld::~jwsWorld()
{
    //dtor
}

void jwsWorld::Draw()
{
    m_window.setView(m_worldView);
    m_window.draw(m_sceneGraph);
    //std::cout << "m_sceneGraph: Address: " << &m_sceneGraph << std::endl;
}

void jwsWorld::LoadTextures()
{
    m_textures.Load(Textures::Desert, "Desert.png");
    m_textures.Load(Textures::Eagle, "Eagle.png");
    m_textures.Load(Textures::Raptor, "Raptor.png");
}

void jwsWorld::BuildScene()
{
    // Initialize the different layers
	for (std::size_t i = 0; i < LayerCount; ++i)
	{
		jwsSceneNode::Ptr layer(new jwsSceneNode());
		m_sceneLayers[i] = layer.get();

		m_sceneGraph.AttachChild(std::move(layer));
	}

    // Prepare the tiled background
	sf::Texture& texture = m_textures.Get(Textures::Desert);
	sf::IntRect textureRect(m_worldBounds);
	texture.setRepeated(true);

	// Add the background sprite to the scene
	std::unique_ptr<jwsSpriteNode> backgroundSprite(new jwsSpriteNode(texture, textureRect));
	backgroundSprite->setPosition(m_worldBounds.left, m_worldBounds.top);
	m_sceneLayers[Background]->AttachChild(std::move(backgroundSprite));

	// Add player's aircraft
	std::unique_ptr<jwsAircraft> leader(new jwsAircraft(jwsAircraft::Eagle, m_textures));
	m_aircraft = leader.get();
	m_aircraft->setPosition(m_spawnPosition);
	m_aircraft->SetVelocity(40.f, m_scrollSpeed);
	m_sceneLayers[Air]->AttachChild(std::move(leader));

	// Add two escorting aircrafts, placed relatively to the main plane
	std::unique_ptr<jwsAircraft> leftEscort(new jwsAircraft(jwsAircraft::Raptor, m_textures));
	leftEscort->setPosition(-80.f, 50.f);
	m_aircraft->AttachChild(std::move(leftEscort));

	std::unique_ptr<jwsAircraft> rightEscort(new jwsAircraft(jwsAircraft::Raptor, m_textures));
	rightEscort->setPosition(80.f, 50.f);
	m_aircraft->AttachChild(std::move(rightEscort));
}

void jwsWorld::Update(sf::Time dt)
{
	// Scroll the world
	m_worldView.move(0.f, m_scrollSpeed * dt.asSeconds());
	//std::cout << "World View: x: " << m_worldView.getSize().x << ", y: " << m_worldView.getSize().y << std::endl;

#if 1
	// Move the player sidewards (plane scouts follow the main aircraft)
	sf::Vector2f position = m_aircraft->getPosition();
	sf::Vector2f velocity = m_aircraft->GetVelocity();

	// If player touches borders, flip its X velocity
	if (position.x <= m_worldBounds.left + 150.f
	 || position.x >= m_worldBounds.left + m_worldBounds.width - 150.f)
	{
		velocity.x = -velocity.x;
		m_aircraft->SetVelocity(velocity);
	}
#endif // 0

	// Apply movements
	m_sceneGraph.Update(dt);
}

