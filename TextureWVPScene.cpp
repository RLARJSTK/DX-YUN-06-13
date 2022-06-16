#include "framework.h"
#include "TextureWVPScene.h"

TextureWVPScene::TextureWVPScene()
{
	_texture = make_shared<Texture>(L"Resource/EARTH.png");

	_worldBuffer = make_shared<MatrixBuffer>();
}

TextureWVPScene::~TextureWVPScene()
{
}

void TextureWVPScene::Update()
{
	// ÀÌ°Ç À¯Á¾¿¬¾¾°Å¸¦ ¹è²¸¼­ÇÑ°Ô¾ê¿ä
	//_cameraPos = { -300.0f,0 };
	//_angle += 0.001f;
	// S ´Â {1,1}
	//XMMATRIX cameraMatrix = XMMatrixRotationZ(_angle);
	//cameraMatrix = XMMatrixTranslation(_cameraPos.x, _cameraPos.y, 0);
	//_viewBuffer->SetMatrix(cameraMatrix);

	//_texture->GetPos().x -= 0.1f;

	if (GetAsyncKeyState(VK_F1))
	{
		_texture->GetScale().x += 0.001f;

	}
	if (GetAsyncKeyState(VK_F2))
	{
		_texture->GetScale().y += 0.001f;
	}

	if (GetAsyncKeyState(VK_F3))
	{
		_texture->GetScale().x -= 0.001f;
	}

	if (GetAsyncKeyState(VK_F4))
	{
		_texture->GetScale().y -= 0.001f;
	}




	if (GetAsyncKeyState(VK_SPACE))
	{
		_texture->GetAnagle() += 0.001f;
	}

	if (GetAsyncKeyState(VK_SHIFT))
	{
		_texture->GetAnagle() -= 0.001f;
	}



	if (GetAsyncKeyState(VK_LEFT))
	{
		_texture->GetPos().x -= 0.1f;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		_texture->GetPos().x += 0.1f;
	}

	if (GetAsyncKeyState(VK_UP))
	{
		_texture->GetPos().y += 0.1f;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		_texture->GetPos().y -= 0.1f;
	}
	_worldBuffer->Update();
	_texture->Update();
}

void TextureWVPScene::Render()
{
	_worldBuffer->SetVSBuffer(0);


	_texture->Render();
}
