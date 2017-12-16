#pragma once
#include "GameHeader.h"
#include "Buffers.h"

class ObjectModel
{
 
	char TextureName[100];
	GLuint TextureIndex; 
	int Type;

	Buffers* ObjectBuffers; 

	glm::mat4 Translation;
	glm::mat4 Scaling;
	glm::mat4 Rotation;
	glm::mat4 ModelMatrix;
	 

public:
	ObjectModel( char* texName, Buffers* buffers , int type); // construct object 
	ObjectModel(char* ObjName, char *texName); // special constructor for spaceship child class 
	ObjectModel();
	~ObjectModel();
	 Box& getBoundingBox(); 
	virtual Buffers* getBuffers();
	int getType(); 
	virtual void translateBoundingBox(float x, float y, float z);
	virtual void scaleBoundingBox(float x, float y, float z);

	glm::mat4 GetModelTranslation();
	glm::mat4 GetModelRotation();
	glm::mat4 GetModelScaling();

	virtual bool Draw(GLuint programID, GLuint MatrixID, GLuint vertexPosition_modelspaceID, GLuint vertexUVID , GLuint TextureID);
	virtual bool setModelMatrix(glm::mat4 model);
	virtual void constructModelMatrix(glm::vec3 Translation, glm::vec3 Scaling, glm::vec3 Rotation);
	virtual bool setTexture(char texName[]);
	virtual bool detectCollision(Box bb);

};
