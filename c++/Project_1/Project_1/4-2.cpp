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
    // 직선의 방정식을 계산해 식 구한 뒤, (point a와 b기준, a(x-1) - y + 2 = 0 에 b값 넣으면 식 나오지)
    // a b for문 작동중에는 c,d,...만 돌고, a,c for작동중에는 뒤만 도는 방식
    // b c for문 작동중에는 d,e....만 돌고, b,d 시 ... 뒤에 것들만 돌게 하면서 중복방지
    void PrintNumMeets()
    {

    }

private:
    // 점 100 개를 보관하는 배열.
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