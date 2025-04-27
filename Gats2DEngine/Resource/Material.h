#pragma once
#include "ResourceBase.h"

class WTexture;
class WShader;

class Material : public ResourceBase
{
public:
	Material();
	Material(std::shared_ptr<WTexture> texture);
	~Material();

public:
	void SetColor(const sf::Color& color);
	void SetAlpha(float alpha); //0.0f ~ 1.0f
	void SetBlendMode(sf::BlendMode mode);

	void SetShader(std::shared_ptr<WShader> shader);
	void Apply(std::shared_ptr<sf::Sprite> sprite);

	const sf::Color& GetColor() const;

private:
	std::shared_ptr<WTexture> mTexture;
	sf::Color mColor;
	sf::BlendMode mBlendMode;
	std::shared_ptr<WShader> mShader;
};

