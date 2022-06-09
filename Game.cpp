#include "Game.h"
#include <iostream>

Game::Game(): myWindow("GameShow", sf::Vector2u(565, 240)) { //Passing Window arguments construtor to Game constructor
    
    CountTime();
    srand(time(NULL));

    if(myTextureManager.load("back", "assets/back.jpg")) {
     
        std::cout << "Load Sucess back\n";
    }

    myTextureManager.draw("back", 0, 0, 564, 236, &backspr);
    
    
    if(myTextureManager.load("Char1", "assets/Fantasy_Warrior/Attack1.png")) {
     
        std::cout << "Load Sucess Char1\n";
    }

    if(myTextureManager.load("Char2", "assets/Huntress/Sprites/Attack2.png")) {
     
        std::cout << "Load Sucess Char2\n";
    }


    //myTextureManager.drawFrame("Char1", 65, 100, 162, 162, 1, mycurrentFrame, &FantasyWarrior, false); 
    //myTextureManager.drawFrame("Char2", 165, 100, 162, 162, 1, mycurrentFrame, &HunterWarrior, true); 

   /* if((FantasyWarrior).getTexture() == nullptr) {

        std::cout << "Draw Fantasy Failed\n";
    }

    if((HunterWarrior).getTexture() == nullptr) {

        std::cout << "Draw Hunter Failed\n";
    }

    */


}

Game::~Game(){}

sf::Time Game::GetElapsed(){ return mySTimer; }
Window* Game::GetWindow(){ return &myWindow; }

void Game::CountTimePh()  {
     myPhysicsTimer += myPhysicsclock.restart();
     if(myPhysicsTimer.asSeconds() >= frametime) { 
        myPhysicsTimer -= sf::seconds(frametime);
     } 
}

void Game::CountTime() {
    mySTimer = mySclock.getElapsedTime();
}

void Game::HandleInput() {
	// Input handling.
}

void Game::Update() {

    myWindow.Update();
    mycurrentFrameF = (int)((mySclock.getElapsedTime().asMilliseconds()/170) % 7);
    mycurrentFrameH = (int)((mySclock.getElapsedTime().asMilliseconds()/170) % 5);

}

void Game::Render() {
	myWindow.BeginDraw(); // Clear.
    myTextureManager.drawFrame("Char1", 65, 100, 162, 162, 1, mycurrentFrameF, &FantasyWarrior, false); 
    myTextureManager.drawFrame("Char2", 340, 100, 150, 150, 1, mycurrentFrameH, &HunterWarrior, true); 
	myWindow.Draw(backspr);
    myWindow.Draw(FantasyWarrior);
    myWindow.Draw(HunterWarrior);
	myWindow.EndDraw(); // Display.
}