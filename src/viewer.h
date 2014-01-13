#ifndef VIEWER_H
#define VIEWER_H

#include <GL/glew.h>
#define GLFW_INCLUDE_GLU
#include <GL/glfw.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/quaternion.hpp>

#include <vector>
#include <string>

#define BUFFER_OFFSET(offset) ((void *) (offset))

enum VAO_IDs { Vertices, IKDebugVertices, RigidDebugVertices, groundVAO, NumVAOs };
enum Buffer_IDs { VertexArrayBuffer, VertexIndexBuffer, IKVertexArrayBuffer, RecordBuffer, depthBuffer, groundBuffer, NumBuffers };
enum Attrib_IDs { vPosition, vUV, vNormal, vBoneIndices, vBoneWeights, vWeightFormula };
enum Uniform_IDs { 
	uAmbient,uDiffuse,uSpecular,uShininess,
	uIsEdge,uEdgeColor,uEdgeSize,
	uHalfVector,uLightDirection,
	uSphereMode,
	uTextureSampler,uSphereSampler,uToonSampler,
	uDrawShadow,uDepthBiasMVP,uShadowMap,
	NumUniforms };

struct PMXInfo;
struct VMDInfo;
class VMDMotionController;
class BulletPhysics;
class MMDPhysics;
class VertexData;


class Viewer
{
	public:
	Viewer(std::string modelPath, std::string motionPath, std::string musicPath="");
	~Viewer();
	
	void run();
		
	
	private:
	void initGLFW();
	void initUniformVarLocations();
	void loadTextures();
	void initBuffers();
	
	void handleEvents();
	void handleLogic();
	void render();
	
	void setCameraMVP(GLuint MVPLoc);
	glm::mat4 getCameraMVP();
	void holdModelInBindPose();
	
	void drawScene(bool drawShadow);
	void drawModel(bool drawEdges, bool drawShadow);
	void drawShadowMap();
	void drawGround();
	void drawIKMarkers();
	
	
	GLuint VAOs[NumVAOs];
	GLuint Buffers[NumBuffers];
	GLuint uniformVars[NumUniforms];

	GLuint MVP_loc;

	PMXInfo *pmxInfo;
	VMDInfo *vmdInfo;
	VMDMotionController *motionController;

	BulletPhysics *bulletPhysics;
	MMDPhysics *mmdPhysics;

	std::vector<GLuint> textures;
	
	//used for shadow mapping
	static const int DEPTH_TEXTURE_SIZE=1920*1080; //No clue what proper sizing should be, using screen dimensions for now
	float FRUSTUM_DEPTH=20.0f;
	GLuint depthTexture;
	GLuint depthFBO; //depth framebuffer-object
	GLuint shadowShaderProgram; //shadow mapping shader program
	
	GLuint shaderProgram;
	
	VertexData *IKVertexData;
	VertexData *RigidVertexData;
	
	
	//***Timing Variables
	double startTime;
	int ticks;
	
	glm::vec3 modelTranslate;
};

#endif
