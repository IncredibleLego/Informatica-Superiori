#x=0
#dictionary=dict()
#while x < 16:
#	if (x%2==0):
#		dictionary[x]=x*x
#	x=x+1
#print(dictionary)

x=0
count=1
userAns=0
import random
Min = int(input("Insert the min value that the random number can be: "))
Max = int(input("Insert the min value that the random number can be: "))
x =random.randint(Min, Max)
print(x)
while(x != userAns):
	userAns = int(input ("Try to guess the number: "))
	if(x == userAns):
		print("Congratulation! You guessed correctly, the number was", x)
		print("You took", count, "tries to guess the number")
	else:
		if(x < userAns):
			print("Wrong! The correct number is lower than your answer")
			count=count+1
		else:
			print("Wrong! The correct number is higher than your answer")
			count=count+1

