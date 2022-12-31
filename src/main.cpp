#include <appdef.hpp>

#include "calc.hpp"
#include "draw_functions.hpp"

#include "lib/core/exceptions.hpp"
#include "lib/core/event_handler.hpp"
#include "lib/core/tile_handler.hpp"
#include "lib/renderer.hpp"
#include "lib/core/debug.hpp"
#include "lib/functions/random.hpp"
#include "lib/core/player.hpp"

/*
 * Fill this section in with some information about your app.
 * All fields are optional - so if you don't need one, take it out.
 */
APP_NAME("My game name")
APP_DESCRIPTION("My First Game")
APP_AUTHOR("My name")
APP_VERSION("1.0")


// Tracks the main game loop
bool game_running = true;

// RNG pointer
RandomGenerator* rng;

// Player pointer
Player* player_pointer;

// Ends the game and is called by the event handler
void endGame() {
	game_running = false;
}

// left
void left() {
	player_pointer->moveLeft();
}

// right
void right() {
	player_pointer->moveRight();
}

// jump
void jump() {
	player_pointer->moveJump();
}


uint8_t debugprintline = 0;

extern "C"
void main() {
	calcInit(); //backup screen and init some variables

	// Put your app's code here!

	//Example for fillScreen(color);
	fillScreen(color(0,64,0));

	//Example for Debug_Printf(x,y,invert_color,0,format_string) //(small text)
	Debug_Printf(10,1,false,0,"HelloWorld%d",42);

	//use this command to actually update the screen 
	LCD_Refresh();

	//Example for getKey
	while(true){
		uint32_t key1, key2;	//First create variables
		getKey(&key1, &key2);	//then read the keys
		if(testKey(key1, key2, KEY_CLEAR)){ //Use testKey() to test if a specific key is pressed
			break;
		}
	}

	calcEnd(); //restore screen and do stuff
}