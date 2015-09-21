//
// PointBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "ImpressionistDoc.h"
#include "ImpressionistUI.h"
#include "LineBrush.h"
#include "math.h"

extern float frand();

char* LineBrush::BrushName() {
	return ImpBrush::BrushName();
}

LineBrush::LineBrush(ImpressionistDoc* pDoc, char* name) :
	ImpBrush(pDoc, name)
{
}

void LineBrush::BrushBegin(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	int size = pDoc->getSize();



	glPointSize((float)size);

	BrushMove(source, target);
}

void LineBrush::BrushMove(const Point source, const Point target)
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg = pDoc->m_pUI;

	if (pDoc == NULL) {
		printf("LineBrush::BrushMove  document is NULL\n");
		return;
	}

	glBegin(GL_LINES);

	float radius = ((float)dlg->getSize() / 2);
	Point point = { target.x, target.y };

	int counter = strcmp(BrushName(), "Scattered Lines") != 0 ? 1 : (float)dlg->getSize();

	for (int i = 0; i < counter; i++) {
		SetColor(point);

		glVertex2d(point.x - radius, point.y);
		glVertex2d(point.x + radius, point.y);

		if (counter != 1) {
			do {
				point = { Math::rand_range(target.x - radius, target.x + radius), Math::rand_range(target.y - radius, target.y + radius) };
			} while (fabs(Math::distance(point.x, point.y, target.x, target.y) - radius) > 0.05f);
		}
	}

	glEnd();
}

void LineBrush::BrushEnd(const Point source, const Point target)
{
	// do nothing so far
}

