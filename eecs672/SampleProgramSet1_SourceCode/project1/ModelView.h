// ModelView.h - a basic combined Model and View for OpenGL

#ifndef MODELVIEW_H
#define MODELVIEW_H

#include "ShaderIF.h"

#include <string>

#ifdef __APPLE_CC__
#include "GLFW/glfw3.h"
#else
#include <GL/gl.h>
#endif

typedef float vec2[2]; // coordinates
typedef float vec3[3]; // colors

class ModelView
{
public:
	/**
	 * @param sIF       The GLSL Shader Interface object
	 * @param coords    The array of coordinates provided from the data file
	 * @param nVertices The number of vertices in the curve
	 */
	ModelView(ShaderIF* sIF, vec2* coords, int nVertices);
	virtual ~ModelView();

	// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
	void getMCBoundingBox(double* xyzLimits) const;
	bool handleCommand(unsigned char anASCIIChar, double ldsX, double ldsY);
	void render() const;

	// Viewing controls common to 2D and 3D:
	static void setAspectRatioPreservationEnabled(bool b)
		{ aspectRatioPreservationEnabled = b; }
	static void setMCRegionOfInterest(double xyz[6]);

private:
	ShaderIF* shaderIF;
	GLuint vao[1];  // VAO for the curve
	GLuint vbo[1];  // VBO for the curve coordinates
	vec3 lineColor; // color of the curve - passed as a uniform

	int numVertices;  // number of vertices in the curve
	int serialNumber; // a unique(?) number representing each MV instance
	double xmin, xmax, ymin, ymax;

	// Routines for computing parameters necessary to map from arbitrary
	// model coordinate ranges into OpenGL's -1..+1 Logical Device Space.
	// 1. linearMap determines the scale and translate parameters needed in
	//    order to map a value, f (fromMin <= f <= fromMax) to its corresponding
	//    value, t (toMin <= t <= toMax). Specifically: t = scale*f + trans.
	static void linearMap(double fromMin, double fromMax,
		double toMin, double toMax, double& scale, double& trans);
	// 2. matchAspectRatio modifies (xmin,xmax) OR (ymin,ymax) to center that
	//    region in an expanded window that matches the given aspect ratio.
	static void matchAspectRatio(double& xmin, double& xmax,
		double& ymin, double& ymax, double vAR);
	// 3. compute2DScaleTrans uses the current model coordinate region of
	//    interest - modified as necessary to preserve aspect ratios - and
	//    then passes the modified limits to linearMap to compute the scale
	//    and translation needed to map MC to LDS.
	//    (The scales and translationes are returned in float[] because
	//    glUniform currently allows only float[].)
	static void compute2DScaleTrans(float* scaleTrans);

	static double mcRegionOfInterest[6];
	static bool aspectRatioPreservationEnabled;

	// count the number of instances create (for serialNumber)
	static int numInstances;

	// table of 6 different colors a line could possess
	static vec3 colorTable[6];

	/**
	 * Initializes the ModelView geometry (i.e. creates the VAO/VBO(s)
	 * and make them active)
	 * @param coords The array coordinates representing the curve
	 */
	void initModelGeometry(vec2* coords);
};

#endif
