#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <TGUI/TGUI.hpp>
#define THEME_CONFIG_FILE "TGUI/widgets/Black.conf"

#include "GameStart.h"
#include "CharGen.h"
//#include "Battle.h"

void GameStart::LoadWidgets(tgui::Gui& gui){
	//this->game->window.draw(this->game->background);
	int WIDTH = 1024;
	int HEIGHT = 768;
	gui.setWindow(game->window);

	gui.setGlobalFont("TGUI/fonts/DejaVuSans.ttf"); // Load the font directly
	tgui::Picture::Ptr picture(gui, "BackgroundImage");
	picture->load("assets/forest.png");
	picture->setSize(WIDTH, HEIGHT);

	tgui::Picture::Ptr title(gui, "title");
	title->load("assets/title.png");
	title->setPosition(200, 120);

	tgui::Button::Ptr button(gui);
	button->load(THEME_CONFIG_FILE);
	button->setPosition(255, 580);
	button->setText("Start");
	button->setCallbackId(1);
	button->bindCallback(tgui::Button::LeftMouseClicked);
	button->setSize(500, 80);
}

void GameStart::Draw(const float t){
	gui.draw();

}

void GameStart::Update(const float t){
}

void GameStart::HandleInput(){
		sf::Event event;
		while (this->game->window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				this->game->window.close();

			// Pass the event to all the widgets (if there would be widgets)
			gui.handleEvent(event);
		}
		tgui::Callback callback;
		while (gui.pollCallback(callback))
		{
			if (callback.id == 1){
				//this->game->window.close();
				//CharGen chargen;
				//chargen.gameLoop();
				//Battle battle;
				//battle.gameLoop();
				//game->ChangeState(new CharGen);

				//bgm.stop();
				game->PushState(new CharGen(game));
			}
		}
	}

GameStart::GameStart(Game* game){
	this->game = game;
	gui.setWindow(game->window);
	LoadWidgets(gui);

	bgm.openFromFile("assets/menu.wav");
	bgm.setVolume(20);
	//bgm.play();

}

void GameStart::StopMusic(){
	bgm.stop();
}

