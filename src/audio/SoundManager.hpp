#pragma once

#include "Uncopiable.hpp"

#include <SFML/Audio.hpp>

#include <vector>
#include <memory>
#include <string>


namespace falksalt
{
	class SoundManager final : Uncopiable
	{
	public:
		SoundManager();

		void playMusic(bool play); // not implement
		void playChime();
		void playSpecialChime();

		typedef std::unique_ptr<std::pair<sf::SoundBuffer, sf::Sound>> Sound;
	
	private:
		std::vector<Sound> m_chimes, m_specialChimes;
		sf::Music m_music;
	};
}

