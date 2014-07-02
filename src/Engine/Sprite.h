#include "Entity.h"


class Sprite : public Entity
{
public:
	void Initialize() override;
	void Render() override;
	bool IsColliding(Entity* collider) override;
	bool SDLCollision(Entity* collider);
	void GenerateTexture();
	std::string TexturePath;
    std::string Texture;

private:
	typedef Entity Super;
};
