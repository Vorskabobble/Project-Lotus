#pragma once
class Stats{
private:
	int m_level;
	int m_playerID;

	int m_health;
	int m_maxHealth;

	int m_attack;
	int m_maxAttack;

	int m_armour;
	int m_maxArmour;

	int m_defence;
	int m_maxDefence;

	int m_maxRange;
	float m_maxSpeed;
public:
	Stats();
	Stats(int level, int playerID, int health, int maxHealth, int attack, int maxAttack, int armour, int maxArmour, int defence, int maxDefence, int range, int speed);
	~Stats();

	void setLevel(int level);
	void setPlayerID(int playerID);
	void setHealth(int health);
	void setMaxHealth(int health);
	void setAttack(int attack);
	void setMaxAttack(int attack);
	void setArmour(int armour);
	void setMaxArmour(int armour);
	void setDefence(int defence);
	void setMaxDefence(int defence);
	void setRange(int range);
	void setSpeed(float speed);

	int getLevel();
	int getPlayerID();
	int getHealth();
	int getMaxHealth();
	int getAttack();
	int getMaxAttack();
	int getArmour();
	int getMaxArmour();
	int getDefence();
	int getMaxDefence();
	int getRange();
	float getSpeed();
};

