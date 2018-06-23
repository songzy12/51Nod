# http://www.51nod.com/contest/Problem.html#!problemId=1960&contestId=49
# http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1960

 
# the result is (a_1^n - 1)/(a_1 - 1) * \sum_n + (a_2^n - 1)/(a_2 - 1) * sum_n

n, m = map(int, raw_input().split())
a = list(map(int, raw_input().split()))
a.sort()

p = int(1e9+7)
a = map(lambda x: x % p, a)

def pow_(x, n):
    if n == 0:
        return 1
    temp = pow_(x, n // 2)
    if n % 2:
        return (temp * temp * x) % p
    return (temp * temp) % p

def map_(x):
    if x != 1: # NOTE: here should be x % p (when x = 1e9 + 8)
        # NOTE: when we have %, take care of /
        return (((pow_(x, n) - 1) * pow_(x - 1, p - 2)) % p + p) % p # // (x - 1)# (pow_(x, n) - 1) // (x - 1)

    # NOTE: take care of the special case
    if x == 1:
        return n % p
    

def solve(a):
    a = map(map_, a)
    b = [(i*n+1+i*n+n)*n//2 % p for i in range(m)]

    res = 0
    for x, y in zip(a, b):
        res += x * y
        res %= p
    return res


print(solve(a))
