#pragma once
#include <memory>
#include <string>

class Player
{
protected:
    std::string name_;
    int health_ = 0;
    int team_id_ = 0;
    float pos_x_ = 0;
    float pos_y_ = 0;
    float pos_z_ = 0;
    std::string weapon_;
    int damage_output_ = 0;
public:
    Player() = default;
    virtual ~Player() = default;
    virtual std::unique_ptr<Player> clone() const = 0;
    virtual void DisplayStatus() const;
};