# 2023-02-09

# # 프로그래머스 '부족한 금액 계산하기' 문제
#
#
# # 이 놀이기구의 원래 이용료는 price원
# # 놀이기구를 N 번 째 이용한다면 원래 이용료의 N배를 받기로
# # n번째 이용시에 N * price만큼 cost 증가
# # 놀이기구를 count번 타게 되면 현재 자신이 가지고 있는 금액에서 얼마가 모자라는지를 return
# # 금액이 부족하지 않으면 0을 return
#
# # 가장 직관적인 방법은 sum_cost 변수를 만들고, 그를 연산하는 for문을 돌리는 것.
# # 놀이기구의 이용 횟수가 최대 2500회이므로, for문을 돌리는 것이 의도인 듯.
#
# # 마지막에 money - sum_cost를 사용해 0보다 작다면 ads를 리턴, 아니라면 0 리턴
#
# def solution(price, money, count):
#
#     sum_cost = 0
#     for i in range(1, count+1):
#         sum_cost += (i * price)
#
#     if money - sum_cost < 0:
#         return sum_cost - money
#     else:
#         return 0
#
# print(solution(3,20,4))
#
#########
#
# # 수학적으로 접근한 케이스에서는, for문을 사용하지 않고 이를 등차수열로 생각해서 풀더라. 이러면 count가 매우 높아도
# # 시간문제에서 자유로울 수 있다.
#
# # 그렇게도 규칙성을 살펴서, for문 대신 이렇게 생각하고 파악할 수 있음을 항상 생각해봐야 할 거 같다.
#
# # def solution(price, money, count): # 해당 코드
# #     return max(0,price*(count+1)*count//2-money)
#
# # 등차수열의 합 공식은 첫항 + 막항 * 항 개수 // 2
# # 첫항은 price, 막항은 count * price. 이므로, (count +1) * price * count // 2
#
# # count는 자연수만 주어지므로 count와 count+1 둘 중 하나는 무조건 짝수입니다.
# # 따라서 이 문제에서는 //말고 /를 써도 아무런 지장이 없습니다. 라는 코멘트도 있었음.
#
# # 언제 시간나면 수학 공식 어떤게 있었는지 한번 다 훑어줄 필요가 있을지도..

#################################################################################################

