# Compering Fibonacci Sequence calculation beteen recursive way to iterative

A = 0
B = 1

######################### recursive #########################
def fibu(i):
    if i == 1: return A
    elif i == 2: return B
    else: return fibu(i-1) + fibu(i-2)

i = 1
while i <= 100:
    print fibu(i)
    i = i+1

######################### iterative #########################
a = A
b = B
i=3
print a
print b

while i <= 100:
  c = a + b
  print c
  a = b
  b = c
  i = i+1
