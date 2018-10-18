def exp(b, e, m):
    p = 1
    while e > 0:
        if e%2 == 1:
            p = ((p%m)*(b%m))%m
        b = ((b%m)*(b%m))%m
        e = e/2
    return p

def gcd(a, b):
    if b > a:
        tmp = a
        a = b
        b = tmp
    if b == 0:
        return a
    while a%b != 0:
        tmp = a%b
        a = b
        b = tmp
    return b

t = int(raw_input())
M = 1000000007
while t > 0:
    s = raw_input()
    tmp = s.split(" ")
    a = int(tmp[0])
    b = int(tmp[1])
    n = int(tmp[2])
    t = t-1
    y = abs(a-b)
    if a == b:
        print (exp(a%M, n, M) + exp(b%M, n, M))%M
        continue
    if y == 1:
        print ("1")
        continue
    x = (exp(a%y, n, y) + exp(b%y, n, y))%y
    print (gcd(x, y)%M)