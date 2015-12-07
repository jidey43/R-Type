#include "IPacket.h"

class NewGamePacket : public IPacket
{
public:
  NewGamePacket();
  virtual ~NewGamePacket();

private:
  NewGamePacket(const NewGamePacket &);
  NewGamePacket &operator=(const NewGamePacket &);
protected:

};
