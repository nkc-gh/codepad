age = int(input("Enter age: "))

if age >= 18 and age < 60:
    print("Adult")
elif age >= 60:
    print("Old")
elif age >= 13:
    print("Teen")
else:
    print("Child")