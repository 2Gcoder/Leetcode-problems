class Solution(object):
    def reverseWords(self, s):
        s1 = s.strip()
        temp = ""
        word = ""
        i=len(s1)-1
        while i >= 0:
            if s1[i] != ' ': # taking that particular word in temp from last , then if we get space that means word is finish now we add this in final sentence 
                temp = s1[i]+temp
                sp = 0 
            else:
                sp += 1 #avoid spaces because we only need single space
                if sp < 2:
                    word = word + temp + " "
                    temp =""
            i = i -1
        word = word + temp 
        
       
        return  word.strip() 

                      

                 


       
        