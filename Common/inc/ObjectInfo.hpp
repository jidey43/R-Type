#ifndef _OBJECT_INFO_HPP_
# define _OBJECT_INFO_HPP_

namespace ObjectInfo
{
enum Type
  {
    PLAYER = 0,
    ALIEN,
    PROJECTILE_PLAYER,
    PROJECTILE_ALIEN
  };

enum Way
  {
    TOP = 0,
    RIGHT,
    BOT,
    LEFT
  };

enum WaveType
  {
    BYDO = 0,
    GLAM,
    DOKAN,
    KAYBEROS,
    RIOS,
    SCANT,
    SHELL,
    YORK,
    XELF16
  };
};

#endif
