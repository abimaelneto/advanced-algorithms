# Initialize each person (m ϵ M , h ϵ H) to be free.
# while (there is a man who is free and hasn't proposed to every woman) {
#  Choose such a man m
#  w = 1º woman on m's list to whom m has not yet proposed
#  if (w is free)
#  m and w become engaged
#  else // w is curently engaged to m’
# if (w prefers m to her fiancé m')
#  m and w become engaged;
# m' becomes free
#  else w rejects m // m remains free!
# }
class StableMatch():
    def __init__(self):
        self.tests_number = 0
        self.test_marriages_number = 0
    
    def initialization(self):

        # initializes everyone as free. '-1' is equivalent to no one engaged
        self.men_list = list([-1 for i in range(self.test_marriages_number)])
        self.women_list= list([-1 for i in range(self.test_marriages_number)])

        # initializes preferences matrix with zeros
        self.womens_preferences = list([0 for i in range(self.test_marriages_number)] for j in range(self.test_marriages_number))
        self.mens_preferences = list([0 for i in range(self.test_marriages_number)] for j in range(self.test_marriages_number))

        # list with mens proposes - False if hasn't still proposed to woman
        self.mens_proposes = list([False for i in range(self.test_marriages_number)] for j in range(self.test_marriages_number))

    def readsWomensPreferences(self):
        for women in range(self.test_marriages_number):
            #read women's preferences and saves it
            input_string = input()
            self.preferencesArray = input_string.split(' ')
            
            for pos in range(1, len(self.preferencesArray)):
                self.womens_preferences[women][pos-1] = int(self.preferencesArray[pos]) - 1

    def readsMensPreferences(self):
        for men in range(self.test_marriages_number):
            #read men's preferences and saves it
            input_string = input()
            self.preferencesArray = input_string.split(' ')
            
            for pos in range(1, len(self.preferencesArray)):
                self.mens_preferences[men][pos-1] = int(self.preferencesArray[pos]) - 1

    def propose(self, man, woman):
        # they engage 
        self.men_list[man] = woman
        self.women_list[woman] = man

    def searchForMarriage(self):
        # while there is free men
        while -1 in self.men_list:
            man = self.men_list.index(-1)
            # while man has options
            while len(self.mens_preferences) > 0:

                # takes his most desired choice that is free
                woman = self.mens_preferences[man][0]

                # if woman is free, propose and break search
                if self.women_list[woman] == -1:
                    self.propose(man, woman)
                    break

                # if not, checks her preference
                else:
                    fiance = self.women_list[woman]
                    fiancePlaceOnPreference = self.womens_preferences[woman].index(fiance)
                    manPlaceOnPreference = self.womens_preferences[woman].index(man)
                    
                    # if man is preferred over her actual fiance, propose
                    if(fiancePlaceOnPreference > manPlaceOnPreference ):                            
                        # frees old fiance
                        self.men_list[fiance] = 0
                        
                        # new proposal
                        self.propose(man, woman)
                        break

                    else:
                        # remove her from preferences list
                        self.mens_preferences[man].pop(0)

    def printStableMatch(self):
        for index, value in enumerate(self.men_list):
            man = index+1
            woman = value+1
            print(f'{man} {woman}')

    def main(self):

        # gets number of tests to be done
        self.tests_number = int(input())

        for test in range(self.tests_number):
            
            # reads number of marriages to be matched - zero based
            self.test_marriages_number = int(input())

            self.initialization()

            self.readsWomensPreferences()
            self.readsMensPreferences()

            # searches for marriage while there is free man
            self.searchForMarriage()

            # if all men and woman are engaged, we've found the stable match
            if -1 in self.men_list or -1 in self.women_list:
                print('We got an error on the algorythm')
            
            self.printStableMatch()

        

   
if __name__ == "__main__":
    stableMatch = StableMatch()
    stableMatch.main()