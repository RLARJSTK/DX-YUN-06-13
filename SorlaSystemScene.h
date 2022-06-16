#pragma once
class SorlaSystemScene : public Scene
{
public:
	SorlaSystemScene();
	virtual ~SorlaSystemScene();

	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;

private:
	shared_ptr<Texture> _texture1;
	shared_ptr<Texture> _texture2;
	shared_ptr<Texture> _texture3;
};