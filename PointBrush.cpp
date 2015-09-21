//
// PointBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "pointbrush.h"
#include "math.h"

extern float frand();

PointBrush::PointBrush( ImpressionistDoc* pDoc, char* name ) :
	ImpBrush(pDoc,name)
{
}

char* PointBrush::BrushName() {
	return ImpBrush::BrushName();
}

void PointBrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	int size = pDoc->getSize();



	glPointSize( (float)size );

	BrushMove( source, target );
}

void PointBrush::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	if ( pDoc == NULL ) {
		printf( "PointBrush::BrushMove  document is NULL\n" );
		return;
	}

	glPointSize(0.1f);

	glBegin( GL_POINTS );

	float radius = ((float)dlg->getSize() / 2);
	Point point = { target.x, target.y };
	
	int counter = strcmp(BrushName(), "Scattered Points") != 0 ? 1 : (float)dlg->getSize();
	
	for (int i = 0; i < counter; i++) {
		SetColor(point);
		glVertex2d(point.x, point.y);

		if (counter != 1) {
			do {
				point = { Math::rand_range(target.x - radius, target.x + radius), Math::rand_range(target.y - radius, target.y + radius) };
			} while (fabs(Math::distance(point.x, point.y, target.x, target.y) - radius) > 0.05f);
		}
	}

	glEnd();
}

void PointBrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
}

