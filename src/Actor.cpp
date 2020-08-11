/**
 * @author Yoshito Nakaue
 * @date 2020/08/11
 */

#include <EZGS/Actor.hpp>
#include <EZGS/System.hpp>

namespace ezgs
{
	Actor::Actor()
		:state_(State::EActive)
	{
		System::AddActor(this);
	}

	Actor::~Actor()
	{
		System::RemoveActor(this);
	}

	void Actor::Update(float dt)
	{
		if (state_ == State::EActive)
		{
			this->UpdateActor(dt);
		}
	}

	void Actor::UpdateActor(float dt)
	{

	}
}