#include "mayaMVG/maya/context/MVGManipContainer.h"
#include "mayaMVG/maya/context/MVGContext.h"
#include "mayaMVG/core/MVGLog.h"
#include "mayaMVG/maya/MVGMayaUtil.h"
#include <maya/MFnDagNode.h>

using namespace mayaMVG;

MTypeId MVGManipContainer::id(0x99999);
MString MVGManipContainer::drawDbClassification("drawdb/geometry/MVGManip");
MString MVGManipContainer::drawRegistrantId("MVGManipNode");

MVGManipContainer::MVGManipContainer() :
	m_ctx(NULL)
{
}

MVGManipContainer::~MVGManipContainer()
{
}

void * MVGManipContainer::creator()
{
	return new MVGManipContainer();
}

MStatus MVGManipContainer::initialize()
{
	return MPxManipContainer::initialize();
}

MStatus MVGManipContainer::createChildren()
{
	return MStatus::kSuccess;
}

void MVGManipContainer::draw(M3dView & view, const MDagPath & path,
                               M3dView::DisplayStyle style, M3dView::DisplayStatus dispStatus)
{
	// // draw children
	// MPxManipContainer::draw(view, path, style, dispStatus);

	// // get infos from context
	// if(!m_ctx)
	// 	return;
	// MVGContext::vpoint_t points = m_ctx->points(); // have to cpy

	// // LINES
	// view.beginGL();
	// glPushAttrib(GL_ALL_ATTRIB_BITS);
	// glBegin(GL_LINES);
	// for(size_t i = 0; i < points.size(); ++i) {
	// 	glVertex3f(points[i].wpos.x, points[i].wpos.y, points[i].wpos.z);
	// 	glVertex3f(points[i].wpos.x+points[i].wdir.x*5000.f, points[i].wpos.y+points[i].wdir.y*5000.f, points[i].wpos.z+points[i].wdir.z*5000.f);
	// }
	// glEnd();
	// glPopAttrib();
	// view.endGL();


	// if(!MVGMayaUtil::isMVGView(view) || !MVGMayaUtil::isActiveView(view))
	// 	return;

	// // POINTS
	// view.beginGL();
	// glPushAttrib(GL_ALL_ATTRIB_BITS);
	// glBegin(GL_LINE_STRIP);
	// for(size_t i = 0; i < points.size(); ++i) {
	// 	glVertex3f(points[i].wpos.x+points[i].wdir.x*50.f, points[i].wpos.y+points[i].wdir.y*50.f, points[i].wpos.z+points[i].wdir.z*50.f);
	// }
	// glEnd();
	// glPopAttrib();
	// view.endGL();



	// // CURSOR
	// view.beginGL();
	// glPushAttrib(GL_ALL_ATTRIB_BITS);

	// size_t mousex = m_ctx->mousePosX();
	// size_t mousey = m_ctx->mousePosY();
	// GLdouble radius = 3.0;
	// glMatrixMode(GL_PROJECTION);
	// glPushMatrix();
	// glLoadIdentity();
	// glOrtho(0, view.portWidth(), 0, view.portHeight(), -1, 1);
	// glMatrixMode(GL_MODELVIEW);
	// glPushMatrix();
	// glColor3f(1.f, 0.f, 0.f);
	// glLoadIdentity();
	// glBegin(GL_LINES);
	// glVertex2f((GLfloat)(mousex + (cos(M_PI / 4.0f) * (radius + 10.0f))),
	//            (GLfloat)(mousey + (sin(M_PI / 4.0f) * (radius + 10.0f))));
	// glVertex2f((GLfloat)(mousex + (cos(-3.0f * M_PI / 4.0f) * (radius + 10.0f))),
	//            (GLfloat)(mousey + (sin(-3.0f * M_PI / 4.0f) * (radius + 10.0f))));
	// glVertex2f((GLfloat)(mousex + (cos(3.0f * M_PI / 4.0f) * (radius + 10.0f))),
	//            (GLfloat)(mousey + (sin(3.0f * M_PI / 4.0f) * (radius + 10.0f))));
	// glVertex2f((GLfloat)(mousex + (cos(-M_PI / 4.0f) * (radius + 10.0f))),
	//            (GLfloat)(mousey + (sin(-M_PI / 4.0f) * (radius + 10.0f))));
	// glEnd();
	// glPopMatrix();
	// glMatrixMode(GL_PROJECTION);
	// glPopMatrix();

	// glPopAttrib();
	// view.endGL();
}

void MVGManipContainer::setContext(MVGContext * ctx) {
	m_ctx = ctx;
}
