import math
s = raw_input().split(" ")
x = int(s[0])
y = int(s[1])

a = y*math.log(x)
b = x*math.log(y)

if a==b:
    print "="
elif a > b:
    print ">"
else:
    print "<"