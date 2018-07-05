#ifndef MONSTER_H
#define MONSTER_H
#include"Character.h"

class Monster :public Character
{
public:
	virtual void PersonInitual(int type, int _x, int _y);//¹ÖÎï³õÊ¼»¯

	//¹ÖÎï±àºÅ type :1¡¢¾Þ³Ýöè 2¡¢ÃÍáï¾ÞÏó 3¡¢¹Å±¤¾ÞÄ§ 4¡¢Ïº±ø 5¡¢Ð·½« 6¡¢Äö³ÝÊó 7¡¢ÊÉÒÏÈº
	              //8¡¢ÎüÑªòð 9¡¢Ò¹ÈËÀÇ 10¡¢ºÚ»¯Ð¡Ç¿ 11¡¢½´ÓÍÑî 12¡¢½´ÓÍ¸Õ

	virtual void GainExp(int _exp){};//»ñµÃ¾­Ñé
	virtual void GainMoney(int _money){};//»ñµÃ½ð±Ò
	virtual void Upgrade(){};//Éý¼¶
	virtual void Move(){};//ÈËÎïÒÆ¶¯
	void monsterStatus(int Number, int _x, int _y);
	
};

#endif
