x = input(("Enter first number"))
y = input(("Enter second number"))
while y != 0:
  x, y = y, x % y
print (x)
