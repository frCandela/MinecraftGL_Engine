#pragma once


#include <iostream>
#include <vector>

#include "engine/RigidBody.h"
#include "util/Input.h"

#include "btBulletDynamicsCommon.h"


class Physics
{
public:
	static void StepSimulation(float timeStep);
	static RigidBody* CreateRigidBody(float mass, const btTransform& startTransform, btCollisionShape* shape, bool isTrigger = false);
	static bool DeleteRigidBody(RigidBody* rigidBody);
	static btCollisionWorld::ClosestRayResultCallback RayCast(glm::vec3 Start, glm::vec3 End);

private:
	//Singleton pattern
	static Physics m_instance;
	Physics& operator= (const Physics&) {}
	Physics(const Physics&) {}
	Physics();
	~Physics();

	//Usefull members to create a bullet physics engine
	static btDefaultCollisionConfiguration * collisionConfiguration;
	static btCollisionDispatcher* dispatcher;
	static btBroadphaseInterface* overlappingPairCache;
	static btSequentialImpulseConstraintSolver* solver;
	static btDiscreteDynamicsWorld* dynamicsWorld;

	//Callbacks for the physics collisions between rigidbodies
	static bool ContactDestroyed(void* userPersistentData);
	static bool ContactAdded(btManifoldPoint& pt, const btCollisionObjectWrapper* colObj0Wrap, int partId0, int index0, const btCollisionObjectWrapper* colObj1Wrap, int partId1, int index1);
};

