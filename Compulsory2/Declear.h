#include <iostream>
#include <stdlib.h>
#include <windows.h>
#pragma once


void Login();
void BlackJack();
void AI();
void Bet();



//-----------------Bet--------------------------
int PlayerBetAmount = 100;
int AIBetAmount = 100;
int PlayerBet{};

//------------------Login-----------------------
int tries{};
const std::string username = "player";
const std::string password = "password";
std::string User;
std::string PassW;

//-----------------BlackJack--------------------
int max = 10;
int AceChoosePlayer{};
int Playerdraw{};
int playernumber{};





