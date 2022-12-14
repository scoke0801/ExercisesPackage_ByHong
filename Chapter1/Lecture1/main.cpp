#include "Game2D.h"
#include "PrimitivesGallery.h"
#include "TankExample.h"
#include "FaceExample.h"
#include "WalkingPerson.h"
#include "SolarSystem.h"

using namespace jm;

class RotatingStarExample : public Game2D
{
	float time = 0.0f;
	void drawLine_()
	{
		beginTransformation();
		// 좌표계를 이동.
		translate(0.1f, 0.0f);

		const vec2 p0(0.0f, 0.0f);
		const vec2 p1(0.5f, 0.5f);
		const vec2 p2(0.5f, 0.0f);

		drawLine(Colors::red, p0, Colors::blue, p1);
		drawLine(Colors::red, p1, Colors::blue, p2);
		drawLine(Colors::red, p2, Colors::blue, p0);

		endTransformation();

		translate(-0.1f, 0.0f);

		drawLine(Colors::red, p0, Colors::blue, p1);
		drawLine(Colors::red, p1, Colors::blue, p2);
		drawLine(Colors::red, p2, Colors::blue, p0);
	}

	void drawBox1()
	{
		drawWiredBox(Colors::gold, 0.5f, 0.25f);

		beginTransformation();
		rotate(30.0f);
		drawWiredBox(Colors::skyblue, 0.5f, 0.25f);
		endTransformation();

		beginTransformation();
		translate(0.25f, 0.0f);
		rotate(30.0f);
		drawWiredBox(Colors::red, 0.5f, 0.25f);
		endTransformation();

		beginTransformation();
		rotate(30.0f);
		translate(0.25f, 0.0f);
		drawWiredBox(Colors::blue, 0.5f, 0.25f);
		endTransformation();
	}

	void drawBox2()
	{
		setLineWidth(3.0f);

		const vec2 center_of_rot(-0.25f, 0.0f);
		
		drawWiredBox(Colors::blue, 0.5f, 0.25f);

		translate(center_of_rot);   // 3. 다시 원래 위치로 이동
		rotate(45.f);				// 2. 회전
		translate(-center_of_rot); // 1. 원점으로 이동
		drawWiredBox(Colors::gold, 0.5f, 0.25f);
		drawPoint(Colors::black, center_of_rot, 5.0f);
	}

	float starRotSpeed = 10.0f;
	float smallCirlceRotSpeed = 30.0f;
	float bigCircleRotSpeed = 20.0f;
	void update() override
	{
		beginTransformation();
		rotate(starRotSpeed * time);
		drawFilledStar(Colors::yellow, 0.25f, 0.125f);
		endTransformation();


		rotate(bigCircleRotSpeed * time);
		translate(-0.5f, 0.0f);
		drawFilledCircle(Colors::red, 0.15f);

		rotate(smallCirlceRotSpeed * time);
		translate(-0.25f, 0.0f);
		drawFilledCircle(Colors::blue, 0.05f);
		time += getTimeStep();
	}
};


int main(void)
{
	//RotatingStarExample().init("Rotating Star Example", 1280, 960, false).run();

	//jm::MouseExample().init("This is my digital canvas!", 1000, 1000, false).run();
	//jm::Game2D().init("This is my digital canvas!", 1280, 960, false).run();
	
	//jm::PrimitivesGallery().init("Primitive Gallery", 1280, 960, false).run();
	//jm::SolarSystem().run();
	//jm::FaceExample().run();
	//jm::WalkingPerson().run();
	jm::TankExample().run();

	return 0;
}
