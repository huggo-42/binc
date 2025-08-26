#include <stdio.h>
#include <time.h>

#include "./raylib/raylib.h"

// #define bw 100
// #define bh 100

typedef struct
{
	bool one;
	bool two;
	bool four;
	bool eight;
} ToPaint;

typedef struct
{
	int first_digit;
	int second_digit;
} TimeDigits;

static TimeDigits extract_digits_from_time(int num)
{
	TimeDigits digits = {0};
	int len_hour = snprintf(NULL, 0, "%d", num);
	digits.first_digit = 0;
	digits.second_digit = 0;
	if (len_hour == 1)
	{
		digits.first_digit = 0;
		digits.second_digit = num;
	}
	else
	{
		digits.first_digit = num / 10;
		digits.second_digit = num % 10;
	}
	return digits;
}

static ToPaint get_indexes_to_paint(int num)
{
	ToPaint indexes = {0};
	switch (num)
	{
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

void draw_rect(bool filled, int posX, int posY, int width, int height)
{
	if (filled)
	{
		DrawRectangle(posX, posY, width, height, BLUE);
	}
	else
	{
		DrawRectangleLines(posX, posY, width, height, BLUE);
	}
}

int calc_col_posX(int x_axis_padding, float square_width, int col_idx)
{
	int col_pos_x = x_axis_padding;
	if (col_idx < 3)
	{
		col_pos_x = x_axis_padding * col_idx + square_width * (col_idx - 1);
	}
	else if (col_idx < 5)
	{
		col_pos_x =
			x_axis_padding * (col_idx + 1) + square_width * (col_idx - 1);
	}
	else
	{
		col_pos_x =
			x_axis_padding * (col_idx + 2) + square_width * (col_idx - 1);
	}
	return col_pos_x;
}

void draw_col_blocks(int col_idx, int digit)
{
	float y_axis_padding = (float)GetScreenHeight() / 5 / 8;
	float x_axis_padding = (float)GetScreenWidth() / 6 / 8;

	float square_height = (GetScreenHeight() - y_axis_padding * 5) / 4;
	float square_width = (GetScreenWidth() - x_axis_padding * 9) / 6;

	int eight_col_y_axis_padding = y_axis_padding;
	int four_col_y_axis_padding = y_axis_padding * 2 + square_height;
	int two_col_y_axis_padding = y_axis_padding * 3 + square_height * 2;
	int one_col_y_axis_padding = y_axis_padding * 4 + square_height * 3;

	int col_posX = calc_col_posX(x_axis_padding, square_width, col_idx);

	ToPaint blocks = get_indexes_to_paint(digit);
	draw_rect(blocks.eight, col_posX, eight_col_y_axis_padding, square_width,
			  square_height);
	draw_rect(blocks.four, col_posX, four_col_y_axis_padding, square_width,
			  square_height);
	draw_rect(blocks.two, col_posX, two_col_y_axis_padding, square_width,
			  square_height);
	draw_rect(blocks.one, col_posX, one_col_y_axis_padding, square_width,
			  square_height);
}

static void draw_binary_clock(int hour, int min, int sec)
{
	TimeDigits digits = extract_digits_from_time(hour);
	draw_col_blocks(1, digits.first_digit);
	draw_col_blocks(2, digits.second_digit);

	digits = extract_digits_from_time(min);
	draw_col_blocks(3, digits.first_digit);
	draw_col_blocks(4, digits.second_digit);

	digits = extract_digits_from_time(sec);
	draw_col_blocks(5, digits.first_digit);
	draw_col_blocks(6, digits.second_digit);
}

int main()
{
	InitWindow(800, 600, "Binc");
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
