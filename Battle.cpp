#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <TGUI/TGUI.hpp>
#define THEME_CONFIG_FILE "TGUI/widgets/Black.conf"

#include "Battle.h"
#include "CharGen.h"
#include "Player.h"


void Battle::LoadWidgets(tgui::Gui& gui){
	int WIDTH = 1024;
	int HEIGHT = 768;
	gui.setWindow(game->window);
	gui.setGlobalFont("TGUI/fonts/DejaVuSans.ttf"); // Load the font directly
	tgui::Picture::Ptr picture(gui, "BackgroundImage");
	picture->load("assets/battlebacks/Cave6.png");
	picture->setSize(WIDTH, HEIGHT);

	sf::Color gray(96, 96, 96, 96);

	tgui::Button::Ptr go(gui, "go");
	go->load(THEME_CONFIG_FILE);
	go->setPosition(780, 720);
	go->setSize(233, 30);
	go->setTransparency(255);
	go->setTextColor(sf::Color(222, 222, 222, 255));
	go->setText("Go!");
	go->setCallbackId(7);
	go->bindCallback(tgui::Button::LeftMouseClicked);


	tgui::Label::Ptr attackLabel(gui, "attackLabel");
	attackLabel->setPosition(820, 605);
	attackLabel->setText("Attack");
	attackLabel->setTextSize(18);

	tgui::RadioButton::Ptr attack(gui, "attack");
	attack->load(THEME_CONFIG_FILE);
	attack->setPosition(780, 600);
	attack->bindCallback(tgui::RadioButton::RadioButtonCallbacks::Checked);
	attack->setCallbackId(1);

	tgui::Label::Ptr parryLabel(gui, "parryLabel");
	parryLabel->setPosition(820, 645);
	parryLabel->setText("Parry");
	parryLabel->setTextSize(18);

	tgui::RadioButton::Ptr parry(gui, "parry");
	parry->load(THEME_CONFIG_FILE);
	parry->setPosition(780, 640);
	parry->bindCallback(tgui::RadioButton::RadioButtonCallbacks::Checked);
	parry->setCallbackId(2);

	tgui::Label::Ptr combatactionLabel(gui, "combatactionLabel");
	combatactionLabel->setPosition(819, 675);
	combatactionLabel->setText("Combat\nAction");
	combatactionLabel->setTextSize(16);

	tgui::RadioButton::Ptr combataction(gui, "combataction");
	combataction->load(THEME_CONFIG_FILE);
	combataction->setPosition(780, 680);
	combataction->bindCallback(tgui::RadioButton::RadioButtonCallbacks::Checked);
	combataction->setCallbackId(3);

	tgui::Label::Ptr itemLabel(gui, "itemLabel");
	itemLabel->setPosition(940, 605);
	itemLabel->setText("Item");
	itemLabel->setTextSize(18);

	tgui::RadioButton::Ptr item(gui, "item");
	item->load(THEME_CONFIG_FILE);
	item->setPosition(900, 600);
	item->bindCallback(tgui::RadioButton::RadioButtonCallbacks::Checked);
	item->setCallbackId(4);

	tgui::Label::Ptr spellLabel(gui, "spellLabel");
	spellLabel->setPosition(940, 645);
	spellLabel->setText("Spell");
	spellLabel->setTextSize(18);

	tgui::RadioButton::Ptr spell(gui, "spell");
	spell->load(THEME_CONFIG_FILE);
	spell->setPosition(900, 640);
	spell->bindCallback(tgui::RadioButton::RadioButtonCallbacks::Checked);
	spell->setCallbackId(5);

	tgui::Label::Ptr equipLabel(gui, "equipLabel");
	equipLabel->setPosition(940, 685);
	equipLabel->setText("Equip");
	equipLabel->setTextSize(18);

	tgui::RadioButton::Ptr equip(gui, "equip");
	equip->load(THEME_CONFIG_FILE);
	equip->setPosition(900, 680);
	equip->bindCallback(tgui::RadioButton::RadioButtonCallbacks::Checked);
	equip->setCallbackId(6);



	
	


	//player portrait
	tgui::Picture::Ptr playerPic(gui, "playerPic");
	playerPic->load("assets/fighter.png");
	playerPic->setPosition(670, 608);
	playerPic->setTransparency(255);

	//player HP
	tgui::LoadingBar::Ptr playerHP(gui, "playerHP");
	playerHP->load("tgui/widgets/white.conf");
	playerHP->setPosition(670, 720);
	playerHP->setSize(100, 30);
	playerHP->setTransparency(150);
	playerHP->setMinimum(0);
	playerHP->setMaximum(100);
	playerHP->setValue((100 / player.getMaxHP()) * player.getHP());
	playerHP->setTextColor(sf::Color(222, 222, 222, 255));
	playerHP->setTextSize(22);
	playerHP->setText("HP");

	//player sprite
	tgui::Picture::Ptr you(gui, "you");
	you->load("assets/battle_sprites/warrior.png");
	you->setPosition(700, 250);


	//enemy sprite
	tgui::Picture::Ptr enemy(gui, "enemy");
	enemy->load("assets/battle_sprites/leotaur.png");
	enemy->setPosition(80, 200);




	//enemy text
	tgui::TextBox::Ptr enemyText(gui, "Enemy Text");
	enemyText->load(THEME_CONFIG_FILE);
	enemyText->setPosition(10, 10);
	enemyText->setSize(120, 43);
	enemyText->setText(monster.getName());
	enemyText->setTextColor(sf::Color(222, 222, 222, 255));
	enemyText->setTextSize(22);
	enemyText->setBorders(2, 2, 2, 2);
	enemyText->setBackgroundColor(gray);
	enemyText->setBorderColor(sf::Color(0, 0, 0, 255));
	enemyText->setReadOnly();

	//enemy HP
	tgui::LoadingBar::Ptr enemyHP(gui, "enemyHP");
	enemyHP->load("tgui/widgets/white.conf");
	enemyHP->setPosition(10, 60);
	enemyHP->setSize(120, 36);
	enemyHP->setMaximum(100);
	enemyHP->setMinimum(0);
	enemyHP->setValue((100 / monster.getMaxHP()) * monster.getHP());//this will be the HP of the monster
	enemyHP->setText("HP");
	enemyHP->setTransparency(150);
	enemyHP->setTextColor(sf::Color(222, 222, 222, 255));
	enemyHP->setTextSize(27);

	//event box
	tgui::ChatBox::Ptr eventBox(gui, "EventBox");
	eventBox->load(THEME_CONFIG_FILE);
	eventBox->setPosition(10, 610);
	eventBox->setSize(640, 150);
	eventBox->setTextSize(22);
	eventBox->setBorders(2, 2, 2, 2);
	eventBox->setBackgroundColor(sf::Color(96, 96, 96, 150));
	eventBox->setBorderColor(sf::Color::Black);





}


