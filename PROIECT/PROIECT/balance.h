#pragma once

double loadBalance();
void saveBalance(double balance);

void bet(double& betAm, double& balance);

void saveStats(int playerWins, int dealerWins);
void loadStats(int& playerWins, int& dealerWins);