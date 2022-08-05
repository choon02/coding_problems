#include "Player.h"
#include "Game.h"

std::default_random_engine Player::random_engine(time(nullptr));
//민첩성
std::uniform_int_distribution<unsigned int> Player::ability_range(0, 100);
//기회
std::uniform_real_distribution<float> Player::possibility(0.f, 1.f);

float PlayerRLGL::fallDownRate = 0.1f;

Player::Player(int number)
{
	this->number = number;

	agility = ability_range(random_engine);
	fearlessness = ability_range(random_engine);
}

Player::Player(int number, int agility, int fearlessness)
{
	// player 번호
	this->number = number;
	// 민첩성
	this->agility = agility;
	// 겁 없음
	this->fearlessness = fearlessness;
}

bool PlayerRLGL::act()
{
	std::uniform_int_distribution<int> random1(0, 10); 
	std::uniform_int_distribution<int> random2(0, 100);
	int random_distance = random1(random_engine);
	int fearlessbonus_distance;
	int random_bonus = random2(random_engine);
	int random_number = random2(random_engine);
	// bonus_chance 받았으나 25%의 확률로 떨어짐
	if (random_bonus <= fearlessness && random_number <= (int)RedLightGreenLight::fallDownRate * 100) 
		return false;
	// bonus_chance 받았고 75%의 확률로 더 감
	else if(random_bonus <= fearlessness && random_number > (int)RedLightGreenLight::fallDownRate * 100)
	{
		fearlessbonus_distance = agility * (fearlessness * 0.01);
		this->current_distance = agility + random_distance + fearlessbonus_distance;
		Player::total_distance += this->current_distance;
		return true;
	}
	// bonus_chance 못 받음 //fearless가 낮을 수록 bonus distance을 받을 수 있으나 떨어질 수 있다.
	else 
	{
		fearlessbonus_distance = 0;
		this->current_distance = agility + random_distance + fearlessbonus_distance;
		Player::total_distance += this->current_distance;
		return true;
	}
}

void PlayerRLGL::dyingMessage()
{ 
	if (isPlaying())
	{
		printStatus();
		std::cout << " is still on the ground and died." << std::endl;
	}
		
	else
	{
		printStatus();
		std::cout << " fell down and died." << std::endl;
	}
};
void PlayerRLGL::escapeMessage()
{
		printStatus();
		std::cout << " safely escaped from the ground." << std::endl;
}





bool PlayerRPS::act()
{
	enum rpsType { Rock, Paper, Scissors };
	auto rps = [] {
		float p = possibility(random_engine);
		// 가위 바위 보 배정
		if (p < float(1.f / 3.f))
			return rpsType::Rock;
		else if (p < float(2.f / 3.f))
			return rpsType::Paper;
		else
			return  rpsType::Scissors;
	};

	rpsType myRPS, yourRPS;
	do {
		myRPS = rps();
		yourRPS = rps();
	}
	while(myRPS == yourRPS);
	// 가위바위보 규칙에 따른 조건문
	if (myRPS == Rock)
	{
		if (yourRPS == Paper)
			return false;
		else
			return true;
	}
	else if (myRPS == Paper)
	{
		if (yourRPS == Scissors)
			return false;
		else
			return true;
	}
	else
	{
		if (yourRPS == Rock)
			return false;
		else
			return true;
	}
}


void PlayerRPS::dyingMessage()
{
	printStatus();
	std::cout << " died." << std::endl;
};

bool PlayerSS::act()
{
	std::uniform_int_distribution<int> random(0, 1);
	
	for (int i = 0; i < 5; i++)
	{ // 선택과 정답을 랜덤으로 배정
		choice[i] = random(random_engine);
		answer[i] = random(random_engine);
	}
	for (int i = 0; i < 5 ; i++)
	{// game class에서 사용하기 위해 배열값을 그대로 옮겨줌
		choice[i] = _choice[i]; 
		answer[i] = _answer[i];
	}
	// agility + fearlessness가 120이하인 경우 도전 포기하거나 떨어짐
	if (agility + fearlessness >= 120) 
		return true;
	else 
		return false;
}
void PlayerSS::dyingMessage()
{
	printStatus();
	std::cout << " died." << std::endl;
}