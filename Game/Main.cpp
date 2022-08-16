#include "Engine.h"
#include "Renderer/Renderer.h"
#include "Components/PlayerComponent.h"
#include <iostream>

class Singleton
{
public:
	
	~Singleton() { std::cout << "cotr\n"; }
	Singleton(const Singleton& other) { std::cout << "cotr\n"; }
	//assignment operator
	Singleton& operator = (const Singleton& other) { return *this; }

	void say() { std::cout << "hi\n"; }

	Singleton& instance()
	{
		Singleton instance;
		return instance;
	}
private:
	Singleton() { std::cout << "cotr\n"; }
};

void f()
{
	static int c = 0;
	c++;
	std::cout << c << std::endl;
}

class A {};
class B : public A{};
class C : public A{};

A* Create(const  std::string& id)
{
	if (id == "B") return new B();
	if (id == "C") return new C();

	return nullptr;
}

int main()

{
	f();
	f();
	f();
	f();
	f();
	f();
	f();


	//block scope
	{
		
	}

	gre::InitializeMemory();
	gre::setFilePath("../Assets");

	//initialize systems
	gre::g_renderer.Initialize();
	gre::g_inputSystem.Initialize();
	gre::g_audioSystem.Initialize();
	gre::g_resources.Initialize();

	gre::Engine::Instance().Register();

	//create window
	gre::g_renderer.CreateWindow("Neumont", 800, 600);
	gre::g_renderer.setClearColor(gre::Color{ 0,0,0,255 });
	
	//load assets
	std::shared_ptr<gre::Texture> texture = gre::g_resources.Get<gre::Texture>("Sprites/Spaceship.png", &gre::g_renderer);
	std::shared_ptr<gre::Texture> texture2 = gre::g_resources.Get<gre::Texture>("Sprites/Spaceship.png", &gre::g_renderer);

	gre::g_audioSystem.AddAudio("Shoot", "Laser_Shoot5.wav");

	//create actor
	gre::Scene scene;

	gre::Transform transform{ gre::Vector2{400,300}, 90, {3,3} };

	std::unique_ptr<gre::Actor> actor = gre::Factory::Instance().Create<gre::Actor>("Actor");
	actor->m_transform = transform;
	std::unique_ptr<gre::Component> pcomponent = gre::Factory::Instance().Create<gre::Component>("PlayerComponent");
	actor->AddComponent(std::move(pcomponent));

	std::unique_ptr<gre::ModelComponent> mcomponent = std::make_unique<gre::ModelComponent>();
	mcomponent->m_model = gre::g_resources.Get<gre::Model>("Models/Player.txt");
	actor->AddComponent(std::move(mcomponent));

	std::unique_ptr<gre::AudioComponent> acomponent = std::make_unique<gre::AudioComponent>();
	acomponent->m_soundName = "Shoot";
	actor->AddComponent(std::move(acomponent));

	std::unique_ptr<gre::Component> phcomponent = gre::Factory::Instance().Create<gre::Component>("PhysicsComponent");
	actor->AddComponent(std::move(phcomponent));



	//child actor
	gre::Transform transformC{ gre::Vector2{10,10}, 0, {1,1} };
	std::unique_ptr<gre::Actor> child = std::make_unique<gre::Actor>(transformC);

	std::unique_ptr<gre::ModelComponent> mcomponentC = std::make_unique<gre::ModelComponent>();
	mcomponentC->m_model = gre::g_resources.Get<gre::Model>("Models/Player.txt");
	child->AddComponent(std::move(mcomponentC));

	actor->AddChild(std::move(child));

	scene.Add(std::move(actor));

	float angle = 0;
	
		//create game
		
		bool quit = false;
		while (!quit)
		{
			//update
			gre::g_time.Tick();
			gre::g_inputSystem.Update();
			gre::g_audioSystem.Update();

			if (gre::g_inputSystem.GetKeyState(gre::key_escape) == gre::InputSystem::KeyState::Pressed) quit = true;
			//spawn enemies
		
			//update scene
			angle = 360.0f * gre::g_time.deltaTime;

			scene.Update();

			//render
			gre::g_renderer.BeginFrame();

			scene.Draw(gre::g_renderer);
			//gre::g_renderer.Draw(texture, { 400, 300 }, angle, { 1, 1 }, { 1, 1 });
			

			gre::g_renderer.EndFrame();
		}

	

	gre::g_renderer.Shutdown();
	gre::g_audioSystem.Shutdown();
}