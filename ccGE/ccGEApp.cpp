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
	void ccGEApp::onUpdate() 
	{

	}

	void ccGEApp::Run() 
	{
		CCGE_LOG("CCGE Running..");

		ccGEWindow::Init();
		ccGEWindow::GetWindow()->Create(600, 400, "TestWindow");

		Picture pic{ "Assets/Textures/test.png" };

		Renderer::Init();

		while (true)
		{
			Renderer::Clear();
			
			Renderer::Draw(pic, 100, 100, 1);

			ccGEWindow::GetWindow()->SwapBuffers();

			onUpdate();
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
