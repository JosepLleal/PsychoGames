#include "Application.h"
#include "PowerUp.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"

PowerUp::PowerUp(int x, int y) : position(x, y), collider(nullptr)
{}

PowerUp::~PowerUp()
{
	if (collider != nullptr)
		collider->to_delete = true;
}

const Collider* PowerUp::GetCollider() const
{
	return collider;
}

void PowerUp::Draw(SDL_Texture* sprites)
{
	if (collider != nullptr)
		collider->SetPos(position.x, position.y);

	App->render->Blit(sprites, position.x, position.y, &(animation->GetCurrentFrame()));
}

void PowerUp::OnCollision(Collider* collider)
{

}
