#include "raylib.h"
#include "raymath.h"
#include "character.h"

int main()
{
    const int windowDimensions[] = {384, 384};

    InitWindow(windowDimensions[0], windowDimensions[1], "Top down game");

    Texture2D map = LoadTexture("nature_tileset/world map.png");
    Vector2 mapPos = {0.0, 0.0};
    const float mapScale{4.0f};

    Character knight(windowDimensions[0], windowDimensions[1]);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(knight.getWorldpos(), -1.f);

        // Draw the map
        DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);
        knight.tick(GetFrameTime());

        if (knight.getWorldpos().x < 0.f ||
            knight.getWorldpos().y < 0.f ||
            (knight.getWorldpos().x + windowDimensions[0]) > map.width *mapScale ||
            (knight.getWorldpos().y + windowDimensions[1]) > map.height *mapScale)
            {
                knight.undoMovemment();
            }

            EndDrawing();
    }

    UnloadTexture(map);
    CloseWindow();
    return 0;
}
