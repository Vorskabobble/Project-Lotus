#pragma once
class Stats{
private:
	int m_level;
	int m_playerID;

	float m_health;
	float m_maxHealth;

	float m_attack;
	float m_maxAttack;

	float m_armour;
	float m_maxArmour;

	float m_defence;
	float m_maxDefence;

	float m_maxRange;
	float m_maxSpeed;
public:
	Stats();
	Stats(int level, int playerID, int health, int maxHealth, int attack, int maxAttack, int armour, int maxArmour, int defence, int maxDefence, int range, int speed);
	~Stats();

	void setLevel(int level);
	void setPlayerID(int playerID);
	void setHealth(float health);
	void setMaxHealth(float health);
	void setAttack(float attack);
	void setMaxAttack(float attack);
	void setArmour(float armour);
	void setMaxArmour(float armour);
	void setDefence(float defence);
	void setMaxDefence(float defence);
	void setRange(float range);
	void setSpeed(float speed);

	int getLevel();
	int getPlayerID();
	float getHealth();
	float getMaxHealth();
	float getAttack();
	float getMaxAttack();
	float getArmour();
	float getMaxArmour();
	float getDefence();
	float getMaxDefence();
	float getRange();
	float getSpeed();
};

