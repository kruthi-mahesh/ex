""" #sample input:
Heraldo Memelli 8135627
2
100 80

	#sample output:
Name: Memelli, Heraldo
ID: 8135627
Grade: O
"""

class Person:
	def __init__(self, firstName, lastName, idNumber):
		self.firstName = firstName
		self.lastName = lastName
		self.idNumber = idNumber
	def printPerson(self):
		print("Name:", self.lastName + ",", self.firstName)
		print("ID:", self.idNumber)

class Student(Person):

    def __init__(self,firstName,lastName,idNumber,scores):
        Person.__init__(self,firstName,lastName,idNumber)
        self.scores = []
        for s in scores:
            self.scores.append(s)
     
    def calculate(self):
        avg = float(sum(self.scores))/len(self.scores)
   
        if avg>=90:
            return 'O'
        elif avg>=80:
            return 'E'
        elif avg>=70:
            return 'A'
        elif avg>=55:
            return 'P'
        elif avg>=40:
            return 'D'
        else:
            return 'T'
     
line = input().split()
firstName = line[0]
lastName = line[1]
idNum = line[2]
numScores = int(input()) 
scores = list( map(int, input().split()) )
s = Student(firstName, lastName, idNum, scores)
s.printPerson()
print("Grade:", s.calculate())
