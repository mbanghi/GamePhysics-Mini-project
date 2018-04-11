#pragma once
#include"..\..\Testbed\Framework\Test.h"

#ifndef PRJTEST_H
#define PRJTEST_H

class PrjTest : public Test
{
	public: 
		PrjTest() 
		{
			{
				b2BodyDef myBodyDef;
				myBodyDef.type = b2_dynamicBody; //Dynamic body type
				myBodyDef.position.Set(0, 20); //Starting position
				myBodyDef.angle = 0; //Starting angle

				b2Body* dynamicBody = m_world->CreateBody(&myBodyDef);

				//Create shapes
				b2PolygonShape box;
				box.SetAsBox(1, 1);

				//Create fixture definition
				b2FixtureDef boxFixtureDef;
				boxFixtureDef.shape = &box;
				boxFixtureDef.density = 1;
				dynamicBody->CreateFixture(&boxFixtureDef);
			}
		}

		void Step(Settings* settings)
		{
			Test::Step(settings);

			//Draw text on screen
			g_debugDraw.DrawString(5, m_textLine, "Test text");
			m_textLine += 15;
		}

		static Test* Create()
		{
			return new PrjTest;
		}
};

#endif 

