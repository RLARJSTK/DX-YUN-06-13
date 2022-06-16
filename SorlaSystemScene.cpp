#include "framework.h"
#include "SorlaSystemScene.h"

SorlaSystemScene::SorlaSystemScene()
{
	_texture1 = make_shared<Texture>(L"Resource/SUN.png");
	_texture2 = make_shared<Texture>(L"Resource/EARTH.png");
	_texture3 = make_shared<Texture>(L"Resource/MOON.png");
	_texture2->GetPos().x = 350;
	_texture2->GetScale().x *= 0.5f;
	_texture2->GetScale().y *= 0.5f;
	_texture3->GetPos().x = 450;
	_texture3->GetScale().x *= 0.5f;
	_texture3->GetScale().y *= 0.5f;
	_texture2->SetParent(_texture1->GetMatrix());
	_texture3->SetParent(_texture2->GetMatrix());
}

SorlaSystemScene::~SorlaSystemScene()
{
}

void SorlaSystemScene::Update()
{
	// 1ÃÊ 100¹ø Update ... angle : 0.1 -> DT : 1/100 => 0.1 * DT
// 1ÃÊ 300¹ø Update ... angle : 0.3 -> DT : 1/300 => 0.3 * DT

	if (KEY_PRESS(VK_SPACE))
	{
		_texture1->GetAnagle() += 1 * DELTA_TIME; // DELTA_TIME : 1 Tick´ç °É¸®´Â ½Ã°£
		_texture2->GetAnagle() += 1 * DELTA_TIME;
		_texture3->GetAnagle() += 1 * DELTA_TIME;
	}

	int temp = Timer::GetInstance()->GetFPS();

	_texture1->GetAnagle()+= 0.001f;
	_texture2->GetAnagle()+= 0.001f;
	_texture3->GetAnagle()+= 0.001f;
	_texture1->Update();
	_texture2->Update();
	_texture3->Update();
}

void SorlaSystemScene::Render()
{
	_texture1->Render();
	_texture2->Render();
	_texture3->Render();
}
