# 2023-02-08

# # 프로그래머스 '나머지가 1이 되는 수 찾기' 문제
#
# # 자연수 n이 매개변수로 주어집니다.
# # n을 x로 나눈 나머지가 1이 되도록 하는
# # 가장 작은 자연수 x를 return 하도록
# # 3 ≤ n ≤ 1,000,000
#
# # 떠오르는 가장 무식한 방법은 2부터 n-1까지 for문 돌려보는거
# # 최대 해봤자 백만번 정도니 충분히 가능할 것 같다.
#
#
# # 아니라면,(조오오오금 더 성능을 높여?보자면?) n-1의 인수 중 가장 작은 소수를 구하기로 더 빠르게 가능할 듯 싶은데?
# # 에라토스테네스의 체 활용
# # 이게 유의미한 행위인지는 모르겠다. 가장 오래걸리는 케이스에서 6ms정도 더 빠르긴 하던데, 어떤 케이스에선 오히려 0.05ms정도 느림.
# # 에라토스테세스의 체 도는 시간이랑 아래 if문에서 또 체크하는 시간 겹처서 크게는 차이가 무의미 한 거 같다. 아래 if문 더 간추릴 방법이 있나?
#
# sosu_matrix = [True for i in range(1000001)]
# sosu_matrix[0] = False
# sosu_matrix[1] = False
# for i in range(2,1001):
#     if sosu_matrix[i]:
#         for j in range(i**2, 1000001, i):
#             sosu_matrix[j] = False
#
# def solution(n):
#     i = 2
#     while True:
#         if sosu_matrix[i] and (n-1) % i == 0:
#             break
#         i += 1
#     answer = i
#     return answer
#
# print(solution(10))
# print(solution(12))

####################################################################################################


