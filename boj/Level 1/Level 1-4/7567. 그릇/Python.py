A = input()
print(sum( 10 if i == 0 or A[i] != A[i-1] else 5 for i in range(len(A)) ))
