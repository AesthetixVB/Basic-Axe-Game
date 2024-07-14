#include "raylib.h"

int main()
{
    int width{800};
    int height{450};

    InitWindow(width, height, "Axe Game");

    // circle coordinates
    int circle_x{200};
    int circle_y{200};
    int circle_radius{25};
    // circle edges
    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};

    // axe coordinates
    int axe_x{400};
    int axe_y{0};
    int axe_length{50};
    // axe edges
    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};

    int direction{10};

    SetTargetFPS(60);

    bool collision_with_axe = 
                        (b_axe_y >= u_circle_y) && 
                        (u_axe_y <= b_circle_y) && 
                        (l_axe_x <= r_circle_x) && 
                        (r_axe_x >= l_circle_x);

    while (WindowShouldClose() != true)
    {
        BeginDrawing();
        ClearBackground(WHITE);
        
        // axe collision
        if (collision_with_axe == true)
        {
            DrawText("Game Over!", 400, 200, 20, RED);
        }
        else
        {
        // Game logic begins

        //update the edges
        l_circle_x = circle_x - circle_radius;
        r_circle_x = circle_x + circle_radius;
        u_circle_y = circle_y - circle_radius;
        u_circle_y = circle_y + circle_radius;
        l_axe_x = axe_x;
        r_axe_x = axe_x + axe_length;
        u_axe_y = axe_y;
        b_axe_y = axe_y + axe_length;
        //update collision with axe
        collision_with_axe = 
                        (b_axe_y >= u_circle_y) && 
                        (u_axe_y <= b_circle_y) && 
                        (l_axe_x <= r_circle_x) && 
                        (r_axe_x >= l_circle_x);

        DrawCircle(circle_x, circle_y, circle_radius, BLUE);
        DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);

        // move the axe
        axe_y += direction; //axe_y = axe_y + 10
        
        if (axe_y > height || axe_y < 0)
        {
            direction = -direction;
        }
        // Move Left
        if (IsKeyDown(KEY_D) && circle_x < width)
        {
            circle_x = circle_x + 10;
        }
        // Move Right
        if (IsKeyDown(KEY_A) && circle_x > 0)
        {
             circle_x -= 10; //circle_x = circle_x - 10;
        }
            
        // Game Logic ends
        
        }

        
        EndDrawing();
    }

}