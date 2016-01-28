#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <TGUI/TGUI.hpp>
#define THEME_CONFIG_FILE "TGUI/widgets/Black.conf"

#include "CharGen.h"
#include "Player.h"
#include "Battle.h"
#include "Loading.h"

void GenerateName(std::vector<std::string> names, tgui::EditBox::Ptr box){

	std::string name;

	int randomIndex = rand() % names.size();
	name = names[randomIndex];

	box->setText(name);
}

int GetStartingMoney(){
	Character c;
	int money = (c.Dice(3, 6) * 10); //3d6*10
	return money;
}

void CharGen::LoadWidgets(tgui::Gui& gui){
	gui.setWindow(game->window);


	player.setSP(GetStartingMoney());


	int WIDTH = 1024;
	int HEIGHT = 768;
	sf::Color grey(96, 96, 96);

	gui.setGlobalFont("TGUI/fonts/DejaVuSans.ttf"); // Load the font directly
	tgui::Picture::Ptr picture(gui, "BackgroundImage");
	picture->load("assets/chargen.png");
	picture->setSize(WIDTH, HEIGHT);

	// Create the username label
	tgui::Label::Ptr labelUsername(gui);
	labelUsername->setText("Enter a name:");
	labelUsername->setPosition(400, 10);

	// Create the name edit box
	tgui::EditBox::Ptr editBoxName(gui, "Name");
	editBoxName->load("TGUI/widgets/Black.conf");
	editBoxName->setSize(400, 40);
	editBoxName->setPosition(310, 40);
	editBoxName->setMaximumCharacters(30);

	//player's money, silver
	tgui::Picture::Ptr silver(gui, "silver");
	silver->load("assets/coins_silver.png");
	silver->setPosition(10, 20);

	// Create the silver label
	tgui::Label::Ptr labelSilver(gui);
	labelSilver->setText(std::to_string(player.getSP()) + " SP");
	labelSilver->setPosition(90, 40);

	//player's hp
	tgui::Picture::Ptr hp(gui, "hp");
	hp->load("assets/heart.png");
	hp->setPosition(930, 20);

	// Create the hp label
	tgui::Label::Ptr labelHP(gui, "labelHP");
	labelHP->setText(std::to_string(player.getMaxHP()) + " HP");
	labelHP->setPosition(840, 40);


	// Create the generate button
	tgui::Button::Ptr button(gui, "generate");
	button->load("TGUI/widgets/Black.conf");
	button->setSize(400, 40);
	button->setPosition(310, 85);
	button->setText("Random Name");
	button->bindCallback(tgui::Button::LeftMouseClicked);
	button->setCallbackId(1);

	//cleric portrait
	tgui::Picture::Ptr cleric(gui, "cleric");
	cleric->load("assets/cleric.png");
	cleric->setPosition(10, 200);

	//cleric label
	tgui::Label::Ptr labelCleric(gui);
	labelCleric->setText("Cleric");
	labelCleric->setPosition(30, 305);
	labelCleric->setTextSize(20);

	//cleric button
	tgui::RadioButton::Ptr clericButton(gui);
	clericButton->load(THEME_CONFIG_FILE);
	clericButton->setPosition(42, 330);
	clericButton->setSize(32, 32);
	clericButton->bindCallback(tgui::RadioButton::RadioButtonCallbacks::Checked);
	clericButton->setCallbackId(2);
	clericButton->check();


	//fighter portrait
	tgui::Picture::Ptr fighter(gui, "fighter");
	fighter->load("assets/fighter.png");
	fighter->setPosition(160, 200);

	//fighter label
	tgui::Label::Ptr labelFighter(gui);
	labelFighter->setText("Fighter");
	labelFighter->setPosition(176, 305);
	labelFighter->setTextSize(20);

	//fighter button
	tgui::RadioButton::Ptr fighterButton(gui, "fighterButton");
	fighterButton->load(THEME_CONFIG_FILE);
	fighterButton->setPosition(192, 330);
	fighterButton->setSize(32, 32);
	fighterButton->bindCallback(tgui::RadioButton::RadioButtonCallbacks::Checked);
	fighterButton->setCallbackId(3);

	//magic user portrait
	tgui::Picture::Ptr magicuser(gui, "magicuser");
	magicuser->load("assets/magic-user.png");
	magicuser->setPosition(310, 200);

	//magic-user label
	tgui::Label::Ptr labelMagicuser(gui);
	labelMagicuser->setText("Magic-User");
	labelMagicuser->setPosition(306, 305);
	labelMagicuser->setTextSize(20);

	//magicuser button
	tgui::RadioButton::Ptr magicuserButton(gui, "magicuserButton");
	magicuserButton->load(THEME_CONFIG_FILE);
	magicuserButton->setPosition(342, 330);
	magicuserButton->setSize(32, 32);
	magicuserButton->bindCallback(tgui::RadioButton::RadioButtonCallbacks::Checked);
	magicuserButton->setCallbackId(4);

	//specialist portrait
	tgui::Picture::Ptr specialist(gui, "specialist");
	specialist->load("assets/specialist.png");
	specialist->setPosition(460, 200);

	//specialist label
	tgui::Label::Ptr labelSpecialist(gui);
	labelSpecialist->setText("Specialist");
	labelSpecialist->setPosition(462, 305);
	labelSpecialist->setTextSize(20);

	//specialist button
	tgui::RadioButton::Ptr specialistButton(gui, "specialistButton");
	specialistButton->load(THEME_CONFIG_FILE);
	specialistButton->setPosition(492, 330);
	specialistButton->setSize(32, 32);
	specialistButton->bindCallback(tgui::RadioButton::RadioButtonCallbacks::Checked);
	specialistButton->setCallbackId(5);

	//dwarf portrait
	tgui::Picture::Ptr dwarf(gui, "dwarf");
	dwarf->load("assets/dwarf.png");
	dwarf->setPosition(610, 200);

	//dwarf label
	tgui::Label::Ptr labelDwarf(gui);
	labelDwarf->setText("Dwarf");
	labelDwarf->setPosition(630, 305);
	labelDwarf->setTextSize(20);

	//dwarf button
	tgui::RadioButton::Ptr dwarfButton(gui, "dwarfButton");
	dwarfButton->load(THEME_CONFIG_FILE);
	dwarfButton->setPosition(642, 330);
	dwarfButton->setSize(32, 32);
	dwarfButton->bindCallback(tgui::RadioButton::RadioButtonCallbacks::Checked);
	dwarfButton->setCallbackId(6);

	//elf portrait
	tgui::Picture::Ptr elf(gui, "elf");
	elf->load("assets/elf.png");
	elf->setPosition(760, 200);

	//elf label
	tgui::Label::Ptr labelElf(gui);
	labelElf->setText("Elf");
	labelElf->setPosition(800, 305);
	labelElf->setTextSize(20);

	//elf button
	tgui::RadioButton::Ptr elfButton(gui, "elfButton");
	elfButton->load(THEME_CONFIG_FILE);
	elfButton->setPosition(792, 330);
	elfButton->setSize(32, 32);
	elfButton->bindCallback(tgui::RadioButton::RadioButtonCallbacks::Checked);
	elfButton->setCallbackId(7);

	//halfling portrait
	tgui::Picture::Ptr halfling(gui, "halfling");
	halfling->load("assets/halfling.png");
	halfling->setPosition(910, 200);

	//halfling label
	tgui::Label::Ptr labelHalfling(gui);
	labelHalfling->setText("Halfling");
	labelHalfling->setPosition(923, 305);
	labelHalfling->setTextSize(20);

	//halfling button
	tgui::RadioButton::Ptr halflingButton(gui, "halflingButton");
	halflingButton->load(THEME_CONFIG_FILE);
	halflingButton->setPosition(942, 330);
	halflingButton->setSize(32, 32);
	halflingButton->bindCallback(tgui::RadioButton::RadioButtonCallbacks::Checked);
	halflingButton->setCallbackId(8);



	//class description
	tgui::TextBox::Ptr textBox(gui, "textBox");
	textBox->load(THEME_CONFIG_FILE);
	textBox->setPosition(10, 370);
	textBox->setSize(1000, 120);
	textBox->setTextSize(12);
	textBox->setReadOnly();
	textBox->setBorderColor(grey);
	textBox->setBorders(2, 2, 2, 2);


	//stats
	tgui::TextBox::Ptr statsBox(gui, "statsBox");
	statsBox->load(THEME_CONFIG_FILE);
	statsBox->setPosition(10, 550);
	statsBox->setSize(100, 120);
	statsBox->setTextSize(16);
	statsBox->setReadOnly();
	statsBox->setBorderColor(grey);
	statsBox->setBorders(2, 2, 2, 2);

	//stats label
	tgui::Label::Ptr labelStats(gui);
	labelStats->setText("Stats");
	labelStats->setPosition(29, 525);
	labelStats->setTextSize(20);


	//saving throws
	tgui::TextBox::Ptr savingBox(gui, "savingBox");
	savingBox->load(THEME_CONFIG_FILE);
	savingBox->setPosition(200, 550);
	savingBox->setSize(170, 120);
	savingBox->setTextSize(16);
	savingBox->setReadOnly();
	savingBox->setBorderColor(grey);
	savingBox->setBorders(2, 2, 2, 2);

	//saving throws label
	tgui::Label::Ptr labelSaving(gui);
	labelSaving->setText("Saving Throws");
	labelSaving->setPosition(209, 525);
	labelSaving->setTextSize(20);

	//Attack Bonuses
	tgui::TextBox::Ptr abBox(gui, "abBox");
	abBox->load(THEME_CONFIG_FILE);
	abBox->setPosition(440, 550);
	abBox->setSize(200, 120);
	abBox->setTextSize(16);
	abBox->setReadOnly();
	abBox->setBorderColor(grey);
	abBox->setBorders(2, 2, 2, 2);

	//attack bonus label
	tgui::Label::Ptr labelAb(gui);
	labelAb->setText("Attack Bonuses");
	labelAb->setPosition(462, 525);
	labelAb->setTextSize(20);

	//Armor Class
	tgui::TextBox::Ptr acBox(gui, "acBox");
	acBox->load(THEME_CONFIG_FILE);
	acBox->setPosition(700, 550);
	acBox->setSize(200, 120);
	acBox->setTextSize(16);
	acBox->setReadOnly();
	acBox->setBorderColor(grey);
	acBox->setBorders(2, 2, 2, 2);

	//attack bonus label
	tgui::Label::Ptr labelAc(gui);
	labelAc->setText("Armor Class");
	labelAc->setPosition(722, 525);
	labelAc->setTextSize(20);

	// Create the finish button
	tgui::Button::Ptr finish(gui, "finish");
	finish->load("TGUI/widgets/Black.conf");
	finish->setSize(400, 40);
	finish->setPosition(310, 700);
	finish->setText("Finish!");
	finish->bindCallback(tgui::Button::LeftMouseClicked);
	finish->setCallbackId(9);


	player = player.RollBaseStats(player);
	player = player.DetermineSavingThrows(player);
	player = player.DetermineAB(player);
	player = player.DetermineAC(player);
	player = player.DetermineHP(player);

	ShowStats();

}

