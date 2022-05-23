#ifndef __PLAYER_H___
#define __PLAYER_H___

#include "DynamicObject.h"
#include "Weapon.h"


class Hero : public DynamicObject {
private:
    bool* __key;
#ifdef DIR_MOUSE
    cocos2d::Vec2* __mouse;
#endif
    
    std::pair<std::vector<weapon_t*>, int> __weapon;
    
    bool isAttacking;

public:
    Hero();
    virtual ~Hero();                                              
    
    CREATE_FUNC(Hero);                                      // Cocos create function
    
    virtual bool init() override;                           // Initialize
    void update(float dt) final;
    void setInput(cocos2d::Vec2* mouse, bool* key);
    
    void flip() final;
    void flipWeapon();
    void move(KEY state);
    void stop(KEY state);
    void run();
    void stopRun();
    
    void changeWeapon(int index);
    void setWeapon(std::vector<weapon_t*> weapons);
    void attack() final;
};

#endif /* __PLAYER_H___ */
