#pragma once

class Object
{
public:
	Object();
	virtual ~Object();

	void Use();
	void Release();

private:
	int m_refcount;

private:
	static int s_count;

public:
	static int Count() { return s_count; }
};