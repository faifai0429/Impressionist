#include "ImpressionistDoc.h"
#include "ImpressionistUI.h"
#include "CircleBrush.h"
#include "math.h"

extern float frand();

CircleBrush::CircleBrush(ImpressionistDoc* pDoc, char* name) :
	ImpBrush(pDoc, name)
{
}

char* CircleBrush::BrushName() {
	return ImpBrush::BrushName();
}

void CircleBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();



	glPointSize((float)size);

	BrushMove(source, target);
}

void CircleBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("CircleBrush::BrushMove  document is NULL\n");
		return;
	}

	glBegin(GL_TRIANGLE_FAN);
	
	float theta, pos_x, pos_y = 0.0f;
	float radius = ((float)dlg->getSize() / 2);
	Point center = { target.x, target.y };
	Point _center_;
	int counter = strcmp(BrushName(), "Scattered Circles")!=0 ? 1 : 3;

	for (int i = 0; i < counter; i++) {
		
		SetColor(center);
		
		for (int j = 0; j < 360; j++)
		{
			theta = 2 * M_PI * j / 360;
			pos_x = center.x + cos(theta) * radius;
			pos_y = center.y + sin(theta) * radius;
			glVertex2f(pos_x, pos_y);
		}

		if (counter!=1) {
			do {
				_center_ = { Math::rand_range(center.x - radius, center.x + radius), Math::rand_range(center.y - radius, center.y + radius) };
			} while (fabs(Math::distance(center.x, center.y, _center_.x, _center_.y) - radius) > 0.05f);
			center = _center_;
		}
	}

	glEnd();
}

void CircleBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

