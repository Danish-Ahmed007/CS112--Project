#include "character.h"
#include "raymath.h"

void Character::undoMovemment()
{
    worldPos = worldPosLastFrame;
}

Character ::Character(int windowWidth, int windowHeight)
{
    width = texture.width / maxFrame;
    height = texture.height;
    screenPos = {static_cast<float>(windowWidth) / 2.0f - scale * (0.5f * width),
                 static_cast<float>(windowHeight) / 2.0f - scale * (0.5f * height)};
}

void Character::tick(float deltaTime)
{
    worldPosLastFrame = worldPos;

    Vector2 direction{};

    if (IsKeyDown(KEY_S))
        direction.y += 1.0;
    if (IsKeyDown(KEY_W))
        direction.y -= 1.0;
    if (IsKeyDown(KEY_A))
        direction.x -= 1.0;
    if (IsKeyDown(KEY_D))
        direction.x += 1.0;

    if (Vector2Length(direction) != 0.0)
    {
        worldPos = Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
        direction.x < 0.0 ? rightLeft = -1 : rightLeft = 1;
        texture = textureRun;
    }
    else
        texture = textureIdle;

    // update animation frame
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;
        if (frame > maxFrame)
            frame = 0;
    }

    // draw the character
    Rectangle knightDest = {screenPos.x, screenPos.y, scale * width, scale * height};
    Rectangle knightSource = {frame * width, 0.0, rightLeft * width, height};

    DrawTexturePro(texture, knightSource, knightDest, Vector2{}, 0.0, WHITE);

    DrawTexturePro(texture, knightSource, knightDest, Vector2{}, 0.0, WHITE);
}


    Rectangle Character:: GetCollisionRec(){

        return Rectangle{
            screenPos.x,
            screenPos.y,
            width * scale,
            height * scale
        };
    }

