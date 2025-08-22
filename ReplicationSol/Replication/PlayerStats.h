#pragma once
class PlayerStats
{
private:
	int health;
	int attack;
	int defence;
	int baseDamage;

	int maxhealth;
public:
	PlayerStats(int health, int attack, int defence, int baseDamage);
	void HealPlayer(int amt);
	void DamagePlayer(int amt);
	void AddAttack(int amt);
	void AddDefence(int amt);

	void RemoveAttack(int amt);
	void RemoveDefence(int amt);

	int GetHealth() const;
	int GetAttack() const;
	int GetDefence() const;
	int GetMaxHealth() const;
	int GetBaseDamage() const;

	void ResetStats();
};

