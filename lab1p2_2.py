file = open("in.txt","r")
string = file.read().replace("\n", " ")
print("The string in the txt file:",string)
def isPalindrome(string: str, first: int, last: int):
    while first < last:
        if string[first] != string[last]:
            return False
        first += 1
        last -= 1
    return True

def checkRemove(string: str):
    first = 0
    last = len(string) - 1
    while first < last:
        if string[first] == string[last]:
            first += 1
            last -= 1
        else:
            if isPalindrome(string, first + 1, last):
                return first
            if isPalindrome(string, first, last - 1):
                return last
            return 2
    return 3

i = checkRemove(string)
 
if(i == 2):
    print("No")
elif(i == 3):
    print("Yes")
else:
    print("Yes, delete", string[i], "at position", i+1)
