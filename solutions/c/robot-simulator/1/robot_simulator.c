#include "robot_simulator.h"
robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
    return (robot_status_t){
        .direction = direction,
        .position = { x, y }
    };
}

void robot_move(robot_status_t *robot, const char *commands)
{
    static int dx[] = { 0, 1, 0, -1 };
    static int dy[] = { 1, 0, -1, 0 };
    for (const char *p = commands; *p != '\0'; p++)
    {
        switch(*p)
        {
            case 'R': 
                robot->direction = (robot->direction + 1) % DIRECTION_MAX;
                break;
            case 'L': 
                robot->direction = (robot->direction - 1 + DIRECTION_MAX) % DIRECTION_MAX;
                break;
            case 'A':
                robot->position.x += dx[robot->direction];
                robot->position.y += dy[robot->direction];
                break;
            default:
                return;
        }
    }
}