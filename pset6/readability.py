from cs50 import get_string
import math

lang = input("What language are you processing?\n")
    
string_length = len(lang)

letters = 0
words = 0
sentences = 0
    
for i in range(string_length):
    
    sentences = lang.count('.') + lang.count('!') + lang.count('?')  
    
    words = lang.count(' ') + 1
    
    for i in range(string_length):
        if(lang[i].isalpha()):
            letters += 1
        
    L = float(letters / words * 100)
    
    S =  float(sentences / words * 100)
    
    index = round(0.0588 * L - 0.296 * S - 15.8)
    
    if(index < 1):
        print('Before Grade 1\n')
        break
       
    elif(index >= 16): 
        print('Grade 16+\n')
        break
       
    else:
        print("Grade ", index)
        break 