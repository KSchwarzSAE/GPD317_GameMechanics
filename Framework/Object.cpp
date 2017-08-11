#include "Object.h"

int Object::s_count = 0;

Object::Object()
{
	s_count++;
	m_refcount = 0;
}

Object::~Object()
{
	s_count--;
}

void Object::Use()
{
	m_refcount++;
}

void Object::Release()
{
	m_refcount--;

	if (m_refcount <= 0)
		delete this;
}
