# 2023-01-29

# # 백준 2163번
#
# # n*m 크기의 초콜릿을 정확히 n*m개의 조각으로 나눠가질 생각임.
# # 금이 가있는 위치만 쪼갤 수 있음.
# # 횟수를 최소로 해서, 모두 1*1크기로 쪼개기 위한 최소 횟수를 구해라
# # 횟수는 (n-1) + (n * (m-1))로 일정함. 가로로 n-1번의 금만큼 쪼개면, n개의 조각이 생기고,
# # 조각마다 m-1번만큼 쪼개야하므로.
#
# import sys
#
# n, m = map(int, sys.stdin.readline().split())
# print((n-1) + (n * (m - 1))) # 짧게 줄이면, n*m-1이 됨.

##############################################################

# # 백준 1110번
#
# # 1. 주어진 수가 10보다 작다면 앞에 0을 붙여 2자리 수로 만든다
# # 2. 각 자리의 숫자를 구한다.
# # 3. 주어진 수의 가장 오른쪽 자리 수와, 앞아서 구한 합의 가장 오른쪽 자리 수를 이어붙인다.
#
# # 26부터 시작한다. 2+6 = 8이다. 새로운 수는 68이다. 6+8 = 14이다. 새로운 수는 84이다. 8+4 = 12이다. 새로운 수는 42이다. 4+2 = 6이다. 새로운 수는 26이다.
# # 위의 예는 4번만에 원래 수로 돌아올 수 있다. 따라서 26의 사이클의 길이는 4이다. 사이클 수를 구하는 프로그램 작성
#
# # 주어진 계산 방법에 따라 반복하며 횟수를 기록하고, 원래 수가 나오면 정지 후 출력
#
# import sys
# n = int(sys.stdin.readline())
# new_num = n
# counter = 1
# while 1:
#     new_num = (10 * (new_num % 10)) + (((new_num // 10) + (new_num % 10)) % 10)
#
#     if new_num == n:
#         break
#     else:
#         counter += 1
#
# print(counter)

##########################################################################################

# # 백준 1085번
#
# # 한수는 지금 (x, y)에 있다. 직사각형은 각 변이 좌표축에 평행하고, 왼쪽 아래 꼭짓점은 (0, 0), 오른쪽 위 꼭짓점은 (w, h)에 있다.
# # 직사각형의 경계선까지 가는 거리의 최솟값을 구하는 프로그램을 작성하시오.
#
# # 직사각형의 선분들 위에 한수가 있는 모양이다. 0,0이 왼쪽아래꼭짓점, 오른쪽위 꼭짓점은 (w,h)네.
# # 입력받은 x, y중 x가 0 혹은 w에 도달하거나, y가 0 또는 h에 도달하면 조건 만족이고, 4가지 중 최솟값을 구하면 되네.
#
# import sys
# x, y, w, h = map(int, sys.stdin.readline().split())
# print(min(x, y, w-x, h-y))

###########################################################################################
#
# # 첫 번째 줄에 손익분기점 즉 최초로 이익이 발생하는 판매량을 출력한다. 손익분기점이 존재하지 않으면 -1을 출력한다.
# # A만원의 고정 비용
# # 한 대의 노트북을 생산하는 데 B만원의 가변 비용
# # 노트북 가격이 C만원으로 책정
# # 손익분기점 판매량을 출력
#
# # 손익분기점이 존재하지 않을 조건 : 가변 비용 >= 노트북 가격
#
# # 손익분기점은 while문 조건에 총비용 >= 이익 달아놓고, 총비용에 b 계속 더해주고, 이익도 더해주고 하면 될듯.
#
# # 0.35초짜리라 통과를 못한건가 사람들이? a,b,c가 21억인거 보니까 쎄한데.
#
# # import sys
# #
# # a, b, c = map(int,sys.stdin.readline().split())
# #
# # if b >= c:
# #     print(-1)
# #     exit(1)
# #
# # all_cost = a
# # all_benefit = 0
# # counter = 0
# # while all_cost >= all_benefit:
# #     counter += 1
# #     all_cost += b
# #     all_benefit += c
# #
# # print(counter)
#
# # 위 코드는 엄청 오래 걸린다. 안됨.
#
# # 실제로, c-b 가 1제품당 순이익이라고 볼 수 있다. 해당 순이익이, 고정지출을 넘는 순간이 총수익이 총지출을 넘는 순간이다.
# # 그렇기 때문에, (a // (c-b)) + 1를 수행하면 되지 않을까?
#
# import sys
#
# a, b, c = map(int,sys.stdin.readline().split())
#
# if b >= c:
#     print(-1)
#     exit(0) # 백준은 exit(1) 시 에러 난다.
#
# print((a // (c-b)) + 1)

##############################################################################################
