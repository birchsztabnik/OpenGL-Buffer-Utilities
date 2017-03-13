#pragma once

#include <Windows.h>
#include <GL\gl.h>
#include <GL\glext.h>
#include <iostream>
#include <vector>

#define BUFFER_OFFSET(i) ((char *)NULL+(i))

using std::vector;

PFNGLGENBUFFERSARBPROC glGenBuffers = (PFNGLGENBUFFERSARBPROC)wglGetProcAddress("glGenBuffers");
PFNGLBINDBUFFERPROC glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
PFNGLBUFFERDATAPROC glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");


//Creates a new array buffer
inline void createArrayBuffer(vector<GLfloat> *array, GLuint *buffer, GLenum usage)
{
	glGenBuffers(1, buffer);
	glBindBuffer(GL_ARRAY_BUFFER, *buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * array->size(), &array->at(0), usage);
}

//Creates multiple array buffers
inline void createArrayBuffer(vector<GLfloat> *array, GLuint *buffer, GLenum usage, int n)
{
	glGenBuffers(n, buffer);
	glBindBuffer(GL_ARRAY_BUFFER, *buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * array->size(), &array->at(0), usage);
}

//Creates multiple array buffers
inline void createArrayBuffer(vector<GLuint> *array, GLuint *buffer, GLenum usage, int n)
{
	glGenBuffers(n, buffer);
	glBindBuffer(GL_ARRAY_BUFFER, *buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GL_UNSIGNED_INT) * array->size(), &array->at(0), usage);
}

//Creates a new array buffer with specific target
inline void createArrayBuffer(GLenum target, vector<GLuint> *array, GLuint *buffer, GLenum usage)
{
	glBindBuffer(target, *buffer);
	glBufferData(target, sizeof(GL_UNSIGNED_INT) * array->size(), &array->at(0), usage);
}

//Creates a new array buffer with specific target
inline void createArrayBuffer(GLenum target, vector<GLfloat> *array, GLuint *buffer, GLenum usage)
{
	glBindBuffer(target, *buffer);
	glBufferData(target, sizeof(GLfloat) * array->size(), &array->at(0), usage);
}

//Binds the buffer and directs the color pointer to it
inline void bindColor(GLuint *buffer, int size)
{
	glBindBuffer(GL_ARRAY_BUFFER, *buffer);
	glColorPointer(size, GL_FLOAT, 0, BUFFER_OFFSET(0));
}

//Binds the buffer and directs the vertex pointer to it
inline void bindVertex(GLuint *buffer, int size)
{
	glBindBuffer(GL_ARRAY_BUFFER, *buffer);
	glVertexPointer(size, GL_FLOAT, 0, BUFFER_OFFSET(0));
}

//Binds the buffer and directs the color pointer to it
inline void bindColor(GLuint *buffer, int size, const int offset)
{
	glBindBuffer(GL_ARRAY_BUFFER, *buffer);
	glColorPointer(size, GL_FLOAT, 0, BUFFER_OFFSET(offset));
}

//Binds the buffer and directs the vertex pointer to it
inline void bindVertex(GLuint *buffer, int size, const int offset)
{
	glBindBuffer(GL_ARRAY_BUFFER, *buffer);
	glVertexPointer(size, GL_FLOAT, 0, BUFFER_OFFSET(offset));
}