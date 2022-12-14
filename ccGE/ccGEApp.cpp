#include "pch.h"
#include "ccGEApp.h"
#include "CCGEUtil.h"
#include "ccGEWindow.h"
#include "glad/glad.h"
#include "stb_image.h"
#include "Picture.h"
#include "Renderer.h"

namespace ccGE
{
	ccGEApp::ccGEApp()
	{
		ccGEWindow::Init();
		ccGEWindow::GetWindow()->Create(1000, 800, "TextWindow");

		Renderer::Init();
	}

	void ccGEApp::onUpdate()
	{

	}

	void ccGEApp::Run() 
	{
		CCGE_LOG("CCGE Running..");

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		Picture pic{ "Assets/Textures/test.png" };

		while (true)
		{
			Renderer::Clear();

			onUpdate();
			
			Renderer::Draw(pic, 200, 200, 1);

			std::this_thread::sleep_until(mNextFrameTime);

			ccGEWindow::GetWindow()->SwapBuffers();

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		}

		
	}
}

/*
	ccGE::Picure pic1{"Assets/pic1.png")
	ccGE::Shader shade{"Assets/vertex.glsl", "Assets/fragment.glsl"};

	coord1 is the x coordinate of the bottom left corner of the picture
	coord2 is the y coordinate of the bottom left corner of the picture
	coord3 is the z coordinate, which is the distance for the viewer
	ccGE::Renderer::Draw(pic1, shade, coord1, coord2, coord3);
*/