void CharGen::ShowStats(){
	statsBox->setText("CON\t" + std::to_string(player.con.getValue()) + "\n" + "DEX\t" + std::to_string(player.dex.getValue()) + "\n" + "INT\t" + std::to_string(player.itl.getValue()) + "\n" + "STR\t" + std::to_string(player.str.getValue()) + "\n" + "WIS\t" + std::to_string(player.wis.getValue()));

	savingBox->setText("Paralyze\t " + std::to_string(player.getParalyze()) + "\n" + "Poison\t\t" + std::to_string(player.getPoison()) + "\n" + "Breath\t\t" + std::to_string(player.getBreath()) + "\n" + "Device\t\t" + std::to_string(player.getMagicDevice()) + "\n" + "Magic\t\t " + std::to_string(player.getMagic()));

	abBox->setText("Base AB\t\t  " + std::to_string(player.getBase()) + "\n" + "Melee AB\t\t" + std::to_string(player.getMelee()) + "\n" + "Ranged AB\t  " + std::to_string(player.getRanged()));

	acBox->setText("Melee AC\t\t  " + std::to_string(player.getMeleeAC()) + "\n" + "Ranged AC\t\t" + std::to_string(player.getRangedAC()) + "\n" + "No Shield AC\t  " + std::to_string(player.getNoshield()) + "\n" + "Surprised AC\t  " + std::to_string(player.getSurprised()));

	labelHP->setText(std::to_string(player.getMaxHP())+ " HP");
}

