#include"StateMachine.hpp"

namespace ChroMoZub
{
	//dodawanie nowego stanu
	void StateMachine::AddState(StateRef newState, bool isReplacing)
	{
		this->_isAdding = true;
		this->_isReplacing = isReplacing;

		this->_newState = std::move(newState);
	}

	//informacja, ¿e jest usuwany stan
	void StateMachine::RemoveState()
	{
		this->_isRemoving = true;
	}

	void StateMachine::ProcessStateChanges()
	{
		//jeœli isRemoving zmienilo sie na true i jesli stos nie jest pusty
		if (this->_isRemoving && !this->_states.empty())
		{
			this->_states.pop();

			//jesli stos nie jest pusty to przelacz/wznow na kolejn stan
			if (!this->_states.empty())
			{
				this->_states.top()->Resume();
			}

			//¿eby nie usuwalo dalej
			this->_isRemoving = false;
		}
		if (this->_isAdding)
		{
			if (!this->_states.empty())
			{
				if (this->_isReplacing)
				{
					this->_states.pop();
				}
				else
				{
					this->_states.top()->Pause();
				}
			}
			//dodawanie nowgo stanu
			this->_states.push(std::move(this->_newState));
			this->_states.top()->Init();
			//koniec dodawania
			this->_isAdding = false;
		}
	}

	//aktywny stan
	StateRef& StateMachine::GetActiveState()
	{
		return this->_states.top();
	}
}