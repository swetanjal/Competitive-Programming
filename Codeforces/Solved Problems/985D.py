S = raw_input().split()
N = int(S[0])
H = int(S[1])
def chk(X):
	low_limit = X
	high_limit = 0
	x = (X + H)//2
	nos = x - H
	if nos < 0:
		high_limit = (X * (X + 1))//2
	else:
		high_limit = (nos * ( 2 * H + nos - 1 ))//2 + (x * (x + 1)) //2
		if (X + H)%2 != 0:
			high_limit = high_limit + H + nos
	if low_limit <= N and N <= high_limit:
		return 1
	elif low_limit > N:
		return 1
	elif N > high_limit:
		return 0

ans = -1
low = 0
high = 1000000000000000000
#Guessing the minimum number of positions
while high >= low:
	mid = (high + low)//2;
	if chk(mid) == 1:
		ans = mid
		high = mid - 1
	else:
		low = mid + 1

print(ans)