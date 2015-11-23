# include <string.h>
# include "CreObstaclePacket.h"

CreObstaclePacket::CreObstaclePacket(ServerUDPResponse resp, int idx, int id, float x, float y, float speed, ObjectInfo::ObstacleType type):
AServerPacket<ServerUDPResponse>(resp, sizeof(*_data) + sizeof(*_header)), _data(new CreObstacleData), _header(new ServerUDPHeader)
{
  _header->magic = MAGIC;
  _header->command = resp;
  _header->size = sizeof(*_data);
  _header->idx = idx;
  _data->id = id;
  _data->x = x;
  _data->y = y;
  _data->speed = speed;
  _data->type = type;
  _data->magic = MAGIC;
}

CreObstaclePacket::CreObstaclePacket(ServerUDPHeader *header)
  : AServerPacket<ServerUDPResponse>(header->command, header->size + sizeof(*_header)), _data(new CreObstacle), _header(header)
{
}

CreObstaclePacket::~CreObstaclePacket()
{
}

void			CreObstaclePacket::setRawData(char *data)
{
  memcpy(_data, (void *)data, sizeof(*_data));
}

CreObstacleData*		CreObstaclePacket::getData() const
{
  return _data;
}

bool			CreObstaclePacket::checkHeader()
{
  if (_header->magic != MAGIC)
    return false;
  else if (_header->command < AUTH_UDP || _header->command > MOVE)
    return false;
  else if (_header->size < 0)
    return false;
  return true;
}

char*				CreObstaclePacket::deserialize()
{
  char*				buff = new char[sizeof(*_header) + sizeof(*_data) + 1];

  memcpy(buff, _header, sizeof(*_header));
  memcpy(buff + sizeof(*_header), _data, sizeof(*_data));
  buff[sizeof(*_header) + sizeof(*_data)] = 0;
  return buff;
}
