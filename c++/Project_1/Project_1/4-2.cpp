#include <iostream>
#include <math.h>

double function(const double& z, const int& x, const int& y, const int& i, const int& j) // x, y�� ������ ��, i,j�� ������ ������ ���� ��
{
    return (z * (x - i) - y + j);
}

double function(const double* z, const int& x, const int& y, const int& i, const int& j) // x, y�� ������ ��, i,j�� ������ ������ ���� ��
{
    return (x - i);
}

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
    // ������ �������� ����� �� ���� ��, (point a�� b����, z(x-1) - y + 2 = 0 �� b�� ������ z ������)
    // a b for�� �۵��߿��� c,d,...�� ����, a,c for�۵��߿��� �ڸ� ���� ���
    // b c for�� �۵��߿��� d,e....�� ����, b,d �� ... �ڿ� �͵鸸 ���� �ϸ鼭 �ߺ�����
    void PrintNumMeets()
    {
        if (num_points <= 2)
        {
            std::cout << "0��" << std::endl;
        }
        else
        {
            int num_meets = num_points ; // 3�����, ���� �ּ� 3������ �����̴�.
            for (int i = 0; i < num_points; i++) // a�۵� �ɸ�
            {
                for (int j = i + 1; j < num_points; j++) // b�۵� �ɸ�
                {
                    if ((point_array[j]->x - point_array[i]->x) == 0)
                    {
                        const char z = NULL; // ������ �Ʒ� �и�, �� x�������� 0�� Ư�� ���

                        for (int x = i + 1; x < num_points; x++)  //c�۵� �ɸ�
                        {
                            if (x == j)
                            {
                                continue;
                            }

                            for (int y = x + 1; y < num_points; y++) // d�۵� �ɸ�.
                            {
                                if (y == j)
                                {
                                    continue;
                                }

                                // ���⼭ ���� f(x,y)�� �̿��Ͽ� f(x1, y1) * f(x2, y2) <= 0�� Ȯ���ϰ�, ������ �����÷���
                                if (function(z, point_array[x]->x, point_array[x]->y, point_array[i]->x, point_array[i]->y) * function(z, point_array[y]->x, point_array[y]->y, point_array[i]->x, point_array[i]->y) < 0)
                                {
                                    num_meets++;
                                }
                            }
                        }
                    }
                    else
                    {
                        const double z = (point_array[j]->y - point_array[i]->y) / (point_array[j]->x - point_array[i]->x); // ���� ���Ѱ���.

                        // ���⼭ f(x,y)�� �˾Ƴ��߰ڳ�.
                        for (int x = i + 1; x < num_points; x++)  //c�۵� �ɸ�
                        {
                            if (x == j)
                            {
                                continue;
                            }

                            for (int y = x + 1; y < num_points; y++) // d�۵� �ɸ�.
                            {
                                if (y == j)
                                {
                                    continue;
                                }

                                // ���⼭ ���� f(x,y)�� �̿��Ͽ� f(x1, y1) * f(x2, y2) <= 0�� Ȯ���ϰ�, ������ �����÷���
                                if ((function(z, point_array[x]->x, point_array[x]->y, point_array[i]->x, point_array[i]->y) * function(z, point_array[y]->x, point_array[y]->y, point_array[i]->x, point_array[i]->y) < 0 ))
                                {
                                    num_meets++;
                                }
                            }
                        }
                    }
                }
            }
            std::cout << num_meets << "��" << std::endl;
        }
    }

    void delete_all_point()
    {
        for (int i = 0; i < num_points; i++)
        {
            delete point_array[i];
        }
    }

private:
    // �� 100 ���� �����ϴ� �迭.
    Point* point_array[100];
    int num_points;
};

int main()
{
    Point a(0, 0);
    Point b(10, 10);
    Point c = Point(0, 10);
    Point d(10, 0);
    Point e(5, 7);
    Geometry geo;
    geo.AddPoint(a);
    geo.AddPoint(b);
    geo.AddPoint(c);
    geo.AddPoint(d);
    geo.AddPoint(e);
    geo.PrintDistance();
    geo.PrintNumMeets();

    geo.delete_all_point();

    return 0;
}

