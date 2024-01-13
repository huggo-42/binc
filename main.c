#include <time.h>

#include "./raylib/raylib.h"

#define NOB_IMPLEMENTATION
#include "nob.h"

#define rec_width 100
#define rec_height 100

typedef struct {
    bool one;
    bool two;
    bool four;
    bool eight;
} ToPaint;

static ToPaint get_indexes_to_paint(int num)
{
    ToPaint indexes = {0};
    switch (num) {
        case 1:
            indexes.one = true;
            break;
        case 2:
            indexes.two = true;
            break;
        case 3:
            indexes.one = true;
            indexes.two = true;
            break;
        case 4:
            indexes.four = true;
            break;
        case 5:
            indexes.one = true;
            indexes.four = true;
            break;
        case 6:
            indexes.two = true;
            indexes.four = true;
            break;
        case 7:
            indexes.one = true;
            indexes.two = true;
            indexes.four = true;
            break;
        case 8:
            indexes.eight = true;
            break;
        case 9:
            indexes.one = true;
            indexes.eight = true;
            break;
        default:
            break;
    };
    return indexes;
}

static void draw_binary_clock(int hour, int min, int sec)
{
    int len_hour = snprintf(NULL, 0, "%d", hour);
    int first_digit = 0;
    int second_digit = 0;
    if (len_hour == 1) {
        first_digit = 0;
        second_digit = hour;
    } else {
        first_digit = hour / 10;
        second_digit = hour % 10;
    }
    ToPaint first_col = get_indexes_to_paint(first_digit);
    ToPaint scnd_col = get_indexes_to_paint(second_digit);
    if (first_col.eight) {
        DrawRectangle(20, 20, rec_width, rec_height, BLUE);
    } else {
        DrawRectangleLines(20, 20, rec_width, rec_height, BLUE);
    }
    if (first_col.four) {
        DrawRectangle(20, 140, rec_width, rec_height, BLUE);
    } else {
        DrawRectangleLines(20, 140, rec_width, rec_height, BLUE);
    }
    if (first_col.two) {
        DrawRectangle(20, 260, rec_width, rec_height, BLUE);
    } else {
        DrawRectangleLines(20, 260, rec_width, rec_height, BLUE);
    }
    if (first_col.one) {
        DrawRectangle(20, 380, rec_width, rec_height, BLUE);
    } else {
        DrawRectangleLines(20, 380, rec_width, rec_height, BLUE);
    }
    if (scnd_col.eight) {
        DrawRectangle(140, 20, rec_width, rec_height, BLUE);
    } else {
        DrawRectangleLines(140, 20, rec_width, rec_height, BLUE);
    }
    if (scnd_col.four) {
        DrawRectangle(140, 140, rec_width, rec_height, BLUE);
    } else {
        DrawRectangleLines(140, 140, rec_width, rec_height, BLUE);
    }
    if (scnd_col.two) {
        DrawRectangle(140, 260, rec_width, rec_height, BLUE);
    } else {
        DrawRectangleLines(140, 260, rec_width, rec_height, BLUE);
    }
    if (scnd_col.one) {
        DrawRectangle(140, 380, rec_width, rec_height, BLUE);
    } else {
        DrawRectangleLines(140, 380, rec_width, rec_height, BLUE);
    }

    int len_min = snprintf(NULL, 0, "%d", min);
    int third_digit = 0;
    int fourth_digit = 0;
    if (len_min == 1) {
        third_digit = 0;
        fourth_digit = min;
    } else {
        third_digit = min / 10;
        fourth_digit = min % 10;
    }
    ToPaint third_col = get_indexes_to_paint(third_digit);
    ToPaint fourth_col = get_indexes_to_paint(fourth_digit);
    if (third_col.eight) {
        DrawRectangle(290, 20, rec_width, rec_height, BLUE);
    } else {
        DrawRectangleLines(290, 20, rec_width, rec_height, BLUE);
    }
    if (third_col.four) {
        DrawRectangle(290, 140, rec_width, rec_height, BLUE);
    } else {
        DrawRectangleLines(290, 140, rec_width, rec_height, BLUE);
    }
    if (third_col.two) {
        DrawRectangle(290, 260, rec_width, rec_height, BLUE);
    } else {
        DrawRectangleLines(290, 260, rec_width, rec_height, BLUE);
    }
    if (third_col.one) {
        DrawRectangle(290, 380, rec_width, rec_height, BLUE);
    } else {
        DrawRectangleLines(290, 380, rec_width, rec_height, BLUE);
    }
    if (fourth_col.eight) {
        DrawRectangle(410, 20, rec_width, rec_height, BLUE);
    } else {
        DrawRectangleLines(410, 20, rec_width, rec_height, BLUE);
    }
    if (fourth_col.four) {
        DrawRectangle(410, 140, rec_width, rec_height, BLUE);
    } else {
        DrawRectangleLines(410, 140, rec_width, rec_height, BLUE);
    }
    if (fourth_col.two) {
        DrawRectangle(410, 260, rec_width, rec_height, BLUE);
    } else {
        DrawRectangleLines(410, 260, rec_width, rec_height, BLUE);
    }
    if (fourth_col.one) {
        DrawRectangle(410, 380, rec_width, rec_height, BLUE);
    } else {
        DrawRectangleLines(410, 380, rec_width, rec_height, BLUE);
    }

    int len_sec = snprintf(NULL, 0, "%d", sec);
    int fifth_digit = 0;
    int sixth_digit = 0;
    if (len_sec == 1) {
        fifth_digit = 0;
        sixth_digit = sec;
    } else {
        fifth_digit = sec / 10;
        sixth_digit = sec % 10;
    }
    ToPaint fifth_col = get_indexes_to_paint(fifth_digit);
    ToPaint sixth_col = get_indexes_to_paint(sixth_digit);
    if (fifth_col.eight) {
        DrawRectangle(560, 20, rec_width, rec_height, BLUE);
    } else {
        DrawRectangleLines(560, 20, rec_width, rec_height, BLUE);
    }
    if (fifth_col.four) {
        DrawRectangle(560, 140, rec_width, rec_height, BLUE);
    } else {
        DrawRectangleLines(560, 140, rec_width, rec_height, BLUE);
    }
    if (fifth_col.two) {
        DrawRectangle(560, 260, rec_width, rec_height, BLUE);
    } else {
        DrawRectangleLines(560, 260, rec_width, rec_height, BLUE);
    }
    if (fifth_col.one) {
        DrawRectangle(560, 380, rec_width, rec_height, BLUE);
    } else {
        DrawRectangleLines(560, 380, rec_width, rec_height, BLUE);
    }
    if (sixth_col.eight) {
        DrawRectangle(680, 20, rec_width, rec_height, BLUE);
    } else {
        DrawRectangleLines(680, 20, rec_width, rec_height, BLUE);
    }
    if (sixth_col.four) {
        DrawRectangle(680, 140, rec_width, rec_height, BLUE);
    } else {
        DrawRectangleLines(680, 140, rec_width, rec_height, BLUE);
    }
    if (sixth_col.two) {
        DrawRectangle(680, 260, rec_width, rec_height, BLUE);
    } else {
        DrawRectangleLines(680, 260, rec_width, rec_height, BLUE);
    }
    if (sixth_col.one) {
        DrawRectangle(680, 380, rec_width, rec_height, BLUE);
    } else {
        DrawRectangleLines(680, 380, rec_width, rec_height, BLUE);
    }
    DrawText(nob_temp_sprintf("For noobs: %02d:%02d:%02d", hour, min, sec), 295, 520, 22, RED);
}

int main ()
{
    InitWindow(800, 550, "Binary Clock");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GetColor(0x181818AA));

        time_t now = time(0);
        int hour = localtime(&now)->tm_hour;
        int min = localtime(&now)->tm_min;
        int sec = localtime(&now)->tm_sec;

        draw_binary_clock(hour, min, sec);

        EndDrawing();
    }
    return 0;
}
