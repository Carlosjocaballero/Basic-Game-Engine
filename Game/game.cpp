/*
	Include ccGE.h
	Inherit a class from ccGEApp. Override method onUpdate in it.
	Feed the name of your class to START_CCGE_GAME macro
*/

#include "ccGE.h"

class Game : public ccGE::ccGEApp 
{
public:
	Game() {}
	void onUpdate() override
	{

	}
};

START_CCGE_GAME(Game)