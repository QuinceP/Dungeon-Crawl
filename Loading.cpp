#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <TGUI/TGUI.hpp>
#define THEME_CONFIG_FILE "TGUI/widgets/Black.conf"

#include "Loading.h"
#include "CharGen.h"
//#include "Battle.h"

void Loading::LoadWidgets(tgui::Gui& gui){
	//this->game->window.draw(this->game->background);
	int WIDTH = 1024;
	int HEIGHT = 768;
	gui.setWindow(game->window);

	gui.setGlobalFont("TGUI/fonts/DejaVuSans.ttf"); // Load the font directly
	tgui::Picture::Ptr picture(gui, "BackgroundImage");
	picture->load("assets/loadingscreen.png");
	picture->setSize(WIDTH, HEIGHT);

	tgui::Picture::Ptr text(gui, "text");
	text->load("assets/loadingtext.png");
	text->setSize(WIDTH, HEIGHT);

}

void Loading::Draw(const float t){
	gui.draw();
	text->moveToFront();

}

void Loading::Update(const float t){
}

void Loading::HandleInput(){
	sf::Event event;
	text->moveToBack();
	while (this->game->window.pollEvent(event)){
		if (event.type == sf::Event::Closed)
			this->game->window.close();

		// Pass the event to all the widgets (if there would be widgets)
		gui.handleEvent(event);
	}
	tgui::Callback callback;
	while (gui.pollCallback(callback))
	{
		game->PushState(new CharGen(game));
	}
}

Loading::Loading(Game* game){
	this->game = game;
	gui.setWindow(game->window);
	LoadWidgets(gui);

	text = gui.get("text");


	

}

