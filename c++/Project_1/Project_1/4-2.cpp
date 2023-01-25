#include <iostream>
#include <math.h>

double function(const double& z, const int& x, const int& y, const int& i, const int& j) // x, y는 임의의 점, i,j는 직선의 방정식 위의 점
{
    return (z * (x - i) - y + j);
}

double function(const double* z, const int& x, const int& y, const int& i, const int& j) // x, y는 임의의 점, i,j는 직선의 방정식 위의 점
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

    // 모든 점들 간의 거리를 출력하는 함수 입니다.
    void PrintDistance()
    {
        for (int i = 0; i < num_points; i++)
        {
            for (int j = i + 1; j < num_points; j++)
            {
                std::cout << i << " point와 " << j << "point의 거리차이 : " << sqrt(pow(point_array[i]->x - point_array[j]->x, 2) + pow(point_array[i]->y - point_array[j]->y, 2)) << std::endl;
            }
        }
    }

    // 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
    // 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
    // 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
    // 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
    // 
    // 
    // 직선의 방정식을 계산해 식 구한 뒤, (point a와 b기준, z(x-1) - y + 2 = 0 에 b값 넣으면 z 나오지)
    // a b for문 작동중에는 c,d,...만 돌고, a,c for작동중에는 뒤만 도는 방식
    // b c for문 작동중에는 d,e....만 돌고, b,d 시 ... 뒤에 것들만 돌게 하면서 중복방지
    void PrintNumMeets()
    {
        if (num_points <= 2)
        {
            std::cout << "0개" << std::endl;
        }
        else
        {
            int num_meets = num_points ; // 3개라면, 교점 최소 3개부터 시작이니.
            for (int i = 0; i < num_points; i++) // a작동 걸림
            {
                for (int j = i + 1; j < num_points; j++) // b작동 걸림
                {
                    if ((point_array[j]->x - point_array[i]->x) == 0)
                    {
                        const char z = NULL; // 기울기의 아랫 분모, 즉 x증가량이 0인 특수 경우

                        for (int x = i + 1; x < num_points; x++)  //c작동 걸림
                        {
                            if (x == j)
                            {
                                continue;
                            }

                            for (int y = x + 1; y < num_points; y++) // d작동 걸림.
                            {
                                if (y == j)
                                {
                                    continue;
                                }

                                // 여기서 위의 f(x,y)를 이용하여 f(x1, y1) * f(x2, y2) <= 0를 확인하고, 성립시 교점플러스
                                if (function(z, point_array[x]->x, point_array[x]->y, point_array[i]->x, point_array[i]->y) * function(z, point_array[y]->x, point_array[y]->y, point_array[i]->x, point_array[i]->y) < 0)
                                {
                                    num_meets++;
                                }
                            }
                        }
                    }
                    else
                    {
                        const double z = (point_array[j]->y - point_array[i]->y) / (point_array[j]->x - point_array[i]->x); // 기울기 구한거임.

                        // 여기서 f(x,y)를 알아내야겠네.
                        for (int x = i + 1; x < num_points; x++)  //c작동 걸림
                        {
                            if (x == j)
                            {
                                continue;
                            }

                            for (int y = x + 1; y < num_points; y++) // d작동 걸림.
                            {
                                if (y == j)
                                {
                                    continue;
                                }

                                // 여기서 위의 f(x,y)를 이용하여 f(x1, y1) * f(x2, y2) <= 0를 확인하고, 성립시 교점플러스
                                if ((function(z, point_array[x]->x, point_array[x]->y, point_array[i]->x, point_array[i]->y) * function(z, point_array[y]->x, point_array[y]->y, point_array[i]->x, point_array[i]->y) < 0 ))
                                {
                                    num_meets++;
                                }
                            }
                        }
                    }
                }
            }
            std::cout << num_meets << "개" << std::endl;
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
    // 점 100 개를 보관하는 배열.
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

