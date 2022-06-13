#pragma once
class Texture
{
public:
	Texture(wstring file);
	~Texture();

	void Update();
	void Render();

    XMFLOAT2& GetPos() { return _pos; }

    XMMATRIX& GetMatrix() { return _srt_matrix; }

    XMFLOAT2& GetScale() { return _scale; }

    float& GetAnagle() { return _angle; }
private:
    void CreateVertices();
    // 사각형에 텍스쳐 맵핑하는데 필요한 것들
    // 1. inputLayOut
    // 2. VertexBuffer
    // 3. 그리는 방법(Primitive Topology)
    // 4. SRV
    // 5. Sampler
    // 6. VS
    // 7. PS

    XMFLOAT2 _scale = { 1,1 };
    float _angle = { 0.0f };
    XMFLOAT2 _pos = { 0,0 };
    XMFLOAT2 _cameraPos = { 0,0 };

    XMMATRIX _srt_matrix;
    shared_ptr<MatrixBuffer> _worldBuffer;
    shared_ptr<MatrixBuffer> _viewBuffer;

    vector<VertexUV> _vertices;
    vector<UINT> _indicies;

    shared_ptr<VertexShader>    _vertexShader;
    shared_ptr<PixelShader>     _pixelShader;

    shared_ptr<VertexBuffer>    _vertexBuffer;
    shared_ptr<IndexBuffer>     _indexBuffer;
    shared_ptr<SRV>             _srv;
    shared_ptr<SamplerState>    _sampler;
	
};

