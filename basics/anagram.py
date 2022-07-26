first = input("First string: ")
second = input("Second string: ")

# remove punctuation, spaces, and capitalization
no_punc_1 = [i.lower() if i.isalnum() else "" for i in first]
no_punc_2 = [i.lower() if i.isalnum() else "" for i in second]
#            ^ removing capitalization
#                         ^ only letters and numbers; alternatively, i.lower() in "abcdefghijklmnopqrstuvwxyz1234567890"
#                                             ^ applies this selection to each character

# no need for [] square brackets because Python knows what you mean
# square brackets are fine though

# check if you can arrange one into the other (is it an anagram?)

if sorted(no_punc_1)==sorted(no_punc_2):
    print("they are anagrams")
else:
    print("they are not anagrams")