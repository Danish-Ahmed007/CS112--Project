#include "raylib.h"

class Character

{
public:
    Vector2 getWorldpos() { return worldPos; }
    void tick(float deltaTime);
    void undoMovemment();
    Character(int windowWidth, int windowHeight);
    Rectangle GetCollisionRec();

private:
    Texture2D texture = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D textureIdle = LoadTexture("characters/knight_idle_spritesheet.png");
    Texture2D textureRun = LoadTexture("characters/knight_run_spritesheet.png");
    Vector2 screenPos{};
    Vector2 worldPos{};
    Vector2 worldPosLastFrame{};
    // 1. facing right direction -1. facing left direction
    float rightLeft{1.f};

    // knght variables
    float runningTime{};
    int frame{};
    int maxFrame{6};
    float updateTime{1.f / 12.f};
    const float speed{4.0};
    float width;
    float height;
    float scale{4.f};
};
