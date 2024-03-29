#include "Window.h"
#include "TextureManager.h"
#include "map"

class Game 
{

    public: 

        Game();
        ~Game();
    
        void HandleInput();
        void Update();
        void Render();
     

        Window* GetWindow();

        sf::Time GetElapsed();
        void CountTime();
        void CountTimePh();

    private:

        Window myWindow;
        TextureManager myTextureManager;

        void Animate();
        sf::Clock mySclock;
        sf::Clock myPhysicsclock;
        sf::Time mySTimer;
        sf::Time myPhysicsTimer;

        sf::Texture FantasyWarriorTex; //Change to generic renders
        sf::Texture back;
        sf::Sprite backspr;
        sf::Sprite FantasyWarrior;
        sf::Sprite HunterWarrior;
        sf::Vector2i myincrement;

        float frametime = 1.0f/50.0f;
        int mycurrentFrameF; int mycurrentFrameH = 0;
};