# # 프로그래머스 '키패드 누르기' 문제
#
# # 요구되는 변수는 왼손 엄지의 현 위치(x,y), 오른손 엄지의 현 위치(x,y). 그 외에는 제시된 내용들
# # 위치 관련 저장하는 내용이 1차적으로 필요하고, if문으로 세가지 경우를 가르면 될 거 같음.
# # 2,5,8,0 의 케이스에만, 해당 번호와 현 손가락들의 위치 차를 계산하는 내용 필요.
# # 손가락의 위치 차를 계산할때는. 열 차이도 무시해서는 안 됨. 중간 라인에 있을수도 있으니.
# # 주 사용 손에 따라 자동으로 걸러지는것도 필요
#
# # 가장 무식한건 숫자 하나하나 위치 변경해주는 if문 다는건데...
# # 그보다 나은건 미리 matrix를 만들어서 해당 숫자 index를 반환받는 식?
# # index가 이차원 리스트에서 안되는구나.
#
# # 무식하지만, 딕셔너리로 미리 지정은 어떨까..? 가능할 듯 싶다.
#
# # 넘버의 수는 1000개 이하이므로, for문으로 충분히 가능할 것 같다.
#
# keypad = {1:[0,0],2:[0,1],3:[0,2],4:[1,0],5:[1,1],6:[1,2],7:[2,0],8:[2,1],9:[2,2],'*':[3,0], 0:[3,1],'#':[3,2]}
#
#
# def solution(numbers, hand):
#     result = []
#     left_pos = keypad.get('*')
#     right_pos = keypad.get('#')
#
#     for i in numbers:
#         if i == 1 or i == 4 or i == 7:
#             left_pos = keypad.get(i)
#             result.append('L')
#         elif i == 3 or i == 6 or i == 9:
#             right_pos = keypad.get(i)
#             result.append('R')
#
#         else:
#             push_pos = keypad.get(i)
#             left_diff = abs(push_pos[0] - left_pos[0]) + abs(push_pos[1] - left_pos[1])
#             right_diff = abs(push_pos[0] - right_pos[0]) + abs(push_pos[1] - right_pos[1])
#             if left_diff > right_diff:
#                 right_pos = keypad.get(i)
#                 result.append('R')
#
#             elif right_diff > left_diff:
#                 left_pos = keypad.get(i)
#                 result.append('L')
#
#             else:
#                 if hand == "right":
#                     right_pos = keypad.get(i)
#                     result.append('R')
#
#                 else:
#                     left_pos = keypad.get(i)
#                     result.append('L')
#
#     return "".join(result)
#
# print(solution([1,3,4,5,8,2,1,4,5,9,5],"right"))
# print(solution([7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2],"left"))
# print(solution([1, 2, 3, 4, 5, 6, 7, 8, 9, 0],"right"))
#
# #######
#
# # 일부의 경우, BFS를 통해 어렵게 풀려고 시도하기도 했다는 것 같다.
# # python에는 if문에 각자 따로 안쓰고 in [1,4,7]이 가능함을 기억하자.
# # 리스트 형식으로 저장 안하고, 파이썬은 문자열 덧셈이 되므로
# # result를 처음부터 문자열로 만들고, result += "L" 이 가능함을 기억하자.
#
# # 그외, 코드 중에 가장 빠른 속도를 자랑할것 같은, 가능한 모든 거리 차이 값들을 이차원 리스트 꼴로 저장해놓는 특이한
# # 코드를 짠 사람이 있었다. 아래 참고.
#
# # def solution(numbers, hand):
# #     l = 10
# #     r = 11
# #     answer = ""
# #     p = [[0, 4, 3, 4, 3, 2, 3, 2, 1, 2],
# #          [4, 0, 1, 2, 0, 2, 3, 0, 3, 4],
# #          [3, 1, 0, 1, 2, 1, 2, 3, 2, 3],
# #          [4, 2, 1, 0, 3, 2, 1, 4, 3, 2],
# #          [3, 0, 2, 3, 0, 1, 2, 0, 2, 3],
# #          [2, 2, 1, 2, 1, 0, 1, 2, 1, 2],
# #          [3, 3, 2, 1, 2, 1, 0, 3, 2, 1],
# #          [2, 0, 3, 4, 0, 2, 3, 0, 1, 2],
# #          [1, 3, 2, 3, 2, 1, 2, 1, 0, 1],
# #          [2, 4, 3, 2, 3, 2, 1, 2, 1, 0],
# #          [1, 0, 4, 5, 0, 3, 4, 0, 2, 3],
# #          [1, 5, 4, 0, 4, 3, 0, 3, 2, 0]]
# #     for i in numbers:
# #         if i in [1, 4, 7]:
# #             l = i
# #             answer += "L"
# #         elif i in [3, 6, 9]:
# #             r = i
# #             answer += "R"
# #         else:
# #             if p[l][i] < p[r][i]:
# #                 l = i
# #                 answer += "L"
# #             elif p[l][i] > p[r][i]:
# #                 r = i
# #                 answer += "R"
# #             elif hand == "left":
# #                 l = i
# #                 answer += "L"
# #             else:
# #                 r = i
# #                 answer += "R"
# #     return answer
#
###########################################################

# 프로그래머스 '음양 더하기' 문제

# absolutes의 길이는 1 이상 1,000 이하입니다.
# absolutes의 모든 수는 각각 1 이상 1,000 이하입니다.
# signs의 길이는 absolutes의 길이와 같습니다.
# signs[i] 가 참이면 absolutes[i] 의 실제 정수가 양수임을, 그렇지 않으면 음수임을 의미합니다.

# 적힌대로 구현하면 끝날듯.

def solution(absolutes, signs):
    index_i = 0
    sum_num = 0
    for value_i in absolutes:
        if not signs[index_i]:
            sum_num -= value_i
        else:
            sum_num += value_i
        index_i += 1
    return sum_num

print(solution([4,7,12],[True,False,True]))

#################

# 문제 조건을 잘 보자. 불리언 리스트라는 말을 못 봐서 이상한 짓 하고 있었다.

# index_i를 활용하기보다, zip을 활용한 for문이면 더 좋았을 듯 싶다.

# def solution(absolutes, signs):
#     answer=0
#     for absolute,sign in zip(absolutes,signs):
#         if sign:
#             answer+=absolute
#         else:
#             answer-=absolute
#     return answer

# 그 외에 좀 기억에 남겨두면 좋을 것 같은 코드들

# def solution(absolutes, signs):
#     return sum(absolutes if sign else -absolutes for absolutes, sign in zip(absolutes, signs))

# def solution(absolutes, signs):
#
#     return sum([a if signs[idx] else -a for idx, a in enumerate(absolutes)])
#####################################################################################