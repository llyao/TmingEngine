#pragma once
#include "Core/SubSystem.h"
#include "Core/Context.h"
#include "imgui.h"
#include "imgui_impl_glfw_gl3.h"
#include "Box2DTest.h"

class TestDemo
{
public:
	TestDemo()
	{
		Initlization();
	}

	~TestDemo()
	{

	}

	virtual void Initlization()
	{
	
	}

	virtual void Render_SceneObject();
private:

};

class Tiles : public Test
{
public:
	enum
	{
		e_count = 20
	};

	Tiles()
	{
		m_fixtureCount = 0;
		b2Timer timer;

		{
			float32 a = 0.5f;
			b2BodyDef bd;
			bd.position.y = -a;
			b2Body* ground = m_world->CreateBody(&bd);

#if 1
			int32 N = 200;
			int32 M = 10;
			b2Vec2 position;
			position.y = 0.0f;
			for (int32 j = 0; j < M; ++j)
			{
				position.x = -N * a;
				for (int32 i = 0; i < N; ++i)
				{
					b2PolygonShape shape;
					shape.SetAsBox(a, a, position, 0.0f);
					ground->CreateFixture(&shape, 0.0f);
					++m_fixtureCount;
					position.x += 2.0f * a;
				}
				position.y -= 2.0f * a;
			}
#else
			int32 N = 200;
			int32 M = 10;
			b2Vec2 position;
			position.x = -N * a;
			for (int32 i = 0; i < N; ++i)
			{
				position.y = 0.0f;
				for (int32 j = 0; j < M; ++j)
				{
					b2PolygonShape shape;
					shape.SetAsBox(a, a, position, 0.0f);
					ground->CreateFixture(&shape, 0.0f);
					position.y -= 2.0f * a;
				}
				position.x += 2.0f * a;
			}
#endif
		}

		{
			float32 a = 0.5f;
			b2PolygonShape shape;
			shape.SetAsBox(a, a);

			b2Vec2 x(-7.0f, 0.75f);
			b2Vec2 y;
			b2Vec2 deltaX(0.5625f, 1.25f);
			b2Vec2 deltaY(1.125f, 0.0f);

			for (int32 i = 0; i < e_count; ++i)
			{
				y = x;

				for (int32 j = i; j < e_count; ++j)
				{
					b2BodyDef bd;
					bd.type = b2_dynamicBody;
					bd.position = y;

					//if (i == 0 && j == 0)
					//{
					//	bd.allowSleep = false;
					//}
					//else
					//{
					//	bd.allowSleep = true;
					//}

					b2Body* body = m_world->CreateBody(&bd);
					body->CreateFixture(&shape, 5.0f);
					++m_fixtureCount;
					y += deltaY;
				}

				x += deltaX;
			}
		}

		m_createTime = timer.GetMilliseconds();
	}

	void Step(Settings* settings)
	{
		const b2ContactManager& cm = m_world->GetContactManager();
		int32 height = cm.m_broadPhase.GetTreeHeight();
		int32 leafCount = cm.m_broadPhase.GetProxyCount();
		int32 minimumNodeCount = 2 * leafCount - 1;
		float32 minimumHeight = ceilf(logf(float32(minimumNodeCount)) / logf(2.0f));
		g_debugDraw.DrawString(5, m_textLine, "dynamic tree height = %d, min = %d", height, int32(minimumHeight));
		m_textLine += DRAW_STRING_NEW_LINE;

		Test::Step(settings);

		g_debugDraw.DrawString(5, m_textLine, "create time = %6.2f ms, fixture count = %d",
			m_createTime, m_fixtureCount);
		m_textLine += DRAW_STRING_NEW_LINE;

		//b2DynamicTree* tree = &m_world->m_contactManager.m_broadPhase.m_tree;

		//if (m_stepCount == 400)
		//{
		//	tree->RebuildBottomUp();
		//}
	}

	static Test* Create()
	{
		return new Tiles;
	}

	int32 m_fixtureCount;
	float32 m_createTime;
};

class Demo1 :public TestDemo
{
public:
	Tiles * tiles;
	Demo1() :TestDemo()
	{
		tiles = new Tiles();
	}

	~Demo1()
	{
	}

	void Render_SceneObject() override;


private:

};

class Demo2 :public TestDemo
{
public:
	Demo2()
	{
	}

	~Demo2()
	{
	}

	void Render_SceneObject() override;

private:

};