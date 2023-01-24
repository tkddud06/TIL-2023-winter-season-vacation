#include <iostream>
#include <math.h>

class Point {
public:
    int x, y;

    Point(int pos_x, int pos_y)
    {
        x = pos_x;
        y = pos_y; 
    }
};

class Geometry {
public:
    Geometry() {
        num_points = 0;
    }

    void AddPoint(const Point& point) {
        point_array[num_points++] = new Point(point.x, point.y);
    }

    // ��� ���� ���� �Ÿ��� ����ϴ� �Լ� �Դϴ�.
    void PrintDistance()
    {
        for (int i = 0; i < num_points; i++)
        {
            for (int j = i + 1; j < num_points; j++)
            {
                std::cout << i << " point�� " << j << "point�� �Ÿ����� : " << sqrt(pow(point_array[i]->x - point_array[j]->x, 2) + pow(point_array[i]->y - point_array[j]->y, 2)) << std::endl;
            }
        }
    }

    // ��� ������ �մ� ������ ���� ������ ���� ������ִ� �Լ� �Դϴ�.
    // ���������� ������ �� ���� �մ� ������ �������� f(x,y) = ax+by+c = 0
    // �̶�� �� �� ������ �ٸ� �� �� (x1, y1) �� (x2, y2) �� f(x,y)=0 �� ��������
    // ���� �ٸ� �κп� ���� ������ f(x1, y1) * f(x2, y2) <= 0 �̸� �˴ϴ�.
    // 
    // 
    // ������ �������� ����� �� ���� ��, (point a�� b����, a(x-1) - y + 2 = 0 �� b�� ������ �� ������)
    // a b for�� �۵��߿��� c,d,...�� ����, a,c for�۵��߿��� �ڸ� ���� ���
    // b c for�� �۵��߿��� d,e....�� ����, b,d �� ... �ڿ� �͵鸸 ���� �ϸ鼭 �ߺ�����
    void PrintNumMeets()
    {

    }

private:
    // �� 100 ���� �����ϴ� �迭.
    Point* point_array[100];
    int num_points;
};

int main()
{
    Point a(1, 2);
    Point b(3, 5);
    Point c = Point(4, 7);

    return 0;
}