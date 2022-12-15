/*
	Include ccGE.h
	Inherit a class from ccGEApp. Override method onUpdate in it.
	Feed the name of your class to START_CCGE_GAME macro
*/

#include <cstdlib>
#include "ccGE.h"

class Game : public ccGE::ccGEApp
{
public:
	Game()
	{
		srand((unsigned)time(NULL));
		ccGE::ccGEWindow::GetWindow()->SetKeyPressedCallback(
		[this](const ccGE::KeyPressedEvent& event) {OnKeyPress(event);});

		ccGE::ccGEWindow::GetWindow()->SetKeyReleasedCallBack(
		[this](const ccGE::KeyReleasedEvent& event) {OnKeyRelease(event);});

	}
	void onUpdate() override
	{
		ccGE::Renderer::Draw(background, 0, 0, 1);
		player.setCoord(p_x, p_y, 1);
		enemy.setCoord(e_x, e_y, 1);
		ccGE::Picture defaultPlayer{ "Assets/Textures/lookingRight.png" };
		ccGE::Renderer::Draw(defaultPlayer, p_x, p_y, 1);
		if (gameIsOver) {
			while (true) {}
		}

		if (m_State == CharState::MOVE_UP && player.GetY() < 738) {
			ccGE::Picture goingUp{ "Assets/Textures/lookingUp.png" };
			ccGE::Renderer::Draw(goingUp, p_x, p_y, 1);
			p_y += 10;
		}
		else if (m_State == CharState::MOVE_DOWN && player.GetY() > 0) {
			ccGE::Picture goingDown{ "Assets/Textures/lookingDown.png" };
			ccGE::Renderer::Draw(goingDown, p_x, p_y, 1);
			p_y -= 10;
		}

		ccGE::Picture enemyPic{ chosenEnemy };
		ccGE::Renderer::Draw(enemyPic, e_x, e_y, 1);

		if (enemy.GetX() < -100) {
			int randYCoord = rand() % 800;
			int randEnemy = rand() % 3;
			chosenEnemy = enemyNames[randEnemy];
			e_x = 1000; e_y = randYCoord;
			enemy.setCoord(e_x, e_y, 1);
			if (enemyVelocity < 30) {
				enemyVelocity ++;
			}
		}
		else e_x -= enemyVelocity;

		if (player.OverlapsWith(enemy)) {
			ccGE::Renderer::Draw(gameOver, 300, 200, 1);
			gameIsOver = true;
		}

		
	}

private:
	ccGE::Unit player{ "Assets/Textures/lookingRight.png" };
	ccGE::Picture background{ "Assets/Textures/background.png" };
	ccGE::Picture gameOver{ "Assets/Textures/game_over.png" };
	int windowHeight = ccGE::ccGEWindow::GetWindow()->GetHeight();
	int p_x{ 20 }, p_y{ 400 }, e_x{900}, e_y{200};
	int enemyVelocity{17};
	bool gameIsOver = false;

	ccGE::Unit enemy{ "Assets/Textures/enemy1.png" };

	std::string chosenEnemy = "Assets/Textures/enemy1.png";

	std::vector<std::string> enemyNames = {
		"Assets/Textures/enemy1.png",
		"Assets/Textures/enemy2.png",
		"Assets/Textures/enemy3.png"
	};

	enum class CharState {
		MOVE_UP,
		MOVE_DOWN, STILL
	} m_State{ CharState::STILL };

	void OnKeyPress(const ccGE::KeyPressedEvent& event)
	{

		switch (event.GetKeyCode())
		{
		case CCGE_KEY_UP:
			m_State = CharState::MOVE_UP;
			break;
		case CCGE_KEY_DOWN:
			m_State = CharState::MOVE_DOWN;
			break;
		}
	}

	void OnKeyRelease(const ccGE::KeyReleasedEvent& event)
	{
		switch (event.GetKeyCode())
		{
		case CCGE_KEY_UP:
			if (m_State == CharState::MOVE_UP)
				m_State = CharState::STILL;
			break;
		case CCGE_KEY_DOWN:
			if (m_State == CharState::MOVE_DOWN)
				m_State = CharState::STILL;
			break;
		}
	}
};



START_CCGE_GAME(Game)