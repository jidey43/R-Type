#ifndef _OBJECT_INFO_HPP_
# define _OBJECT_INFO_HPP_

namespace ObjectInfo
{
enum Type
  {
    PLAYER = 0,
    ALIEN,
    SHOT
  };

enum ShotType
{
  PLAYERREGULAR = 0,
  ALIENREGULAR,
  NUMBEROFSHOT
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
    XELF16,
    WALL,
    NUMBEROFWAVE
  };
};

#endif
