#pragma once
class SorlaSystemScene : public Scene
{
public:
	SorlaSystemScene();
	virtual ~SorlaSystemScene();

	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

private:
	shared_ptr<Texture> _texture1;
	shared_ptr<Texture> _texture2;
	shared_ptr<Texture> _texture3;
};