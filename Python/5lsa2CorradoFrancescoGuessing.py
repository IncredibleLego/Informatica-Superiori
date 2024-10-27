def getGuess(mini, maxi):
	pass
	return guess

def getRange():
	pass
	return a,b


def guessingGame(mini = 0, maxi = 100):
	secretNumber = random.randint(mini, maxi)
	guess = getGuess(mini, maxi)
	counter = 1
	while guess != secretNumber:
		if guess < secretNumber:
			print("Wrong! The correct number is lower than your answer")
		else:
			print("Wrong! The correct number is higher than your answer")
	
	return counter, secretNumber

print("Congratulation! You guessed correctly")
print("You took", counter, "tries to guess the number")
