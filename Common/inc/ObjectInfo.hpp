#ifndef _OBJECT_INFO_HPP_
# define _OBJECT_INFO_HPP_

namespace ObjectInfo
{
enum Type
  {
    PLAYER = 0,
    ALIEN,
    SHOT,
  };

enum PlayerType
  {
    PLAYER1 = 0,
    PLAYER2,
    PLAYER3,
    PLAYER4,
    NUMBERPLAYER
  };

enum ShotType
{
  PLAYERREGULAR = 1,
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
    OBSTACLE,
    NUMBEROFWAVE
  };

enum ObstacleType
  {
    NOT_WALL = -1,
    TYPE1,
    TYPE2,
    TYPE3,
    TYPE4,
    NBOBSTACLE
  };
};

#endif
