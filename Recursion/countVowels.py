def isVowel(character):
  character = character.lower()
  vowels = 'aeiou'
  if character in vowels:
    return 1
  else:
    return 0

def countVowels(string, n):
  if n == 1:
    return isVowel(string[0])

  return countVowels(string, n - 1) + isVowel(string[n - 1])

string = 'Educative'
print(countVowels(string, len(string)))