#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

void name(int x)
{
	printf("triangle\n");
}

float area_triangle(float a, float b, float c)
{
	float p, S;
	p = (a + b + c) / 2;
	S = sqrt(p * (p - a) * (p - b) * (p - c));
	return S;
}
void draw_triangle(int c, char sim)
{
	for (int i = 1; i <= c; i++)
	{
		for (int j = 1; j <= c; j++)
			if (j == c || i == c || i == c - j + 1)
				putchar(sim);
			else
				putchar(' ');
		putchar('\n');
	}
	return 0;
}

void main()
{
	setlocale(LC_ALL, "rus");
	float a, b, c;
	int sch;
	char sim;
	printf("Введите стороны треугольника\n");
	scanf("%f %f %f", &a, &b, &c);
	puts("Выберите необходимое действие: 1 - рассчитать площадь, 2 - вывести определение фигуры, 3 - нарисовать фигуру");
	scanf("%d", &sch);
	float s = area_triangle(a, b, c);
	switch (sch)
	{
	case 1:
		printf("Площадь треугольника равна %f\n", s);
		break;
	case 2:
		name(a);
		break;
	case 3:
		puts("Введите символ, которым будут нарисованы фигуры:");
		while (getchar() != '\n');
		scanf("%c", &sim);
		draw_triangle(c, sim);
		break;
	default:
		printf("Неверное значение");
	}
}