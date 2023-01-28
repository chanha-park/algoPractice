#include <stdio.h>
#include <math.h>

double	g = 9.81;

int	determinant(double j, double p, double h, double l)
{
	if ((h + p) * 4 * j > l * l)
		return (3);
	else if (((p + h / 2.0) * j) > (l * l / 16.0))
		return (2);
	else
		return (1);
}

double	solve_quad(double a, double b, double c)
{
	double	d = b * b - 4.0 * a * c;
	double	ans;

	ans = -b + sqrt(d);
	ans = ans / (2.0 * a);
	return (ans);
}

double	v_final(double vx, double vy)
{
	return (sqrt(vx * vx + vy * vy));
}

double	degree1(double h, double d, double l, double vx, double vy)
{
	double	tan_slope = 4.0 * h * d / (l * l);
	double	tan_v = vy / vx;

	return ((180.0 / M_PI) * atan((tan_v - tan_slope) / (1 + tan_slope * tan_v)));
}

void	slope1(double j, double p, double h, double l)
{
	double	vx, vy, t, d;

	vx = sqrt(2 * g * j);
	t = sqrt(p / (g * (0.5 - 4.0 * h * j / (l * l))));
	d = vx * t;
	vy = g * t;
	printf("%f %f %f\n", d, v_final(vx, vy), degree1(h, d, l, vx, vy));
}

double	degree2(double h, double d, double l, double vx, double vy)
{
	double	tan_slope = 4.0 * h * (1.0 - d / l) / l;
	double	tan_v = vy / vx;

	return ((180.0 / M_PI) * atan((tan_v - tan_slope) / (1.0 + tan_slope * tan_v)));
}

void	slope2(double j, double p, double h, double l)
{
	double	vx, vy, t, d;
	double	a, b, c;

	vx = sqrt(2 * g * j);
	a = g * (0.5 + 4.0 * h * j / (l * l));
	b = -4.0 * h * vx / l;
	c = h - p;
	t = solve_quad(a, b, c);
	d = vx * t;
	vy = g * t;
	printf("%f %f %f\n", d, v_final(vx, vy), degree2(h, d, l, vx, vy));
}

double	degree3(double vx, double vy)
{
	return ((180.0 / M_PI) * atan(vy / vx));
}

void	slope3(double j, double p, double h)
{
	double	vx, vy, t, d;

	vx = sqrt(2 * g * j);
	t = sqrt(2 * (h + p) / g);
	d = vx * t;
	vy = g * t;
	printf("%f %f %f\n", d, v_final(vx, vy), degree3(vx, vy));
}

void	print_result(int j, int p, int h, int l)
{
	int	det = determinant(j, p, h, l);
	
	if (det == 1)
		slope1(j, p, h, l);
	else if (det == 2)
		slope2(j, p, h, l);
	else
		slope3(j, p, h);
}

int	main(void)
{
	int	t, j, p, h, l;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d %d %d", &j, &p, &h, &l);
		print_result(j, p, h, l);
	}
	return (0);
}