void CharGen::Draw(const float t){
	gui.draw();
}

void CharGen::Update(const float t){

}




void CharGen::HandleInput(){



	tgui::Callback callback;

		sf::Event event;
		while (game->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				game->window.close();

			// Pass the event to all the widgets (if there would be widgets)
			gui.handleEvent(event);
		}
		
		while (gui.pollCallback(callback)){
			if (callback.id == 1){
				tgui::EditBox::Ptr nameBox = gui.get("Name");
				GenerateName(names, nameBox);
			}
			else if (callback.id == 9){
				tgui::EditBox::Ptr nameBox = gui.get("Name");
				name = nameBox->getText();
				if (name == ""){
					tgui::MessageBox::Ptr blankNameText(gui, "blankNameText");
					blankNameText->load(THEME_CONFIG_FILE);
					blankNameText->setTextSize(20);
					blankNameText->setText("Enter or generate a name.");
					blankNameText->setPosition(1024 / 3, 768 / 3);
					blankNameText->setTextColor(sf::Color::White);
					blankNameText->setTitle("Blank Name");
				}
				else{
					player.setName(name);
					Monster leotaur = Monster("Leotaur", "Fighter");
					leotaur.DetermineAB(leotaur);
					leotaur.DetermineAC(leotaur);
					leotaur.DetermineSavingThrows(leotaur);
					
					leotaur.setMaxHP(30);
					leotaur.setHP(30);
					Weapon sword = Weapon("Sword", "This is a sword.", 50, 8);
					player.equipWeapon(sword);

					bgm.stop();
					game->PushState(new Battle(game, player, leotaur));
				}
				//game->window.close();
			}
			else{

				
				if (callback.id == 2){
					player.setProfession("Cleric");
					
					player = player.DetermineSavingThrows(player);
					player = player.DetermineAB(player);
					player = player.DetermineAC(player);
					player = player.DetermineHP(player);
					ShowStats();
					textBox->setText("Some religions teach the people how to receive the grace of their loving deity. Some religions teach the people how to survive the wrath of a cruel and vicious deity. Some religions simply strive to teach the truth about creation. All religions serving true powers have one thing in common : orders of those selected few who are not mere priests, but spiritual warriors endowed by their deity with mystic powers.These few are known as Clerics.");
				}

				else if (callback.id == 3){
					player.setProfession("Fighter");

					player = player.DetermineSavingThrows(player);
					player = player.DetermineAB(player);
					player = player.DetermineAC(player);
					player = player.DetermineHP(player);

					ShowStats();
					textBox->setText("Slaughter defines man's history. Every new era is defined by the cruelty man inflicts upon man, or the victory fighting against it. To those in power, soldiers are but tools to shape the populace to their whims. The price that is paid to enact their desires is irrelevant to those giving the orders. In battle, there is no law. Man maims man. Horribly wounded men scream for mercy as their life's blood pours out from cruelly hacked wounds. Their cries are ignored and their lives extinguished by those too cruel or frightened to listen. Poets and politicians speak of the honor of battle for a just cause, but in battle there is no justice. There is just death from metal implements that crush, slash, and stab. To be willing to slaughter at another's command in the name of peace and nobility, to be hardened to the deaths of loved companions, to be immersed in this worthlessness of life, that is the life of a soldier. Fighters are these soldiers that have seen the cruelty of battle, have committed atrocities that in any just universe will damn them to Hell, and have survived. Fighters begin with the best combat capabilities in the game, and are the only character class to further improve in combat skill as levels are gained.");
				}

				else if (callback.id == 4){
					player.setProfession("Magic-User");

					player = player.DetermineSavingThrows(player);
					player = player.DetermineAB(player);
					player = player.DetermineAC(player);
					player = player.DetermineHP(player);

					ShowStats();
					textBox->setText("Most of the world lies sheltered from the existence of magic, encountering it only as it victimizes them. They huddle in their churches for comfort and trade their freedom and dignity to a ruler as they beg for protection, all for the fear of the supernatural which they do not, and cannot, understand. Magic-Users choose a different path. Instead of cowering away from the darkness, they revel in it. They see the forces of magic as a new frontier to explore, a new tool for the attainment of power and knowledge. If it blackens the soul to equal that of any devil, it is but a small price to pay.");
				}

				else if (callback.id == 5){
					player.setProfession("Specialist");

					player = player.DetermineSavingThrows(player);
					player = player.DetermineAB(player);
					player = player.DetermineAC(player);
					player = player.DetermineHP(player);

					ShowStats();
					textBox->setText("Fighters are adventurers because they are so inured to death that they cannot settle down to a normal life. Magic-Users are those that have pursued the dark arts and are no longer welcome in society. Clerics are charged by their god to go forth and perform their special duties. Specialists? They do it because they want to. Whether inspired by greed, boredom, or idle curiosity, Specialists are professional explorers risking life and limb simply because a less active life is distasteful to them. In some ways this makes them the only sane and normal adventuring characters, but in other ways it makes them the most unusual.");
				}

				else if (callback.id == 6){
					player.setProfession("Dwarf");

					player = player.DetermineSavingThrows(player);
					player = player.DetermineAB(player);
					player = player.DetermineAC(player);
					player = player.DetermineHP(player);

					ShowStats();
					textBox->setText("The Dwarfs are a dying race. Once the most powerful people on the planet, their decline has left them a spiritually shattered people. Once they took great pride in their grand architecture, their technological supremacy, and loved each other just as hard as they worked. Yet they did not change with the world, and as the rest of the world's inhabitants came into their own, the Dwarfs retreated into their subterranean fortresses. War and impotence stripped the Dwarfs of their pride, and all that was left was to work. And work is the life of the average Dwarf. There is no love, no joy. Just never ending work meant to numb the brain and appease the spirit through the acquisition of gems and precious metals. Dwarfs do not even really breed anymore; such is their disregard for the basic pleasures of existence. Not all are like that though. Some strike out into the world, wanting to live. These types often have just as much trouble settling down in human society as their own, and become wandering adventurers. As a race, Dwarfs are short and stocky, about four feet tall, and one hundred thirty-five pounds. They live about three hundred years. They typically have a ruddy complexion and rather gruff personalities; joviality is an unknown quality in Dwarfs, even those roaming the surface. All Dwarfs value their beards, and the length of one's beard is the real measure of a Dwarf's virility and worth, and often the beard is exquisitely styled and decorated.");
				}

				else if (callback.id == 7){
					player.setProfession("Elf");

					player = player.DetermineSavingThrows(player);
					player = player.DetermineAB(player);
					player = player.DetermineAC(player);
					player = player.DetermineHP(player);

					ShowStats();
					textBox->setText("Once the epitome of enlightenment and responsibility, elven civilization has fallen before the expansive nature of Man. Where once the Elf nations ruled the forests, the plains and the mountains, their now-small numbers live in secret enclaves, possessing great power, but utterly impotent in matters of projecting it. Unlike the Dwarfs, the Elves recognize that this is simply the way of things, and accept their decline with grace. Their attitude towards Man is not so unified, however. Some see Man as the natural heir to creation and seek to guide him and help him rule in wisdom. Some see Man as a great blight, and work to destroy him before he destroys all natural order. And some, considered young and foolish by their people, walk among Man. Elves are creatures of magic related to the faerie. As such, they typically enjoy living in the deep wilderness and adapting their homes to be in harmony with their surroundings. They are on average about five feet tall, and usually slender. Their most striking features are their pointed ears (how large these ears are will differ from region to region) and disproportionately large eyes which are often a color not found in the other races.");
				}

				else if (callback.id == 8){
					player.setProfession("Halfling");

					player = player.DetermineSavingThrows(player);
					player = player.DetermineAB(player);
					player = player.DetermineAC(player);
					player = player.DetermineHP(player);

					ShowStats();
					textBox->setText("Halflings are curious creatures who are popularly known as creatures of leisure, but there is far more to them than that. Usually standing about three feet tall, all other physical features of Halflings will differ by region, but one never varies. They have rather large, hairy feet and prefer to go barefoot. Their feet are sufficiently protected and insulated that they suffer not frostbite in the winter, nor disease or parasitical infestation in warmer climes. Halflings as a race do tend to take their pleasures very seriously, and the fat and happy Halfling stereotype has taken hold because rural farmers, while dedicated and fastidious in their work, have all the food that they could ever want and not a lot of reason to engage in moderation. Those used to that stereotype are very surprised the first time that they meet a chiseled, battle-scarred warrior Halfling. Halflings live on average about one hundred years. One stereotype of Halflings that rings true is that while they tend to be gracious to guests and not shy about invitations, they do prefer to be home. Halfling Player Characters are those that have left their homelands to seek adventure and fortune. They are generally seen as troublemakers (and perhaps a touch crazy) by their kin who are not so inclined.");
				}
			}
		}
	}


CharGen::CharGen(Game* game){
	this->game = game;
	gui.setWindow(game->window);
	LoadWidgets(gui);


	clericButton = gui.get("clericButton");
	fighterButton = gui.get("fighterButton");
	magicuserButton = gui.get("magicuserButton");
	specialistButton = gui.get("specialistButton");
	dwarfButton = gui.get("dwarfButton");
	elfButton = gui.get("elfButton");
	halflingButton = gui.get("halflingButton");
	savingBox = gui.get("savingBox");
	abBox = gui.get("abBox");
	acBox = gui.get("acBox");
	textBox = gui.get("textBox");
	labelHP = gui.get("labelHP");
	statsBox = gui.get("statsBox");

	std::ifstream fin;
	fin.open("names.txt");

	while (fin.good()){
		fin >> name;
		names.push_back(name);
	}

	fin.close();

	bgm.openFromFile("assets/characterselect.wav");
	bgm.setVolume(20);
	bgm.play();
}



