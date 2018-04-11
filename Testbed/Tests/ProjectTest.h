#pragma once
#include <vector>

#ifndef PRJTEST_H
#define PRJTEST_H

#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f

class Ball
{
	public:
		b2Body * m_body;
		float m_radius;

		Ball(b2World* world, float radius)
		{
			m_body = NULL;
			m_radius = radius;
		}
		
		~Ball() {}
};

class PrjTest : public Test
{
	public: 
		std::vector<Ball*> balls;

		PrjTest() 
		{
			{
				//a static body
				b2BodyDef myBodyDef;
				myBodyDef.type = b2_staticBody;
				myBodyDef.position.Set(0, 0);
				b2Body* staticBody = m_world->CreateBody(&myBodyDef);

				//shape definition
				b2PolygonShape polygonShape;

				//fixture definition
				b2FixtureDef myFixtureDef;
				myFixtureDef.shape = &polygonShape;

				//add four walls to the static body
				polygonShape.SetAsBox(20, 1, b2Vec2(0, 0), 0);//ground
				staticBody->CreateFixture(&myFixtureDef);
				polygonShape.SetAsBox(20, 1, b2Vec2(0, 40), 0);//ceiling
				staticBody->CreateFixture(&myFixtureDef);
				polygonShape.SetAsBox(1, 20, b2Vec2(-20, 20), 0);//left wall
				staticBody->CreateFixture(&myFixtureDef);
				polygonShape.SetAsBox(1, 20, b2Vec2(20, 20), 0);//right wall
				staticBody->CreateFixture(&myFixtureDef);
			}
		}

		void Step(Settings* settings)
		{
			Test::Step(settings);
		}

		static Test* Create()
		{
			return new PrjTest;
		}
};

#endif 

