#pragma once

#include "engine/Camera.h"
#include "util/Input.h"
#include "util/Signal.h"

class PlayerController
{
public:
	PlayerController(Camera& camera);

	void Update(float delta);



private:
	Camera & m_camera;

	float m_moveSpeed = 0.2f;
	float m_mouseXspeed = 0.005f;
	float m_mouseYspeed = 0.005f;
};