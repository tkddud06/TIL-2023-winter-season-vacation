# 2023-01-26 간만에 다시 시작하는 파이썬 처음처럼

## 백준 1357번
import sys

a, b = map(reversed,sys.stdin.readline().split())

a = ''.join(a)
b = ''.join(b)

a = int(a)
b = int(b)

c = list(str(a+b))
c = int(''.join(reversed(c)))

print(c)
# 좀더 간단? 하게도 될거 같은데 오랜만이라...

