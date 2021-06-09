#pragma once

namespace ChroMoZub
{
	class State
	{
	public:
		virtual void Init() = 0; // inicjuje stan

		virtual void HandleInput() = 0; // ogarnia inputy
		virtual void Update(float dt) = 0; //updejtuje ró¿ne zmienne itd
		virtual void Draw(float dt) = 0; //rysuje w zale¿noœci od delty

		virtual void Pause() {} 
		virtual void Resume() {}
	};
}
