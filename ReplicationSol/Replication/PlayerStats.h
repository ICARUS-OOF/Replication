#pragma once
class PlayerStats
{
private:
	int health;
	int attack;
	int defence;
	int maxhealth;
public:
	PlayerStats(int health, int attack, int defence);
	void HealPlayer(int amt);
	void DamagePlayer(int amt);
	void AddAttack(int amt);
	void AddDefence(int amt);
};

