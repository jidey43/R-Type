#include "GameSelectorController.hh"

GameSelectorController::GameSelectorController(CUDPNetworkHandler **handler, CNetworkHandler *tcpHand) :
_tcpHand(tcpHand)
{
	_background = new Backgroud;
	std::string txt("Choisissez une partie, que la force soit avec vous");
	_disclaimer = new sf::Text(txt, *(ac->getFont(STAR)));
	
	_disclaimer->setPosition(
	(RES_X / 2) - ((_disclaimer->getCharacterSize() * txt.size()) / 2)
	, 30	
	);
	
}

void						GameSelectorController::loop()
{
  while (true)
    {
      _clock.restart();
      vc->clear();

      if (_join)
	return;

      _keyboardStatus = vc->getKeyboardStatus();
      treatEvents();

      update();
      drawMenuItems();

      vc->refresh();
      _loopTime = _clock.getElapsedTime();
      sf::sleep(sf::Time(sf::microseconds(16666)) - _loopTime);
    }	
}

void						GameSelectorController::treatEvents()
{
	
}

void						GameSelectorController::update()
{
  _background->update();	
}

void						GameSelectorController::drawMenuItems()
{
	vc->draw(_background->getDrawable());
	vc->draw(_disclaimer);
}

void						GameSelectorController::onClick(ButtonType)
{
	
}

void						GameSelectorController::joinGame()
{
	
}
