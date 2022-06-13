#include "framework.h"
#include "TextureScene.h"

TextureScene::TextureScene()
{
	_texture = make_shared<Texture>(L"Resource/Bazel.png");
}

TextureScene::~TextureScene()
{
}

void TextureScene::Update()
{
	_texture->Update();
}

void TextureScene::Render()
{
	_texture->Render();
}
