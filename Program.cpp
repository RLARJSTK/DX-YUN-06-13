#include "framework.h"
#include "Program.h"

#include "../Scene/TextureScene.h"
#include "../Scene/TextureWVPScene.h"
#include "../Scene/SorlaSystemScene.h"

Program::Program()
{
	_scene = make_shared<SorlaSystemScene>();
	_viewBuffer = make_shared<MatrixBuffer>();
	_projectionBuffer = make_shared<MatrixBuffer>();

	XMMATRIX projection = XMMatrixOrthographicLH(WIN_WIDTH, WIN_HEIGHT, 0.0f, 1.0f);

	_projectionBuffer->SetMatrix(projection);
	Timer::GetInstance()->SetFPS(60);
}

Program::~Program()
{
}

void Program::Update()
{
	
	_scene->Update();
	_projectionBuffer->Update();
	int FPS = Timer::GetInstance()->GetFPS();
	_viewBuffer->Update();
}

void Program::Render()
{
	Device::GetInstance()->Clear();
	_viewBuffer->SetVSBuffer(1);
	_projectionBuffer->SetVSBuffer(2);
	_scene->Render();

	Device::GetInstance()->Present();
}
