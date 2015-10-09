firstnumber = int(raw_input("Enter first number"))
secondnumber = int(raw_input ("Enter the number that you wich to multiply by"))
print "Are this the numbers that you which?"
print firstnumber, "X",  secondnumber
for i in range(1, secondnumber + 1):
    print firstnumber, 'times', i, '=', secondnumber * i
