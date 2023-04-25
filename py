#Q1

list1 = [1, 2, 3, 4, 5]
list2 = [2, 4, 6, 8, 10]

def sameNumberGenerator(list1, list2):

    return list(set(list1) & set(list2))
sameNumbers = sameNumberGenerator(list1, list2)
print(sameNumbers)

#Q2


words = ["kayak", "ata", "alper", "eye", "level"]

def findPalindromes(words):

    palindromes = []
    for word in words:
        if word == word[::-1]:
            palindromes.append(word)
    return palindromes

print(findPalindromes(words))



#Q3


list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17]

def primeFinder(list):
    i = 0
    while i < len(list):
        if list[i] > 1:
            is_prime = True
            for j in range(2, list[i]):
                if list[i] % j == 0 :
                    is_prime = False
                    break
            if not is_prime:
                del list[i]
                continue
        else:
            del list[i]
            continue
        i += 1
    return list

print(primeFinder(list))


#Q4


def anagramFinder(word, wordList):
    word_chars = sorted(word.lower().replace(" ", ""))
    anagrams = []
    for w in wordList:
        w_chars = sorted(w.lower().replace(" ", ""))
        if w_chars == word_chars:
            anagrams.append(w)
    return anagrams

word = "listen"
wordList = ["enlist", "google", "inlets", "banana"]
anagram_list = anagramFinder(word, wordList)
print(anagram_list)