void Battle::StatusScreen(std::string action, sf::Color color){ //the screen showing the detail of the battle, customized for the action currently being taken
	eventBox->addLine(action, color);
}

bool Battle::AttackHit(Character target){	//determine whether or not the attack hits, depending on the stats of the target
	bool hit = false;						//doesn't hit by default
	int roll = target.Dice(1, 20);					//roll 1d20
	if (roll == 1){							//a roll of 1 is always a miss.
		hit = false;
	}
	else if (roll == 20 || roll >= target.getMeleeAC()){	//a roll of 20 is always a hit, any other roll is a hit as long as it is less than the target's AC.
		hit = true;
	}
	return hit;
}

int Battle::DetermineDmg(Character attacker){ //determine the damage output of the attacker
	int dmg = 0;							//initial dmg at 0
	if (attacker.armed == true){			//check if the attacker is armed
		dmg = attacker.Dice(1, attacker.weapon.getDamage()) + attacker.getMelee(); // the damage is equal to 1d(damage) + the melee AC bonus.
	}
	//i dont think i need this else if i start every character with fists
	else{ //no weapon equipped
		dmg = attacker.Dice(1, 2); //1d2 fists
	}
	return dmg;
}

//returns a message to display to the status screen and handles the attack
std::string Battle::MonsterAttack(){
	std::string msg; //message to display
	int dmg = 0;
	if (AttackHit(player) == true){ //the attack hit
		dmg = DetermineDmg(monster);//get damage
		player.TakeDamage(dmg);		//player takes damage
		msg = "The " + monster.getName() + " strikes you with its " + monster.weapon.getName() + " for " + std::to_string(dmg) + " damage.";
		sound.play();

	}
	else{
		msg = "The " + monster.getName() + " missed.";
	}
	return msg;
}

