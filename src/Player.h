#include "Engine\Entity.h"

class Player : public Entity
{
public:
	void Spawn() override;
	void Tick() override;
	void Input() override;
	void Render() override;

	void DefaultProperties() override;

	Vector2f velocity;
};
