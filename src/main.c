#include <stdio.h>

struct area {
	double	area;
	double	length;
	double	width;
	double	height;

	double	(*getLength)	(struct area);
	double	(*getWidth)		(struct area);
	double	(*getHeight)	(struct area);
	double	(*getArea)		(struct area);

	void	(*setLength)	(struct area *, double);
	void	(*setWidth)		(struct area *, double);
	void	(*setHeight)	(struct area *, double);
};

double gL(struct area data)
{
	return data.length;
}

double gW(struct area data)
{
	return data.width;
}

double gH(struct area data)
{
	return data.height;
}

double gA(struct area data)
{
	return data.height * data.length * data.width;
}

void sL(struct area *data, double arg)
{
	data->length = arg;
}

void sW(struct area *data, double arg)
{
	data->width = arg;
}

void sH(struct area *data, double arg)
{
	data->height = arg;
}

void struct_init(struct area *data)
{
	data->setHeight	= sH;
	data->setWidth	= sW;
	data->setLength	= sL;
	data->getHeight	= gH;
	data->getWidth	= gW;
	data->getLength	= gL;
	data->getArea	= gA;
	data->height	= 0;
	data->width		= 0;
	data->length	= 0;
}

int
main (int argc, char *argv[])
{
	struct area mine;
	struct_init(&mine);
	printf("L: %.3lf W: %.3lf H: %.3lf\n",
			mine.getLength	(mine),
			mine.getWidth	(mine),
			mine.getHeight	(mine)
			);

	mine.setLength	(&mine, 3);
	mine.setWidth	(&mine, 3);
	mine.setHeight	(&mine, 3);

	printf("L: %.3lf W: %.3lf H: %.3lf\n",
			mine.getLength	(mine), 
			mine.getWidth	(mine), 
			mine.getHeight	(mine)
			);
	printf("A: %.3lf\n", 
			mine.getArea	(mine)
			);
	return 0;
}