std::string Battle::PlayerAttack(){
	std::string msg; //message to display
	int dmg = 0;
	if (AttackHit(monster) == true){ //the attack hit
		dmg = DetermineDmg(player);
		monster.TakeDamage(dmg);
		
		msg = "You strike the " + monster.getName() + " with your " + player.weapon.getName() + " for " + std::to_string(dmg) + " damage.";
		sound.play();
		tgui::AnimatedPicture::Ptr blood(gui, "blood");

		blood->addFrame("assets/battle_sprites/blood-0-0.png", sf::milliseconds(50));
		blood->addFrame("assets/battle_sprites/blood-1-0.png", sf::milliseconds(50));
		blood->addFrame("assets/battle_sprites/blood-2-0.png", sf::milliseconds(50));
		blood->addFrame("assets/battle_sprites/blood-3-0.png", sf::milliseconds(50));
		blood->addFrame("assets/battle_sprites/blood-0-1.png", sf::milliseconds(50));
		blood->addFrame("assets/battle_sprites/blood-1-1.png", sf::milliseconds(50));
		blood->addFrame("assets/battle_sprites/blood-2-1.png", sf::milliseconds(50));
		blood->addFrame("assets/battle_sprites/blood-3-1.png", sf::milliseconds(50));
		blood->addFrame("assets/battle_sprites/blood-0-2.png", sf::milliseconds(50));
		blood->addFrame("assets/battle_sprites/blood-1-2.png", sf::milliseconds(50));
		blood->addFrame("assets/battle_sprites/blood-2-2.png", sf::milliseconds(50));
		blood->addFrame("assets/battle_sprites/blood-3-2.png", sf::milliseconds(50));
		blood->addFrame("assets/battle_sprites/blood-0-3.png", sf::milliseconds(50));
		blood->addFrame("assets/battle_sprites/blood-1-3.png", sf::milliseconds(50));
		blood->addFrame("assets/battle_sprites/blood-2-3.png", sf::milliseconds(50));
		blood->addFrame("assets/battle_sprites/blood-3-3.png", sf::milliseconds(50));
		blood->setPosition(enemy->getPosition().x*0.3, enemy->getPosition().y*0.7);
		blood->setSize(384, 384);
		blood->play();

		
		
		
		



	}
	else{
		msg = "You missed.";
	}
	return msg;
}

bool Battle::TakeTurn(Player player){ //player's turn
	
	StatusScreen("It's your turn.", sf::Color::Cyan);
	tgui::Callback callback;
	turnprinted = true;


	

	//StatusScreen(options->getSelectedItem(), sf::Color::White);
	return true;
}
void Battle::TakeTurn(Monster monster){ //monster's turn
	StatusScreen("It's " + monster.getName() + "'s turn.", sf::Color::Magenta);
	StatusScreen(MonsterAttack(), sf::Color::Red);
}






void Battle::Draw(const float t){
	gui.draw();

}
void Battle::Update(const float t){

}
void Battle::HandleInput(){
	sf::Event event;



		while (game->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				game->window.close();

			// Pass the event to all the widgets (if there would be widgets)
			gui.handleEvent(event);



		}
		if (!player.dead && !monster.dead){
		tgui::Callback callback;
		while (gui.pollCallback(callback)){
			if (callback.id == 7){
				if (attack->isChecked()){

					StatusScreen(PlayerAttack(), sf::Color::Blue);
					playersTurn = false;
					turnprinted = false;
					if (monster.dead == true){
						playersTurn = true;
					}

				}
			}
		}

		
		if (playersTurn == true){
			if (turnprinted == false){
				TakeTurn(player);
			}
				playerHP->setValue((100 / player.getMaxHP()) * player.getHP());
				enemyHP->setValue((100 / monster.getMaxHP()) * monster.getHP());//this will be the HP of the monster

			}
			else{
				TakeTurn(monster);
				playerHP->setValue((100 / player.getMaxHP()) * player.getHP());
				enemyHP->setValue((100 / monster.getMaxHP()) * monster.getHP());//this will be the HP of the monster
				playersTurn = true;
			}
		}
	
	else{
		if (battleover == false){
			if (monster.dead){
				StatusScreen("The " + monster.getName() + " died!", sf::Color::Yellow);
				StatusScreen("You win!", sf::Color::Yellow);
				win = true;
				battleover = true;
			}
			if (player.dead){
				StatusScreen("You died!", sf::Color::Magenta);
				StatusScreen("You lose.", sf::Color::Magenta);
				battleover = true;
			}
		}
	}



}


Battle::Battle(Game* game){
	this->game = game;
	gui.setWindow(game->window);
	LoadWidgets(gui);
}

Battle::Battle(Game* game, Player player, Monster monster){
	this->game = game;
	this->player = player;
	this->monster = monster;
	win = false;
	battleover = false;

	bgm.openFromFile("assets/vidya.wav");
	buffer.loadFromFile("assets/Hit.wav");
	
	bgm.setVolume(30);
	sound.setBuffer(buffer);
	sound.setVolume(20);


	gui.setWindow(game->window);
	LoadWidgets(gui);

	eventBox = gui.get("EventBox");
	attack = gui.get("attack");
	parry = gui.get("parry");
	combataction = gui.get("combataction");
	item = gui.get("item");
	spell = gui.get("spell");
	equip = gui.get("equip");
	enemyHP = gui.get("enemyHP");
	playerHP = gui.get("playerHP");
	enemy = gui.get("enemy");
	you = gui.get("you");

	playersTurn = false;

	Character character;
	int playerInitiative = character.Dice(1, 6);		//roll for initiative (who attacks first?)

	int monsterInitiative = character.Dice(1, 6);
	if (playerInitiative >= monsterInitiative){
		playersTurn = true;
	}
	turnprinted = false;

	player.setHP(15);
	
	bgm.play();
}



