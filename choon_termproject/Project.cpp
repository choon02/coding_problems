// 프로그래밍 입문(2) term project 교수님이 짜신 코드 중 빈칸 완성하는 과제
// 제가 짠 부분은 stepping stone 게임 전체와
// bool PlayerRLGL::act()
// void RedLightGreenLight::play()
#include <iostream>
#include "Player.h"
#include "Game.h"
int main()
{
    //player 생성
    std::list<Player*> players;
    for (int i = 0; i < 456; ++i)
    {
        players.push_back(new Player(i+1));
    }
    // vector games에 게임 넣기
    std::vector<Game*> games;
    games.push_back(new RedLightGreenLight(10));
    games.push_back(new RPS());
    games.push_back(new SteppingStone());
    
    // 넣어진 게임 만큼 for문 돌리기
    for (auto game : games)
    {
        for (auto player : players)
            game->join(player);
        //게임 실행
        game->play();
        //생존자 alive players에 넣기
        auto alivePlayers = game->getAlivePlayers();
        //players 전부 없애기
        players.clear();
        for (auto player : alivePlayers)
        {
            // 생존자 새로운 player에 다시 넣기
            players.push_back(new Player(*player));
        }
    }
    // game 삭제
    for (auto game : games)
        delete game;

    system("pause");
    return 0;
}