#pragma once
class TextureWVPScene : public Scene
{
public:
	TextureWVPScene(); 
	virtual ~TextureWVPScene(); 
	
	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

private:
	shared_ptr<Texture> _texture;
	shared_ptr<MatrixBuffer> _worldBuffer;
	XMFLOAT2 _worldPos = { 0,0 };
};

