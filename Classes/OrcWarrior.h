#ifndef __ORC_WARRIOR_H__
#define __ORC_WARRIOR_H__

#include "BaseMonster.h"


class OrcWarrior : public BaseMonster {
public:
    OrcWarrior() : BaseMonster("orc_warrior") {}
    ~OrcWarrior() {}

    CREATE_FUNC(OrcWarrior);

    bool init() final {
        IF(!BaseMonster::init());
        setHP(150);
        setDamage(1);
        setSpeed(1.5f);
        attackRange = 300.0f;
        detectRange = 300.0f;

        PhysicsObject::scale(0.6f, b2Vec2(0.0f, 0.0f));
        
        return true;
    }
    virtual void followTarget()
    {
        float distance = std::numeric_limits<float>::max();
        auto diff = cocos2d::Vec2::ZERO;

        for (auto iter : __target) {
            diff = iter->getPosition() - getPosition();
            float diff_len = length(diff);
            if (distance > diff_len) distance = diff_len;
        }

        if (diff == cocos2d::Vec2::ZERO) return;
        normalize(diff);
        setVelocity(C2B(diff));
        setFuture(MOVE);
    }
    void roaming()
    {
        cocos2d::Vec2 vec = AI->getRoamVec();
        setVelocity(b2Vec2(vec.x, vec.y));
        setFuture(MOVE);
    }
    virtual void attack() final
    {
        followTarget();
    }
};

#endif /* __ORC_WARRIOR_H__ */
